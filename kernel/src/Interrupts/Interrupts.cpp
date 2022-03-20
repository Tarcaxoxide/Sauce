#include<Sauce/Interrupts/Interrupts.hpp>

namespace Sauce{
    namespace Interrupts{
        __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame){
            Panic("Page Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void DoubleFault_handler(struct interrupt_frame* frame){
            Panic("Double Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void GeneralProtectionFault_handler(struct interrupt_frame* frame){
            Panic("General Protection Fault Detected!\n\r");
        }
    };
};