#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/DynamicArray.hpp>



namespace Sauce{
    namespace IO{
        namespace AHCI{
            
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
            struct HBACommandHeader{
                uint8_t commandFISLength:5; //5
                uint8_t atapi:1; //6
                uint8_t write:1; //7
                uint8_t prefetchable:1; //8

                uint8_t reset:1; //1
                uint8_t bist:1; //2
                uint8_t clearBusy:1; //3
                uint8_t rsv0:1; //4
                uint8_t portMultiplier:4; //8

                uint16_t prdtLength;
                uint32_t prdbCount;
                uint32_t commandTableBaseAddress;
                uint32_t commandTableBaseAddressUpper;
                uint32_t resv1[4];
            };
            struct Port{
                HBAPort* hbaPort=nullptr;
                PortType portType;
                uint8_t* buffer=nullptr;
                uint8_t portNumber;
                void Configure();
                void StopCMD();
                void StartCMD();
            };
            
            class AHCIDriver{
                Sauce::IO::PCIDeviceHeader* PCIBaseAddress=nullptr;
                HBAMemory* ABAR=nullptr;
                Sauce::Memory::List_cl<Port> Ports;
                //uint8_t portCount; //<- taken care of by my list class
                public:
                    AHCIDriver(Sauce::IO::PCIDeviceHeader* pciBaseAddress);
                    ~AHCIDriver();
                    void ProbePorts();
            };
        };
    };
};