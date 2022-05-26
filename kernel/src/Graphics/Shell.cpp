#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Point64_t Size,Point64_t Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::Shell_cl]\n\0");
            Clear();
        }
        void Shell_cl::PutChar(wchar_t chr,bool AddToBuffer){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::PutChar]\n\0");
            size_t chrindex = (size_t)chr;
            if(chrindex > 255)chrindex-=8236; //<- get out of here you stupid "wide characters",
                                              // i'll deal with you later but for now i'm not insane enough.

            switch(chrindex){
                case '\n':{
                    if(AddToBuffer){
                        CharBuffer.AddLast(chr);
                        RunCmd();
                    }
                    GoDown();
                }break;
                case '\b':{
                    if(AddToBuffer)CharBuffer.RemoveLast();
                    if(!GoLeft()){
                        if(GoUp()){
                            GoFarRight();
                        }
                    }
                }break;
                case '\r':{
                    GoFarLeft();
                    if(AddToBuffer)CharBuffer.Clear();
                }break;
                default:{
                    if(AddToBuffer)CharBuffer.AddLast(chr);
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
        void Shell_cl::PutString(const wchar_t* str,bool AddToBuffer){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::PutString]\n\0");
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar((wchar_t)ThisChar,AddToBuffer);
            }
        }
        void Shell_cl::PutString(const char* str,bool AddToBuffer){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::PutString]\n\0");
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar((wchar_t)ThisChar,AddToBuffer);
            }
        }
        bool Shell_cl::GoDown(size_t amount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoDown]\n\0");
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) )return false;
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoUp(size_t amount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoUp]\n\0");
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0)return false;
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoRight(size_t amount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoRight]\n\0");
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) )return false;
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        bool Shell_cl::GoLeft(size_t amount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoLeft]\n\0");
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0)return false;
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        void Shell_cl::GoFarDown(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoFarDown]\n\0");
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
        }
        void Shell_cl::GoFarUp(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoFarUp]\n\0");
            Cursor.Y=0;
        }
        void Shell_cl::GoFarRight(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoFarRight]\n\0");
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
        }
        void Shell_cl::GoFarLeft(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::GoFarLeft]\n\0");
            Cursor.X=0;
        }
        void Shell_cl::RunCmd(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::SHELL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Shell_cl::RunCmd]\n\0");
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
            if((*ArgBuffer[0]) == (char*)"test"){
                PutString(L"\n\roK!\n\r",false);
            }
            else{
                PutString(L"\n\rUnknown Command:'",false);
                PutString(ArgBuffer[0]->Raw(),false);
                PutString(L"'\n\r",false);
            }
        }
    };
};