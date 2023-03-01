#ifndef __Sauce_Storage_AHCI
#define __Sauce_Storage_AHCI
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
namespace Sauce{
    namespace Storage{
        #define HBA_PORT_DEVICE_PRESENT 0x3
        #define HBA_PORT_IPM_ACTIVE 0x1
        #define SATA_SIG_ATAPI 0xEB140101
        #define SATA_SIG_ATA 0x00000101
        #define SATA_SIG_SEMB 0xC33C0101
        #define SATA_SIG_PM 0x96690101
        #define HBA_PxCMD_CR 0x8000
        #define HBA_PxCMD_FRE 0x0010
        #define HBA_PxCMD_FR 0x4000
        #define HBA_PxCMD_ST 0x0001
        #define HBA_PxIS_TFES (1 << 30)
        #define FIS_TYPE_REG_H2D 0x27
        #define FIS_TYPE_REG_D2H 0x34
        #define FIS_TYPE_DMA_ACT 0x39
        #define FIS_TYPE_DMA_ 0x41
        #define FIS_TYPE_DATA 0x46
        #define FIS_TYPE_BIST 0x58
        #define FIS_TYPE_PIO_SETUP 0x5F
        #define FIS_TYPE_DEV_BITS 0xA1
        #define ATA_CMD_READ_DMA_EX 0x25
        #define ATA_DEV_BUSY 0x80
        #define ATA_DEV_DRQ 0x08
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
        struct HBAPRDTEntry_st{
            uint32_t dataBaseAddress;
            uint32_t dataBaseAddressUpper;
            uint32_t rsv0;
            uint32_t byteCount:22;
            uint32_t rsv1:9;
            uint32_t interruptOnCompletion:1;
        };
        struct HBACommandTable_st{
            uint8_t commandFIS[64];
            uint8_t atapiCommand[16];
            uint8_t rsv[48];
            HBAPRDTEntry_st prdtEntry[];
        };
        struct FIS_REG_H2D_st{
            uint8_t fisType;
            uint8_t portMultiplier:4;
            uint8_t rsv0:3;
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
            uint8_t rsv1[4];
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
            bool Read(uint64_t sector,uint16_t sectorCount,void* buffer);
        };
        ParsedHBAPort_st CheckPortType(HBAPort_st* port);
        class AHCIDriver_cl{
            Sauce::IO::PCIDeviceHeader_st* pciBaseAddress;
            HBAMemory_st* ABAR;
            Sauce::Memory::List_cl<ParsedHBAPort_st> HBAPorts;
            public:
                size_t sector_size{512};
            public:
                AHCIDriver_cl(Sauce::IO::PCIDeviceHeader_st* pciBaseAddress);
                ~AHCIDriver_cl();
                void ProbePorts();
                std::string ListPorts();
                void Read(size_t portNumber,size_t startingSector,size_t sectorCount,Sauce::Memory::List_cl<uint8_t> &Bufferr);
                uint8_t Read(size_t portNumber,size_t ByteToRead);
        };
    };
};
#endif