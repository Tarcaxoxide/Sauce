#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/Global.hpp>
#include<std/to_string.hpp>
namespace Sauce{
	namespace Storage{
		ParsedHBAPort_st CheckPortType(HBAPort_st* port){
			ParsedHBAPort_st ParsedHBAPort;
			ParsedHBAPort.Address=port;
			ParsedHBAPort.SataStatus = port->sataStatus;
			ParsedHBAPort.InterfacePowerManagement = (ParsedHBAPort.SataStatus >> 8)&0b111;
			ParsedHBAPort.DeviceDetection = ParsedHBAPort.SataStatus&0b111;
			if(ParsedHBAPort.DeviceDetection != HBA_PORT_DEVICE_PRESENT){
				ParsedHBAPort.Type=HBAPortType::NONE;
				return ParsedHBAPort;
			}
			if(ParsedHBAPort.InterfacePowerManagement != HBA_PORT_IPM_ACTIVE){
				ParsedHBAPort.Type=HBAPortType::NONE;
				return ParsedHBAPort;
			}
			switch(port->signature){
				case SATA_SIG_ATAPI:{
					ParsedHBAPort.Type = HBAPortType::SATAPI;
				}break;
				case SATA_SIG_ATA:{
					ParsedHBAPort.Type = HBAPortType::SATA;
				}break;
				case SATA_SIG_PM:{
					ParsedHBAPort.Type = HBAPortType::PM;
				}break;
				case SATA_SIG_SEMB:{
					ParsedHBAPort.Type = HBAPortType::SEMB;
				}break;
				default:{
					ParsedHBAPort.Type = HBAPortType::NONE;
				}break;
			}
			return ParsedHBAPort;
		}
		void ParsedHBAPort_st::Configure(){
			StopCMD();
			void* commandBase = Sauce::Global::Memory::PageFrameAllocator.RequestPage();
			Address->commandListBase = (uint32_t)(uint64_t)commandBase;
			Address->commandListBaseUpper = (uint32_t)((uint64_t)commandBase >> 32);
			Sauce::Memory::memset(commandBase,0,1024);
			void* fisBase = Sauce::Global::Memory::PageFrameAllocator.RequestPage();
			Address->fisBaseAddress = (uint32_t)(uint64_t)fisBase;
			Address->fisBaseAddressUpper = (uint32_t)((uint64_t)fisBase >> 32);
			Sauce::Memory::memset(fisBase,0,1024);
			HBACommandHeader_st* cmdHeader = (HBACommandHeader_st*)((uint64_t)Address->commandListBase + ((uint64_t)Address->commandListBaseUpper << 32));
			for(int i=0;i<32;i++){
				cmdHeader[i].prdtLength = 8;
				void* cmdTableAddress = Sauce::Global::Memory::PageFrameAllocator.RequestPage();
				uint64_t _address = ((uint64_t)cmdTableAddress + (i << 8));
				cmdHeader[i].commandTableBaseAddress = (uint32_t)_address;
				cmdHeader[i].commandTableBaseAddressUpper = (uint32_t)(_address >> 32);
				Sauce::Memory::memset((void*)_address,0,256);
			}
			StartCMD();
		}
		void ParsedHBAPort_st::StartCMD(){
			while(Address->cmdSts & HBA_PxCMD_CR);
			Address->cmdSts |=  HBA_PxCMD_FRE;
			Address->cmdSts |=  HBA_PxCMD_ST;
		}
		void ParsedHBAPort_st::StopCMD(){
			Address->cmdSts &= ~HBA_PxCMD_ST;
			Address->cmdSts &= ~HBA_PxCMD_FRE;
			while((Address->cmdSts & HBA_PxCMD_FR || Address->cmdSts & HBA_PxCMD_CR));
		}
		bool ParsedHBAPort_st::Read(uint64_t sector,uint16_t sectorCount,void* buffer){
			size_t spin=0;
			while((Address->taskFileData & (ATA_DEV_BUSY | ATA_DEV_DRQ)) && spin < 1000000){spin++;}
			if(spin == 1000000){return false;}
			uint32_t sectorL = (uint32_t)sector;
			uint32_t sectorH = (uint32_t)(sector >> 32);
			Address->interruptStatus = (uint32_t)-1; // Clear pending interrupt bits
			HBACommandHeader_st* cmdHeader = (HBACommandHeader_st*)(uint64_t)Address->commandListBase;
			cmdHeader->commandFISLength = sizeof(FIS_REG_H2D_st)/sizeof(uint32_t); // command FIS size
			cmdHeader->write=0; // this is a read.
			cmdHeader->prdtLength=1;
			HBACommandTable_st* commandTable = (HBACommandTable_st*)((uint64_t)cmdHeader->commandTableBaseAddress);
			Sauce::Memory::memset(commandTable,0,sizeof(HBACommandTable_st)+(cmdHeader->prdtLength-1)*sizeof(HBAPRDTEntry_st));
			commandTable->prdtEntry[0].dataBaseAddress = (uint32_t)(uint64_t)buffer;
			commandTable->prdtEntry[0].dataBaseAddressUpper = (uint32_t)((uint64_t)buffer >> 32);
			commandTable->prdtEntry[0].byteCount = (sectorCount<<9)-1; // 512 per sector
			commandTable->prdtEntry[0].interruptOnCompletion=1;
			FIS_REG_H2D_st* cmdFIS = (FIS_REG_H2D_st*)(&commandTable->commandFIS);
			cmdFIS->fisType = FIS_TYPE_REG_H2D;
			cmdFIS->commandControl = 1; // command
			cmdFIS->command = ATA_CMD_READ_DMA_EX;
			cmdFIS->lba0 = (uint8_t)sectorL;
			cmdFIS->lba1 = (uint8_t)(sectorL >> 8);
			cmdFIS->lba2 = (uint8_t)(sectorL >> 16);
			cmdFIS->lba3 = (uint8_t)sectorH;
			cmdFIS->lba4 = (uint8_t)(sectorH >> 8);
			cmdFIS->lba5 = (uint8_t)(sectorH >> 16);
			cmdFIS->deviceRegister = 1<<6; // LBA mode
			cmdFIS->countLow = sectorCount & 0xFF;
			cmdFIS->countHigh = (sectorCount >> 8) & 0xFF;
			Address->commandIssue = 1;
			while(!(Address->commandIssue == 0)){if(Address->interruptStatus & HBA_PxIS_TFES){return false;}}
			return true;
		}
		void AHCIDriver_cl::Read(size_t portNumber,size_t startingSector,size_t sectorCount,std::ustring &Bufferr){
			if(HBAPorts[portNumber].buffer == nullptr)HBAPorts[portNumber].buffer=(uint8_t*)Sauce::Global::Memory::PageFrameAllocator.RequestPage();
			for(size_t SectorI=0;SectorI<sectorCount;SectorI++){
				Sauce::Memory::memset(HBAPorts[portNumber].buffer,0,1024);
				HBAPorts[portNumber].Read(startingSector+SectorI,1,HBAPorts[portNumber].buffer);
				for(size_t t=0;t<sector_size;t++){
					Bufferr.AddLast((uint8_t)HBAPorts[portNumber].buffer[t]);
				}
			}
		}
		uint8_t AHCIDriver_cl::Read(size_t portNumber,size_t ByteToRead){
			if(HBAPorts[portNumber].buffer == nullptr)HBAPorts[portNumber].buffer=(uint8_t*)Sauce::Global::Memory::PageFrameAllocator.RequestPage();
			size_t SectorToRead=ByteToRead/sector_size;
			size_t SectorOffset=ByteToRead%sector_size;
			HBAPorts[portNumber].Read(SectorToRead,1,HBAPorts[portNumber].buffer);
			return HBAPorts[portNumber].buffer[SectorOffset];
		}
		AHCIDriver_cl::AHCIDriver_cl(Sauce::IO::PCI::PCIDeviceHeader_st* pciBaseAddress){
			this->pciBaseAddress=pciBaseAddress;
			ABAR = (HBAMemory_st*)((uint64_t)((Sauce::IO::PCI::PCIHeader0_st*)pciBaseAddress)->BAR5);
			Sauce::Global::Memory::PageTableManager.MapMemory(ABAR,ABAR);
			ProbePorts();
		}
		void AHCIDriver_cl::ProbePorts(){
			uint32_t portsImplemented = ABAR->portsImplemented;
			if(!HBAPorts.Size()){
				for(int i=0;i<32;i++){
					if(portsImplemented&(1<<i)){
						HBAPorts.AddLast(CheckPortType(&ABAR->ports[i]));
					}
				}
			}
			for(size_t i=0;i<HBAPorts.Size();i++){
				switch(HBAPorts[i].Type){
					case HBAPortType::NONE:{
					}break;
					case HBAPortType::SATA:{
						HBAPorts[i].Configure();
					}break;
					case HBAPortType::SEMB:{
						HBAPorts[i].Configure();
					}break;
					case HBAPortType::PM:{
						HBAPorts[i].Configure();
					}break;
					case HBAPortType::SATAPI:{
						HBAPorts[i].Configure();
					}break;
				}
			}
		}
		std::string AHCIDriver_cl::ListPorts(){
			std::string Result;
			for(size_t i=0;i<HBAPorts.Size();i++){
				Result.AddLast((char*)"[");
				Result.AddLast(std::to_string(i));
				Result.AddLast((char*)",");
				switch(HBAPorts[i].Type){
					case HBAPortType::NONE:{
						Result.AddLast((char*)"NONE");
					}break;
					case HBAPortType::SATA:{
						Result.AddLast((char*)"SATA");
					}break;
					case HBAPortType::SEMB:{
						Result.AddLast((char*)"SEMB");
					}break;
					case HBAPortType::PM:{
						Result.AddLast((char*)"PM");
					}break;
					case HBAPortType::SATAPI:{
						Result.AddLast((char*)"SATAPI");
					}break;
				}
				Result.AddLast((char*)"]\n\r");
			}
			return Result;
		}
		AHCIDriver_cl::~AHCIDriver_cl(){
		}
	};
};