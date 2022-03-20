#include<Sauce/Interrupts/Interrupts.hpp>

namespace Sauce{
    __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame){
        GlobalTerminal->PutString("PageFault!\n\r");
        while(true){
            asm volatile("cli;hlt");
        }
    }
};