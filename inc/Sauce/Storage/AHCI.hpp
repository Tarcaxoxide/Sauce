#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Storage{
        enum HBAPortType{
            NONE=0,
            SATA,
            SEMB,
            PM,
            SATAPI
        };
        struct HBAPort_st{
            uint32_t commandListBase;
            uint32_t commandListBaseUpper;
            uint32_t fisBaseAddress;
            uint32_t fisBaseAddressUpper;
            uint32_t interruptStatus;
            uint32_t interruptEnable;
            uint32_t cmdSts;
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

        struct HBACommandHeader_st{
            uint8_t commandFISLength:5;
            uint8_t atapi:1;
            uint8_t write:1;
            uint8_t prefetchable:1;

            uint8_t reset:1;
            uint8_t bist:1;
            uint8_t clearBusy:1;
            uint8_t rsv0:1;
            uint8_t portMultiplier:4;

            uint16_t prdtLength;
            uint32_t prdbCount;
            uint32_t commandTableBaseAddress;
            uint32_t commandTableBaseAddressUpper;
            uint32_t rsv1[4];
        };

        struct HBAMemory_st{
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
            uint32_t biosHandoffCtrlSts;
            uint8_t rsv0[0x74];
            uint8_t vendor[0x60];
            HBAPort_st ports[1];
        };

        struct ParsedHBAPort_st{
            HBAPort_st* Address=nullptr;
            uint8_t* buffer=nullptr;
            HBAPortType Type;
            uint32_t SataStatus;
            uint8_t InterfacePowerManagement;
            uint8_t DeviceDetection;
            void Configure();
            void StartCMD();
            void StopCMD();
        };

        ParsedHBAPort_st CheckPortType(HBAPort_st* port);

        class AHCIDriver_cl{
            Sauce::IO::PCIDeviceHeader_st* pciBaseAddress;
            HBAMemory_st* ABAR;
            Sauce::Memory::List_cl<ParsedHBAPort_st> HBAPorts;
            public:
                AHCIDriver_cl(Sauce::IO::PCIDeviceHeader_st* pciBaseAddress);
                ~AHCIDriver_cl();
                void ProbePorts();
        };
    };
};