#pragma once
#include<Sauce/Math.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Graphics{
        namespace SauceFont{
            const static size_t GlyphWidth=13;
            const static size_t GlyphHeight=13;
            const static size_t GlyphSize=GlyphWidth*GlyphHeight;
            extern uint8_t Glyphs[][GlyphSize];
        };
    };
};

/*
    . . . . . . .
    . . * * * . .
    . . * . * . .
    . . * * * . .
    . . * . * . .
    . . * * * . .
    . . . . . . .

*/