#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Common.hpp>
#include<Sauce/IO/Keyboard.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/GDT/GDT.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

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
        private: //private functions
            void Prep_GlobalAllocator(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_VirtualAddresses(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_GDT(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_Interrupts(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_IO(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_ACPI(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Prep_Windows(Sauce::IO::Debug::Debugger_st* pDebugger);
            void Add_Interrupt(Sauce::IO::Debug::Debugger_st* pDebugger,void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector);
            void MainLoop(Sauce::IO::Debug::Debugger_st* pDebugger); // the main loop 
        public: //public variables
        public: //public functions
            Kernel_cl(DataStructure* DFBL);
            static void Notify(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Interrupts::InterruptDataStruct InterruptData);
            void oNotify_Of_KeyPress(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Keyboard_st xKeyboard);
            void oNotify_Of_Mouse(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Mouse_st* xMouse);
            void DrawUI(Sauce::IO::Debug::Debugger_st* pDebugger);
            void AcceptingInterrupts(Sauce::IO::Debug::Debugger_st* pDebugger,size_t TimeSpan);
    };
};