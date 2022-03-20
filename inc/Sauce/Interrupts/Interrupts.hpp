#pragma once

#include<Sauce/Terminal.hpp>
#include<Sauce/Panic.hpp>
#include<Sauce/IO.hpp>
#include<Sauce/Convert/To_String.hpp>

#define PIC1_COMMAND 0X20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0XA0
#define PIC2_DATA 0xA1

#define ICW1_INIT 0X10
#define ICW1_ICW4 0X01
#define ICW4_8086 0X01
#define PIC_EOI 0x20

namespace Sauce{
    namespace Interrupts{
        struct interrupt_frame;
        __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame);
        __attribute__((interrupt)) void DoubleFault_handler(struct interrupt_frame* frame);
        __attribute__((interrupt)) void GeneralProtectionFault_handler(struct interrupt_frame* frame);
        __attribute__((interrupt)) void KeyboardInterrupt_handler(struct interrupt_frame* frame);
        void RemapPic();
        void PIC1_Done();
        void PIC2_Done();
    };
};