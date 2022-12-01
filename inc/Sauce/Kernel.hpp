#pragma once

#include<Sauce/InputTypes.hpp>
#include<Sauce/Common.hpp>
#include<Sauce/IO/Keyboard.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/GDT/GDT.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

extern uint64_t* _KernelStartRef;
extern uint64_t* _KernelEndRef;


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
        private: //private functions
            void Prep_GlobalAllocator();
            void Prep_VirtualAddresses();
            void Prep_GDT();
            void Prep_Interrupts();
            void Prep_IO();
            void Prep_ACPI();
            void Prep_Windows();
            void Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector);
            void MainLoop(); // the main loop 
        public: //public variables
        public: //public functions
            Kernel_cl(DataStructure* DFBL);
            static void Notify(Sauce::Interrupts::InterruptDataStruct InterruptData);
            void oNotify_Of_KeyPress(Sauce::Keyboard_st xKeyboard);
            void oNotify_Of_Mouse(Sauce::InputTypes::Mouse_st* xMouse);
            void DrawUI();
            void AcceptingInterrupts(size_t TimeSpan);
    };
};