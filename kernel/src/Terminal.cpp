#include<Sauce/Terminal.hpp>
namespace Sauce{
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
                for(unsigned long Y=Cursor_Y;Y < Cursor_Y+DFBL->Font->psf1_header->char_height;Y++){
                    for(unsigned long X=Cursor_X;X<Cursor_X+DFBL->Font->psf1_header->char_width;X++){
                        if((*fontPtr & (0b10000000 >>(X-Cursor_X)))>0){
                            DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Fcolor;
                        }else{
                            DFBL->FrameBuffer->BaseAddress[(X + (Y * DFBL->FrameBuffer->PixelsPerScanLine))] = Bcolor;
                        }

                    }
                    fontPtr++;
                }
                Cursor_X+=DFBL->Font->psf1_header->char_width;
                break;}
        }
        if(Cursor_X+DFBL->Font->psf1_header->char_width > DFBL->FrameBuffer->PixelsPerScanLine){
            NewLine();
            ReturnCaret();
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
            //Cursor_X+=DFBL->Font->psf1_header->char_width;
        }
    }
    void Terminal::NewLine(){
        Cursor_Y+=DFBL->Font->psf1_header->char_height;
    }
    void Terminal::ReturnCaret(){
        Cursor_X=0;
    }
    void Terminal::BackSpace(){
        Cursor_X-=DFBL->Font->psf1_header->char_width;
        PutChar(' ');
        Cursor_X-=DFBL->Font->psf1_header->char_width;
    }
    void Terminal::Clear(){
        Fill(' ');
    }
    void Terminal::FillRow(char chr,size_t Row){
        for(size_t X=0;X<DFBL->FrameBuffer->PixelsPerScanLine-DFBL->Font->psf1_header->char_width;X+=DFBL->Font->psf1_header->char_width){
           PutCharAt(chr,X,Row);
        }
    }
    void Terminal::FillColumn(char chr,size_t Column){
        for(size_t Y=0;Y<DFBL->FrameBuffer->Height-DFBL->Font->psf1_header->char_height;Y+=DFBL->Font->psf1_header->char_height){
            PutCharAt(chr,Column,Y);
        }
    }
    void Terminal::Fill(char chr){
        for(size_t X=0;X<DFBL->FrameBuffer->Width-DFBL->Font->psf1_header->char_width;X+=DFBL->Font->psf1_header->char_width){
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
        Cursor_X=X;
        Cursor_Y=Y;
    }
    Terminal* GlobalTerminal;
};