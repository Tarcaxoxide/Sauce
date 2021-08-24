#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack();

void tests(){
    Sauce::Terminal::Clear();
    Sauce::Terminal::String("Hello From Sauce OS.\n\r");
    Sauce::Memory::MemoryMapEntryMap MemMap = Sauce::Memory::GetMemoryRegions();
    Sauce::Terminal::String("\n\rUsable Memory Region...\n\r");
    for(uint8_t I=0;I<MemMap.MemoryMapEntryCount;I++){
        Sauce::Memory::PrintMemoryMap(MemMap.MemoryMapEntries[I]);
        Sauce::Terminal::String("\n\r");
    }
    Sauce::Terminal::String("\n\rRemaining stack space available...\n\r");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(GetFreeStack()));
    Sauce::Terminal::String("\n\r");
}

void Kernel_Main(){
    tests();
    
    Sauce::Interrupts::InitializeIDT();

    
    while(1){
        asm volatile("hlt");
    }
}
