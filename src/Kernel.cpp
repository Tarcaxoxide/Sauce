#include <Sauce.hpp>

void tests(){
    Sauce::Terminal::Clear();
    Sauce::Memory::MemoryMapEntryMap MemMap = Sauce::Memory::GetMemoryRegions();
    Sauce::Terminal::String("\n\n\r");
    for(uint8_t I=0;I<MemMap.MemoryMapEntryCount;I++){
        //Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(I));Sauce::Terminal::String("::");
        Sauce::Memory::PrintMemoryMap(MemMap.MemoryMapEntries[I]);
        Sauce::Terminal::String("\n\r");
    }
}

void Kernel_Main(){
    tests();
    
    Sauce::Interrupts::InitializeIDT();
    while(1){
        asm volatile("hlt");
    }
}