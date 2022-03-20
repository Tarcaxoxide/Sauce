#pragma once

#include<Sauce/Common.h>
#include<Sauce/Terminal.hpp>
#include<Sauce/Convert.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/GDT/GDT.hpp>
#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Panic.hpp>

extern uint64_t _KernelStartRef;
extern uint64_t _KernelEndRef;


namespace Sauce{
    class _Kernel{
        private: //private variables
            DataStructure* DFBL;
            Sauce::PageTableManager pageTableManager;
            Sauce::PageTable* PML4;
            uint64_t mMapEntries;
            uint64_t kernelSize;
            uint64_t kernelPages;
            uint64_t fbBase;
            uint64_t fbSize;
            GDTDescriptor gdtDescriptor;
            IDTR idtr;
        private: //private functions
            void Prep_GlobalAllocator();
            void Prep_VirtualAddresses();
            void Prep_GDT();
            void Prep_Interrupts();
        public: //public variables
            Sauce::Terminal Term;
            bool Debug=true;
        public: //public functions
            _Kernel(DataStructure* DFBL);
            void Stop();
    };
};