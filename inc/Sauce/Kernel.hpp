#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Common.h>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/efiMemory.h>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/GDT/GDT.hpp>
#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Keyboard.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/IO/ACPI/ACPI.hpp>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Shell.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/UserLand/VirtualMachine.hpp>
#include<Sauce/IO/Debug/Serial.hpp>
#include<Sauce/IO/Debug/Console.hpp>

extern uint64_t _KernelStartRef;
extern uint64_t _KernelEndRef;


namespace Sauce{
    class Kernel_cl{
        private: //private variables
            DataStructure* DFBL;
            Sauce::Memory::PageTable* PML4=nullptr;
            uint64_t mMapEntries;
            uint64_t kernelSize;
            uint64_t kernelPages;
            Sauce::GDT::GDTDescriptor_st gdtDescriptor; //global descriptor table
            Sauce::Interrupts::IDTR idtr; // interrupt descriptor table.
            static Kernel_cl* Self; // Pointer to the kernel itself , used in static functions. it kind of acts like python's self.
            Sauce::IO::InputData_st InputData;
        private: //private functions
            void Prep_GlobalAllocator();
            void Prep_VirtualAddresses();
            void Prep_GDT();
            void Prep_Interrupts();
            void Prep_IO();
            void Prep_ACPI();
            void Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector);
            void PreLoop(); // execute before the main loop
            void MainLoop(); // the main loop 
        public: //public variables
            Sauce::Shell::Kshell kShell;
        public: //public functions
            Kernel_cl(DataStructure* DFBL);
            void Stop(bool ClearInterrupts=false);
            //static void Notify_Of_KeyPress(Sauce::IO::Keyboard_st xKeyboard);
            //static void Notify_Of_Mouse();
            static void Notify(Sauce::Interrupts::InterruptDataStruct InterruptData);
            void oNotify_Of_KeyPress(Sauce::IO::Keyboard_st xKeyboard);
            void oNotify_Of_Mouse(Sauce::IO::Mouse_st* xMouse);
    };
};