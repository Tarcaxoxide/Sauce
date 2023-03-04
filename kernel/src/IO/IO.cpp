#include<Sauce/IO/IO.hpp>

namespace Sauce{
	namespace IO{
		void io_wait(){
			asm volatile("outb %%al, $0x80" : : "a"(0));
		}
		void outb(uint16_t port,uint8_t value){
			asm volatile("outb %0, %1" : : "a"(value),"Nd"(port));
		}
		uint8_t inb(uint16_t port){
			uint8_t value;
			asm volatile("inb %1, %0" 
			: "=a"(value) 
			: "Nd"(port));
			return value;
		}
		void outw(uint16_t port,uint16_t value){
			asm volatile("outw %0, %1" : : "a"(value),"Nd"(port));
		}
		uint16_t inw(uint16_t port){
			uint16_t value;
			asm volatile("inw %1, %0" 
			: "=a"(value) 
			: "Nd"(port));
			return value;
		}
		void outl(uint16_t port,uint32_t value){
			asm volatile("outl %0, %1" : : "a"(value),"Nd"(port));
		}
		uint32_t inl(uint16_t port){
			uint32_t value;
			asm volatile("inl %1, %0" 
			: "=a"(value) 
			: "Nd"(port));
			return value;
		}
		void outb_w(uint16_t port,uint8_t value){
			outb(port,value);
			io_wait();
		}
		uint8_t inb_w(uint16_t port){
			uint8_t ret = inb(port);
			io_wait();
			return ret;
		}
		void outw_w(uint16_t port,uint16_t value){
			outw(port,value);
			io_wait();
		}
		uint16_t inw_w(uint16_t port){
			uint16_t ret = inw(port);
			io_wait();
			return ret;
		}
		void outl_w(uint16_t port,uint32_t value){
			outl(port,value);
			io_wait();
		}
		uint32_t inl_w(uint16_t port){
			uint32_t ret = inl(port);
			io_wait();
			return ret;
		}
	};
	namespace IO{//objects, objects everywhere.
		Port_cl::Port_cl(uint16_t portNumber,bool slow):PortNumber(portNumber),Slow(slow){}
		Port_cl::~Port_cl(){}

		Port8Bit_cl::Port8Bit_cl(uint16_t portNumber,bool slow):Port_cl(portNumber,slow){}
		Port8Bit_cl& Port8Bit_cl::operator<<(uint8_t Data){outb(PortNumber,Data);if(Slow)io_wait();return *this;}
		Port8Bit_cl& Port8Bit_cl::operator>>(uint8_t& Data){Data=inb(PortNumber);if(Slow)io_wait();return *this;}
		Port8Bit_cl::~Port8Bit_cl(){}
		
		Port16Bit_cl::Port16Bit_cl(uint16_t portNumber,bool slow):Port_cl(portNumber,slow){}
		Port16Bit_cl& Port16Bit_cl::operator<<(uint16_t Data){outw(PortNumber,Data);if(Slow)io_wait();return *this;}
		Port16Bit_cl& Port16Bit_cl::operator>>(uint16_t& Data){Data=inw(PortNumber);if(Slow)io_wait();return *this;}
		Port16Bit_cl::~Port16Bit_cl(){}

		Port32Bit_cl::Port32Bit_cl(uint16_t portNumber,bool slow):Port_cl(portNumber,slow){}
		Port32Bit_cl& Port32Bit_cl::operator<<(uint32_t Data){outl(PortNumber,Data);if(Slow)io_wait();return *this;}
		Port32Bit_cl& Port32Bit_cl::operator>>(uint32_t& Data){Data=inl(PortNumber);if(Slow)io_wait();return *this;}
		Port32Bit_cl::~Port32Bit_cl(){}
	};
};