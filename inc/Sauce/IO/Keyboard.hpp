#pragma

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/InputData.hpp>

namespace Sauce{
    namespace IO{
        uint16_t Translate_KeyCode(uint8_t KeyCode,size_t KeySet=1);
		Sauce::IO::Keyboard_st Code_To_Key(uint16_t TranslatedKeyCode);
        extern const uint8_t KeyMapCodes_1[];
    };
};