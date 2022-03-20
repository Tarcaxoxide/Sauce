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
        private: //private functions
            void Prep_GlobalAllocator();
            void Prep_VirtualAddresses();
        public: //public variables
            Sauce::Terminal Term;
        public: //public functions
            _Kernel(DataStructure* DFBL);
            void Stop();
    };
};