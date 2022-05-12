#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/DynamicArray.hpp>



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
            #define ATA_CMD_READ_DMA_EX 0x25
            #define ATA_DEV_BUSY 0x80
            #define ATA_DEV_DRQ 0x08
            #define HBA_PxIS_TFES (1<<30)
            enum PortType{
                None = 0,
                SATA,
                SEMB,
                PM,
                SATAPI
            };
            enum FIS_TYPE{
                REG_H2D = 0x27,
                REG_D2H = 0x34,
                DMA_ACT = 0x39,
                DMA_SETUP = 0x41,
                DATA = 0x46,
                BIST = 0x58,
                PIO_SETUP = 0x5F,
                DEV_BITS = 0xA1
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
            struct HBAPRDTEntry{
                uint32_t dataBaseAddress;
                uint32_t dataBaseAddressUpper;
                uint32_t resv0;

                uint32_t byteCount:22; //22
                uint32_t resv1:9; //31
                uint32_t interruptOnCompletion:1; //32
            };
            struct HBACommandTable{
                uint8_t commandFIS[64];
                uint8_t atapiCommand[16];
                uint8_t resv[48];
                HBAPRDTEntry prdtEntry[];
            };
            struct FIS_REG_H2D{
                uint8_t fisType;

                uint8_t portMultiplier:4;
                uint8_t resv0:3;
                uint8_t commandControl:1;

                uint8_t command;
                uint8_t featureLow;

                uint8_t lba0;
                uint8_t lba1;
                uint8_t lba2;
                uint8_t deviceRegister;

                uint8_t lba3;
                uint8_t lba4;
                uint8_t lba5;
                uint8_t featureHigh;

                uint8_t countLow;
                uint8_t countHigh;
                uint8_t isoCommandCompletion;
                uint8_t control;

                uint8_t resv1[4];
            };
            struct Port{
                HBAPort* hbaPort=nullptr;
                PortType portType;
                uint8_t* buffer=nullptr;
                uint8_t portNumber;
                void Configure();
                void StopCMD();
                void StartCMD();
                bool Read(uint64_t sector,uint32_t sectorCount);
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