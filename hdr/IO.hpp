#pragma once

#include <stdint.h>
#include <stddef.h>

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA 0xa1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01
#define COMn 0x3f8

namespace Sauce{
    namespace IO{
		void outb(uint16_t port,uint8_t val,bool slow=false);
		uint8_t inb(uint16_t port);
		void outw(uint16_t port,uint16_t val);
		uint16_t inw(uint16_t port);
		void outl(uint16_t port,uint32_t val);
		uint32_t inl(uint16_t port);
		void RemapPic();
		int init_serial();
		int serial_received();
		char read_serial();
		int is_transmit_empty();
		void Write_Serial(char a);
	};
};