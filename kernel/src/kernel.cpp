#define CCPP 
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

extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::Terminal Term(DFBL);
    Sauce::GlobalAllocator = Sauce::PageFrameAllocator();
    Term.Clear();
    Term.SetCursor(0,0);
    uint64_t mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
    Sauce::GlobalAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
    uint64_t kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
    uint64_t kernelPages = (uint64_t)kernelSize/4096 +1;
    Sauce::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);

    Sauce::PageTable* PML4 = (Sauce::PageTable*)Sauce::GlobalAllocator.RequestPage();
    Sauce::memset(PML4,0,0x1000);
    Sauce::PageTableManager pageTableManager = PageTableManager(PML4);

    for(uint64_t t=0;t<Sauce::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
        pageTableManager.MapMemory((void*)t,(void*)t);
    } 

    uint64_t fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
    uint64_t fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
    for(uint64_t t=fbBase;t<fbBase+fbSize;t+=0x1000){
        pageTableManager.MapMemory((void*)t,(void*)t);
    }
    asm volatile("mov %0, %%cr3" : : "r" (PML4));

    Term.DFBL=&DFBL;

    Term.Clear();
    Term.SetCursor(0,0);
    Term.PutString("Hello World?");


    while(true){
        asm volatile("hlt");
    }
    return DFBL->TestNumber;
}