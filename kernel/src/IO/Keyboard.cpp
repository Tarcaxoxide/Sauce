#include<Sauce/IO/Keyboard.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace IO{
        uint16_t Translate_KeyCode(uint8_t KeyCode,size_t KeySet){
            Sauce::IO::Debug::Debugger_st Debugger("Translate_KeyCode",_NAMESPACE_,_ALLOW_PRINT_);
            static bool isShift;
            static bool isCaps;
            uint8_t* KeyMapCodes = NULL;
            uint16_t KeyCodeDecoded = 0;
          
            switch(KeySet){
                case 1:KeyMapCodes = (uint8_t*)&KeyMapCodes_1;break;
            }
            for(size_t I = 0;(I < 250);I++){
                uint16_t X = 0;
                if(KeyMapCodes[I] == KeyCode){ //basically we are converting the keycode to the index of the keycode inside the key map.
                    if(!(I % 2))X = 0x1000;  //and then we are doing some fancy math to seperate press/release (the last 2 bytes are the code, the first 2 are the indicators to determine press/release and capital/lowercase)
                    X += (uint16_t)(I - (I % 2));
                    KeyCodeDecoded=X;
                }
            }
            if(KeyCodeDecoded == 0x103A){
                isCaps =! isCaps;
            }
            if(KeyCodeDecoded == 0x0056 || KeyCodeDecoded == 0x0070){
                isShift = false;
            }
            if(KeyCodeDecoded == 0x1056 || KeyCodeDecoded == 0x1070){
                isShift = true;
            }
            if(isCaps != isShift){
                KeyCodeDecoded += 0x0100; // if we are shifted or capitalized but not at the same time then make the indicator so it's capital letter of what ever key is being pressed.
            }
            return KeyCodeDecoded;
        }
        Sauce::Keyboard_st Code_To_Key(uint16_t TranslatedKeyCode){
            Sauce::IO::Debug::Debugger_st Debugger("Code_To_Key",_NAMESPACE_,_ALLOW_PRINT_);
            uint8_t IPress = (((uint8_t)(TranslatedKeyCode >> 12)) << 4);
            uint8_t ICapital = (((uint8_t)(TranslatedKeyCode >> 8)) << 4);
            uint8_t IKey = ((uint8_t)TranslatedKeyCode);
            bool IVisible = true;
            wchar_t IDisplay = '\0';
            bool Press = (IPress == 0x10);
            bool Capital = (ICapital == 0x10);
            switch(IKey){ // we check if the key is any of the keys that should not be visible.(visible being anything that you could type into a terminal, the key 'm' is visible but the key 'ctrl' is not visible)
                case 0xDA:IVisible = false;break;
                case 0x1E:IVisible = false;break;
                case 0X3A:IVisible = false;break;
                case 0X56:IVisible = false;break;
                case 0x7E:IVisible = false;break;
                case 0x7A:IVisible = false;break;
                case 0x70:IVisible = false;break;
                case 0xD6:IVisible = false;break;
                case 0x1C:IVisible = false;break;
                case 0XDE:IVisible = false;break;
                case 0XE0:IVisible = false;break;
                case 0XE2:IVisible = false;break;
                case 0XE4:IVisible = false;break;
                case 0XE6:IVisible = false;break;
                case 0XE8:IVisible = false;break;
                case 0XEA:IVisible = false;break;
                case 0XEC:IVisible = false;break;
                case 0XEE:IVisible = false;break;
                case 0XF0:IVisible = false;break;
                case 0XF2:IVisible = false;break;
                case 0XF4:IVisible = false;break;
                case 0xCE:IVisible = false;break;
                case 0xC4:IVisible = false;break;
                case 0xC6:IVisible = false;break;
                case 0xF8:IVisible = false;break;
                case 0xB4:IVisible = false;break;
                case 0xB8:IVisible = false;break;
                case 0xCC:IVisible = false;break;
                case 0xC8:IVisible = false;break;
                case 0xD2:IVisible = false;break;
                case 0xBE:IVisible = false;break;
                case 0xCA:IVisible = false;break;
                case 0xC2:IVisible = false;break;
                case 0xB6:IVisible = false;break;
            }
            if(!Capital){
                switch(IKey){// we set the display character for keys that can be visible.
                    case 0x00:IDisplay = L'`';break;
                    case 0x02:IDisplay = L'1';break;
                    case 0x04:IDisplay = L'2';break;
                    case 0x06:IDisplay = L'3';break;
                    case 0x08:IDisplay = L'4';break;
                    case 0x0A:IDisplay = L'5';break;
                    case 0x0C:IDisplay = L'6';break;
                    case 0x0E:IDisplay = L'7';break;
                    case 0x10:IDisplay = L'8';break;
                    case 0x12:IDisplay = L'9';break;
                    case 0x14:IDisplay = L'0';break;
                    case 0x16:IDisplay = L'-';break;
                    case 0x18:IDisplay = L'=';break;
                    case 0x20:IDisplay = L'q';break;
                    case 0x22:IDisplay = L'w';break;
                    case 0x24:IDisplay = L'e';break;
                    case 0x26:IDisplay = L'r';break;
                    case 0x28:IDisplay = L't';break;
                    case 0x2A:IDisplay = L'y';break;
                    case 0x2C:IDisplay = L'u';break;
                    case 0x2E:IDisplay = L'i';break;
                    case 0x30:IDisplay = L'o';break;
                    case 0x32:IDisplay = L'p';break;
                    case 0x34:IDisplay = L'[';break;
                    case 0x36:IDisplay = L']';break;
                    case 0x52:IDisplay = L'\\';break;
                    case 0x3C:IDisplay = L'a';break;
                    case 0x3E:IDisplay = L's';break;
                    case 0x40:IDisplay = L'd';break;
                    case 0x42:IDisplay = L'f';break;
                    case 0x44:IDisplay = L'g';break;
                    case 0x46:IDisplay = L'h';break;
                    case 0x48:IDisplay = L'j';break;
                    case 0x4A:IDisplay = L'k';break;
                    case 0x4C:IDisplay = L'l';break;
                    case 0x4E:IDisplay = L';';break;
                    case 0x50:IDisplay = L'\'';break;
                    case 0x5A:IDisplay = L'z';break;
                    case 0x5C:IDisplay = L'x';break;
                    case 0x5E:IDisplay = L'c';break;
                    case 0x60:IDisplay = L'v';break;
                    case 0x62:IDisplay = L'b';break;
                    case 0x64:IDisplay = L'n';break;
                    case 0x66:IDisplay = L'm';break;
                    case 0x68:IDisplay = L',';break;
                    case 0x6A:IDisplay = L'.';break;
                    case 0xBC:IDisplay = L'/';break;
                    case 0x78:IDisplay = L' ';break;
                }
            }else{
                switch(IKey){// we set the display character for keys that can be visible.
                    case 0x00:IDisplay = L'~';break;
                    case 0x02:IDisplay = L'!';break;
                    case 0x04:IDisplay = L'@';break;
                    case 0x06:IDisplay = L'#';break;
                    case 0x08:IDisplay = L'$';break;
                    case 0x0A:IDisplay = L'%';break;
                    case 0x0C:IDisplay = L'^';break;
                    case 0x0E:IDisplay = L'&';break;
                    case 0x10:IDisplay = L'*';break;
                    case 0x12:IDisplay = L'(';break;
                    case 0x14:IDisplay = L')';break;
                    case 0x16:IDisplay = L'_';break;
                    case 0x18:IDisplay = L'+';break;
                    case 0x20:IDisplay = L'Q';break;
                    case 0x22:IDisplay = L'W';break;
                    case 0x24:IDisplay = L'E';break;
                    case 0x26:IDisplay = L'R';break;
                    case 0x28:IDisplay = L'T';break;
                    case 0x2A:IDisplay = L'Y';break;
                    case 0x2C:IDisplay = L'U';break;
                    case 0x2E:IDisplay = L'I';break;
                    case 0x30:IDisplay = L'O';break;
                    case 0x32:IDisplay = L'P';break;
                    case 0x34:IDisplay = L'{';break;
                    case 0x36:IDisplay = L'}';break;
                    case 0x52:IDisplay = L'|';break;
                    case 0x3C:IDisplay = L'A';break;
                    case 0x3E:IDisplay = L'S';break;
                    case 0x40:IDisplay = L'D';break;
                    case 0x42:IDisplay = L'F';break;
                    case 0x44:IDisplay = L'G';break;
                    case 0x46:IDisplay = L'H';break;
                    case 0x48:IDisplay = L'J';break;
                    case 0x4A:IDisplay = L'K';break;
                    case 0x4C:IDisplay = L'L';break;
                    case 0x4E:IDisplay = L':';break;
                    case 0x50:IDisplay = L'"';break;
                    case 0x5A:IDisplay = L'Z';break;
                    case 0x5C:IDisplay = L'X';break;
                    case 0x5E:IDisplay = L'C';break;
                    case 0x60:IDisplay = L'V';break;
                    case 0x62:IDisplay = L'B';break;
                    case 0x64:IDisplay = L'N';break;
                    case 0x66:IDisplay = L'M';break;
                    case 0x68:IDisplay = L'<';break;
                    case 0x6A:IDisplay = L'>';break;
                    case 0xBC:IDisplay = L'?';break;
                    case 0x78:IDisplay = L' ';break;
                }
            }
            char xDisplay[2]={0};
            xDisplay[0]=IDisplay;
            return {Capital,Press,IVisible,IKey,IDisplay}; // we return a structure of the values which is defined in Keyboard.hpp
        }
    };
};