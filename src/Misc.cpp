#include <Misc.hpp>


void* operator new[](size_t size){
    return Sauce::Memory::alloc(size);
}
void operator delete[](void* pointer){
    Sauce::Memory::free(pointer);
}

void STOP(bool fail){
    Sauce::Terminal::String("\n\r System halted");
    while(true){
        if(fail){
            asm volatile("cli");// stop interrupts.
            Sauce::Terminal::String(" and stopped interrupts");
        }
        Sauce::Terminal::String(" \n\r");
        asm volatile("hlt"); // halt the cpu.
    }
}
void REBOOT(){
    // TODO: add reboot assembly function to actually do the reboot.
}