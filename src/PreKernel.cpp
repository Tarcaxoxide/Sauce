#include <Sauce.hpp>

extern void Kernel_Main();

void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    // theoretically i should just be able to pass this _Key object to userland.
    if(_Key.Press){ // we just have some testing code here I guess; a prototype key handler.
        char D=_Key.Display;
        if(D != NULL && _Key.visible){
            Sauce::Terminal::Character(D);
        }else if(_Key.visible){ // unhandled key.
            Sauce::Terminal::String("0x");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(_Key.Key));
        }else{
            switch(_Key.Key){
                case 0x1C:{
                    Sauce::Terminal::BackSpace();
                    }break;
                case 0xD6:{
                    Sauce::Terminal::NewLine();
                    Sauce::Terminal::ReturnCaret();
                    }break;
                case 0xBE:{
                    Sauce::Terminal::RelativeSetCursor(true,0,-1); //up arrow
                    }break;
                case 0xCA:{
                    Sauce::Terminal::RelativeSetCursor(true,1,0); //right arrow
                    }break;
                case 0xC2:{
                    Sauce::Terminal::RelativeSetCursor(true,0,1); //down arrow
                    }break;
                case 0xB6:{
                    Sauce::Terminal::RelativeSetCursor(true,-1,0); //left arrow
                    }break;
            }
        }
        
    }
}

extern "C" void _start(){
    Kernel_Main();
}