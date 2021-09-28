#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
extern "C" uint8_t IsGraphical;


void Notify_Kernel_Of_KeyPress(Sauce::Keyboard::KeyboardKey _Key){
    
    Sauce::Shell::KeyPress(_Key);
    
}

void Notify_Kernel_Of_Timer(float rate){
    Sauce::Interrupts::ProgrammableInterruptTimerCounter+=0x0000000000000001;
        
    if(Sauce::Interrupts::ProgrammableInterruptTimerCounter > 0x1000000000000000){
        Sauce::Interrupts::ProgrammableInterruptTimerCounter=0;
    }
}

void Kernel_Main(){
    Sauce::IO::init_serial();
    Sauce::Interrupts::Initialize_Interrupt_Descriptor_Table();
    Sauce::Filesystem::Initialize_Filesystem();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Sauce::Memory::GetFreeHeap()));
    Sauce::Terminal::String(" \n\r");
    
    uint32_t Atest = Sauce::Convert::To_uint32::From_Char('5');
    Atest+=5;
    Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(Atest));
    Sauce::Terminal::String(" \n\r");

    while(true){
        asm volatile("hlt");
    }
}
