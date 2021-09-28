#include "Keyboard.hpp"

// this file contains stuff for the keyboard. like keycode conversion.
// it also uses a custom type 'KeyboardKey'

namespace Sauce{
    namespace Keyboard{
        uint16_t Translate_KeyCode(uint8_t KeyCode,size_t KeySet){
                static bool isShift;
                static bool isCaps;
                uint8_t* KeyMapCodes = NULL;
                uint16_t KeyCodeDecoded = NULL;
              
              
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
        KeyboardKey Code_To_Key(uint16_t TranslatedKeyCode){
            uint8_t IPress = (((uint8_t)(TranslatedKeyCode >> 12)) << 4);
            uint8_t ICapital = (((uint8_t)(TranslatedKeyCode >> 8)) << 4);
            uint8_t IKey = ((uint8_t)TranslatedKeyCode);
            bool IVisible = true;
            char IDisplay = NULL;
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
                    case 0x00:IDisplay = '`';break;
                    case 0x02:IDisplay = '1';break;
                    case 0x04:IDisplay = '2';break;
                    case 0x06:IDisplay = '3';break;
                    case 0x08:IDisplay = '4';break;
                    case 0x0A:IDisplay = '5';break;
                    case 0x0C:IDisplay = '6';break;
                    case 0x0E:IDisplay = '7';break;
                    case 0x10:IDisplay = '8';break;
                    case 0x12:IDisplay = '9';break;
                    case 0x14:IDisplay = '0';break;
                    case 0x16:IDisplay = '-';break;
                    case 0x18:IDisplay = '=';break;
                    case 0x20:IDisplay = 'q';break;
                    case 0x22:IDisplay = 'w';break;
                    case 0x24:IDisplay = 'e';break;
                    case 0x26:IDisplay = 'r';break;
                    case 0x28:IDisplay = 't';break;
                    case 0x2A:IDisplay = 'y';break;
                    case 0x2C:IDisplay = 'u';break;
                    case 0x2E:IDisplay = 'i';break;
                    case 0x30:IDisplay = 'o';break;
                    case 0x32:IDisplay = 'p';break;
                    case 0x34:IDisplay = '[';break;
                    case 0x36:IDisplay = ']';break;
                    case 0x52:IDisplay = '\\';break;
                    case 0x3C:IDisplay = 'a';break;
                    case 0x3E:IDisplay = 's';break;
                    case 0x40:IDisplay = 'd';break;
                    case 0x42:IDisplay = 'f';break;
                    case 0x44:IDisplay = 'g';break;
                    case 0x46:IDisplay = 'h';break;
                    case 0x48:IDisplay = 'j';break;
                    case 0x4A:IDisplay = 'k';break;
                    case 0x4C:IDisplay = 'l';break;
                    case 0x4E:IDisplay = ';';break;
                    case 0x50:IDisplay = '\'';break;
                    case 0x5A:IDisplay = 'z';break;
                    case 0x5C:IDisplay = 'x';break;
                    case 0x5E:IDisplay = 'c';break;
                    case 0x60:IDisplay = 'v';break;
                    case 0x62:IDisplay = 'b';break;
                    case 0x64:IDisplay = 'n';break;
                    case 0x66:IDisplay = 'm';break;
                    case 0x68:IDisplay = ',';break;
                    case 0x6A:IDisplay = '.';break;
                    case 0xBC:IDisplay = '/';break;
                    case 0x78:IDisplay = ' ';break;
                }
            }else{
                switch(IKey){// we set the display character for keys that can be visible.
                    case 0x00:IDisplay = '~';break;
                    case 0x02:IDisplay = '!';break;
                    case 0x04:IDisplay = '@';break;
                    case 0x06:IDisplay = '#';break;
                    case 0x08:IDisplay = '$';break;
                    case 0x0A:IDisplay = '%';break;
                    case 0x0C:IDisplay = '^';break;
                    case 0x0E:IDisplay = '&';break;
                    case 0x10:IDisplay = '*';break;
                    case 0x12:IDisplay = '(';break;
                    case 0x14:IDisplay = ')';break;
                    case 0x16:IDisplay = '_';break;
                    case 0x18:IDisplay = '+';break;
                    case 0x20:IDisplay = 'Q';break;
                    case 0x22:IDisplay = 'W';break;
                    case 0x24:IDisplay = 'E';break;
                    case 0x26:IDisplay = 'R';break;
                    case 0x28:IDisplay = 'T';break;
                    case 0x2A:IDisplay = 'Y';break;
                    case 0x2C:IDisplay = 'U';break;
                    case 0x2E:IDisplay = 'I';break;
                    case 0x30:IDisplay = 'O';break;
                    case 0x32:IDisplay = 'P';break;
                    case 0x34:IDisplay = '{';break;
                    case 0x36:IDisplay = '}';break;
                    case 0x52:IDisplay = '|';break;
                    case 0x3C:IDisplay = 'A';break;
                    case 0x3E:IDisplay = 'S';break;
                    case 0x40:IDisplay = 'D';break;
                    case 0x42:IDisplay = 'F';break;
                    case 0x44:IDisplay = 'G';break;
                    case 0x46:IDisplay = 'H';break;
                    case 0x48:IDisplay = 'J';break;
                    case 0x4A:IDisplay = 'K';break;
                    case 0x4C:IDisplay = 'L';break;
                    case 0x4E:IDisplay = ':';break;
                    case 0x50:IDisplay = '"';break;
                    case 0x5A:IDisplay = 'Z';break;
                    case 0x5C:IDisplay = 'X';break;
                    case 0x5E:IDisplay = 'C';break;
                    case 0x60:IDisplay = 'V';break;
                    case 0x62:IDisplay = 'B';break;
                    case 0x64:IDisplay = 'N';break;
                    case 0x66:IDisplay = 'M';break;
                    case 0x68:IDisplay = '<';break;
                    case 0x6A:IDisplay = '>';break;
                    case 0xBC:IDisplay = '?';break;
                    case 0x78:IDisplay = ' ';break;
                }
            }
            return {Capital,Press,IVisible,IKey,IDisplay}; // we return a structure of the values which is defined in Keyboard.hpp
        }
    };
};