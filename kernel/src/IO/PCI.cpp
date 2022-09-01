#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Utilities/Conversion.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global/Global.hpp>

namespace Sauce{
    namespace IO{
        void EnemerateFunction(uint64_t deviceAddress,uint64_t function){
            Sauce::IO::Debug::Print_Call("EnemerateFunction",Sauce::IO::Debug::PCI);
            uint64_t offset = function << 12;
            uint64_t functionAddress = deviceAddress + offset;
            Sauce::Global::PageTableManager.MapMemory((void*)functionAddress,(void*)functionAddress);
            PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)functionAddress;
            if(pciDeviceHeader->DeviceID == 0x0000)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;

            switch(pciDeviceHeader->Class){
                case 0x01:{ // mass storage controller
                    switch(pciDeviceHeader->Subclass){
                        case 0x06:{ // serial ata
                            switch(pciDeviceHeader->ProgIF){
                                case 0x01:{ // ahci 1.0 device
                                    Sauce::Global::AHCIDriver = new Sauce::Storage::AHCIDriver_cl(pciDeviceHeader);
                                }break;
                            }
                        }break;
                    }
                }break;
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::PCI);
        }
        void EnumerateDevice(uint64_t busAddress,uint64_t device){
            Sauce::IO::Debug::Print_Call("EnumerateDevice",Sauce::IO::Debug::PCI);
            uint64_t offset = device << 15;
            uint64_t deviceAddress = busAddress + offset;
            Sauce::Global::PageTableManager.MapMemory((void*)deviceAddress,(void*)deviceAddress);
            PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)deviceAddress;
            if(pciDeviceHeader->DeviceID == 0x0000)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;
            for(uint64_t function=0;function < 8;function++){
                EnemerateFunction(deviceAddress,function);
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::PCI);
        }
        void EnumerateBus(uint64_t baseAddress,uint64_t bus){
            Sauce::IO::Debug::Print_Call("EnumerateBus",Sauce::IO::Debug::PCI);
            uint64_t offset = bus << 20;
            uint64_t busAddress = baseAddress + offset;
            Sauce::Global::PageTableManager.MapMemory((void*)busAddress,(void*)busAddress);
            PCIDeviceHeader_st* pciDeviceHeader = (PCIDeviceHeader_st*)busAddress;
            if(pciDeviceHeader->DeviceID == 0x0000)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;
            for(uint64_t device =0;device < 32;device++){
                EnumerateDevice(busAddress,device);
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::PCI);
        }
        void EnumeratePCI(Sauce::IO::ACPI::MCFGHeader* mcfg){
            Sauce::IO::Debug::Print_Call("EnumeratePCI",Sauce::IO::Debug::PCI);
            int entries = ((mcfg->Header.Length) - sizeof(Sauce::IO::ACPI::MCFGHeader)) / sizeof(Sauce::IO::ACPI::DeviceConfig);
            for(int t=0;t<entries;t++){
                Sauce::IO::ACPI::DeviceConfig *nDeviceConfig = (Sauce::IO::ACPI::DeviceConfig*)((uint64_t)mcfg + sizeof(Sauce::IO::ACPI::MCFGHeader) + (sizeof(Sauce::IO::ACPI::DeviceConfig)*t));
                for(uint64_t Bus = nDeviceConfig->StartBus;Bus<nDeviceConfig->EndBus;Bus++){
                    EnumerateBus(nDeviceConfig->BaseAddress,Bus);
                }
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::PCI);
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
        const char* GetVenderName(uint16_t VendorID){
            Sauce::IO::Debug::Print_Call("GetVenderName",Sauce::IO::Debug::PCI);
            switch(VendorID){
                case 0x8086:{Sauce::IO::Debug::Print_Return("Intel Corperation",Sauce::IO::Debug::PCI);return "Intel Corperation";}
                case 0x1022:{Sauce::IO::Debug::Print_Return("AMD",Sauce::IO::Debug::PCI);return "AMD";}
                case 0x10DE:{Sauce::IO::Debug::Print_Return("NVIDIA Corperation",Sauce::IO::Debug::PCI);return "NVIDIA Corperation";}
                default: {Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString(VendorID),Sauce::IO::Debug::PCI);return (const char*)Sauce::Convert::HexToString(VendorID);}
            }
            
        }
        const char* GetDeviceName(uint16_t VendorID,uint16_t DeviceID){
            Sauce::IO::Debug::Print_Call("GetDeviceName",Sauce::IO::Debug::PCI);
            switch(VendorID){
                case 0x8086:{
                    switch(DeviceID){
                        case 0x29C0:{Sauce::IO::Debug::Print_Return("Express DRAM Controller",Sauce::IO::Debug::PCI);return "Express DRAM Controller";}
                        case 0x2918:{Sauce::IO::Debug::Print_Return("LPC Interface Controller",Sauce::IO::Debug::PCI);return "LPC Interface Controller";}
                        case 0x2922:{Sauce::IO::Debug::Print_Return("6 port SATA Controller [AHCI mode]",Sauce::IO::Debug::PCI);return "6 port SATA Controller [AHCI mode]";}
                        case 0x2930:{Sauce::IO::Debug::Print_Return("SMBus Controller",Sauce::IO::Debug::PCI);return "SMBus Controller";}
                    }
                }
                case 0x1022:{
                    switch(DeviceID){}
                }
                case 0x10DE:{
                    switch(DeviceID){}
                }
                default: {Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString(DeviceID),Sauce::IO::Debug::PCI);return (const char*)Sauce::Convert::HexToString(DeviceID);}
            }
        }
        const char* GetSubClassName(uint8_t ClassCode,uint8_t SubClassCode){
            Sauce::IO::Debug::Print_Call("GetSubClassName",Sauce::IO::Debug::PCI);
            switch(ClassCode){
                case 0x01:{
                    switch(SubClassCode){
                        case 0x00:{Sauce::IO::Debug::Print_Return("SCSI Bus Controller",Sauce::IO::Debug::PCI);return "SCSI Bus Controller";}
                        case 0x01:{Sauce::IO::Debug::Print_Return("IDE Controller",Sauce::IO::Debug::PCI);return "IDE Controller";}
                        case 0x02:{Sauce::IO::Debug::Print_Return("Floppy Disk Controller",Sauce::IO::Debug::PCI);return "Floppy Disk Controller";}
                        case 0x03:{Sauce::IO::Debug::Print_Return("IPI Bus Controller",Sauce::IO::Debug::PCI);return "IPI Bus Controller";}
                        case 0x04:{Sauce::IO::Debug::Print_Return("RAID Controller",Sauce::IO::Debug::PCI);return "RAID Controller";}
                        case 0x05:{Sauce::IO::Debug::Print_Return("ATA Controller",Sauce::IO::Debug::PCI);return "ATA Controller";}
                        case 0x06:{Sauce::IO::Debug::Print_Return("Serial ATA",Sauce::IO::Debug::PCI);return "Serial ATA";}
                        case 0x07:{Sauce::IO::Debug::Print_Return("Serial Attached SCSI",Sauce::IO::Debug::PCI);return "Serial Attached SCSI";}
                        case 0x08:{Sauce::IO::Debug::Print_Return("Non-Volatile Memory Controller",Sauce::IO::Debug::PCI);return "Non-Volatile Memory Controller";}
                        case 0x80:{Sauce::IO::Debug::Print_Return("Other",Sauce::IO::Debug::PCI);return "Other";}
                    }
                }
                case 0x03:{
                    switch (SubClassCode){
                        case 0x00:{Sauce::IO::Debug::Print_Return("VGA Compatible Controller",Sauce::IO::Debug::PCI);return "VGA Compatible Controller";}
                    }
                }
                case 0x06:{
                    switch (SubClassCode){
                        case 0x00:{Sauce::IO::Debug::Print_Return("Host Bridge",Sauce::IO::Debug::PCI);return "Host Bridge";}
                        case 0x01:{Sauce::IO::Debug::Print_Return("ISA Bridge",Sauce::IO::Debug::PCI);return "ISA Bridge";}
                        case 0x02:{Sauce::IO::Debug::Print_Return("EISA Bridge",Sauce::IO::Debug::PCI);return "EISA Bridge";}
                        case 0x03:{Sauce::IO::Debug::Print_Return("MCA Bridge",Sauce::IO::Debug::PCI);return "MCA Bridge";}
                        case 0x04:{Sauce::IO::Debug::Print_Return("PCI-to-PCI Bridge",Sauce::IO::Debug::PCI);return "PCI-to-PCI Bridge";}
                        case 0x05:{Sauce::IO::Debug::Print_Return("PCMCIA Bridge",Sauce::IO::Debug::PCI);return "PCMCIA Bridge";}
                        case 0x06:{Sauce::IO::Debug::Print_Return("NuBus Bridge",Sauce::IO::Debug::PCI);return "NuBus Bridge";}
                        case 0x07:{Sauce::IO::Debug::Print_Return("CardBus Bridge",Sauce::IO::Debug::PCI);return "CardBus Bridge";}
                        case 0x08:{Sauce::IO::Debug::Print_Return("RACEway Bridge",Sauce::IO::Debug::PCI);return "RACEway Bridge";}
                        case 0x09:{Sauce::IO::Debug::Print_Return("PCI-to-PCI Bridge",Sauce::IO::Debug::PCI);return "PCI-to-PCI Bridge";}
                        case 0x0a:{Sauce::IO::Debug::Print_Return("InfiniBand-to-PCI Host Bridge",Sauce::IO::Debug::PCI);return "InfiniBand-to-PCI Host Bridge";}
                        case 0x80:{Sauce::IO::Debug::Print_Return("Other",Sauce::IO::Debug::PCI);return "Other";}
                    }
                }
                case 0x0C:{
                    switch (SubClassCode){
                        case 0x00:{Sauce::IO::Debug::Print_Return("FireWire (IEEE 1394) Controller",Sauce::IO::Debug::PCI);return "FireWire (IEEE 1394) Controller";}
                        case 0x01:{Sauce::IO::Debug::Print_Return("ACCESS Bus",Sauce::IO::Debug::PCI);return "ACCESS Bus";}
                        case 0x02:{Sauce::IO::Debug::Print_Return("SSA",Sauce::IO::Debug::PCI);return "SSA";}
                        case 0x03:{Sauce::IO::Debug::Print_Return("USB Controller",Sauce::IO::Debug::PCI);return "USB Controller";}
                        case 0x04:{Sauce::IO::Debug::Print_Return("Fibre Channel",Sauce::IO::Debug::PCI);return "Fibre Channel";}
                        case 0x05:{Sauce::IO::Debug::Print_Return("SMBus",Sauce::IO::Debug::PCI);return "SMBus";}
                        case 0x06:{Sauce::IO::Debug::Print_Return("Infiniband",Sauce::IO::Debug::PCI);return "Infiniband";}
                        case 0x07:{Sauce::IO::Debug::Print_Return("IPMI Interface",Sauce::IO::Debug::PCI);return "IPMI Interface";}
                        case 0x08:{Sauce::IO::Debug::Print_Return("SERCOS Interface (IEC 61491)",Sauce::IO::Debug::PCI);return "SERCOS Interface (IEC 61491)";}
                        case 0x09:{Sauce::IO::Debug::Print_Return("CANbus",Sauce::IO::Debug::PCI);return "CANbus";}
                        case 0x80:{Sauce::IO::Debug::Print_Return("SerialBusController - Other",Sauce::IO::Debug::PCI);return "SerialBusController - Other";}
                    }
                }
                default:{Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString(SubClassCode),Sauce::IO::Debug::PCI);return (const char*)Sauce::Convert::HexToString(SubClassCode);}
            }
        }
        const char* GetProgIFName(uint8_t ClassCode, uint8_t SubClassCode, uint8_t ProgIFCode){
            Sauce::IO::Debug::Print_Call("GetProgIFName",Sauce::IO::Debug::PCI);
            switch (ClassCode){
                case 0x01:{
                    switch (SubClassCode){
                        case 0x06:{
                            switch (ProgIFCode){
                                case 0x00:{Sauce::IO::Debug::Print_Return("Vendor Specific Interface",Sauce::IO::Debug::PCI);return "Vendor Specific Interface";}
                                case 0x01:{Sauce::IO::Debug::Print_Return("AHCI 1.0",Sauce::IO::Debug::PCI);return "AHCI 1.0";}
                                case 0x02:{Sauce::IO::Debug::Print_Return("Serial Storage Bus",Sauce::IO::Debug::PCI);return "Serial Storage Bus";}
                            }
                        }
                    }
                }
                case 0x03:{
                    switch (SubClassCode){
                        case 0x00:{
                            switch (ProgIFCode){
                                case 0x00:{Sauce::IO::Debug::Print_Return("VGA Controller",Sauce::IO::Debug::PCI);return "VGA Controller";}
                                case 0x01:{Sauce::IO::Debug::Print_Return("8514-Compatible Controller",Sauce::IO::Debug::PCI);return "8514-Compatible Controller";}
                            }
                        }
                    }
                }
                case 0x0C:{
                    switch (SubClassCode){
                        case 0x03:{
                            switch (ProgIFCode){
                                case 0x00:{Sauce::IO::Debug::Print_Return("UHCI Controller",Sauce::IO::Debug::PCI);return "UHCI Controller";}
                                case 0x10:{Sauce::IO::Debug::Print_Return("OHCI Controller",Sauce::IO::Debug::PCI);return "OHCI Controller";}
                                case 0x20:{Sauce::IO::Debug::Print_Return("EHCI (USB2) Controller",Sauce::IO::Debug::PCI);return "EHCI (USB2) Controller";}
                                case 0x30:{Sauce::IO::Debug::Print_Return("XHCI (USB3) Controller",Sauce::IO::Debug::PCI);return "XHCI (USB3) Controller";}
                                case 0x80:{Sauce::IO::Debug::Print_Return("Unspecified",Sauce::IO::Debug::PCI);return "Unspecified";}
                                case 0xFE:{Sauce::IO::Debug::Print_Return("USB Device (Not a Host Controller)",Sauce::IO::Debug::PCI);return "USB Device (Not a Host Controller)";}
                            }
                        }
                    }
                }
                default:{Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString(SubClassCode),Sauce::IO::Debug::PCI);return (const char*)Sauce::Convert::HexToString(SubClassCode);}
            }
        }
    };
};