#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>

namespace Sauce{
    namespace Graphics{
        const uint16_t MAX_Xpos=320,MAX_Ypos=200;
        void PlacePixel(uint16_t X,uint16_t Y,uint16_t color);
        void PlaceRectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color);
    };
};