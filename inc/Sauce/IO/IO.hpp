#ifndef __Sauce_IO_IO
#define __Sauce_IO_IO
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace IO{
		void io_wait();
		/*8bit out*/ void outb(uint16_t port,uint8_t value);
		/*8bit in*/  uint8_t inb(uint16_t port);
		/*16bit out*/void outw(uint16_t port,uint16_t value);
		/*16bit in*/ uint16_t inw(uint16_t port);
		/*32bit out*/void outl(uint16_t port,uint32_t value);
		/*32bit in*/ uint32_t inl(uint16_t port);

		/*8bit out and wait*/ void outb_w(uint16_t port,uint8_t value);
		/*8bit in and wait*/  uint8_t inb_w(uint16_t port);
		/*16bit out and wait*/void outw_w(uint16_t port,uint16_t value);
		/*16bit in and wait*/ uint16_t inw_w(uint16_t port);
		/*32bit out and wait*/void outl_w(uint16_t port,uint32_t value);
		/*32bit in and wait*/ uint32_t inl_w(uint16_t port);
	};
	namespace IO{//objects, objects everywhere.
		class Port_cl{
			protected:
				uint16_t PortNumber;
				bool Slow=false;
				Port_cl(uint16_t portNumber,bool slow);
				~Port_cl();
		};
		class Port8Bit_cl:public Port_cl{
			public:
				Port8Bit_cl(uint16_t portNumber,bool slow=false);
				Port8Bit_cl& operator<<(uint8_t Data);
				Port8Bit_cl& operator>>(uint8_t& Data);
				~Port8Bit_cl();
		};
		class Port16Bit_cl:public Port_cl{
			public:
				Port16Bit_cl(uint16_t portNumber,bool slow=false);
				Port16Bit_cl& operator<<(uint16_t Data);
				Port16Bit_cl& operator>>(uint16_t& Data);
				~Port16Bit_cl();
		};
		class Port32Bit_cl:public Port_cl{
			public:
				Port32Bit_cl(uint16_t portNumber,bool slow=false);
				Port32Bit_cl& operator<<(uint32_t Data);
				Port32Bit_cl& operator>>(uint32_t& Data);
				~Port32Bit_cl();
		};
	};
};
#endif


//someportobject << data1 << data2 << data3 << data4;