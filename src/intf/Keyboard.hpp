#pragma once

#include<stdint.h>
#include<stddef.h>
#include "KeyboardMaps.hpp"


namespace Sauce{
    namespace Keyboard{
		struct KeyboardKey{
			bool Capital=false;
			bool Press=false;
			bool visible=true;
			uint8_t Key;
			char Display;
		};
		uint16_t Translate_KeyCode(uint8_t KeyCode,size_t KeySet=1);
		KeyboardKey CodeToKey(uint16_t TranslatedKeyCode);
	};
};