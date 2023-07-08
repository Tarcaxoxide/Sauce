#ifndef __Sauce_Interrupts_Interrupts
#define __Sauce_Interrupts_Interrupts
#include<stddef.h>
#include<stdint.h>
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
		enum InterruptTypeCode:uint8_t{
			ITC__NULL=0,
			ITC__Time,
			ITC__Keyboard,
			ITC__Mouse,
			ITC__GeneralProtectionFault,
			ITC__DoubleFault,
			ITC__PageFault,
			ITC__Request_Memory_B,
			ITC__Request_Memory_KB,
			ITC__Request_Memory_MB,
			ITC__Request_Memory_GB,
			ITC__Request_Memory_TB
		};

		struct interrupt_frame{
			uint8_t ip;
			uint8_t cs;
			uint8_t flags;
			uint8_t sp;
			uint8_t ss;
		}__attribute__((packed));
		struct InterruptDataStruct{
			InterruptTypeCode TypeCode;
			uint8_t RawInterruptData;
			interrupt_frame Frame;
			uint8_t ExtraData{0x00};
		}__attribute__((packed));
		__attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame);
		__attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame);
		__attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame);
		__attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame);
		__attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame);
		__attribute__((interrupt)) void PITInterrupt_handler(interrupt_frame* frame);
		void RemapPic();
		void PIC1_Done();
		void PIC2_Done();
	};
};
#endif