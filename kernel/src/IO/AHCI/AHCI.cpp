#include<Sauce/IO/AHCI/AHCI.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        namespace AHCI{
            #define HBA_PORT_DEV_PRESENT 0x3
            #define HBA_PORT_IPM_ACTIVE 0x1
            #define HBA_PxCMD_CR 0x8000
            #define HBA_PxCMD_FRE 0x0010
            #define HBA_PxCMD_FR 0x4000
            #define HBA_PxCMD_ST 0x0001
            #define SATA_SIG_ATAPI 0xEB140101
            #define SATA_SIG_ATA 0x00000101
            #define SATA_SIG_SEMB 0xC33C0101
            #define SATA_SIG_PM 0x96690101
            PortType CheckPortType(HBAPort* port){
                uint32_t sataStatus = port->sataStatus;
                uint8_t interfacePowerManagement = (sataStatus >> 8) & 0b111;
                uint8_t deviceDetection = sataStatus & 0b111;

                if(deviceDetection != HBA_PORT_DEV_PRESENT)return PortType::None;
                switch(port->signature){
                    case SATA_SIG_ATAPI:return PortType::SATAPI;
                    case SATA_SIG_ATA:return PortType::SATA;
                    case SATA_SIG_SEMB:return PortType::SEMB;
                    case SATA_SIG_PM:return PortType::PM;
                    default:return PortType::None;
                }
                return PortType::None; //<- if for some odd reason you get here, should be impossible but still.
            }
            void Port::Configure(){
                Sauce::IO::Debug::COM1_Console.Write("[Port::Configure]\n\0");
                StopCMD();

                void* newBase = Sauce::Memory::GlobalAllocator.RequestPage();
                hbaPort->commandListBase = (uint32_t)(uint64_t)newBase;
                hbaPort->commandListBaseUpper = (uint32_t)((uint64_t)newBase >> 32);
                Sauce::Memory::memset((void*)(hbaPort->commandListBase),0,1024);
                void* fisBase = Sauce::Memory::GlobalAllocator.RequestPage();
                hbaPort->fisBaseAddress = (uint32_t)(uint64_t)fisBase;
                hbaPort->fisBaseAddressUpper = (uint32_t)((uint64_t)fisBase >> 32);
                Sauce::Memory::memset(fisBase,0,256);

                HBACommandHeader* cmdheader = (HBACommandHeader*)(((uint64_t)hbaPort->commandListBase) + ((uint64_t)hbaPort->commandListBaseUpper << 32));

                for(int i=0;i<32;i++){
                    cmdheader[i].prdtLength = 8;
                    void* cmdTableAddress = Sauce::Memory::GlobalAllocator.RequestPage();
                    uint64_t address = (uint64_t)cmdTableAddress + (i << 8);
                    cmdheader[i].commandTableBaseAddress = (uint32_t)address;
                    cmdheader[i].commandTableBaseAddressUpper = (uint32_t)(address >> 32);
                    Sauce::Memory::memset(cmdTableAddress,0,256);
                }

                StartCMD();
            }
            void Port::StopCMD(){
                Sauce::IO::Debug::COM1_Console.Write("[Port::StopCMD]\n\0");
                hbaPort->cmdStatus &= ~HBA_PxCMD_ST;
                hbaPort->cmdStatus &= ~HBA_PxCMD_FRE;
                while((hbaPort->cmdStatus & HBA_PxCMD_FR) || (hbaPort->cmdStatus & HBA_PxCMD_CR));
            }
            void Port::StartCMD(){
                Sauce::IO::Debug::COM1_Console.Write("[Port::StartCMD]\n\0");
                while(hbaPort->cmdStatus & HBA_PxCMD_CR);

                hbaPort->cmdStatus |= HBA_PxCMD_FRE;
                hbaPort->cmdStatus |= HBA_PxCMD_ST;
            }
            AHCIDriver::AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress){
                Sauce::IO::Debug::COM1_Console.Write("[AHCIDriver::AHCIDriver]\n\0");
                this->PCIBaseAddress=pciBaseAddress;

                ABAR = (Sauce::IO::AHCI::HBAMemory*)((Sauce::IO::PCIHeader0*)pciBaseAddress)->BAR5;
                Sauce::Memory::GlobalPageTableManager.MapMemory(ABAR,ABAR);
                ProbePorts();
                for(int i=0;i<Ports.Size();i++){
                    Ports[i].Configure();
                    switch(Ports[i].portType){
                            case PortType::SATA:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SATA)\n\0");
                                
                            }break;
                            case PortType::SEMB:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SEMB)\n\0");
                            }break;
                            case PortType::PM:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(PM)\n\0");
                            }break;
                            case PortType::SATAPI:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SATAPI)\n\0");
                            }break;
                            default:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(\0");
                                Sauce::IO::Debug::COM1_Console.Write("?:\0");
                                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString(ABAR->ports[i].signature));
                                Sauce::IO::Debug::COM1_Console.Write(")\n\0");
                            }break;
                        }
                }
            }
            AHCIDriver::~AHCIDriver(){
                Sauce::IO::Debug::COM1_Console.Write("[AHCIDriver::~AHCIDriver]\n\0");
            }
            void AHCIDriver::ProbePorts(){
                Sauce::IO::Debug::COM1_Console.Write("[AHCIDriver::ProbePorts]\n\0");
                uint32_t portsImplemented = ABAR->portsImplemented;
                for(int i=0;i<32;i++){
                    if(portsImplemented & (1 << i)){
                        PortType portType = CheckPortType(&ABAR->ports[i]);
                        switch(portType){
                            case PortType::SATA:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SATA)\n\0");
                                Ports.AddLast({&ABAR->ports[i],portType,nullptr,i});
                            }break;
                            case PortType::SEMB:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SEMB)\n\0");
                                Ports.AddLast({&ABAR->ports[i],portType,nullptr,i});
                            }break;
                            case PortType::PM:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(PM)\n\0");
                                Ports.AddLast({&ABAR->ports[i],portType,nullptr,i});
                            }break;
                            case PortType::SATAPI:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(SATAPI)\n\0");
                                Ports.AddLast({&ABAR->ports[i],portType,nullptr,i});
                            }break;
                            default:{
                                Sauce::IO::Debug::COM1_Console.Write("\t->(\0");
                                Sauce::IO::Debug::COM1_Console.Write("?:\0");
                                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString(ABAR->ports[i].signature));
                                Sauce::IO::Debug::COM1_Console.Write(")\n\0");
                                //Ports.AddLast({&ABAR->ports[i],portType,nullptr,i});
                            }break;
                        }
                    }
                }
            }
        };
    };
};