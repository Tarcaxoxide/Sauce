#include "Sauce.hpp"

extern Sauce::Interrupts::IDT64 _idt[256];
extern uint64_t isr1;
extern "C" void loadIDT();

namespace Sauce{
    namespace IO{
        void outb(unsigned short port,unsigned char val){
            asm volatile ("outb %0, %1": : "a"(val), "Nd"(port));
        }
        unsigned char inb(unsigned short port){
            unsigned char Result=NULL;
            asm volatile("inb %1, %0": "=a"(Result): "Nd"(port));
            return Result;
        }
        void RemapPic(){
            uint8_t a1,a2;
            a1 = inb(PIC1_DATA);
            a2 = inb(PIC2_DATA);
            outb(PIC1_COMMAND,ICW1_INIT|ICW1_ICW4);
            outb(PIC2_COMMAND,ICW1_INIT|ICW1_ICW4);
            outb(PIC1_DATA,0);
            outb(PIC2_DATA,8);
            outb(PIC1_DATA,4);
            outb(PIC2_DATA,2);
            outb(PIC1_DATA,ICW4_8086);
            outb(PIC2_DATA,ICW4_8086);

            outb(PIC1_DATA,a1);
            outb(PIC2_DATA,a2);
        }
    };
   
    namespace Interrupts{
        void MapIDT(size_t index,uint64_t &This_isr){
            _idt[index].offset_low = ((uint16_t)(((uint64_t)&This_isr & 0x000000000000ffff)));
			_idt[index].selector = 0x08;
			_idt[index].ist = 0;
			_idt[index].types_attr = 0x8e;
			_idt[index].offset_mid  = ((uint16_t)(((uint64_t)&This_isr & 0x00000000ffff0000) >> 16));
			_idt[index].offset_high = ((uint32_t)(((uint64_t)&This_isr & 0xffffffff00000000) >> 32));
			_idt[index].zero = 0;
        }
        void InitializeIDT(){
            MapIDT(1,isr1);
            Sauce::IO::RemapPic();
            Sauce::IO::outb(0x21,0xfd);
            Sauce::IO::outb(0xa1,0xff);
            loadIDT();
        }

        extern "C" void isr1_handler(){
            uint8_t input = 0;
            do {
              if(Sauce::IO::inb(0x60) != input) {
                input = Sauce::IO::inb(0x60);

                if(input > 0) {
                    uint16_t Xinput = Sauce::Keyboard::Translate_KeyCode(input);
                    if(Xinput != NULL){
                        Sauce::Keyboard::KeyboardKey Xkey = Sauce::Keyboard::CodeToKey(Xinput);
                        if(Xkey.Key != NULL)NotifyKernelOfKeyPress(Xkey);
                    }
                }
              }
            } while(input != 0);

            Sauce::IO::outb(0x20,0x20);
            Sauce::IO::outb(0xa0,0x20);
        }
    };
    namespace Terminal{
        // x = column; y = row;
        const static size_t MAX_X = 80;
        const static size_t MAX_Y = 25;
    	size_t x_pos = 0; 
    	size_t y_pos = 0;
    	uint8_t color = (COLOR_LIGHT_GREEN | COLOR_BLACK << 4);
    };

