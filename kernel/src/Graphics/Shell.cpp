#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<_std/deque.hpp>
#include<_std/functional.hpp>


namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::Shell_cl",_NAMESPACE_,_ALLOW_PRINT_);
            ShellClear(true);
        }
        void Shell_cl::PutChar(char chr,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::PutChar",_NAMESPACE_,_ALLOW_PRINT_);
            size_t chrindex = (size_t)chr;

            switch(chrindex){
                case '\n':{
                    if(AddToBuffer){
                        if(!CharBuffer.Size())break;
                        CharBuffer.AddLast(chr);
                        ParseAndRunCommand();
                    }
                    GoDown();
                }break;
                case '\b':{
                    if(AddToBuffer){
                        if(!CharBuffer.RemoveLast())break;
                    }
                    if(!GoLeft()){
                        if(GoUp()){
                            GoFarRight();
                        }
                    }else{
                        PutChar(' ',false);
                        GoLeft();
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
                            PixelBuffer[Sauce::Math::index(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=Blend(ForegroundColor,BackgroundColor,Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)]);
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
        void Shell_cl::PutString(_std::string str,bool AddToBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::PutString",_NAMESPACE_,_ALLOW_PRINT_);
            for(size_t i=0;i<str.Size();i++){
                PutChar(str[i],AddToBuffer);
            }
        }
        bool Shell_cl::GoDown(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoDown",_NAMESPACE_,_ALLOW_PRINT_);
            if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
                return false;
            }
            Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoUp(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoUp",_NAMESPACE_,_ALLOW_PRINT_);
            if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
                return false;
            }
            Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
            return true;
        }
        bool Shell_cl::GoRight(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoRight",_NAMESPACE_,_ALLOW_PRINT_);
            if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
                return false;
            }
            Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        bool Shell_cl::GoLeft(size_t amount){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoLeft",_NAMESPACE_,_ALLOW_PRINT_);
            if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
                return false;
            }
            Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
            return true;
        }
        void Shell_cl::GoFarDown(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarDown",_NAMESPACE_,_ALLOW_PRINT_);
            Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
        }
        void Shell_cl::GoFarUp(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarUp",_NAMESPACE_,_ALLOW_PRINT_);
            Cursor.Y=0;
        }
        void Shell_cl::GoFarRight(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarRight",_NAMESPACE_,_ALLOW_PRINT_);
            Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
        }
        void Shell_cl::GoFarLeft(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::GoFarLeft",_NAMESPACE_,_ALLOW_PRINT_);
            Cursor.X=0;
        }
        void Shell_cl::ParseAndRunCommand(){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::ParseAndRunCommand",_NAMESPACE_,_ALLOW_PRINT_);
            _std::deque<_std::string*> ArgBuffer;
            {/*Parse command string*/
                size_t CrawlerVal=0;
                for(size_t i=0;i<CharBuffer.Size();i++){
                    if(CharBuffer[i] == ' ' || CharBuffer[i] == '\n'){
                        _std::string* str = new _std::string;
                        for(size_t a=CrawlerVal;a<i;a++){
                            if(!(CharBuffer[a] == ' ' || CharBuffer[a] == '\n')){
                                str->AddLast((char)CharBuffer[a]);
                            }
                        }
                        ArgBuffer.AddLast(new _std::string((*str).Raw()));
                        delete str;
                        CrawlerVal=i;
                    }
                }
            }
            ShellClear(false);
            _std::deque<_std::function<void(_std::deque<_std::string*>& Args)>> Commandz={
                #include<Sauce/Commands/HelloWorld.hpp>
            };
            _std::cout<<_std::endl;
            {/*Executable command string*/
                for(size_t iCommand=0;iCommand<Commandz.Size();iCommand++)Commandz[iCommand](ArgBuffer);
            }
        }
        void Shell_cl::ShellClear(bool ClearScreen){
            Sauce::IO::Debug::Debugger_st Debugger("Shell_cl::ShellClear",_NAMESPACE_,_ALLOW_PRINT_);
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
