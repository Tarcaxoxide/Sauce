#include <Shell.hpp>

namespace Sauce{
    namespace Shell{

        static Sauce::Container::String LineBuffer;
        //static Sauce::Container::DynamicArray<Sauce::Container::DynamicArray<char>> wordlist;
        
        void Command(){
            // 
            LineBuffer.Push(' ');
            Sauce::Terminal::String(LineBuffer.Value());
            Sauce::Terminal::NewLine();Sauce::Terminal::ReturnCaret();
        }

        void KeyPress(Sauce::Keyboard::KeyboardKey _Key){
            if(_Key.Press){ 
                    char D=_Key.Display;
                    if(_Key.visible){
                        LineBuffer.Push(_Key.Display);
                        Sauce::Terminal::Character(_Key.Display);
                    }else{
                        switch(_Key.Key){
                            case 0x1C:{
                                Sauce::Terminal::BackSpace();
                                LineBuffer.Pop();
                                }break;
                            case 0xD6:{
                                Sauce::Terminal::NewLine();
                                Sauce::Terminal::ReturnCaret();
                                Command();
                                LineBuffer.Clear();
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