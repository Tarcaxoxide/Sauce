#include<Sauce/Kernel.hpp>

_Kernel::_Kernel(DataStructure* DFBL)
    :Term(DFBL){
        Term.Clear();
        Term.SetCursor(0,0);
        Term.PutString("Kernel Init...\n\r");
        this->DFBL=DFBL;
        Sauce::GlobalAllocator = Sauce::PageFrameAllocator();
        uint64_t mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::GlobalAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        uint64_t kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        uint64_t kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::PageTable*)Sauce::GlobalAllocator.RequestPage();
        Sauce::memset(PML4,0,0x1000);
        Sauce::PageTableManager pageTableManager = Sauce::PageTableManager(PML4);
        this->pageTableManager=&pageTableManager;
        for(uint64_t t=0;t<Sauce::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        uint64_t fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        uint64_t fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::GlobalAllocator.LockPages((void*)fbBase,fbSize/0x1000 +1);
        for(uint64_t t=fbBase;t<fbBase+fbSize;t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
        Term.PutString("Kernel init finished.\n\r");
    }