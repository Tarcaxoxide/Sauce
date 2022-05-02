#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Math.hpp>
#include<Sauce/IO/InputData.hpp>


#define PS2LeftButton 0b00000001
#define PS2RightButton 0b00000010
#define PS2MiddleButton 0b00000100
#define PS2XSign 0b00010000
#define PS2YSign 0b00100000
#define PS2XOverflow 0b01000000
#define PS2YOverflow 0b10000000

namespace Sauce{
    namespace IO{

        void MouseWait();
        void MouseWaitInput();
        void MouseWrite(uint8_t value);
        uint8_t MouseRead();
        void HandlePS2Mouse(uint8_t data);
        Sauce::IO::Mouse_st* ProcessMousePacket();
        void PS2MouseInitialize();
        extern Point64_t MousePosition;
    };
};