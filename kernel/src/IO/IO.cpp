#include<Sauce/IO/IO.hpp>

namespace Sauce{
    namespace IO{
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
        void io_wait(){
            asm volatile("outb %%al, $0x80" : : "a"(0));
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
    };
};