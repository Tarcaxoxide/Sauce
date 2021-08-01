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
    };
    namespace Interrupts{
        
    };
    namespace Interrupts{
        void InitializeIDT(){
            for(uint64_t t = 0;t<256;t++){
                _idt[t].offset_low = (uint16_t)(((uint64_t)&isr1 & 0x000000000000ffff));
			    _idt[t].selector = 0x08;
			    _idt[t].ist = 0;
			    _idt[t].types_attr = 0x8e;
			    _idt[t].offset_mid  = (uint16_t)(((uint64_t)&isr1 & 0x00000000ffff0000) >> 16);
			    _idt[t].offset_high = (uint32_t)(((uint64_t)&isr1 & 0xffffffff00000000) >> 32);
			    _idt[t].zero = 0;
            }
            Sauce::IO::outb(0x21,0xfd);
            Sauce::IO::outb(0xa1,0xff);
            loadIDT();
        }

        extern "C" void isr1_handler(){
            //Sauce::Terminal::String(Sauce::Convert::ToString::From_uint8(Sauce::IO::inb(0x60)));

            uint8_t input = 0;
            
            do {
              if(Sauce::IO::inb(0x60) != input) {
                input = Sauce::IO::inb(0x60);

                if(input > 0) {
                  Sauce::Terminal::String(Sauce::Convert::ToString::From_uint8(input));
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
    	size_t x_pos =0; 
    	size_t y_pos = 0;
    	uint8_t color = COLOR_LIGHT_GREEN|COLOR_BLACK << 4;
    };

    namespace Terminal{
        void Fill(char character){
            for (size_t a=0;a<MAX_Y;a++){
                FillRow(a,character);
            }
        }
        void Clear(){
            Fill(' ');
            SetCursor();
        }
        void FillRow(size_t Row,char character){
            for(size_t a=0;a<MAX_X;a++){
                SetCharacterAt(a,Row,character);
            }
        }
        void FillColumn(size_t column,char character){
            for(size_t a=0;a<MAX_X;a++){
                SetCharacterAt(column,a,character);
            }
        }
        void ClearRow(size_t Row){
            FillRow(Row,' ');
        }
        void Character(char character){
            switch(character){
                case '\n':{
                    NewLine();
                }break;
                case '\r':{
                    x_pos=0;
                }break;
                default:{
                    SetCharacterAt(x_pos++,y_pos,character);
                }break;
            }
            if(x_pos > MAX_X){
                    NewLine();
                }
                SetCursor();
        }
        void SetCharacterAt(size_t X,size_t Y,char character){
            struct Char FillChar = {(uint8_t)character,color};
            buffer[X+MAX_X*Y] = FillChar;
        }
        void SetCharacterAt(size_t X,size_t Y,Char character){
            buffer[X+MAX_X*Y] = character;
        }
        Char GetCharacterAt(size_t X,size_t Y){
            return buffer[X+MAX_X*Y];
        }
        void String(char* string){
            size_t stringLen = StringLength(string);
            for(size_t a=0;a<stringLen;a++){
                Character(string[a]);
            }
        }
        void Setcolor(uint8_t foreground,uint8_t background){
            color = foreground + (background << 4);
        }
        size_t StringLength(char* string){
            size_t Result=0;
            for(Result=0;string[Result] != '\0';Result++);
            return Result;
        }
        void NewLine(){
            if(y_pos < MAX_Y -1){
                y_pos++;
            }else{
                for(size_t row=1;row<MAX_Y;row++){
                    for(size_t col=0;col<MAX_X;col++){
                        SetCharacterAt(col,(row-1),GetCharacterAt(col,row));
                    }
                }
                ClearRow(MAX_X);
            }
            SetCursor();
        }
        void ReturnCaret(){
            x_pos=0;
            SetCursor();
        }
        void SetCursor(bool adjust,size_t X, size_t Y){
            if(adjust){
                x_pos=X;
                y_pos=Y;
            }
            SetRealCursor(x_pos,y_pos);
        }
        void SetRealCursor(size_t X,size_t Y){
            size_t position=(X+MAX_X*Y);
            Sauce::IO::outb(0x3D4, 0x0F);
            Sauce::IO::outb(0x3D5,(unsigned char)position & 0xFF);
            Sauce::IO::outb(0x3D4,0x0E);
            Sauce::IO::outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
        }
    };

    namespace Convert{
        namespace ToString{
            char hxString[256]={0};
            char* From_uint8(uint8_t value){
                for(size_t a=0;a<256;a++){
                    hxString[a]=0;
                }
                uint8_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = (sizeof(uint8_t)*2)-1;
                uint8_t i;
                for(i=0;i<size;i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[size - (i * 2 + 1)]= temp + (temp > 9 ? 55 : 48);
                    temp = ((*ptr & 0x0F));
                    hxString[size - (i * 2 + 0)]= temp + (temp > 9 ? 55 : 48);
                }
                return hxString;
            }
            char* From_uint16(uint16_t value){
                for(size_t a=0;a<256;a++){
                    hxString[a]=0;
                }
                uint16_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = (sizeof(uint16_t)*2)-1;
                uint8_t i;
                for(i=0;i<size;i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[size - (i * 2 + 1)]= temp + (temp > 9 ? 55 : 48);
                    temp = ((*ptr & 0x0F));
                    hxString[size - (i * 2 + 0)]= temp + (temp > 9 ? 55 : 48);
                }
                return hxString;
            }
            char* From_uint32(uint32_t value){
                for(size_t a=0;a<256;a++){
                    hxString[a]=0;
                }
                uint32_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = (sizeof(uint32_t)*2)-1;
                uint8_t i;
                for(i=0;i<size;i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[size - (i * 2 + 1)]= temp + (temp > 9 ? 55 : 48);
                    temp = ((*ptr & 0x0F));
                    hxString[size - (i * 2 + 0)]= temp + (temp > 9 ? 55 : 48);
                }
                return hxString;
            }
            char* From_uint64(uint64_t value){
                for(size_t a=0;a<256;a++){
                    hxString[a]=0;
                }
                uint64_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = (sizeof(uint64_t)*2)-1;
                uint8_t i;
                for(i=0;i<size;i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    hxString[size - (i * 2 + 1)]= temp + (temp > 9 ? 55 : 48);
                    temp = ((*ptr & 0x0F));
                    hxString[size - (i * 2 + 0)]= temp + (temp > 9 ? 55 : 48);
                }
                return hxString;
            }
        };
        
    };
};
