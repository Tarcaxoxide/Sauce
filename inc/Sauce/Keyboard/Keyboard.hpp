#pragma

#include<stddef.h>
#include<stdint.h>

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
		KeyboardKey Code_To_Key(uint16_t TranslatedKeyCode);
        extern const uint8_t KeyMapCodes_1[];
    };
};