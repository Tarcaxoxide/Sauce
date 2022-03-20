#pragma once

#include<Sauce/Common.h>
#include<Sauce/Terminal.hpp>
#include<Sauce/Convert.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/Memory/PageTableManager.hpp>

extern uint64_t _KernelStartRef;
extern uint64_t _KernelEndRef;



struct _Kernel{
    Sauce::Terminal Term;
    DataStructure* DFBL;
    Sauce::PageTableManager* pageTableManager;
    Sauce::PageTable* PML4;
    _Kernel(DataStructure* DFBL);
};