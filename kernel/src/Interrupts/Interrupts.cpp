#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Interrupts{
		__attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFault_handler",_NAMESPACE_,_ALLOW_PRINT_);
			Kernel_cl::Notify({InterruptTypeCode::ITC__PageFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"DoubleFault_handler",_NAMESPACE_,_ALLOW_PRINT_);
			Kernel_cl::Notify({InterruptTypeCode::ITC__DoubleFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GeneralProtectionFault_handler",_NAMESPACE_,_ALLOW_PRINT_);
			Kernel_cl::Notify({InterruptTypeCode::ITC__GeneralProtectionFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"KeyboardInterrupt_handler",_NAMESPACE_,_ALLOW_PRINT_);
			uint8_t input = Sauce::IO::inb(0x60);
			Kernel_cl::Notify({InterruptTypeCode::ITC__Keyboard,input,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC1_Done();
		}
		__attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"MouseInterrupt_handler",_NAMESPACE_,_ALLOW_PRINT_);
			uint8_t mouseData = Sauce::IO::inb(0x60);
			Kernel_cl::Notify({InterruptTypeCode::ITC__Mouse,mouseData,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC2_Done();
		}
		__attribute__((interrupt)) void PITInterrupt_handler(interrupt_frame* frame){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PITInterrupt_handler",_NAMESPACE_,_ALLOW_PRINT_);
			Sauce::Interrupts::PIT::Tick();
			Kernel_cl::Notify({InterruptTypeCode::ITC__Time,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC1_Done();
		}
		void PIC1_Done(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PIC1_Done",_NAMESPACE_,_ALLOW_PRINT_);
			Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
		}
		void PIC2_Done(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PIC2_Done",_NAMESPACE_,_ALLOW_PRINT_);
			Sauce::IO::outb(PIC2_COMMAND,PIC_EOI);
			Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
		}
		void RemapPic(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"RemapPic",_NAMESPACE_,_ALLOW_PRINT_);
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
