#pragma once

#include<Sauce/Terminal.hpp>
#include<Sauce/Panic.hpp>

namespace Sauce{
    namespace Interrupts{
        struct interrupt_frame;
        __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame);
        __attribute__((interrupt)) void DoubleFault_handler(struct interrupt_frame* frame);
        __attribute__((interrupt)) void GeneralProtectionFault_handler(struct interrupt_frame* frame);
    };
};