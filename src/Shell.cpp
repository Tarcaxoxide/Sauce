#include <Shell.hpp>

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
            Sauce::Memory::memset(Parts,0,LineBufferSize);
            Sauce::Utils::split(LineBuffer,' ',Parts);

            Sauce::Terminal::String("Cmd : ");
            Sauce::Terminal::String((char*)Parts[0]);
            Sauce::Terminal::String(" \n\r");
            return;

            if(Sauce::Utils::StringCompare(LineBuffer,"clear")){
                Sauce::Terminal::Clear();
            }else if(Sauce::Utils::StringCompare(LineBuffer,"test")){
                Sauce::Terminal::String("Working?!?");
                Sauce::Terminal::String("\n\r");
            }else{
                Sauce::Terminal::String("Unknown command:");
                Sauce::Terminal::String(LineBuffer);
                Sauce::Terminal::String("\n\r");
            }
        }


        void Init(){
            Parts = (char**)Sauce::Memory::alloc(LineBufferSize*sizeof(char*),sizeof(char*));
        }

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