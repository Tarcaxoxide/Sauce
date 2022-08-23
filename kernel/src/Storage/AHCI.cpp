#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Storage{
        ParsedHBAPort_st CheckPortType(HBAPort_st* port){
            Sauce::IO::Debug::Print_Call("CheckPortType",Sauce::IO::Debug::STORAGE);
            ParsedHBAPort_st ParsedHBAPort;
            ParsedHBAPort.Address=port;
            ParsedHBAPort.SataStatus = port->sataStatus;
            ParsedHBAPort.InterfacePowerManagement = (ParsedHBAPort.SataStatus >> 8)&0b111;
            ParsedHBAPort.DeviceDetection = ParsedHBAPort.SataStatus&0b111;

            if(ParsedHBAPort.DeviceDetection != HBA_PORT_DEVICE_PRESENT){
                ParsedHBAPort.Type=HBAPortType::NONE;
                Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE);
                return ParsedHBAPort;
            }
            if(ParsedHBAPort.InterfacePowerManagement != HBA_PORT_IPM_ACTIVE){
                ParsedHBAPort.Type=HBAPortType::NONE;
                Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE);
                return ParsedHBAPort;
            }
            switch(port->signature){
                case SATA_SIG_ATAPI:{
                    ParsedHBAPort.Type = HBAPortType::SATAPI;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SATAPI",Sauce::IO::Debug::STORAGE);
                }break;
                case SATA_SIG_ATA:{
                    ParsedHBAPort.Type = HBAPortType::SATA;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SATA",Sauce::IO::Debug::STORAGE);
                }break;
                case SATA_SIG_PM:{
                    ParsedHBAPort.Type = HBAPortType::PM;
                    Sauce::IO::Debug::Print_Return("HBAPortType::PM",Sauce::IO::Debug::STORAGE);
                }break;
                case SATA_SIG_SEMB:{
                    ParsedHBAPort.Type = HBAPortType::SEMB;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SEMB",Sauce::IO::Debug::STORAGE);
                }break;
                default:{
                    ParsedHBAPort.Type = HBAPortType::NONE;
                    Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE);
                }break;
            }
            return ParsedHBAPort;
        }
        void ParsedHBAPort_st::Configure(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::Configure",Sauce::IO::Debug::STORAGE);
            StopCMD();

            void* commandBase = Sauce::Global::PageFrameAllocator.RequestPage();
            Address->commandListBase = (uint32_t)(uint64_t)commandBase;
            Address->commandListBaseUpper = (uint32_t)((uint64_t)commandBase >> 32);
            Sauce::Memory::memset(commandBase,0,1024);

            void* fisBase = Sauce::Global::PageFrameAllocator.RequestPage();
            Address->fisBaseAddress = (uint32_t)(uint64_t)fisBase;
            Address->fisBaseAddressUpper = (uint32_t)((uint64_t)fisBase >> 32);
            Sauce::Memory::memset(fisBase,0,1024);

            HBACommandHeader_st* cmdHeader = (HBACommandHeader_st*)((uint64_t)Address->commandListBase + ((uint64_t)Address->commandListBaseUpper << 32));

            for(int i=0;i<32;i++){
                cmdHeader[i].prdtLength = 8;
                void* cmdTableAddress = Sauce::Global::PageFrameAllocator.RequestPage();
                uint64_t _address = ((uint64_t)cmdTableAddress + (i << 8));
                cmdHeader[i].commandTableBaseAddress = (uint32_t)_address;
                cmdHeader[i].commandTableBaseAddressUpper = (uint32_t)(_address >> 32);
                Sauce::Memory::memset((void*)_address,0,256);
            }

            StartCMD();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE);
        }
        void ParsedHBAPort_st::StartCMD(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::StartCMD",Sauce::IO::Debug::STORAGE);
            while(Address->cmdSts & HBA_PxCMD_CR);
            Address->cmdSts |=  HBA_PxCMD_FRE;
            Address->cmdSts |=  HBA_PxCMD_ST;
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE);
        }
        void ParsedHBAPort_st::StopCMD(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::StopCMD",Sauce::IO::Debug::STORAGE);
            Address->cmdSts &= ~HBA_PxCMD_ST;
            Address->cmdSts &= ~HBA_PxCMD_FRE;
            while((Address->cmdSts & HBA_PxCMD_FR || Address->cmdSts & HBA_PxCMD_CR));
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE);
        }
        bool ParsedHBAPort_st::Read(uint64_t sector,uint16_t sectorCount,void* buffer){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::Read",Sauce::IO::Debug::STORAGE);

            size_t spin=0;
            while((Address->taskFileData & (ATA_DEV_BUSY | ATA_DEV_DRQ)) && spin < 1000000){spin++;}

            if(spin == 1000000){Sauce::IO::Debug::Print_Return("False",Sauce::IO::Debug::STORAGE);return false;}

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

            while(!(Address->commandIssue == 0)){if(Address->interruptStatus & HBA_PxIS_TFES){Sauce::IO::Debug::Print_Return("False",Sauce::IO::Debug::STORAGE);return false;}}

            Sauce::IO::Debug::Print_Return("True",Sauce::IO::Debug::STORAGE);
            return true;
        }

        void AHCIDriver_cl::Read(size_t portNumber,size_t startingSector,size_t sectorCount,Sauce::Memory::List_cl<uint8_t> &Bufferr){
            if(HBAPorts[portNumber].buffer == nullptr)HBAPorts[portNumber].buffer=(uint8_t*)Sauce::Global::PageFrameAllocator.RequestPage();

            for(size_t SectorI=0;SectorI<sectorCount;SectorI++){
                Sauce::Memory::memset(HBAPorts[portNumber].buffer,0,1024);
                HBAPorts[portNumber].Read(startingSector+SectorI,1,HBAPorts[portNumber].buffer);
                
                for(int t=0;t<512;t++){
                    Bufferr.AddLast((uint8_t)HBAPorts[portNumber].buffer[t]);
                }
            }
        }
        AHCIDriver_cl::AHCIDriver_cl(Sauce::IO::PCIDeviceHeader_st* pciBaseAddress){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::AHCIDriver_cl",Sauce::IO::Debug::STORAGE);
            this->pciBaseAddress=pciBaseAddress;
            ABAR = (HBAMemory_st*)((uint64_t)((Sauce::IO::PCIHeader0_st*)pciBaseAddress)->BAR5);
            Sauce::Global::PageTableManager.MapMemory(ABAR,ABAR);
            ProbePorts();


            Sauce::IO::Debug::Print_Return("this",Sauce::IO::Debug::STORAGE);
        }
        void AHCIDriver_cl::ProbePorts(){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::ProbePorts",Sauce::IO::Debug::STORAGE);
            uint32_t portsImplemented = ABAR->portsImplemented;
            if(!HBAPorts.Size()){
                for(int i=0;i<32;i++){
                    if(portsImplemented&(1<<i)){
                        HBAPorts.AddLast(CheckPortType(&ABAR->ports[i]));
                    }
                }
            }
            for(int i=0;i<HBAPorts.Size();i++){
                switch(HBAPorts[i].Type){
                    case HBAPortType::NONE:{
                        Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Start);
                        Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Middle);
                        Sauce::IO::Debug::Print_Detail(",HBAPortType::NONE",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::End);
                    }break;
                    case HBAPortType::SATA:{
                        Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Start);
                        Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Middle);
                        Sauce::IO::Debug::Print_Detail(",HBAPortType::SATA",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::End);
                        HBAPorts[i].Configure();
                    }break;
                    case HBAPortType::SEMB:{
                        Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Start);
                        Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Middle);
                        Sauce::IO::Debug::Print_Detail(",HBAPortType::SEMB",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::End);
                        HBAPorts[i].Configure();
                    }break;
                    case HBAPortType::PM:{
                        Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Start);
                        Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Middle);
                        Sauce::IO::Debug::Print_Detail(",HBAPortType::PM",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::End);
                        HBAPorts[i].Configure();
                    }break;
                    case HBAPortType::SATAPI:{
                        Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Start);
                        Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::Middle);
                        Sauce::IO::Debug::Print_Detail(",HBAPortType::SATAPI",Sauce::IO::Debug::STORAGE,Sauce::IO::Debug::StartOfPrint::End);
                        HBAPorts[i].Configure();
                    }break;
                }
            }
            
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE);
        }
        AHCIDriver_cl::~AHCIDriver_cl(){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::~AHCIDriver_cl",Sauce::IO::Debug::STORAGE);
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE);
        }
    };
};