#include <Misc.hpp>


void* operator new[](size_t size){
    return Sauce::Memory::alloc(size);
}
void operator delete[](void* pointer){
    Sauce::Memory::free(pointer);
}

namespace Sauce{
    void STOP(ERROR_CODES code){
        Sauce::Terminal::String("\n\r [");
        Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(code));
        Sauce::Terminal::String("] System halted");
        while(true){
            if(code){
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
};