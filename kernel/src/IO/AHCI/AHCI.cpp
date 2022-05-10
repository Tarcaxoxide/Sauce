#include<Sauce/IO/AHCI/AHCI.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Memory/PageTableManager.hpp>

namespace Sauce{
    namespace IO{
        namespace AHCI{
            PortType CheckPortType(HBAPort* port){
                uint32_t sataStatus = port->sataStatus;
                uint8_t interfacePowerManagement = (sataStatus >> 8) & 0b111;
                uint8_t deviceDetection = sataStatus & 0b111;

                if(deviceDetection != HBA_PORT_DEV_PRESENT)return PortType::None;
                
            }
            AHCIDriver::AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress){
                this->PCIBaseAddress=pciBaseAddress;
                Sauce::IO::GlobalTerminal->PutString("AHCI Driver instance Initialized.\n\r");

                ABAR = (HBAMemory*)((Sauce::IO::PCIHeader0*)pciBaseAddress)->BAR5;
                Sauce::Memory::GlobalPageTableManager.MapMemory(ABAR,ABAR);
            }
            AHCIDriver::~AHCIDriver(){}
            void AHCIDriver::ProbePorts(){
                uint32_t portsImplemented ABAR->portsImplemented;
                for(int i=0;i<32;i++){
                    if(portsImplemented & (1 << i)){

                    }
                }
            }
        };
    };
};