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
#include<Sauce/Math.hpp>

extern uint64_t _KernelStartRef;
extern uint64_t _KernelEndRef;


namespace Sauce{
    class _Kernel{
        private: //private variables
            DataStructure* DFBL;
            Sauce::Memory::PageTableManager pageTableManager;
            Sauce::Memory::PageTable* PML4;
            uint64_t mMapEntries;
            uint64_t kernelSize;
            uint64_t kernelPages;
            uint64_t fbBase;
            uint64_t fbSize;
            Sauce::GDT::GDTDescriptor_t gdtDescriptor;
            Sauce::Interrupts::IDTR idtr;
            static _Kernel* Self;
        private: //private functions
            void Prep_GlobalAllocator();
            void Prep_VirtualAddresses();
            void Prep_GDT();
            void Prep_Interrupts();
            void Prep_IO();
            void Prep_ACPI();
            void Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector);
        public: //public variables
            Sauce::IO::Terminal Term;
        public: //public functions
            _Kernel(DataStructure* DFBL);
            void Stop(bool ClearInterrupts=false);
            static void Notify_Of_KeyPress(Sauce::IO::KeyboardKey Xkey);
            static void Notify_Of_Mouse(Sauce::IO::MouseData Xmouse);
    };
};