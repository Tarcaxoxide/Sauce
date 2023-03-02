#ifndef __Sauce_Memory_PageTableManager
#define __Sauce_Memory_PageTableManager
#include<Sauce/Memory/Paging.hpp>
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
#endif