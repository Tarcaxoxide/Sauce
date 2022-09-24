#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Utility/NeuralNetwork.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Terminal_cl(pDebugger,(Size.X*Size.Y),Size.X,Offset){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::Shell_cl");
            ShellClear(&Debugger);
        }
        void Shell_cl::PutChar(Sauce::IO::Debug::Debugger_st* pDebugger,wchar_t chr,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::PutChar");
            size_t chrindex = (size_t)chr;
            if(chrindex > 255)chrindex-=8236; //<- get out of here you stupid "wide characters",
                                              // i'll deal with you later but for now i'm not insane enough.

            switch(chrindex){
                case '\n':{
                    if(AddToBuffer){
                        CharBuffer.AddLast(chr);
                        RunCmd(&Debugger);
                    }
                    GoDown(&Debugger);
                }break;
                case '\b':{
                    if(AddToBuffer)CharBuffer.RemoveLast();
                    if(!GoLeft(&Debugger)){
                        if(GoUp(&Debugger)){
                            GoFarRight(&Debugger);
                        }
                    }
                }break;
                case '\r':{
                    GoFarLeft(&Debugger);
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
                            ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(&Debugger,X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(&Debugger,X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(&Debugger,X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Alpha=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(&Debugger,X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                                PixelBuffer[Sauce::Math::index(&Debugger,X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                            }else{
                                PixelBuffer[Sauce::Math::index(&Debugger,X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                            }
                        }
                    }
                    if(!GoRight(&Debugger)){
                        if(GoDown(&Debugger)){
                            GoFarLeft(&Debugger);
                        }
                    }
                }break;
            }
        }
        void Shell_cl::PutString(Sauce::IO::Debug::Debugger_st* pDebugger,const wchar_t* str,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::PutString");
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar(&Debugger,(wchar_t)ThisChar,AddToBuffer);
            }
        }
        void Shell_cl::PutString(Sauce::IO::Debug::Debugger_st* pDebugger,const char* str,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::PutString");
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar(&Debugger,(wchar_t)ThisChar,AddToBuffer);
            }
        }
        bool Shell_cl::GoDown(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::GoDown");
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
                return false;
            }
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoUp(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoUp");
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
                return false;
            }
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoRight(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoRight");
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
                return false;
            }
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        bool Shell_cl::GoLeft(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoLeft");
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
                return false;
            }
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        void Shell_cl::GoFarDown(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::GoFarDown");
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
        }
        void Shell_cl::GoFarUp(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::GoFarUp");
            Cursor.Y=0;
            
        }
        void Shell_cl::GoFarRight(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::GoFarRight");
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
            
        }
        void Shell_cl::GoFarLeft(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::GoFarLeft");
            Cursor.X=0;
            
        }
        void Shell_cl::RunCmd(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::RunCmd");
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
            ShellClear(&Debugger);
            for(size_t ii=0;ii<ArgBuffer.Size();ii++){
                PutString(&Debugger,Sauce::Utility::ToString(&Debugger,ii),false);
                PutString(&Debugger,L":'",false);
                PutString(&Debugger,ArgBuffer[ii]->Raw(),false);
                PutString(&Debugger,L"'\n\r",false);
            }
            
        }
        void Shell_cl::ShellClear(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Shell_cl::ShellClear");
            CharBuffer.Clear();
            Cursor.X=0;
            Cursor.Y=0;
            Cursor.Z=0;
            Clear(&Debugger);
        }
    };
};
