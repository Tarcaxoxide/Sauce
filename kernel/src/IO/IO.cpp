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

        //IO port classes
        Port8Bit::Port8Bit(uint16_t portNumber,bool Slow){this->portNumber=portNumber;this->Slow=Slow;}
        Port16Bit::Port16Bit(uint16_t portNumber,bool Slow){this->portNumber=portNumber;this->Slow=Slow;}
        Port32Bit::Port32Bit(uint16_t portNumber,bool Slow){this->portNumber=portNumber;this->Slow=Slow;}
        void Port8Bit::operator<<(uint8_t data){
            outb(portNumber,data);
            if(Slow)io_wait();
        }
        void Port8Bit::operator>>(uint8_t &data){
            data = inb(portNumber);
            if(Slow)io_wait();
        }
        void Port16Bit::operator<<(uint16_t data){
            outw(portNumber,data);
            if(Slow)io_wait();
        }
        void Port16Bit::operator>>(uint16_t &data){
            data = inw(portNumber);
            if(Slow)io_wait();
        }
        void Port32Bit::operator<<(uint32_t data){
            outl(portNumber,data);
            if(Slow)io_wait();
        }
        void Port32Bit::operator>>(uint32_t &data){
            data = inl(portNumber);
            if(Slow)io_wait();
        }
        Port32Bit::~Port32Bit(){}
        Port16Bit::~Port16Bit(){}
        Port8Bit::~Port8Bit(){}
        
    };
};