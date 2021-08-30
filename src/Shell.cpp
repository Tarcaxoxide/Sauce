#include <Shell.hpp>

extern "C" uint8_t IsGraphical;

namespace Sauce{
    namespace Shell{
        const size_t LineBufferSize=320;
        char LineBuffer[LineBufferSize];
        size_t LineBufferCounter=0;
        char** Parts=NULL;

        void ClearBuffer(){
            for(size_t I=0;I<320;I++){
                LineBuffer[I]=0;
            }
            LineBufferCounter=0;
        }

        void Command(){
            LineBuffer[LineBufferCounter++]=' ';
            if(Parts == NULL){
                Parts = (char**)Sauce::Memory::malloc(50*sizeof(char*),sizeof(char*));
            }
            Sauce::Memory::allocarr(Parts, 512, 50);
            size_t PartCount = Sauce::Utils::split(LineBuffer,' ',Parts);

            if(Sauce::Utils::StringCompare(Parts[0],"clear")){
                Sauce::Terminal::Clear();
            }else if(Sauce::Utils::StringCompare(Parts[0],"test")){
                Sauce::Terminal::String("Working?!?");
                Sauce::Terminal::String("\n\r");
            }else if(Sauce::Utils::StringCompare(Parts[0],"echo")){
                Sauce::Terminal::String(Parts[1]);
                Sauce::Terminal::String("\n\r");
            }
            else{
                Sauce::Terminal::String("Unknown command:");
                for(size_t I=0;I<PartCount;I++){
                    Sauce::Terminal::String(Parts[I]);
                    Sauce::Terminal::String(" ");
                }
                Sauce::Terminal::String("\n\r");
            }
        }

        size_t XX=0,YY=0;

        void KeyPress(Sauce::Keyboard::KeyboardKey _Key){
            if(_Key.Press){ // we just have some testing code here I guess; a prototype key handler.
                    char D=_Key.Display;
                    if(_Key.visible){
                        LineBuffer[LineBufferCounter++]=_Key.Display;
                        Sauce::Terminal::Character(_Key.Display);
                    }else{
                        switch(_Key.Key){
                            case 0x1C:{
                                Sauce::Terminal::BackSpace();
                                LineBuffer[LineBufferCounter--]=0;
                                }break;
                            case 0xD6:{
                                Sauce::Terminal::NewLine();
                                Sauce::Terminal::ReturnCaret();
                                Command();
                                ClearBuffer();
                                }break;
                            case 0xBE:{
                                //Sauce::Terminal::RelativeSetCursor(true,0,-1); //up arrow
                                }break;
                            case 0xCA:{
                                //Sauce::Terminal::RelativeSetCursor(true,1,0); //right arrow
                                }break;
                            case 0xC2:{
                                //Sauce::Terminal::RelativeSetCursor(true,0,1); //down arrow
                                }break;
                            case 0xB6:{
                                //Sauce::Terminal::RelativeSetCursor(true,-1,0); //left arrow
                                }break;
                        }
                    }
                }
            }
    };
};