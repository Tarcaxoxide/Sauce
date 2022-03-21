#pragma once

#include<stddef.h>
#include<stdint.h>

namespace Sauce{
    namespace IO{
        void outb(uint16_t port,uint8_t value);
        uint8_t inb(uint16_t port);
        void io_wait();
        void outb_w(uint16_t port,uint8_t value);
        uint8_t inb_w(uint16_t port);
    };
};