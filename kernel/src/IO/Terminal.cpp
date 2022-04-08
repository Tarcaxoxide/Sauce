#include<Sauce/IO/Terminal.hpp>
namespace Sauce{
    namespace IO{
        Terminal::Terminal(DataStructure* DFBL){
            this->DFBL=DFBL;
            Fcolor=GOP_GREEN;
            Bcolor={0x33,0x22,0x22,0xFF};
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
            DisableMouse=true;
            while(*str){
                PutChar(*str);
                str++;
                //Cursor.X+=DFBL->Font->psf1_header->char_width;
            }
            DisableMouse=false;
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
            DisableMouse=true;
            Fill(' ');
            SetCursor(0,0);
            DisableMouse=false;
        }
        void Terminal::FillRow(char chr,size_t Row){
            DisableMouse=true;
            for(size_t X=0;X<MaxX(DFBL->Font->psf1_header->char_width/2);X+=DFBL->Font->psf1_header->char_width){
               PutCharAt(chr,X,Row);
            }
            DisableMouse=false;
        }
        void Terminal::FillColumn(char chr,size_t Column){
            DisableMouse=true;
            for(size_t Y=0;Y<MaxY(DFBL->Font->psf1_header->char_height/2);Y+=DFBL->Font->psf1_header->char_height){
                PutCharAt(chr,Column,Y);
            }
            DisableMouse=false;
        }
        void Terminal::Fill(char chr){
            DisableMouse=true;
            for(size_t X=0;X<MaxX(DFBL->Font->psf1_header->char_width/2);X+=DFBL->Font->psf1_header->char_width){
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
        void Terminal::Mouse(Point64_t NewMousePosition){
            if(DisableMouse)return;
            if(NewMousePosition.X < 0)NewMousePosition.X=0;//< Don't draw the mouse too far to the right.
            if(NewMousePosition.Y < 0)NewMousePosition.Y=0;//< Don't draw the mouse too high up.
            if(NewMousePosition.X > MaxX(CharX()))NewMousePosition.X=MaxX(CharX());//< Don't draw the mouse too far to the left.
            if(NewMousePosition.Y > MaxY(CharY()))NewMousePosition.Y=MaxY(CharY());//< Don't draw the mouse too far down.
            
            if(OldMousePosition.Z)RemoveMouse(OldMousePosition.X,OldMousePosition.Y);//< if this isn't the first time then remove the old mouse first.
            PlaceMouse(NewMousePosition.X,NewMousePosition.Y);
            OldMousePosition.Z=1;//<using Z to determine of this is the first time we have been here.
            OldMousePosition.Y=NewMousePosition.Y;
            OldMousePosition.X=NewMousePosition.X;
        }
        void Terminal::PutPoint(Sauce::uPoint8_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::uPoint16_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::uPoint32_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::uPoint64_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::Point8_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::Point16_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::Point32_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
        }
        void Terminal::PutPoint(Sauce::Point64_t aPoint){
            PutString("[X:");
            PutString(Sauce::Convert::ToString(aPoint.X));
            PutString(",Y:");
            PutString(Sauce::Convert::ToString(aPoint.Y));
            PutString(",Z:");
            PutString(Sauce::Convert::ToString(aPoint.Z));
            PutChar(']');
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