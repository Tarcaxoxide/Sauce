#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/PCI.hpp>




namespace Sauce{
    namespace IO{
        namespace AHCI{
            static const uint8_t HBA_PORT_DEV_PRESENT=0x3;
            
            enum PortType{
                None = 0,
                SATA,
                SEMB,
                PM,
                SATAPI
            };
            struct HBAPort{
                uint32_t commandListBase;
                uint32_t commandListBaseUpper;
                uint32_t fisBaseAddress;
                uint32_t fisBaseAddressUpper;
                uint32_t interruptStatus;
                uint32_t interruptEnable;
                uint32_t cmdStatus;
                uint32_t rsv0;
                uint32_t taskFileData;
                uint32_t signature;
                uint32_t sataStatus;
                uint32_t sataControl;
                uint32_t sataError;
                uint32_t sataActive;
                uint32_t commandIssue;
                uint32_t sataNotification;
                uint32_t fisSwitchControl;
                uint32_t rsv1[11];
                uint32_t vendor[4];
            };
            struct HBAMemory{
                uint32_t hostCapability;
                uint32_t globalHostControl;
                uint32_t interruptStatus;
                uint32_t portsImplemented;
                uint32_t version;
                uint32_t cccControl;
                uint32_t cccPorts;
                uint32_t enclosureManagementLocation;
                uint32_t enclosureManagementControl;
                uint32_t hostCapabilitiesExtended;
                uint32_t biosHandoffCtrlStatus;
                uint8_t resv0[0x74];
                uint8_t vendor[0x60];
                HBAPort ports[1];
            };
            PortType CheckPortType(HBAPort* port);
            class AHCIDriver{
                Sauce::IO::PCIDeviceHeader* PCIBaseAddress=nullptr;
                HBAMemory* ABAR=nullptr;
                public:
                    AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress);
                    ~AHCIDriver();
                    void ProbePorts();
            };
        };
    };
};