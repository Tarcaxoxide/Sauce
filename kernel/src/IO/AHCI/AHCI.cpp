#include<Sauce/IO/AHCI/AHCI.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        namespace AHCI{
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

                buffer = (uint8_t*)Sauce::Memory::GlobalAllocator.RequestPage();
                Sauce::Memory::memset(buffer,0,0x1000);

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
            bool Port::Read(uint64_t sector,uint32_t sectorCount){
                Sauce::IO::Debug::COM1_Console.Write("[Port::Read]\0");
                Sauce::IO::Debug::COM1_Console.Write(" ->(sector:\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString(sector));
                Sauce::IO::Debug::COM1_Console.Write(",sectorCount:\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString(sectorCount));
                Sauce::IO::Debug::COM1_Console.Write(",buffer:\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString((uint64_t)buffer));
                Sauce::IO::Debug::COM1_Console.Write(")\n\0");

                Sauce::IO::Debug::COM1_Console.Write("\t(Waiting for port to be free)\n\0");
                uint64_t spin=0;
                while((hbaPort->taskFileData & (ATA_DEV_BUSY | ATA_DEV_DRQ)) && spin < 1000000){
                    spin++;
                }
                if(spin >= 1000000){
                    Sauce::IO::Debug::COM1_Console.Write("\t(Failed, Hanged)\n\0");
                    return false;
                }
                if(buffer == nullptr){
                    Sauce::IO::Debug::COM1_Console.Write("\t(Failed, no buffer)\n\0");
                    return false;
                }
                Sauce::IO::Debug::COM1_Console.Write("\t(Done waiting)\n\0");
                uint32_t sectorL = (uint32_t)sector;
                uint32_t sectorH = (uint32_t)(sector >> 32);

                hbaPort->interruptStatus = (uint32_t)-1; // Clear pending interrupt bits
                HBACommandHeader* cmdheader = (HBACommandHeader*)hbaPort->commandListBase;
                cmdheader->commandFISLength = sizeof(FIS_REG_H2D)/sizeof(uint32_t); //command FIS size
                cmdheader->write=0; // this is a read;
                cmdheader->prdtLength=1;

                HBACommandTable* commandTable = (HBACommandTable*)(cmdheader->commandTableBaseAddress);
                Sauce::Memory::memset(commandTable,0,sizeof(HBACommandTable)+(cmdheader->prdtLength-1)*sizeof(HBAPRDTEntry));

                commandTable->prdtEntry[0].dataBaseAddress = (uint32_t)(uint64_t)buffer;
                commandTable->prdtEntry[0].dataBaseAddressUpper = (uint32_t)((uint64_t)buffer >> 32);
                commandTable->prdtEntry[0].byteCount = (sectorCount<<9)-1; // 512 bytes per sector
                commandTable->prdtEntry[0].interruptOnCompletion=1;

                FIS_REG_H2D* cmdFIS = (FIS_REG_H2D*)(&commandTable->commandFIS);
                cmdFIS->fisType = FIS_TYPE::REG_H2D;
                cmdFIS->commandControl = 1; // command
                cmdFIS->command = ATA_CMD_READ_DMA_EX;

                cmdFIS->lba0 = (uint8_t)sectorL;
                cmdFIS->lba1 = (uint8_t)(sectorL >> 8);
                cmdFIS->lba2 = (uint8_t)(sectorL >> 16);
                cmdFIS->lba3 = (uint8_t)sectorH;
                cmdFIS->lba4 = (uint8_t)(sectorH >> 8);
                cmdFIS->lba5 = (uint8_t)(sectorH >> 16);

                cmdFIS->deviceRegister = 1<<6; //LBA mode
                cmdFIS->countLow = sectorCount&0xFF;
                cmdFIS->countHigh = (sectorCount >> 8)&0xFF;
                cmdFIS->command = 1;

                while(!((hbaPort->commandIssue == 0) || (hbaPort->interruptStatus & HBA_PxIS_TFES)));
                if(hbaPort->interruptStatus & HBA_PxIS_TFES)return false;
                return true;
            }
            AHCIDriver::AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress){
                Sauce::IO::Debug::COM1_Console.Write("[AHCIDriver::AHCIDriver]\n\0");
                this->PCIBaseAddress=pciBaseAddress;

                ABAR = (Sauce::IO::AHCI::HBAMemory*)((Sauce::IO::PCIHeader0*)pciBaseAddress)->BAR5;
                Sauce::Memory::GlobalPageTableManager.MapMemory(ABAR,ABAR);
                ProbePorts();
                for(int i=0;i<Ports.Size();i++){
                    Ports[i].Configure();

                    Sauce::IO::Debug::COM1_Console.Write("[Port:\0");
                    Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(i));
                    Sauce::IO::Debug::COM1_Console.Write("]\0");
                    if(Ports[i].Read(0,4)){
                        for(int t=0;t<1024;t++){
                            char out[4]{0};
                            out[0]=(char)Ports[i].buffer[t];
                            Sauce::IO::Debug::COM1_Console.Write(out);
                        }
                        Sauce::IO::Debug::COM1_Console.Write("\n\0");
                    }else{
                        Sauce::IO::Debug::COM1_Console.Write("\t->(Failed to read)\n\0");
                    }

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