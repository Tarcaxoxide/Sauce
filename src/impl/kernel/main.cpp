#include "Sauce.hpp"


void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    if(_Key.Press){
        char D=_Key.Display;
        if(D != NULL && _Key.visible){
            Sauce::Terminal::Character(D);
        }else if(_Key.visible){
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
            }
        }
        
    }
}

extern "C" void Kernel_Main(){
    Sauce::Terminal::Clear();
    Sauce::Terminal::Setcolor(Sauce::Terminal::COLOR_LIGHT_GREEN, Sauce::Terminal::COLOR_BLACK);
    Sauce::Terminal::String("Hello World!\n\r");
    Sauce::Interrupts::InitializeIDT();

    while(1){
        asm volatile("hlt");
    }
}



