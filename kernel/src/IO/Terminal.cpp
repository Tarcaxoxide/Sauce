#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/Memory.hpp>

namespace Sauce{
    namespace IO{
        Terminal::Terminal(DataStructure* DFBL){
            this->DFBL=DFBL;
            Fcolor=GOP_GREEN;
            Bcolor={0x33,0x22,0x22,0xFF};
        }
        void Terminal::PutChar(const char chr){
            switch(chr){
                case '\n':NewLine();break;
                case '\r':ReturnCaret();break;
                case '\b':BackSpace();break;
                default:{
                    unsigned int* pixPtr = (unsigned int*)DFBL->FrameBuffer->BaseAddress;
                    char* fontPtr = (char*)DFBL->Font->glyphBuffer + (chr * DFBL->Font->psf1_header->char_size);
                    for(unsigned long Y=Cursor.Y;Y < Cursor.Y+CharY();Y++){
                        for(unsigned long X=Cursor.X;X<Cursor.X+CharX();X++){
                            if((*fontPtr & (0b10000000 >>(X-Cursor.X)))>0){
                                DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Fcolor;
                            }else{
                                DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Bcolor;
                            }
                        }
                        fontPtr++;
                    }
                    Cursor.X+=CharX();
                    break;}
            }
            if(Cursor.X+CharX() > DFBL->FrameBuffer->PixelsPerScanLine){
                NewLine();
                ReturnCaret();
            }
        }
        void Terminal::PlaceMouse(size_t _X,size_t _Y){
            size_t BufferX=0,BufferY=0;
            for(unsigned long Y=_Y;Y < _Y+CharY();Y++){
                for(unsigned long X=_X;X<_X+CharX();X++){
                    DoubleBuffer[(BufferX + DFBL->FrameBuffer->PixelsPerScanLine * BufferY)] = DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))];
                    GOP_PixelStructure nPixel;
                    nPixel.Red = (0xFF)-DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))].Red;
                    nPixel.Green = (0xFF)-DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))].Green;
                    nPixel.Blue = (0xFF)-DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))].Blue;
                    nPixel.Alpha = DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))].Alpha;
                    DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = nPixel;
                    BufferX++;
                }
                BufferY++;
                BufferX=0;
            }
        }
        void Terminal::RemoveMouse(size_t _X,size_t _Y){
            size_t BufferX=0,BufferY=0;
            for(unsigned long Y=_Y;Y < _Y+CharY();Y++){
                for(unsigned long X=_X;X<_X+CharX();X++){
                    DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = DoubleBuffer[(BufferX + DFBL->FrameBuffer->PixelsPerScanLine * BufferY)];
                    BufferX++;
                }
                BufferY++;
                BufferX=0;
            }
        }
        void Terminal::PutCharAt(const char chr,size_t X,size_t Y){
            SetCursor(X,Y);
            PutChar(chr);
        }
        void Terminal::PutString(const char* str){
            DisableMouse=true;
            while(*str){
                PutChar(*str);
                str++;
                //Cursor.X+=CharX();
            }
            DisableMouse=false;
        }
        void Terminal::NewLine(){
            if(!DownwardChar()){
                // TODO::scroll text.
            }
        }
        bool Terminal::ForwardChar(){
            if(Cursor.X+CharX() > MaxX(CharX()))return false;
            Cursor.X+=CharX();
            return true;
        }
        bool Terminal::BackwardChar(){
            if(Cursor.X-CharX() < 0)return false;
            Cursor.X-=CharX();
            return true;
        }
        bool Terminal::UpwardChar(){
            if(Cursor.Y-CharY() < 0)return false;
            Cursor.Y-=CharY();
            return true;
        }
        bool Terminal::DownwardChar(){
            if(Cursor.Y+CharY() > MaxY(CharY()))return false;
            Cursor.Y+=CharY();
            return true;
        }
        void Terminal::TopChar(){
            Cursor.Y=0;
        }
        void Terminal::BottomChar(){
            Cursor.Y=MaxY(CharY());
        }
        void Terminal::FrontChar(){
            Cursor.X=0;
        }
        void Terminal::BackChar(){
            Cursor.X=MaxX(CharX());
        }
        void Terminal::ReturnCaret(){
            FrontChar();
        }
        void Terminal::BackSpace(){
            if(!BackwardChar()){
                if(UpwardChar())BackChar();
            }
            PutChar(' ');
            if(!BackwardChar()){
                if(UpwardChar())BackChar();
            }
        }
        void Terminal::Clear(){
            DisableMouse=true;
            Fill(' ');
            SetCursor(0,0);
            DisableMouse=false;
        }
        void Terminal::FillRow(const char chr,size_t Row){
            DisableMouse=true;
            for(size_t X=0;X<MaxX(CharX()/2);X+=CharX()){
               PutCharAt(chr,X,Row);
            }
            DisableMouse=false;
        }
        void Terminal::FillColumn(const char chr,size_t Column){
            DisableMouse=true;
            for(size_t Y=0;Y<MaxY(CharY()/2);Y+=CharY()){
                PutCharAt(chr,Column,Y);
            }
            DisableMouse=false;
        }
        void Terminal::Fill(const char chr){
            DisableMouse=true;
            for(size_t X=0;X<MaxX(CharX()/2);X+=CharX()){
               FillColumn(chr,X);
            }
            DisableMouse=false;
        }
        void Terminal::SetColor(GOP_PixelStructure Fcolor,GOP_PixelStructure Bcolor){
            this->Fcolor=Fcolor;
            this->Bcolor=Bcolor;
        }
        void Terminal::SetColor(GOP_PixelStructure Fcolor){
            SetColor(Fcolor,Bcolor);
        }
        void Terminal::SetCursor(size_t X,size_t Y){
            Cursor.X=X;
            Cursor.Y=Y;
        }
        uint64_t Terminal::MaxY(uint64_t Margin){
            return (uint64_t)DFBL->FrameBuffer->Height-Margin;
        }
        uint64_t Terminal::MaxX(uint64_t Margin){
            return (uint64_t)DFBL->FrameBuffer->PixelsPerScanLine-Margin;
        }
        uint8_t Terminal::CharX(){
            return (uint8_t)DFBL->Font->psf1_header->char_width;
        }
        uint8_t Terminal::CharY(){
            return (uint8_t)DFBL->Font->psf1_header->char_height;
        }
        void Terminal::Mouse(Point64_t* NewMousePosition){
            if(OldMousePosition.Z)RemoveMouse(OldMousePosition.X,OldMousePosition.Y);//< if this isn't the first time then remove the old mouse first.
            PlaceMouse(NewMousePosition->X,NewMousePosition->Y);
            OldMousePosition.Z=1;//<using Z to determine of this is the first time we have been here.
            OldMousePosition.Y=NewMousePosition->Y;
            OldMousePosition.X=NewMousePosition->X;
        }
        Terminal* GlobalTerminal;
        const GOP_PixelStructure GOP_RED={0x00,0x00,0xff,0xff};
        const GOP_PixelStructure GOP_GREEN={0x00,0xff,0x00,0xff};
        const GOP_PixelStructure GOP_BLUE={0xff,0x00,0x00,0xff};
        const GOP_PixelStructure GOP_YELLOW={0x00,0xff,0xff,0xff};
        const GOP_PixelStructure GOP_PURPLE={0xff,0x00,0xff,0xff};
        const GOP_PixelStructure GOP_CYAN={0xff,0xff,0x00,0xff};
        const GOP_PixelStructure GOP_WHITE={0xff,0xff,0xff,0xff};
        const GOP_PixelStructure GOP_BLACK={0x00,0x00,0x00,0xff};
    };
};