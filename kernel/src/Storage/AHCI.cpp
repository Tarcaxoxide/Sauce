#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Storage{

        #define HBA_PORT_DEVICE_PRESENT 0x3
        #define HBA_PORT_IPM_ACTIVE 0x1
        #define SATA_SIG_ATAPI 0xEB140101
        #define SATA_SIG_ATA 0x00000101
        #define SATA_SIG_SEMB 0xC33C0101
        #define SATA_SIG_PM 0x96690101

        #define HBA_PxCMD_CR 0x8000
        #define HBA_PxCMD_FRE 0x0010
        #define HBA_PxCMD_FR 0x4000
        #define HBA_PxCMD_ST 0x0001


        ParsedHBAPort_st CheckPortType(HBAPort_st* port){
            Sauce::IO::Debug::Print_Call("CheckPortType",Sauce::IO::Debug::STORAGE,true);
            ParsedHBAPort_st ParsedHBAPort;
            ParsedHBAPort.Address=port;
            ParsedHBAPort.SataStatus = port->sataStatus;
            ParsedHBAPort.InterfacePowerManagement = (ParsedHBAPort.SataStatus >> 8)&0b111;
            ParsedHBAPort.DeviceDetection = ParsedHBAPort.SataStatus&0b111;

            if(ParsedHBAPort.DeviceDetection != HBA_PORT_DEVICE_PRESENT){
                ParsedHBAPort.Type=HBAPortType::NONE;
                Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE,true);
                return ParsedHBAPort;
            }
            if(ParsedHBAPort.InterfacePowerManagement != HBA_PORT_IPM_ACTIVE){
                ParsedHBAPort.Type=HBAPortType::NONE;
                Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE,true);
                return ParsedHBAPort;
            }
            switch(port->signature){
                case SATA_SIG_ATAPI:{
                    ParsedHBAPort.Type = HBAPortType::SATAPI;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SATAPI",Sauce::IO::Debug::STORAGE,true);
                }break;
                case SATA_SIG_ATA:{
                    ParsedHBAPort.Type = HBAPortType::SATA;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SATA",Sauce::IO::Debug::STORAGE,true);
                }break;
                case SATA_SIG_PM:{
                    ParsedHBAPort.Type = HBAPortType::PM;
                    Sauce::IO::Debug::Print_Return("HBAPortType::PM",Sauce::IO::Debug::STORAGE,true);
                }break;
                case SATA_SIG_SEMB:{
                    ParsedHBAPort.Type = HBAPortType::SEMB;
                    Sauce::IO::Debug::Print_Return("HBAPortType::SEMB",Sauce::IO::Debug::STORAGE,true);
                }break;
                default:{
                    ParsedHBAPort.Type = HBAPortType::NONE;
                    Sauce::IO::Debug::Print_Return("HBAPortType::NONE",Sauce::IO::Debug::STORAGE,true);
                }break;
            }
            return ParsedHBAPort;
        }

        void ParsedHBAPort_st::Configure(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::Configure",Sauce::IO::Debug::STORAGE,true);
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
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE,true);
        }
        void ParsedHBAPort_st::StartCMD(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::StartCMD",Sauce::IO::Debug::STORAGE,true);
            while(Address->cmdSts & HBA_PxCMD_CR);
            Address->cmdSts |=  HBA_PxCMD_FRE;
            Address->cmdSts |=  HBA_PxCMD_ST;
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE,true);
        }
        void ParsedHBAPort_st::StopCMD(){
            Sauce::IO::Debug::Print_Call("ParsedHBAPort_st::StopCMD",Sauce::IO::Debug::STORAGE,true);
            Address->cmdSts &= ~HBA_PxCMD_ST;
            Address->cmdSts &= ~HBA_PxCMD_FRE;
            while((Address->cmdSts & HBA_PxCMD_FR || Address->cmdSts & HBA_PxCMD_CR));
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE,true);
        }

        AHCIDriver_cl::AHCIDriver_cl(Sauce::IO::PCIDeviceHeader_st* pciBaseAddress){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::AHCIDriver_cl",Sauce::IO::Debug::STORAGE,true);
            this->pciBaseAddress=pciBaseAddress;
            ABAR = (HBAMemory_st*)((uint64_t)((Sauce::IO::PCIHeader0_st*)pciBaseAddress)->BAR5);
            Sauce::Global::PageTableManager.MapMemory(ABAR,ABAR);
            ProbePorts();
            Sauce::IO::Debug::Print_Return("this",Sauce::IO::Debug::STORAGE,true);
        }
        void AHCIDriver_cl::ProbePorts(){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::ProbePorts",Sauce::IO::Debug::STORAGE,true);
            uint32_t portsImplemented = ABAR->portsImplemented;
            if(!HBAPorts.Size()){
                for(int i=0;i<32;i++){
                    if(portsImplemented&(1<<i)){
                        HBAPorts.AddLast(CheckPortType(&ABAR->ports[i]));
                    }
                }
            }
            for(int i=0;i<32;i++){
                switch(HBAPorts[i].Type){
                    case HBAPortType::NONE:{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::STORAGE,true){
                            Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(",HBAPortType::NONE",Sauce::IO::Debug::STORAGE,true);
                        }
                    }break;
                    case HBAPortType::SATA:{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::STORAGE,true){
                            Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(",HBAPortType::SATA",Sauce::IO::Debug::STORAGE,true);
                            HBAPorts[i].Configure();
                        }
                    }break;
                    case HBAPortType::SEMB:{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::STORAGE,true){
                            Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(",HBAPortType::SEMB",Sauce::IO::Debug::STORAGE,true);
                            //HBAPorts[i].Configure();
                        }
                    }break;
                    case HBAPortType::PM:{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::STORAGE,true){
                            Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(",HBAPortType::PM",Sauce::IO::Debug::STORAGE,true);
                            //HBAPorts[i].Configure();
                        }
                    }break;
                    case HBAPortType::SATAPI:{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::STORAGE,true){
                            Sauce::IO::Debug::Print_Detail("HBAPort#",Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(i),Sauce::IO::Debug::STORAGE,false);
                            Sauce::IO::Debug::Print_Detail(",HBAPortType::SATAPI",Sauce::IO::Debug::STORAGE,true);
                            HBAPorts[i].Configure();
                        }
                    }break;
                }
            }
            
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE,true);
        }
        AHCIDriver_cl::~AHCIDriver_cl(){
            Sauce::IO::Debug::Print_Call("AHCIDriver_cl::~AHCIDriver_cl",Sauce::IO::Debug::STORAGE,true);
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::STORAGE,true);
        }
    };
};