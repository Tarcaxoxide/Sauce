#ifndef __Sauce_Graphics_Font
#define __Sauce_Graphics_Font
#include<stddef.h>
#include<stdint.h>
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
#endif
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
