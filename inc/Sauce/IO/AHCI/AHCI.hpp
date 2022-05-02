#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/PCI.hpp>




namespace Sauce{
    namespace IO{
        namespace AHCI{
            class AHCIDriver{
                Sauce::IO::PCIDeviceHeader* PCIBaseAddress;
                public:
                    AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress);
                    ~AHCIDriver();
            };
        };
    };
};