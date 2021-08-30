#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Convert.hpp>
#include <Terminal.hpp>

namespace Sauce{
    namespace Graphics{
        const uint16_t MAX_Xpos=320,MAX_Ypos=200;
        struct _Vector{
            uint16_t StartX;
            uint16_t StartY;
            uint16_t StopX;
            uint16_t StopY;
        };

        typedef int16_t Gchar[8][8];

        void Store_GChar(Gchar Val);
        void Place_Char(char Char,uint16_t color);
        void Store_GChar(Gchar Val);
        void Place_String(char* Str,uint16_t color);
        void Place_Pixel(uint16_t X,uint16_t Y,uint16_t color);
        void Place_Rectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color);
        void Place_Vector(_Vector Vector,uint16_t color);
        void Place_EmptySquare(uint16_t Xs,uint16_t Ys,uint16_t Xp,uint16_t Yp,uint16_t color);
    };
};