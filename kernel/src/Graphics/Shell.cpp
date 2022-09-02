#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Utility/Conversion.hpp>

#include<Sauce/Utility/NeuralNetwork.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            Sauce::IO::Debug::Print_Call("Shell_cl::Shell_cl",Sauce::IO::Debug::SHELL);
            ShellClear();
            
            Sauce::IO::Debug::Print_Return("<this>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::PutChar(wchar_t chr,bool AddToBuffer){
            Sauce::IO::Debug::Print_Call("Shell_cl::PutChar",Sauce::IO::Debug::SHELL);
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
                            ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Alpha=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                                PixelBuffer[Sauce::Math::index(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                            }else{
                                PixelBuffer[Sauce::Math::index(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
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
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::PutString(const wchar_t* str,bool AddToBuffer){
            Sauce::IO::Debug::Print_Call("Shell_cl::PutString",Sauce::IO::Debug::SHELL);
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar((wchar_t)ThisChar,AddToBuffer);
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::PutString(const char* str,bool AddToBuffer){
            Sauce::IO::Debug::Print_Call("Shell_cl::PutString",Sauce::IO::Debug::SHELL);
            while(true){
                char ThisChar = (char)*str++;
                if(ThisChar == '\0')break;
                PutChar((wchar_t)ThisChar,AddToBuffer);
            }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        bool Shell_cl::GoDown(size_t amount){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoDown",Sauce::IO::Debug::SHELL);
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
                Sauce::IO::Debug::Print_Return("<False>",Sauce::IO::Debug::SHELL);
                return false;
            }
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            Sauce::IO::Debug::Print_Return("<True>",Sauce::IO::Debug::SHELL);
            return true;
        }
        bool Shell_cl::GoUp(size_t amount){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoUp",Sauce::IO::Debug::SHELL);
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
                Sauce::IO::Debug::Print_Return("<False>",Sauce::IO::Debug::SHELL);
                return false;
            }
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            Sauce::IO::Debug::Print_Return("<True>",Sauce::IO::Debug::SHELL);
            return true;
        }
        bool Shell_cl::GoRight(size_t amount){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoRight",Sauce::IO::Debug::SHELL);
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
                Sauce::IO::Debug::Print_Return("<False>",Sauce::IO::Debug::SHELL);
                return false;
            }
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            Sauce::IO::Debug::Print_Return("<True>",Sauce::IO::Debug::SHELL);
            return true;
        }
        bool Shell_cl::GoLeft(size_t amount){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoLeft",Sauce::IO::Debug::SHELL);
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
                Sauce::IO::Debug::Print_Return("<False>",Sauce::IO::Debug::SHELL);
                return false;
            }
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            Sauce::IO::Debug::Print_Return("<True>",Sauce::IO::Debug::SHELL);
            return true;
        }
        void Shell_cl::GoFarDown(){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoFarDown",Sauce::IO::Debug::SHELL);
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::GoFarUp(){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoFarUp",Sauce::IO::Debug::SHELL);
            Cursor.Y=0;
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::GoFarRight(){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoFarRight",Sauce::IO::Debug::SHELL);
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::GoFarLeft(){
            Sauce::IO::Debug::Print_Call("Shell_cl::GoFarLeft",Sauce::IO::Debug::SHELL);
            Cursor.X=0;
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::RunCmd(){
            Sauce::IO::Debug::Print_Call("Shell_cl::RunCmd",Sauce::IO::Debug::SHELL);
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
            ShellClear();
            /*actually run the command*/
                if((*ArgBuffer[0]) == (char*)"test"){
                    PutString(L"\n\roK!\n\r",false);
                    Sauce::Memory::List_cl<Sauce::Point64_st> test;

                    size_t numberOfLines=Sauce::Math::random_get(30);
                    size_t maxRandomNumber=Sauce::Math::minimum(PixelsPerLine,PixelsBufferHeight);
                    for(size_t i=0;i<numberOfLines;i++){
                        Sauce::Math::make_line({(int64_t)Sauce::Math::random_get(maxRandomNumber),(int64_t)Sauce::Math::random_get(maxRandomNumber),0},test);
                    }
                    for(size_t i=0;i<test.Size();i++){
                        PutPixel(test[i],{0xA5,0x00,0xA5,0xFF});
                    }
                    Sauce::Utility::Neural::Network_st TestNetwork(5,5,5,5);
                    TestNetwork.EntryNeurons.First()->Poke();
                }
                else if((*ArgBuffer[0]) == (char*)"shutdown"){
                    if(ArgBuffer.Size() < 2){
                        PutString(L"\n\rNo System Specified, Supported Systems (qemu,bochs,virtualbox)\n\r",false);
                    }
                    else if((*ArgBuffer[1]) == (char*)"qemu"){Sauce::IO::outw(0x604, 0x2000);}
                    else if((*ArgBuffer[1]) == (char*)"bochs"){Sauce::IO::outw(0xB004, 0x2000);}
                    else if((*ArgBuffer[1]) == (char*)"virtualbox"){Sauce::IO::outw(0x4004, 0x3400);}
                    else{
                        PutString(L"\n\rUnsupported System!, Supported Systems (qemu,bochs,virtualbox)\n\r",false);
                    }
                }
                else{
                    PutString(L"\n\rUnknown Command:'",false);
                    PutString(ArgBuffer[0]->Raw(),false);
                    PutString(L"'\n\r",false);
                }
            Sauce::IO::Debug::Print_Return("<void>",Sauce::IO::Debug::SHELL);
        }
        void Shell_cl::ShellClear(){
            CharBuffer.Clear();
            Cursor.X=0;
            Cursor.Y=0;
            Cursor.Z=0;
            Clear();
        }
    };
};
