#include<Sauce/IO/AHCI/AHCI.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Kernel.hpp>

namespace Sauce{
    namespace IO{
        namespace AHCI{
            #define HBA_PORT_DEV_PRESENT 0x3
            #define HBA_PORT_IPM_ACTIVE 0x1
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
            AHCIDriver::AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress){
                Kernel_cl::Debug("[AHCIDriver::AHCIDriver]\n\0");
                this->PCIBaseAddress=pciBaseAddress;

                ABAR = (Sauce::IO::AHCI::HBAMemory*)((Sauce::IO::PCIHeader0*)pciBaseAddress)->BAR5;
                Sauce::Memory::GlobalPageTableManager.MapMemory(ABAR,ABAR);
                ProbePorts();
            }
            AHCIDriver::~AHCIDriver(){
                Kernel_cl::Debug("[AHCIDriver::~AHCIDriver]\n\0");
            }
            void AHCIDriver::ProbePorts(){
                Kernel_cl::Debug("[AHCIDriver::ProbePorts]\n\0");
                uint32_t portsImplemented = ABAR->portsImplemented;
                for(int i=0;i<32;i++){
                    if(portsImplemented & (1 << i)){
                        PortType portType = CheckPortType(&ABAR->ports[i]);
                        switch(portType){
                            case PortType::SATA:{
                                Kernel_cl::Debug("\t->(SATA)\n\0");
                            }break;
                            case PortType::SEMB:{
                                Kernel_cl::Debug("\t->(SEMB)\n\0");
                            }break;
                            case PortType::PM:{
                                Kernel_cl::Debug("\t->(PM)\n\0");
                            }break;
                            case PortType::SATAPI:{
                                Kernel_cl::Debug("\t->(SATAPI)\n\0");
                            }break;
                            default:{
                                Kernel_cl::Debug("\t->(Other/Unknown)\n\0");
                            }break;
                        }
                    }
                }
            }
        };
    };
};