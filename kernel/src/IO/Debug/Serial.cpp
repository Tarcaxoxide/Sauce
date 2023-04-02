#include<Sauce/IO/Debug/Serial.hpp>
#include<Sauce/IO/IO.hpp>
namespace Sauce{
	namespace IO{
		namespace Debug{
			bool init_serial(uint16_t PORT){
				Sauce::IO::outb(PORT + 1, 0x00);	// Disable all interrupts
				Sauce::IO::outb(PORT + 3, 0x80);	// Enable DLAB (set baud rate divisor)
				Sauce::IO::outb(PORT + 0, 0x03);	// Set divisor to 3 (lo byte) 38400 baud
				Sauce::IO::outb(PORT + 1, 0x00);	//				  (hi byte)
				Sauce::IO::outb(PORT + 3, 0x03);	// 8 bits, no parity, one stop bit
				Sauce::IO::outb(PORT + 2, 0xC7);	// Enable FIFO, clear them, with 14-byte threshold
				Sauce::IO::outb(PORT + 4, 0x0B);	// IRQs enabled, RTS/DSR set
				Sauce::IO::outb(PORT + 4, 0x1E);	// Set in loopback mode, test the serial chip
				Sauce::IO::outb(PORT + 0, 0xAE);	// Test serial chip (send byte 0xAE and check if serial returns same byte)

				// Check if serial is faulty (i.e: not same byte as sent)
				if(inb(PORT + 0) != 0xAE) {
				   return false;
				}

				// If serial is not faulty set it in normal operation mode
				// (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
				Sauce::IO::outb(PORT + 4, 0x0F);
				return true;
			}
			int serial_received(uint16_t PORT){
				return Sauce::IO::inb(PORT + 5) & 1;
			}
			char read_serial(uint16_t PORT){
				while (serial_received(PORT) == 0);
				return Sauce::IO::inb(PORT);
			}
			int is_transmit_empty(uint16_t PORT){
				return Sauce::IO::inb(PORT + 5) & 0x20;
			}
			void write_serial(char a,uint16_t PORT){
				while (is_transmit_empty(PORT) == 0);
				Sauce::IO::outb(PORT,a);
			}
			void write_string_serial(const char* a,uint16_t PORT){
				char* ValPtr = (char*)a;
				while(*ValPtr){
					write_serial(*ValPtr,PORT);
					ValPtr++;
				}
			}
		};
	};
};