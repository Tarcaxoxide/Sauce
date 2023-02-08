#include<Sauce/Types.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Memory/List.hpp>
#pragma once
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
    . . . . . . . . . . . . .
    . 9 9 9 9 9 9 9 9 9 9 9 .
    . 9 5 0 0 0 0 0 0 0 5 9 .
    . 9 0 5 0 0 0 0 0 5 0 9 .
    . 9 0 0 5 0 0 0 5 0 0 9 .
    . 9 0 0 0 5 0 5 0 0 0 9 .
    . 9 0 0 0 0 5 0 0 0 0 9 .
    . 9 0 0 0 5 0 5 0 0 0 9 .
    . 9 0 0 5 0 0 0 5 0 0 9 .
    . 9 0 5 0 0 0 0 0 5 0 9 .
    . 9 5 0 0 0 0 0 0 0 5 9 .
    . 9 9 9 9 9 9 9 9 9 9 9 .
    . . . . . . . . . . . . .

*/
