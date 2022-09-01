#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace IO{
        struct Keyboard_st{
            bool Capital=false;
		    bool Press=false;
		    bool visible=true;
		    uint8_t Key;
		    wchar_t Display;
        };
        struct Mouse_st{
            bool RightButton;
            bool LeftButton;
            bool CenterButton;
			Sauce::Math::Point64_t* Position;
            bool Good;
        };
    };
};
