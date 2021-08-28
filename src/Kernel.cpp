#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack

extern "C" uint64_t _HeadOfheap;


void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    Sauce::Shell::KeyPress(_Key);
}

void NotifyKernelOfTimer(float rate){
    Sauce::Interrupts::PIT_Counter+=0x0000000000000001;
        //Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Sauce::Interrupts::PIT_Counter));
        //Sauce::Terminal::String(":");
        //Sauce::Terminal::String(Sauce::Convert::To_String::From_Decimal(rate,10));
        //Sauce::Terminal::String("\n\r");
    if(Sauce::Interrupts::PIT_Counter > 0x1000000000000000){
        Sauce::Interrupts::PIT_Counter=0;
    }
}

void tests(){
    
}

void Kernel_Main(){
    Sauce::Interrupts::InitializeIDT();
    Sauce::IO::init_serial();
    Sauce::Filesystem::InitializeFilesystem();
    Sauce::Memory::InitializeHeap(_HeadOfheap,0x1000000);
    tests();

    while(1){
        asm volatile("hlt");
    }
}
