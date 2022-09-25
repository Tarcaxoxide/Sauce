#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Interrupts{
        __attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("PageFault_handler",_NAMESPACE_);
            Debugger.Print(Sauce::Utility::HexToString(&Debugger,(uint64_t)(*((uint64_t*)frame))));
            Sauce::IO::Panic(&Debugger,"Page Fault Detected!");
        }
        __attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("DoubleFault_handler",_NAMESPACE_);
            Debugger.Print(Sauce::Utility::HexToString(&Debugger,(uint64_t)(*((uint64_t*)frame))));
            Sauce::IO::Panic(&Debugger,"Double Fault Detected!");
        }
        __attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("GeneralProtectionFault_handler",_NAMESPACE_);
            Debugger.Print(Sauce::Utility::HexToString(&Debugger,(uint64_t)(*((uint64_t*)frame))));
            Sauce::IO::Panic(&Debugger,"General Protection Fault Detected!");
        }
        __attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("KeyboardInterrupt_handler",_NAMESPACE_);
            uint8_t input = Sauce::IO::inb(0x60);
            Kernel_cl::Notify(&Debugger,{InterruptTypeCode::ITC__Keyboard,input});
            PIC1_Done(&Debugger);
        }
        __attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("MouseInterrupt_handler",_NAMESPACE_);
            uint8_t mouseData = Sauce::IO::inb(0x60);
            Kernel_cl::Notify(&Debugger,{InterruptTypeCode::ITC__Mouse,mouseData});
            PIC2_Done(&Debugger);
        }
        __attribute__((interrupt)) void PITInterrupt_handler(interrupt_frame* frame){
            Sauce::IO::Debug::Debugger_st Debugger("PITInterrupt_handler",_NAMESPACE_);
            Sauce::Interrupts::PIT::Tick(&Debugger);
            Kernel_cl::Notify(&Debugger,{InterruptTypeCode::ITC__Time,0xFF});
            PIC1_Done(&Debugger);
        }
        void PIC1_Done(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PIC1_Done",_NAMESPACE_);
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
        }
        void PIC2_Done(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PIC2_Done",_NAMESPACE_);
            Sauce::IO::outb(PIC2_COMMAND,PIC_EOI);
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
        }
        void RemapPic(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"RemapPic",_NAMESPACE_);
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
        }
    };
};
