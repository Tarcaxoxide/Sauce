#pragma once
#include<Sauce/Math.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Graphics{
        namespace SauceFont{
            const static size_t GlyphSize=7*7;
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