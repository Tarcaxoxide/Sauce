#define CCPP 
#include<Sauce/Common.h>
#include<Sauce/Terminal.hpp>
#include<Sauce/Convert.hpp>
#include<Sauce/efiMemory.hpp>
#include<Sauce/Memory.hpp>
#include<Sauce/Bitmap.hpp>
#include<Sauce/PageFrameAllocator.hpp>

extern uint64_t _KernelStartRef;
extern uint64_t _KernelEndRef;

extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::Terminal Term(DFBL);
    Term.Clear();
    Term.SetCursor(0,0);

    Term.PutString("Sauce OS\n\r");

    uint64_t mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;

    Sauce::PageFrameAllocator PageAllocator;

    PageAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
    uint64_t kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
    uint64_t kernelPages = (uint64_t)kernelSize/4096 +1;
    PageAllocator.LockPages(&_KernelStartRef,kernelPages);


    Term.PutString("Free RAM:");
    Term.PutString(Sauce::Convert::To_String::From_Decimal( (float)(PageAllocator.GetFreeRAM()/1024) ,2));
    Term.PutString(" KB\n\rUsed RAM:");
    Term.PutString(Sauce::Convert::To_String::From_Decimal( (float)(PageAllocator.GetUsedRAM()/1024) ,2));
    Term.PutString(" KB\n\rReserved RAM:");
    Term.PutString(Sauce::Convert::To_String::From_Decimal( (float)(PageAllocator.GetReservedRAM()/1024) ,2));
    Term.PutString(" KB\n\r");

    for(int t=0;t<20;t++){
        void* address = PageAllocator.RequestPage();
        Term.PutString(Sauce::Convert::To_String::From_uint64((uint64_t)address));
        Term.PutString("\n\r");
    }

    //Term.PutString(Sauce::Convert::To_String::From_Integer(Sauce::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize)));
    //for(int i=0;i<mMapEntries;i++){
    //    Term.SetColor(GOP_GREEN);
    //    Sauce::EFI_MEMORY_DESCRIPTOR* descriptor = (Sauce::EFI_MEMORY_DESCRIPTOR*)((uint64_t)DFBL->mMap + (i*DFBL->mDescriptorSize));
    //    Term.PutString((char*)Sauce::EFI_MEMORY_TYPE_STRINGS[descriptor->type]);
    //    Term.PutString(" ");
    //    Term.SetColor(GOP_BLUE);
    //    Term.PutString(Sauce::Convert::To_String::From_Integer(descriptor->numPages * 4096 / 1024));
    //    Term.PutString(" K\n\r");
    //}

    while(true){
        asm volatile("hlt");
    }
    return DFBL->TestNumber;
}