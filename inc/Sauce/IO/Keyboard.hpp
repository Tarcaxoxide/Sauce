#pragma

#include<Sauce/Types.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace IO{
        uint16_t Translate_KeyCode(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t KeyCode,size_t KeySet=1);
		Sauce::Keyboard_st Code_To_Key(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t TranslatedKeyCode);
        extern const uint8_t KeyMapCodes_1[];
    };
};