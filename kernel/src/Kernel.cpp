#include<Sauce/Kernel.hpp>

namespace Sauce{
    _Kernel::_Kernel(DataStructure* DFBL)
        :Term(DFBL){
        Term.Clear();
        Term.SetCursor(0,0);
        Term.PutString("Kernel Init...\n\r");
        this->DFBL=DFBL;
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        
        Term.PutString("Kernel init finished.\n\r");
    }
    void _Kernel::Prep_GlobalAllocator(){
        Term.PutString("Preping Allocator...\n\r");
        Sauce::GlobalAllocator = Sauce::PageFrameAllocator();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::GlobalAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::PageTable*)Sauce::GlobalAllocator.RequestPage();
        Sauce::memset(PML4,0,0x1000);
        pageTableManager.Initialize(PML4);
    }
    void _Kernel::Prep_VirtualAddresses(){
        Term.PutString("Preping Virtual Addresses...\n\r");
        for(uint64_t t=0;t<Sauce::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::GlobalAllocator.LockPages((void*)fbBase,fbSize/0x1000 +1);
        for(uint64_t t=fbBase;t<fbBase+fbSize;t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
    }
    void _Kernel::Stop(){
        while(true){
            asm volatile("hlt");
        }
    }
};