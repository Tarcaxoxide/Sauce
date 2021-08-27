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
		void InitializeIDT();
		void MapIDT(size_t index,uint64_t (*This_isr));
		void isr_handler(uint64_t isr_number);
		uint64_t IntHandler(uint64_t Interrupt_Number,uint64_t esp);
	};
};


extern "C" void SetStackBase(uint64_t address);
extern "C" void SetStackPointer(uint64_t address);
extern "C" uint64_t GetStackBase();
extern "C" uint64_t GetStackPointer();

extern void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key);
extern void NotifyKernelOfTimer();
