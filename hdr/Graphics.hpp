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
        void PlacePixel(uint16_t X,uint16_t Y,uint16_t color);
        void PlaceRectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color);
        void PlaceVector(_Vector Vector,uint16_t color);
        void PlaceEmptySquare(uint16_t Xs,uint16_t Ys,uint16_t Xp,uint16_t Yp,uint16_t color);
    };
};