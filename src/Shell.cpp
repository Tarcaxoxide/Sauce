#include <Shell.hpp>

namespace Sauce{
    namespace Shell{

    Sauce::Container::String LineBuffer;
	Sauce::Container::String Word;
	void Command(){
		
		if(Sauce::Utils::String_Compare_ReturnBool(LineBuffer.Raw(),"test")){
			Sauce::Terminal::String("Hello World!\n\r");
		}else if(Sauce::Utils::String_Compare_ReturnBool(LineBuffer.Raw(),"clear")){
            Sauce::Terminal::Clear();
        }
        else{
            Sauce::Terminal::String("Uknown Command: '");
            Sauce::Terminal::String(LineBuffer.Raw());
            Sauce::Terminal::String("'\n\r");
        }
		LineBuffer.Clear();
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
