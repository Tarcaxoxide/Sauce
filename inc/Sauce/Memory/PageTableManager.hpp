#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        class PageTableManager_cl{
            public:
            PageTableManager_cl(Sauce::IO::Debug::Debugger_st* pDebugger,PageTable* PML4Address);
            PageTable* PML4Address=nullptr;
            void MapMemory(Sauce::IO::Debug::Debugger_st* pDebugger,void* virtualMemory,void* physicalMemory);
        };
        
    };
};