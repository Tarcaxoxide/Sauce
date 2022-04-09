#include<Sauce/IO/PCI.hpp>

namespace Sauce{
    namespace IO{
        void EnemerateFunction(uint64_t deviceAddress,uint64_t function){
            uint64_t offset = function << 12;
            uint64_t functionAddress = deviceAddress + offset;
            Sauce::Memory::GlobalPageTableManager.MapMemory((void*)functionAddress,(void*)functionAddress);
            PCIDeviceHeader* pciDeviceHeader = (PCIDeviceHeader*)functionAddress;
            if(pciDeviceHeader->DeviceID == NULL)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;

            Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString(pciDeviceHeader->VendorID));
            Sauce::IO::GlobalTerminal->PutString(" ");
            Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString(pciDeviceHeader->DeviceID));
            Sauce::IO::GlobalTerminal->PutString("\n\r");
        }
        void EnumerateDevice(uint64_t busAddress,uint64_t device){
            uint64_t offset = device << 15;
            uint64_t deviceAddress = busAddress + offset;
            Sauce::Memory::GlobalPageTableManager.MapMemory((void*)deviceAddress,(void*)deviceAddress);
            PCIDeviceHeader* pciDeviceHeader = (PCIDeviceHeader*)deviceAddress;
            if(pciDeviceHeader->DeviceID == NULL)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;
            for(uint64_t function =0;device < 8;device++){
                EnemerateFunction(deviceAddress,function);
            }
        }
        void EnumerateBus(uint64_t baseAddress,uint64_t bus){
            uint64_t offset = bus << 20;
            uint64_t busAddress = baseAddress + offset;
            Sauce::Memory::GlobalPageTableManager.MapMemory((void*)busAddress,(void*)busAddress);
            PCIDeviceHeader* pciDeviceHeader = (PCIDeviceHeader*)busAddress;
            if(pciDeviceHeader->DeviceID == NULL)return;
            if(pciDeviceHeader->DeviceID == 0xFFFF)return;
            for(uint64_t device =0;device < 32;device++){
                EnumerateDevice(busAddress,device);
            }
        }
        void EnumeratePCI(Sauce::IO::ACPI::MCFGHeader* mcfg){
            int entries = ((mcfg->Header.Length) - sizeof(Sauce::IO::ACPI::MCFGHeader)) / sizeof(Sauce::IO::ACPI::DeviceConfig);
            for(int i=0;i<entries;i++){
                Sauce::IO::ACPI::DeviceConfig *nDeviceConfig = (Sauce::IO::ACPI::DeviceConfig*)((uint64_t)mcfg + sizeof(Sauce::IO::ACPI::MCFGHeader)+sizeof(Sauce::IO::ACPI::DeviceConfig)*i);
                for(uint64_t Bus = nDeviceConfig->StartBus;Bus<nDeviceConfig->EndBus;Bus++){
                    EnumerateBus(nDeviceConfig->BaseAddress,Bus);
                }
            }
        }
    };
};