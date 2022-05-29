#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/Utilities/Conversion.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Interrupts{
        __attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Call("PageFault_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
            Sauce::IO::Panic("Page Fault Detected!");
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
        }
        __attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Call("DoubleFault_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
            Sauce::IO::Panic("Double Fault Detected!");
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
        }
        __attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Call("GeneralProtectionFault_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
            Sauce::IO::Panic("General Protection Fault Detected!");
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_FAULTS,true);
        }
        __attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Call("KeyboardInterrupt_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_KEYBOARD,true);
            uint8_t input = Sauce::IO::inb(0x60);
            Kernel_cl::Notify({InterruptTypeCode::ITC__Keyboard,input});
            PIC1_Done();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_KEYBOARD,true);
        }
        __attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Call("MouseInterrupt_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_MOUSE,true);
            uint8_t mouseData = Sauce::IO::inb(0x60);
            Kernel_cl::Notify({InterruptTypeCode::ITC__Mouse,mouseData});
            PIC2_Done();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_MOUSE,true);
        }
        __attribute__((interrupt)) void PITInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::SetNestLevel(0);
            Sauce::IO::Debug::Print_Spammy_Call("PITInterrupt_handler",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_PIT,true);
            Sauce::Interrupts::PIT::Tick();
            Kernel_cl::Notify({InterruptTypeCode::ITC__Time,0xFF});
            PIC1_Done();
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_PIT,true);
        }
        void PIC1_Done(){
            Sauce::IO::Debug::Print_Spammy_Call("PIC1_Done",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_DONE,true);
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_DONE,true);
        }
        void PIC2_Done(){
            Sauce::IO::Debug::Print_Spammy_Call("PIC2_Done",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_DONE,true);
            Sauce::IO::outb(PIC2_COMMAND,PIC_EOI);
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPTS && Sauce::IO::Debug::INTERRUPT_DONE,true);
        }
        void RemapPic(){
            Sauce::IO::Debug::Print_Call("RemapPic",true,true);
            uint8_t a1, a2;
            
            a1 = Sauce::IO::inb_w(PIC1_DATA);
            a2 = Sauce::IO::inb_w(PIC2_DATA);
            
            Sauce::IO::outb_w(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
            Sauce::IO::outb_w(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

            Sauce::IO::outb_w(PIC1_DATA,0x20);
            Sauce::IO::outb_w(PIC2_DATA,0x28);

            Sauce::IO::outb_w(PIC1_DATA, 4);
            Sauce::IO::outb_w(PIC2_DATA, 2);

            Sauce::IO::outb_w(PIC1_DATA, ICW4_8086);
            Sauce::IO::outb_w(PIC2_DATA, ICW4_8086);

            Sauce::IO::outb_w(PIC1_DATA,a1);
            Sauce::IO::outb_w(PIC2_DATA,a2);
            Sauce::IO::Debug::Print_Return("void",true,true);
        }
    };
};