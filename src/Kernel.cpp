#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
extern "C" uint8_t IsGraphical;


void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    
    Sauce::Shell::KeyPress(_Key);
    
}

void NotifyKernelOfTimer(float rate){
    Sauce::Interrupts::PIT_Counter+=0x0000000000000001;
        
    if(Sauce::Interrupts::PIT_Counter > 0x1000000000000000){
        Sauce::Interrupts::PIT_Counter=0;
    }
}

void Kernel_Main(){
    Sauce::Interrupts::InitializeIDT();
    Sauce::IO::init_serial();
    Sauce::Filesystem::InitializeFilesystem();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Sauce::Memory::GetFreeHeap()));
    Sauce::Terminal::String(" \n\r");
    
    uint8_t Atest = Sauce::Convert::To_uint8::From_Char('5');
    Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(Atest));
    Sauce::Terminal::String(" \n\r");

    while(true){
        asm volatile("hlt");
    }
}
