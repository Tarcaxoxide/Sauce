#include<Sauce/IO/Terminal.hpp>
namespace Sauce{
    namespace IO{
        GOP_PixelStructure* Terminal::DoubleBuffer;
        Terminal::Terminal(DataStructure* DFBL){
            this->DFBL=DFBL;
            Fcolor=GOP_GREEN;
            Bcolor={0x33,0x22,0x22,0xFF};
            DoubleBuffer[DFBL->Font->psf1_header->char_height*DFBL->Font->psf1_header->char_width];
        }
        void Terminal::PutChar(char chr){
            switch(chr){
                case '\n':NewLine();break;
                case '\r':ReturnCaret();break;
                case '\b':BackSpace();break;
                default:{
                    unsigned int* pixPtr = (unsigned int*)DFBL->FrameBuffer->BaseAddress;
                    char* fontPtr = (char*)DFBL->Font->glyphBuffer + (chr * DFBL->Font->psf1_header->char_size);
                    for(unsigned long Y=Cursor.Y;Y < Cursor.Y+DFBL->Font->psf1_header->char_height;Y++){
                        for(unsigned long X=Cursor.X;X<Cursor.X+DFBL->Font->psf1_header->char_width;X++){
                            if((*fontPtr & (0b10000000 >>(X-Cursor.X)))>0){
                                DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Fcolor;
                            }else{
                                DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Bcolor;
                            }
                        }
                        fontPtr++;
                    }
                    Cursor.X+=DFBL->Font->psf1_header->char_width;
                    break;}
            }
            if(Cursor.X+DFBL->Font->psf1_header->char_width > DFBL->FrameBuffer->PixelsPerScanLine){
                NewLine();
                ReturnCaret();
            }
        }
        void Terminal::PlaceMouse(size_t _X,size_t _Y){
            size_t BufferX=0,BufferY=0;
            for(unsigned long Y=_Y;Y < _Y+DFBL->Font->psf1_header->char_height;Y++){
                for(unsigned long X=_X;X<_X+DFBL->Font->psf1_header->char_width;X++){
                    DoubleBuffer[(BufferX + DFBL->FrameBuffer->PixelsPerScanLine * BufferY)] = DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))];
                    DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Fcolor;
                    BufferX++;
                }
                BufferY++;
                BufferX=0;
            }
        }
        void Terminal::RemoveMouse(size_t _X,size_t _Y){
            size_t BufferX=0,BufferY=0;
            for(unsigned long Y=_Y;Y < _Y+DFBL->Font->psf1_header->char_height;Y++){
                for(unsigned long X=_X;X<_X+DFBL->Font->psf1_header->char_width;X++){
                    DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = DoubleBuffer[(BufferX + DFBL->FrameBuffer->PixelsPerScanLine * BufferY)];
                    BufferX++;
                }
                BufferY++;
                BufferX=0;
            }
        }
        void Terminal::PutCharAt(char chr,size_t X,size_t Y){
            SetCursor(X,Y);
            PutChar(chr);
        }
        void Terminal::PutString(char* str){
            while(*str){
                PutChar(*str);
                str++;
                //Cursor.X+=DFBL->Font->psf1_header->char_width;
            }
        }
        void Terminal::NewLine(){
            Cursor.Y+=DFBL->Font->psf1_header->char_height;
        }
        void Terminal::ReturnCaret(){
            Cursor.X=0;
        }
        void Terminal::BackSpace(){
            Cursor.X-=DFBL->Font->psf1_header->char_width;
            PutChar(' ');
            Cursor.X-=DFBL->Font->psf1_header->char_width;
        }
        void Terminal::Clear(){
            Fill(' ');
        }
        void Terminal::FillRow(char chr,size_t Row){
            //for(size_t X=0;X<DFBL->FrameBuffer->PixelsPerScanLine-DFBL->Font->psf1_header->char_width;X+=DFBL->Font->psf1_header->char_width){
            for(size_t X=0;X<MaxX((uint64_t)DFBL->Font->psf1_header->char_width);X+=DFBL->Font->psf1_header->char_width){
               PutCharAt(chr,X,Row);
            }
        }
        void Terminal::FillColumn(char chr,size_t Column){
            //for(size_t Y=0;Y<DFBL->FrameBuffer->Height-DFBL->Font->psf1_header->char_height;Y+=DFBL->Font->psf1_header->char_height){
            for(size_t Y=0;Y<MaxY(DFBL->Font->psf1_header->char_height);Y+=DFBL->Font->psf1_header->char_height){
                PutCharAt(chr,Column,Y);
            }
        }
        void Terminal::Fill(char chr){
            //for(size_t X=0;X<DFBL->FrameBuffer->Width-DFBL->Font->psf1_header->char_width;X+=DFBL->Font->psf1_header->char_width){
            for(size_t X=0;X<MaxX((uint64_t)DFBL->Font->psf1_header->char_width);X+=DFBL->Font->psf1_header->char_width){
               FillColumn(chr,X);
            }
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
        void Terminal::Mouse(Point64_t NewMousePosition){
            if(NewMousePosition.X < 0)NewMousePosition.X=0;
            if(NewMousePosition.Y < 0)NewMousePosition.Y=0;
            if(NewMousePosition.X > MaxX(CharX()))NewMousePosition.X=MaxX(CharX());
            if(NewMousePosition.Y > MaxY(CharY()))NewMousePosition.Y=MaxY(CharY());
            
            RemoveMouse(OldMousePosition.X,OldMousePosition.Y);
            PlaceMouse(NewMousePosition.X,NewMousePosition.Y);
            OldMousePosition.Z=NewMousePosition.Z;
            OldMousePosition.Y=NewMousePosition.Y;
            OldMousePosition.X=NewMousePosition.X;
        }
        Terminal* GlobalTerminal;
    };
};