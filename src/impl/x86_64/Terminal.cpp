#include "Terminal.hpp"

// this file contains stuff to handle the default terminal.
// eventually this will not be needed because userland will be graphical but
// this will be used for now and also for the early boot up.

namespace Sauce{
    namespace Terminal{
        // x = column; y = row;
        const static size_t MAX_X = 80;
        const static size_t MAX_Y = 25;
    	size_t x_pos = 0; 
    	size_t y_pos = 0;
    	uint8_t color = (COLOR_LIGHT_GREEN | COLOR_BLACK << 4);
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
                case '\r':ReturnCaret();break;
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
};