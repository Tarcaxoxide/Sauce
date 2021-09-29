#include <Misc.hpp>


void* operator new[](size_t size){
    return Sauce::Memory::alloc(size);
}
void operator delete[](void* pointer){
    Sauce::Memory::free(pointer);
}
namespace Sauce{
    void STOP(bool fail){
        while(true){
            if(fail)asm volatile("cli"); // stop interrupts.
            asm volatile("hlt"); // halt the cpu.
        }
    }
    void REBOOT(){
        // TODO: add reboot assembly function to actually do the reboot.
    }
};