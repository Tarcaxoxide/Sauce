#ifndef __Sauce_IO_PCI
#define __Sauce_IO_PCI
#include<Sauce/Types.hpp>
#include<Sauce/IO/ACPI.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace IO{
		namespace PCI{
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
				uint8_t BIST;// Built In Self Test
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
			struct PCIHeader1_st{
				PCIDeviceHeader_st Header;
				uint32_t BAR0;
				uint32_t BAR1;
				uint8_t PrimaryBusNumber;
				uint8_t SecondaryBusNumber;
				uint8_t SubOrdinateBusNumber;
				uint8_t SecondaryLatencyTimer;
				uint8_t IOBus;
				uint8_t IOLimit;
				uint16_t SecondaryStatus;
				uint16_t MemoryBase;
				uint16_t MemoryLimit;
				uint16_t PrefetchableMemoryBase;
				uint16_t PrefetchableMemoryLimit;
				uint32_t PrefetchableBaseUpper;
				uint32_t PrefetchableLimitUpper;
				uint16_t IOBaseUpper;
				uint16_t IOLimitUpper;
				uint8_t CapabilitiesPtr;
				uint8_t Rsv0;
				uint16_t Rsv1;
				uint32_t ExpansionROMBaseAddr;
				uint8_t InterruptLine;
				uint8_t InterruptPin;
				uint16_t BridgeControl;
			};
			struct PCIHeader2_st{
				PCIDeviceHeader_st Header;
				uint32_t CardBusSocket;
				uint8_t OffsetOfCapabilitiesList;
				uint8_t Reserved;
				uint16_t SecondaryStatus;
				uint8_t PCIBusNumber;
				uint8_t CardBusNumber;
				uint8_t SubOrdinateBusNumber;
				uint8_t CardBusLatencyTimer;
				uint32_t MemoryBaseAddress0;
				uint32_t MemoryLimit0;
				uint32_t MemoryBaseAddress1;
				uint32_t MemoryLimit1;
				uint32_t IOBaseAddress0;
				uint32_t IOLimit0;
				uint32_t IOBaseAddress1;
				uint32_t IOLimit1;
				uint8_t InterruptLine;
				uint8_t InterruptPin;
				uint16_t BridgeControl;
				uint16_t SubsystemDeviceID;
				uint16_t SubsystemVendorID;
				uint32_t PCCardLegacyModeBaseAddress;
			};
			void EnemerateFunction(uint64_t deviceAddress,uint64_t function);
			void EnumerateDevice(uint64_t busAddress,uint64_t device);
			void EnumerateBus(uint64_t baseAddress,uint64_t bus);
			void EnumeratePCI(Sauce::IO::ACPI::MCFGHeader* mcfg);
			extern const char* DeviceClasses[];
			const std::string GetVenderName(uint16_t VendorID);
			const std::string GetDeviceName(uint16_t VendorID,uint16_t DeviceID);
			const std::string GetDeviceClassName(uint8_t ClassCode);
			const std::string GetSubClassName(uint8_t ClassCode,uint8_t SubClassCode);
			const std::string GetProgIFName(uint8_t ClassCode,uint8_t SubClassCode,uint8_t ProgIFCode);
		};
	};
	
};
#endif