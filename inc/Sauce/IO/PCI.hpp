#pragma once


#include<Sauce/Types.hpp>
#include<Sauce/IO/ACPI.hpp>


namespace Sauce{
    namespace IO{
        struct PCIDeviceHeader_st{
            uint16_t VendorID;
            uint16_t DeviceID;
            uint16_t Command;
            uint16_t Status;
            uint8_t RevisionID;
            uint8_t ProgIF;//IF InterFace
            uint8_t Subclass;
            uint8_t Class;
            uint8_t CacheLineSize;
            uint8_t LatencyTimer;
            uint8_t HeaderType;
            uint8_t BIST;
        };
        struct PCIHeader0_st{
            PCIDeviceHeader_st Header;
            uint32_t BAR0;
            uint32_t BAR1;
            uint32_t BAR2;
            uint32_t BAR3;
            uint32_t BAR4;
            uint32_t BAR5;
            uint32_t CardbusCISPtr;
            uint16_t SubsystemVendorID;
            uint16_t SubsystemID;
            uint32_t ExpansionROMBaseAddr;
            uint8_t  CapabilitiesPtr;
            uint8_t Rsv0;
            uint16_t Rsv1;
            uint32_t Rsv2;
            uint8_t InterruptLine;
            uint8_t InterruptPin;
            uint8_t MinGrant;
            uint8_t MaxLatency;
        };
        void EnemerateFunction(uint64_t deviceAddress,uint64_t function);
        void EnumerateDevice(uint64_t busAddress,uint64_t device);
        void EnumerateBus(uint64_t baseAddress,uint64_t bus);
        void EnumeratePCI(Sauce::IO::ACPI::MCFGHeader* mcfg);
        extern const char* DeviceClasses[];
        const char* GetVenderName(uint16_t VendorID);
        const char* GetDeviceName(uint16_t VendorID,uint16_t DeviceID);
        const char* GetSubClassName(uint8_t ClassCode,uint8_t SubClassCode);
        const char* GetProgIFName(uint8_t ClassCode,uint8_t SubClassCode,uint8_t ProgIFCode);
    };
};