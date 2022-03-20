#include<Sauce/Memory/PageTableManager.hpp>

namespace Sauce{
    namespace Memory{
        void PageTableManager::Initialize(PageTable* PML4Address){
            if(this->PML4Address != NULL)return;
            this->PML4Address=PML4Address;
        }
        void PageTableManager::MapMemory(void* virtualMemory,void* physicalMemory){
            PageMapIndexer indexer = PageMapIndexer((uint64_t)virtualMemory);
            PageDirectoryEntry PDE;
            PDE = PML4Address->entries[indexer.PDP_i];
            PageTable* PDP;
            if(!PDE.GetFlag(PT_Flag::Present)){
                PDP = (PageTable*)GlobalAllocator.RequestPage();
                memset(PDP,0,0x1000);
                PDE.SetAddress((uint64_t)PDP >> 12);
                PDE.SetFlag(PT_Flag::Present,true);
                PDE.SetFlag(PT_Flag::ReadWrite,true);
                PML4Address->entries[indexer.PDP_i] = PDE;
            }else{
                PDP = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
            }
            PDE = PDP->entries[indexer.PD_i];
            PageTable* PD;
            if(!PDE.GetFlag(PT_Flag::Present)){
                PD = (PageTable*)GlobalAllocator.RequestPage();
                memset(PD,0,0x1000);
                PDE.SetAddress((uint64_t)PD >> 12);
                PDE.SetFlag(PT_Flag::Present,true);
                PDE.SetFlag(PT_Flag::ReadWrite,true);
                PDP->entries[indexer.PD_i] = PDE;
            }else{
                PD = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
            }
            PDE = PD->entries[indexer.PT_i];
            PageTable* PT;
            if(!PDE.GetFlag(PT_Flag::Present)){
                PT = (PageTable*)GlobalAllocator.RequestPage();
                memset(PT,0,0x1000);
                PDE.SetAddress((uint64_t)PT >> 12);
                PDE.SetFlag(PT_Flag::Present,true);
                PDE.SetFlag(PT_Flag::ReadWrite,true);
                PD->entries[indexer.PT_i] = PDE;
            }else{
                PT = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
            }
            PDE = PT->entries[indexer.P_i];
            PDE.SetAddress((uint64_t)physicalMemory >> 12);
            PDE.SetFlag(PT_Flag::Present,true);
            PDE.SetFlag(PT_Flag::ReadWrite,true);
            PT->entries[indexer.P_i] = PDE;
        }
    };
};

//comment
/*aa*/ 