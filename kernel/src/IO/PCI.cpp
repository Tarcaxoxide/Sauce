#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Network/AM78C973/Driver.hpp>

namespace Sauce{
	namespace IO{
		void EnemerateFunction(uint64_t deviceAddress,uint64_t function){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"EnemerateFunction",_NAMESPACE_,_ALLOW_PRINT_);
			uint64_t offset = function << 12;
			uint64_t functionAddress = deviceAddress + offset;
			Sauce::Global::Memory::PageTableManager.MapMemory((void*)functionAddress,(void*)functionAddress);
			PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)functionAddress;
			if(pciDeviceHeader->DeviceID == 0x0000)return;
			if(pciDeviceHeader->DeviceID == 0xFFFF)return;
			switch(pciDeviceHeader->VendorID){
				case 0x1022:/*AMD*/{
					switch(pciDeviceHeader->DeviceID){
						case 0x2000:/*AM78C973*/{
							Sauce::Global::Network::AM78C973Drivers.AddLast(new Sauce::Network::AM78C973::Driver_cl(pciDeviceHeader));
						}break;
					}
				}break;
				case 0x8086:/*INTEL*/{}break;
			}
			switch(pciDeviceHeader->Class){
				case 0x01:{ // mass storage controller
					switch(pciDeviceHeader->Subclass){
						case 0x06:{ // serial ata
							switch(pciDeviceHeader->ProgIF){
								case 0x01:{ // ahci 1.0 device
									Sauce::Global::Storage::AHCIDrivers.AddLast(new Sauce::Storage::AHCIDriver_cl(pciDeviceHeader));
								}break;
							}
						}break;
					}
				}break;
			}
		}
		void EnumerateDevice(uint64_t busAddress,uint64_t device){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"EnumerateDevice",_NAMESPACE_,_ALLOW_PRINT_);
			uint64_t offset = device << 15;
			uint64_t deviceAddress = busAddress + offset;
			Sauce::Global::Memory::PageTableManager.MapMemory((void*)deviceAddress,(void*)deviceAddress);
			PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)deviceAddress;
			if(pciDeviceHeader->DeviceID == 0x0000)return;
			if(pciDeviceHeader->DeviceID == 0xFFFF)return;
			for(uint64_t function=0;function < 8;function++){
				EnemerateFunction(deviceAddress,function);
			}
		}
		void EnumerateBus(uint64_t baseAddress,uint64_t bus){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"EnumerateBus",_NAMESPACE_,_ALLOW_PRINT_);
			uint64_t offset = bus << 20;
			uint64_t busAddress = baseAddress + offset;
			Sauce::Global::Memory::PageTableManager.MapMemory((void*)busAddress,(void*)busAddress);
			PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)busAddress;
			if(pciDeviceHeader->DeviceID == 0x0000)return;
			if(pciDeviceHeader->DeviceID == 0xFFFF)return;
			for(uint64_t device =0;device < 32;device++){
				EnumerateDevice(busAddress,device);
			}
		}
		void EnumeratePCI(Sauce::IO::ACPI::MCFGHeader* mcfg){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"EnumeratePCI",_NAMESPACE_,_ALLOW_PRINT_);
			int entries = ((mcfg->Header.Length) - sizeof(Sauce::IO::ACPI::MCFGHeader)) / sizeof(Sauce::IO::ACPI::DeviceConfig);
			for(int t=0;t<entries;t++){
				Sauce::IO::ACPI::DeviceConfig *nDeviceConfig = (Sauce::IO::ACPI::DeviceConfig*)((uint64_t)mcfg + sizeof(Sauce::IO::ACPI::MCFGHeader) + (sizeof(Sauce::IO::ACPI::DeviceConfig)*t));
				for(uint64_t Bus = nDeviceConfig->StartBus;Bus<nDeviceConfig->EndBus;Bus++){
					EnumerateBus(nDeviceConfig->BaseAddress,Bus);
				}
			}
		}
		const char* DeviceClasses[]{
			"Unclassified",
			"Mass Storage Controller",
			"Network Controller",
			"Display Controller",
			"Multimedia Controller",
			"Memory Controller",
			"Bridge Device",
			"Simple Communication Controller",
			"Base System Peripheral",
			"Input Device Controller",
			"Docking Station",
			"Processor",
			"Serial Bus Controller",
			"Wireless Controller",
			"Intelligent Controller",
			"Satellite Communication Controller",
			"Encryption Controller",
			"Signal Processing Controller",
			"Processing Accelerator",
			"Non Essential Instrumentation"
		};
		const std::string GetVenderName(uint16_t VendorID){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetVenderName",_NAMESPACE_,_ALLOW_PRINT_);
			switch(VendorID){
				case 0x8086:{return "Intel Corperation";}
				case 0x1022:{return "AMD";}
				case 0x10DE:{return "NVIDIA Corperation";}
				default: {return Sauce::Utility::Conversion::HexToString(VendorID);}
			}
		}
		const std::string GetDeviceName(uint16_t VendorID,uint16_t DeviceID){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetDeviceName",_NAMESPACE_,_ALLOW_PRINT_);
			switch(VendorID){
				case 0x8086:{
					switch(DeviceID){
						case 0x29C0:{return "Express DRAM Controller";}
						case 0x2918:{return "LPC Interface Controller";}
						case 0x2922:{return "6 port SATA Controller [AHCI mode]";}
						case 0x2930:{return "SMBus Controller";}
					}
				}
				case 0x1022:{
					switch(DeviceID){}
				}
				case 0x10DE:{
					switch(DeviceID){}
				}
				default: {return Sauce::Utility::Conversion::HexToString(DeviceID);}
			}
		}
		const std::string GetSubClassName(uint8_t ClassCode,uint8_t SubClassCode){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetSubClassName",_NAMESPACE_,_ALLOW_PRINT_);
			switch(ClassCode){
				case 0x01:{
					switch(SubClassCode){
						case 0x00:{return "SCSI Bus Controller";}
						case 0x01:{return "IDE Controller";}
						case 0x02:{return "Floppy Disk Controller";}
						case 0x03:{return "IPI Bus Controller";}
						case 0x04:{return "RAID Controller";}
						case 0x05:{return "ATA Controller";}
						case 0x06:{return "Serial ATA";}
						case 0x07:{return "Serial Attached SCSI";}
						case 0x08:{return "Non-Volatile Memory Controller";}
						case 0x80:{return "Other";}
					}
				}
				case 0x03:{
					switch (SubClassCode){
						case 0x00:{return "VGA Compatible Controller";}
					}
				}
				case 0x06:{
					switch (SubClassCode){
						case 0x00:{return "Host Bridge";}
						case 0x01:{return "ISA Bridge";}
						case 0x02:{return "EISA Bridge";}
						case 0x03:{return "MCA Bridge";}
						case 0x04:{return "PCI-to-PCI Bridge";}
						case 0x05:{return "PCMCIA Bridge";}
						case 0x06:{return "NuBus Bridge";}
						case 0x07:{return "CardBus Bridge";}
						case 0x08:{return "RACEway Bridge";}
						case 0x09:{return "PCI-to-PCI Bridge";}
						case 0x0a:{return "InfiniBand-to-PCI Host Bridge";}
						case 0x80:{return "Other";}
					}
				}
				case 0x0C:{
					switch (SubClassCode){
						case 0x00:{return "FireWire (IEEE 1394) Controller";}
						case 0x01:{return "ACCESS Bus";}
						case 0x02:{return "SSA";}
						case 0x03:{return "USB Controller";}
						case 0x04:{return "Fibre Channel";}
						case 0x05:{return "SMBus";}
						case 0x06:{return "Infiniband";}
						case 0x07:{return "IPMI Interface";}
						case 0x08:{return "SERCOS Interface (IEC 61491)";}
						case 0x09:{return "CANbus";}
						case 0x80:{return "SerialBusController - Other";}
					}
				}
				default:{return Sauce::Utility::Conversion::HexToString(SubClassCode);}
			}
		}
		const std::string GetProgIFName(uint8_t ClassCode, uint8_t SubClassCode, uint8_t ProgIFCode){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetProgIFName",_NAMESPACE_,_ALLOW_PRINT_);
			switch (ClassCode){
				case 0x01:{
					switch (SubClassCode){
						case 0x06:{
							switch (ProgIFCode){
								case 0x00:{return "Vendor Specific Interface";}
								case 0x01:{return "AHCI 1.0";}
								case 0x02:{return "Serial Storage Bus";}
							}
						}
					}
				}
				case 0x03:{
					switch (SubClassCode){
						case 0x00:{
							switch (ProgIFCode){
								case 0x00:{return "VGA Controller";}
								case 0x01:{return "8514-Compatible Controller";}
							}
						}
					}
				}
				case 0x0C:{
					switch (SubClassCode){
						case 0x03:{
							switch (ProgIFCode){
								case 0x00:{return "UHCI Controller";}
								case 0x10:{return "OHCI Controller";}
								case 0x20:{return "EHCI (USB2) Controller";}
								case 0x30:{return "XHCI (USB3) Controller";}
								case 0x80:{return "Unspecified";}
								case 0xFE:{return "USB Device (Not a Host Controller)";}
							}
						}
					}
				}
				default:{return Sauce::Utility::Conversion::HexToString(SubClassCode);}
			}
		}
	};
};