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


//TEST



//TEST




void test(){
    char _Char='a';
    size_t XX=0;
    // 40x25
    Sauce::Graphics::Place_String("HELLO WORLD!",2);
}

void Kernel_Main(){
    Sauce::Interrupts::InitializeIDT();
    Sauce::IO::init_serial();
    Sauce::Filesystem::InitializeFilesystem();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    test();

    while(1){
        asm volatile("hlt");
    }
}
