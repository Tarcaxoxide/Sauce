#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Point64_t Size,Point64_t Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            Clear();
        }
        void Shell_cl::PutChar(wchar_t chr){
            size_t chrindex = (size_t)chr;
            if(chrindex > 255)chrindex-=8236; //<- get out of here you stupid "wide characters",
                                              // i'll deal with you later but for now i'm not insane enough.

            switch(chrindex){
                case '\n':{
                    CharBuffer.AddLast(chr);
                    RunCmd();
                    GoDown();
                }break;
                case '\b':{
                    if(!GoLeft()){
                        if(GoUp()){
                            GoFarRight();
                        }
                    }
                }break;
                case '\r':{GoFarLeft();}break;
                default:{
                    CharBuffer.AddLast(chr);
                    for(size_t X=2;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
                        for(size_t Y=2;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
                            GOP_PixelStructure ThisColor{0,0,0,0xFF};
                            ThisColor.Red=ForegroundColor.Red/9;
                            ThisColor.Green=ForegroundColor.Green/9;
                            ThisColor.Blue=ForegroundColor.Blue/9;
                            ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Alpha=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                                PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                            }else{
                                PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                            }
                        }
                    }
                    if(!GoRight()){
                        if(GoDown()){
                            GoFarLeft();
                        }
                    }
                }break;
            }
        }
        bool Shell_cl::GoDown(size_t amount){
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) )return false;
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoUp(size_t amount){
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0)return false;
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoRight(size_t amount){
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) )return false;
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        bool Shell_cl::GoLeft(size_t amount){
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0)return false;
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        void Shell_cl::GoFarDown(){
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
        }
        void Shell_cl::GoFarUp(){
            Cursor.Y=0;
        }
        void Shell_cl::GoFarRight(){
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
        }
        void Shell_cl::GoFarLeft(){
            Cursor.X=0;
        }
        void Shell_cl::RunCmd(){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::RunCmd]\n\0");
            Sauce::Memory::List_cl<Sauce::Memory::List_cl<char>*> ArgBuffer;
            size_t CrawlerVal=0;
            for(size_t i=0;i<CharBuffer.Size();i++){
                if(CharBuffer[i] == ' ' || CharBuffer[i] == '\n'){
                    Sauce::Memory::List_cl<char>* str = new Sauce::Memory::List_cl<char>;
                    for(size_t a=CrawlerVal;a<i;a++){
                        if(!(CharBuffer[a] == ' ' || CharBuffer[a] == '\n')){
                            str->AddLast((char)CharBuffer[a]);
                        }
                    }
                    ArgBuffer.AddLast(str);
                    delete[] str;
                    CrawlerVal=i;
                }
            }
            CharBuffer.Clear();
            for(size_t i=0;i<ArgBuffer.Size();i++){
                Sauce::IO::Debug::COM1_Console.Write((char*)" ->(\0");
                Sauce::IO::Debug::COM1_Console.Write(ArgBuffer[i]->Raw());
                Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            }
        }
    };
};