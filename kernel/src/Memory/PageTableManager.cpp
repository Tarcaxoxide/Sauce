#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        PageTableManager_cl::PageTableManager_cl(PageTable* PML4Address){
            Sauce::IO::Debug::Print_Spammy_Call("PageTableManager_cl::PageTableManager_cl",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
            if(this->PML4Address != NULL)return;
            this->PML4Address=PML4Address;
            Sauce::IO::Debug::Print_Spammy_Return("this",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
        }
        void PageTableManager_cl::MapMemory(void* virtualMemory,void* physicalMemory){
            Sauce::IO::Debug::Print_Spammy_Call("PageTableManager_cl::MapMemory",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
            Sauce::IO::Debug::Print_Spammy_Detail(Sauce::Convert::HexToString((uint64_t)virtualMemory),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
            Sauce::IO::Debug::Print_Spammy_Detail(Sauce::Convert::HexToString((uint64_t)physicalMemory),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
            
            PageMapIndexer indexer = PageMapIndexer((uint64_t)virtualMemory);
            PageDirectoryEntry PDE;
            PDE = PML4Address->entries[indexer.PDP_i];
            PageTable* PDP;
            if(!PDE.GetFlag(PT_Flag::Present)){
                PDP = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage();
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
                PD = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage();
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
                PT = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage();
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
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::TableManager);
        }
    };
};
