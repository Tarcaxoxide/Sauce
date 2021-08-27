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

namespace Sauce{
    namespace IO{
		void outb(uint16_t port,uint8_t val,bool slow=false);
		uint8_t inb(uint16_t port);
		void outw(uint16_t port,uint16_t val);
		uint16_t inw(uint16_t port);
		void outl(uint16_t port,uint32_t val);
		uint32_t inl(uint16_t port);
		void RemapPic();
	};
	namespace EIO{ // E for Extended or Extra , basically it's not neccesary but it's nice to have.
		class _Port{
			protected:
				uint16_t port_number;
				_Port(uint16_t port_number);
				~_Port();
		};

		class _8Bit_Port : public _Port{
			public:
				_8Bit_Port(uint16_t port_number);
				~_8Bit_Port();
				virtual void operator<<(uint8_t Data);
				virtual void operator>>(uint8_t &Data);

		};

		class _8BitSlow_Port : public _8Bit_Port{
			public:
				_8BitSlow_Port(uint16_t port_number);
				~_8BitSlow_Port();
				virtual void operator<<(uint8_t Data);

		};

		class _16Bit_Port : public _Port{
			public:
				_16Bit_Port(uint16_t port_number);
				~_16Bit_Port();
				virtual void operator<<(uint16_t Data);
				virtual void operator>>(uint16_t &Data);
				
		};

		class _32Bit_Port : public _Port{
			public:
				_32Bit_Port(uint16_t port_number);
				~_32Bit_Port();
				virtual void operator<<(uint32_t Data);
				virtual void operator>>(uint32_t &Data);
		};
	};
};