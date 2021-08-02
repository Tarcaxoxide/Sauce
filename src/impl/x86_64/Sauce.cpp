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
            outb(PIC1_COMMAND, ICW1_INIT|ICW1_ICW4);
            outb(PIC2_COMMAND, ICW1_INIT|ICW1_ICW4);
            outb(PIC1_DATA,0);
            outb(PIC2_DATA,8);
            outb(PIC1_DATA, 4);
            outb(PIC2_DATA, 2);
            outb(PIC1_DATA, ICW4_8086);
            outb(PIC2_DATA, ICW4_8086);

            outb(PIC1_DATA,a1);
            outb(PIC2_DATA,a2);
        }
    };
   
    namespace Interrupts{
        void MapIDT(size_t index,uint64_t &This_isr){
            _idt[index].offset_low = (uint16_t)(((uint64_t)&This_isr & 0x000000000000ffff));
			_idt[index].selector = 0x08;
			_idt[index].ist = 0;
			_idt[index].types_attr = 0x8e;
			_idt[index].offset_mid  = (uint16_t)(((uint64_t)&This_isr & 0x00000000ffff0000) >> 16);
			_idt[index].offset_high = (uint32_t)(((uint64_t)&This_isr & 0xffffffff00000000) >> 32);
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
            //Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(Sauce::IO::inb(0x60)));

            uint8_t input = 0;
            
            do {
              if(Sauce::IO::inb(0x60) != input) {
                input = Sauce::IO::inb(0x60);

                if(input > 0) {
                    uint16_t Xinput = Sauce::Convert::To_uint16::From_KeyCode(input);
                  Sauce::Terminal::String(Sauce::Convert::To_String::From_uint16(Xinput));
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
                ReturnCaret();
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
                ClearRow(MAX_Y);
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

    namespace Keyboard{
        struct Keyboard_KeyPair{
            uint8_t Make_Code=0x00;
            uint8_t Break_Code=0x00;
            char KeyName[64];
        };
        const size_t KeyCount=126;
        Keyboard_KeyPair Keyboard_Map[KeyCount];


        void Register_Keyboard_KeyPair(size_t KeyIndex,uint8_t Make_Code,uint8_t Break_Code,char* KeyName){
            size_t KeyNameSize=Sauce::Terminal::StringLength(KeyName);
            Keyboard_KeyPair New_Keyboard_KeyPair;
            for(size_t I=0;(I<KeyNameSize && I<64);I++){
                New_Keyboard_KeyPair.KeyName[I]=KeyName[I];
            }
            
            New_Keyboard_KeyPair.Make_Code=Make_Code;
            New_Keyboard_KeyPair.Break_Code=Break_Code;
            Keyboard_Map[KeyIndex]=New_Keyboard_KeyPair;
        }
    };

    namespace Convert{
        namespace To_uint16{
            uint16_t From_KeyCode(uint8_t KeyCode,size_t KeySet){
                static bool isShift;
                static bool isCaps;
                uint16_t KeyCodeDecoded=404;
                uint8_t* KeyMapCodes=NULL;
                switch(KeySet){
                    case 1: KeyMapCodes=(uint8_t*)&KeyMapCodes_1;break;

                }

                for(size_t I=0;I<250;I++){
                    if(KeyMapCodes[I] == KeyCode){
                        uint16_t X=0;
                        if((I%2))X=0x1000;
                        X+=(uint16_t)(I-(I%2));
                        KeyCodeDecoded=X;
                    }
                }
                if(KeyCodeDecoded == 0x103A){
                    isCaps=!isCaps;
                }
                if(KeyCodeDecoded == 0x0056){
                    isShift=true;
                }
                if(KeyCodeDecoded == 0x1056){
                    isShift=false;
                }
                if(isCaps != isShift){
                    KeyCodeDecoded+=0x0100;
                }
                return KeyCodeDecoded;
            }
        };
        namespace To_String{
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

