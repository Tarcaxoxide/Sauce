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
};