    namespace Terminal{
        void Fill(char character){
            for (size_t a = 0;(a < MAX_Y);a++){
                FillRow(a,character);
            }
        }
        void Clear(){
            Fill(' ');
            SetCursor();
        }
        void FillRow(size_t Row,char character){
            for(size_t a = 0;(a < MAX_X);a++){
                SetCharacterAt(a,Row,character);
            }
        }
        void FillColumn(size_t column,char character){
            for(size_t a = 0;(a < MAX_X);a++){
                SetCharacterAt(column,a,character);
            }
        }
        void ClearRow(size_t Row){
            FillRow(Row,' ');
        }
        void Character(char character){
            switch(character){
                case '\n':NewLine();break;
                case '\r':x_pos = 0;break;
                default:SetCharacterAt(x_pos++,y_pos,character);break;
            }
            if(x_pos > MAX_X){
                NewLine();
                ReturnCaret();
            }
            SetCursor();   
        }
        void SetCharacterAt(size_t X,size_t Y,char character){
            struct Char FillChar = ((struct Char){(uint8_t)character,color});
            buffer[(X + MAX_X * Y)] = FillChar;
        }
        void SetCharacterAt(size_t X,size_t Y,Char character){
            buffer[(X + MAX_X * Y)] = character;
        }
        Char GetCharacterAt(size_t X,size_t Y){
            return buffer[(X + MAX_X * Y)];
        }
        void String(char* string){
            size_t stringLen = StringLength(string);
            for(size_t a = 0;(a < stringLen);a++){
                Character(string[a]);
            }
        }
        void Setcolor(uint8_t foreground,uint8_t background){
            color = (foreground + (background << 4));
        }
        size_t StringLength(char* string){
            size_t Result = 0;
            for(Result = 0;string[Result] != '\0';Result++);
            return Result;
        }
        void NewLine(){
            if(y_pos < MAX_Y -1){
                y_pos++;
            }else{
                for(size_t row = 1;(row < MAX_Y);row++){
                    for(size_t col = 0;(col < MAX_X);col++){
                        SetCharacterAt(col,(row-1),GetCharacterAt(col,row));
                    }
                }
                ClearRow(MAX_Y);
            }
            SetCursor();
        }
        void ReturnCaret(){
            x_pos = 0;
            SetCursor();
        }
        void SetCursor(bool adjust,size_t X, size_t Y){
            if(adjust){
                x_pos=X;
                y_pos=Y;
            }
            SetRealCursor(x_pos,y_pos);
        }
        void RelativeSetCursor(bool adjust,long int X, long int Y){
            if(adjust){
                x_pos+=X;
                y_pos+=Y;
            }
            SetRealCursor(x_pos,y_pos);
        }
        void SetRealCursor(size_t X,size_t Y){
            size_t position=(X + MAX_X * Y);
            Sauce::IO::outb(0x3D4, 0x0F);
            Sauce::IO::outb(0x3D5,(unsigned char)position & 0xFF);
            Sauce::IO::outb(0x3D4,0x0E);
            Sauce::IO::outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
        }
        void BackSpace(){
            if(x_pos > 0){
                x_pos--;
                Character(' ');
                x_pos--;
                SetCursor();
            }else if(y_pos > 0){
                y_pos--;
                for(x_pos = MAX_X;IsSpace();x_pos--);
                x_pos++;
                SetCursor();
            }
        }
        bool IsSpace(){
            return (GetCharacterAt(x_pos,y_pos).character == ' ');
        }
    };

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
                    if(KeyMapCodes[I] == KeyCode){
                        if(!(I % 2))X = 0x1000;
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
                    KeyCodeDecoded += 0x0100;
                }
                return KeyCodeDecoded;
            }



            KeyboardKey CodeToKey(uint16_t TranslatedKeyCode){
                uint8_t IPress = (((uint8_t)(TranslatedKeyCode >> 12)) << 4);
                uint8_t ICapital = (((uint8_t)(TranslatedKeyCode >> 8)) << 4);
                uint8_t IKey = ((uint8_t)TranslatedKeyCode);
                bool IVisible = true;
                char IDisplay = NULL;
                bool Press = (IPress == 0x10);
                bool Capital = (ICapital == 0x10);

                switch(IKey){
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
                }
                if(!Capital){
                    switch(IKey){
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
                    switch(IKey){
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
                return {Capital,Press,IVisible,IKey,IDisplay};
            }
    };

    namespace Convert{
        namespace To_String{
            char hxString[512] = {0};
            void Clear_hxString(){
                for(size_t a = 0;(a < 512);a++){
                    hxString[a] = 0;
                }
            }
            char* From_uint8(uint8_t value){
                Clear_hxString();
                uint8_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint8_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    hxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return hxString;
            }
            char* From_uint16(uint16_t value){
                Clear_hxString();
                uint16_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint16_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    hxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return hxString;
            }
            char* From_uint32(uint32_t value){
                Clear_hxString();
                uint32_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint32_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    hxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return hxString;
            }
            char* From_uint64(uint64_t value){
                Clear_hxString();
                uint64_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint64_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    hxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return hxString;
            }

			char* From_Integer(uint64_t value){
                Clear_hxString();
                uint8_t size = 0;
                uint64_t sizeTester = (uint64_t)value;
                while(sizeTester / 10 > 0){
                    sizeTester /= 10;
                    size++;
                }
                uint8_t index = 0;
                uint64_t newValue = (uint64_t)value;
                while(newValue / 10 > 0){
                    uint8_t remainder = (newValue % 10);
                    newValue /= 10;
                    hxString[size - index] = (remainder + 48);
                    index++;
                }
                uint8_t remainder = (newValue % 10);
                hxString[size - index] = (remainder + 48);
                return hxString;
            }
        };
        
    };
};
