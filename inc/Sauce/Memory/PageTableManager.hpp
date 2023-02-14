#include<Sauce/Memory/Paging.hpp>
#pragma once
namespace Sauce{
    namespace Memory{
        namespace Management{
            class PageTableManager_cl{
                public:
                PageTableManager_cl(PageTable* PML4Address);
                PageTable* PML4Address=nullptr;
                void MapMemory(void* virtualMemory,void* physicalMemory);
            };
        };
    };
};