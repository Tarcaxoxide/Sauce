#pragma once

#include <stdint.h>
#include <stddef.h>
#include <IO.hpp>
#include <Keyboard.hpp>
#include <Terminal.hpp>
#include <Convert.hpp>

namespace Sauce{
    namespace Interrupts{
		struct IDT64{
			uint16_t offset_low;
			uint16_t selector;
			uint8_t ist;
			uint8_t types_attr;
			uint16_t offset_mid;
			uint32_t offset_high;
			uint32_t zero;
		};
		void Initialize_Interrupt_Descriptor_Table();
		void Map_Interrupt_Descriptor_Table(size_t index,uint64_t (*This_isr));
		void Interrupt_SubRoutine_Handler(uint64_t isr_number);
		uint64_t Interrupt_Handler(uint64_t Interrupt_Number,uint64_t esp);
		extern uint64_t ProgrammableInterruptTimerCounter;
	};
};


extern "C" void Set_Stack_Base(uint64_t address);
extern "C" void Set_Stack_Pointer(uint64_t address);
extern "C" uint64_t Get_Stack_Base();
extern "C" uint64_t Get_Stack_Pointer();

extern void Notify_Kernel_Of_KeyPress(Sauce::Keyboard::KeyboardKey _Key);
extern void Notify_Kernel_Of_Timer(float rate);
