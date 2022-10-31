#pragma once
#include<stddef.h>
#include<stdint.h>
#include<cstring>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<float.h>
#include<iso646.h>
#include<limits.h>
#include<stdarg.h>

namespace Sauce{
    	struct uPoint8_st{
        	uint8_t X;
        	uint8_t Y;
        	uint8_t Z;
    	};
    	struct uPoint16_st{
        	uint16_t X;
        	uint16_t Y;
        	uint16_t Z;
    	};
    	struct uPoint32_st{
        	uint32_t X;
        	uint32_t Y;
        	uint32_t Z;
    	};
    	struct uPoint64_st{
        	uint64_t X;
        	uint64_t Y;
        	uint64_t Z;
    	};
    	struct Point8_st{
        	int8_t X;
        	int8_t Y;
        	int8_t Z;
    	};
    	struct Point16_st{
        	int16_t X;
        	int16_t Y;
        	int16_t Z;
    	};
    	struct Point32_st{
        	int32_t X;
        	int32_t Y;
    		int32_t Z;
    	};
    	struct Point64_st{
        	int64_t X;
        	int64_t Y;
        	int64_t Z;
    	};
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
			Point64_st* Position;
            bool Good;
        };
};
