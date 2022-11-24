#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Utility/NeuralNetwork.hpp>

/*experimentation*/#include <Sauce/Storage/FileSystem/FAT.hpp>

namespace Sauce{
    namespace Commands{
        Sauce::string Exec(Sauce::Memory::List_cl<Sauce::string*>& Args){
            Sauce::string Result;
            if((*Args[0]) == Sauce::string((char*)"AHCI")){
                if((*Args[1]) == Sauce::string((char*)"List")){
                    Result=Sauce::Global::AHCIDriver->ListPorts();
                    return Result;
                }
            }
            if((*Args[0]) == Sauce::string((char*)"TEST")){
                Sauce::Storage::FileSystem::FAT::Extended_Boot_Record_FAT32_st FAT32Record = Sauce::Storage::FileSystem::FAT::READ_FAT32(0);
                for(size_t i=0;i<11;i++){
                    Result.AddLast((char)FAT32Record.VOLUME_LABEL[i]);
                }
                Result.AddLast((char*)"\n\r");
                return Result;
            }
            Result=(char*)"Unknown Command: ";
            Result.AddLast(Args[0]->Raw());
            return Result;
        }
    };
};

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::Shell_cl",_NAMESPACE_);
            ShellClear(true);
        }
        void Shell_cl::PutChar(char chr,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::PutChar",_NAMESPACE_);
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
        }
        void Shell_cl::PutString(Sauce::string str,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::PutString",_NAMESPACE_);
            for(size_t i=0;i<str.Size();i++){
                PutChar(str[i],AddToBuffer);
            }
        }
        bool Shell_cl::GoDown(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoDown",_NAMESPACE_);
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
                return false;
            }
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoUp(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoUp",_NAMESPACE_);
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
                return false;
            }
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoRight(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoRight",_NAMESPACE_);
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
                return false;
            }
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        bool Shell_cl::GoLeft(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoLeft",_NAMESPACE_);
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
                return false;
            }
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        void Shell_cl::GoFarDown(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarDown",_NAMESPACE_);
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
        }
        void Shell_cl::GoFarUp(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarUp",_NAMESPACE_);
            Cursor.Y=0;
            
        }
        void Shell_cl::GoFarRight(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarRight",_NAMESPACE_);
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
            
        }
        void Shell_cl::GoFarLeft(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarLeft",_NAMESPACE_);
            Cursor.X=0;
            
        }
        void Shell_cl::RunCmd(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::RunCmd",_NAMESPACE_);
            Sauce::Memory::List_cl<Sauce::string*> ArgBuffer;
            size_t CrawlerVal=0;
            for(size_t i=0;i<CharBuffer.Size();i++){
                if(CharBuffer[i] == ' ' || CharBuffer[i] == '\n'){
                    Sauce::string* str = new Sauce::string;
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
            ShellClear(false);
            PutString((char*)"\n\r",false);
            PutString(Sauce::Commands::Exec(ArgBuffer),false);
        }
        void Shell_cl::ShellClear(bool ClearScreen){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::ShellClear",_NAMESPACE_);
            CharBuffer.Clear();
            if(ClearScreen){
                Cursor.X=0;
                Cursor.Y=0;
                Cursor.Z=0;
                Clear();
            }
        }
    };
};
