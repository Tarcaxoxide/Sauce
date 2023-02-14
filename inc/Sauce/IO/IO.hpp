#pragma once
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
    namespace IO{
        void io_wait();
        void outb(uint16_t port,uint8_t value);
        uint8_t inb(uint16_t port);

        void outw(uint16_t port,uint16_t value);
        uint16_t inw(uint16_t port);

        void outl(uint16_t port,uint32_t value);
        uint32_t inl(uint16_t port);

        void outb_w(uint16_t port,uint8_t value);
        uint8_t inb_w(uint16_t port);

        void outw_w(uint16_t port,uint16_t value);
        uint16_t inw_w(uint16_t port);

        void outl_w(uint16_t port,uint32_t value);
        uint32_t inl_w(uint16_t port);

        //IO port classes
        class Port8Bit{
            uint16_t portNumber;
            bool Slow;
            public:
            Port8Bit(uint16_t portNumber,bool Slow=false);
            ~Port8Bit();
            void operator<<(uint8_t data);
            void operator>>(uint8_t &data);
        };
        class Port16Bit{
            uint16_t portNumber;
            bool Slow;
            public:
            Port16Bit(uint16_t portNumber,bool Slow=false);
            ~Port16Bit();
            void operator<<(uint16_t data);
            void operator>>(uint16_t &data);
        };
        class Port32Bit{
            uint16_t portNumber;
            bool Slow;
            public:
            Port32Bit(uint16_t portNumber,bool Slow=false);
            ~Port32Bit();
            void operator<<(uint32_t data);
            void operator>>(uint32_t &data);
        };
    };
};