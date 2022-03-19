#define CCPP 
#include<Sauce/Common.h>
#include<Sauce/Terminal.hpp>
#include<Sauce/Convert.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>

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

    Sauce::PageMapIndexer pageIndexer = Sauce::PageMapIndexer(0x1000 * 52 + 0x50000 * 7);

    //Sauce::PageMapIndexer pageIndexer = Sauce::PageMapIndexer(0x1000);

    Term.PutString(Sauce::Convert::To_String::From_Integer(pageIndexer.P_i));
    Term.PutString(" - ");
    Term.PutString(Sauce::Convert::To_String::From_Integer(pageIndexer.PT_i));
    Term.PutString(" - ");
    Term.PutString(Sauce::Convert::To_String::From_Integer(pageIndexer.PD_i));
    Term.PutString(" - ");
    Term.PutString(Sauce::Convert::To_String::From_Integer(pageIndexer.PDP_i));
    Term.PutString("\n\r");


    while(true){
        asm volatile("hlt");
    }
    return DFBL->TestNumber;
}