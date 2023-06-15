#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/Interrupts/PIT.hpp>

namespace Sauce{
	namespace Interrupts{
		__attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame){
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__PageFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame){
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__DoubleFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame){
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__GeneralProtectionFault,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
		}
		__attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame){
			uint8_t input = Sauce::IO::inb(0x60);
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__Keyboard,input,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC1_Done();
		}
		__attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame){
			uint8_t mouseData = Sauce::IO::inb(0x60);
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__Mouse,mouseData,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC2_Done();
		}
		__attribute__((interrupt)) void PITInterrupt_handler(interrupt_frame* frame){
			Sauce::Interrupts::PIT::Tick();
			Core::Kernel_cl::Notify({InterruptTypeCode::ITC__Time,0xFF,{frame->ip,frame->cs,frame->flags,frame->sp,frame->ss}});
			PIC1_Done();
		}
		void PIC1_Done(){
			Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
		}
		void PIC2_Done(){
			Sauce::IO::outb(PIC2_COMMAND,PIC_EOI);
			Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
		}
		void RemapPic(){
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
