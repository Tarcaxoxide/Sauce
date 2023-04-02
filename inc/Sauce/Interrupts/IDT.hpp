#ifndef __Sauce_Interrupts_IDT
#define __Sauce_Interrupts_IDT
#include<stddef.h>
#include<stdint.h>
#define IDT_TA_InterruptGate 0b10001110
#define IDT_TA_CallGate 0b10001100
#define IDT_TA_TrapGate 0b10001111
namespace Sauce{
	namespace Interrupts{
		struct IDTDescriptorEntry {
			uint16_t offset0; 
			uint16_t selector; // segment selector, used when interrupt is caught. switches to segment defined here.
			uint8_t ist; // interrupt stack table offset
			uint8_t type_attr;
			uint16_t offset1;
			uint32_t offset2;
			uint32_t ignore;
			void SetOffset(uint64_t offset);
			uint64_t GetOffset();
		};
		struct IDTR{
			uint16_t Limit;
			uint64_t Offset;
		}__attribute__((packed));
	};
};
#endif