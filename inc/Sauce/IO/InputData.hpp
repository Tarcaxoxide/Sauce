#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace IO{

        struct Keyboard_st{
            bool Capital=false;
		    bool Press=false;
		    bool visible=true;
		    uint8_t Key;
		    char Display;
        }__attribute__((packed));
        struct Mouse_st{
            bool RightButton;
            bool LeftButton;
            bool CenterButton;
            Point64_t* Position;
        }__attribute__((packed));

    };
};