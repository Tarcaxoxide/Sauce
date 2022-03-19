#pragma once

#include<stddef.h>
#include<stdint.h>
#include <cstring>

#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>

namespace Sauce{
    class PageTableManager{
        public:
        PageTableManager(PageTable* PML4Address);
        PageTable* PML4Address;
        void MapMemory(void* virtualMemory,void* physicalMemory);
    };
};