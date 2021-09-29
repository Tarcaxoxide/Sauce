#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Convert.hpp>
#include <Terminal.hpp>
#include <Container.hpp>

namespace Sauce{
    namespace Graphics{
        const uint16_t MAX_Xpos=320,MAX_Ypos=200;
        typedef uint16_t vertex[3];
        
        struct _Vector{
            uint16_t StartX;
            uint16_t StartY;
            uint16_t StopX;
            uint16_t StopY;
        };

        typedef int16_t Gchar[8][8]; // Gchar standing for "Graphic char", it's 8x8 but the last column should be left blank as a spacer between letters.

        void Store_GChar(Gchar Val);
        void Place_Char(char Char,uint16_t color);
        void Place_String(char* Str,uint16_t color);
        void Place_Pixel(uint16_t X,uint16_t Y,uint16_t color);
        void Place_Rectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color);
    };
};