#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        PageTableManager_cl::PageTableManager_cl(Sauce::IO::Debug::Debugger_st* pDebugger,PageTable* PML4Address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageTableManager_cl::PageTableManager_cl");
            if(this->PML4Address != NULL)return;
            this->PML4Address=PML4Address;
        }
        void PageTableManager_cl::MapMemory(Sauce::IO::Debug::Debugger_st* pDebugger,void* virtualMemory,void* physicalMemory){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageTableManager_cl::MapMemory");
            PageMapIndexer indexer = PageMapIndexer(&Debugger,(uint64_t)virtualMemory);
            PageDirectoryEntry PDE;
            PDE = PML4Address->entries[indexer.PDP_i];
            PageTable* PDP;
            if(!PDE.GetFlag(&Debugger,PT_Flag::Present)){
                PDP = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage(&Debugger);
                memset(&Debugger,PDP,0,0x1000);
                PDE.SetAddress(&Debugger,(uint64_t)PDP >> 12);
                PDE.SetFlag(&Debugger,PT_Flag::Present,true);
                PDE.SetFlag(&Debugger,PT_Flag::ReadWrite,true);
                PML4Address->entries[indexer.PDP_i] = PDE;
            }else{
                PDP = (PageTable*)((uint64_t)PDE.GetAddress(&Debugger) << 12);
            }
            PDE = PDP->entries[indexer.PD_i];
            PageTable* PD;
            if(!PDE.GetFlag(&Debugger,PT_Flag::Present)){
                PD = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage(&Debugger);
                memset(&Debugger,PD,0,0x1000);
                PDE.SetAddress(&Debugger,(uint64_t)PD >> 12);
                PDE.SetFlag(&Debugger,PT_Flag::Present,true);
                PDE.SetFlag(&Debugger,PT_Flag::ReadWrite,true);
                PDP->entries[indexer.PD_i] = PDE;
            }else{
                PD = (PageTable*)((uint64_t)PDE.GetAddress(&Debugger) << 12);
            }
            PDE = PD->entries[indexer.PT_i];
            PageTable* PT;
            if(!PDE.GetFlag(&Debugger,PT_Flag::Present)){
                PT = (PageTable*)Sauce::Global::PageFrameAllocator.RequestPage(&Debugger);
                memset(&Debugger,PT,0,0x1000);
                PDE.SetAddress(&Debugger,(uint64_t)PT >> 12);
                PDE.SetFlag(&Debugger,PT_Flag::Present,true);
                PDE.SetFlag(&Debugger,PT_Flag::ReadWrite,true);
                PD->entries[indexer.PT_i] = PDE;
            }else{
                PT = (PageTable*)((uint64_t)PDE.GetAddress(&Debugger) << 12);
            }
            PDE = PT->entries[indexer.P_i];
            PDE.SetAddress(&Debugger,(uint64_t)physicalMemory >> 12);
            PDE.SetFlag(&Debugger,PT_Flag::Present,true);
            PDE.SetFlag(&Debugger,PT_Flag::ReadWrite,true);
            PT->entries[indexer.P_i] = PDE;
        }
    };
};
