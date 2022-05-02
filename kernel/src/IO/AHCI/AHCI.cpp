#include<Sauce/IO/AHCI/AHCI.hpp>
#include<Sauce/IO/Terminal.hpp>

namespace Sauce{
    namespace IO{
        namespace AHCI{
            AHCIDriver::AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress){
                this->PCIBaseAddress=pciBaseAddress;
                Sauce::IO::GlobalTerminal->PutString("AHCI Driver instance Initialized.\n\r");
            }
            AHCIDriver::~AHCIDriver(){}
        };
    };
};