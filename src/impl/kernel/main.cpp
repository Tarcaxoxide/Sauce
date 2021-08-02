#include "Sauce.hpp"


void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    if(_Key.Press){
        char D=_Key.Display;
        if(D != NULL && _Key.visible){
            Sauce::Terminal::Character(D);
        }else if(_Key.visible){
            //Sauce::Terminal::String("0x");
            //Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(_Key.Key));
            switch(_Key.Key){
                case 0xBE:Sauce::Terminal::RelativeSetCursor(true,0,-1);break;//up
                case 0xCA:Sauce::Terminal::RelativeSetCursor(true,1,0);break;//right
                case 0xC2:Sauce::Terminal::RelativeSetCursor(true,0,1);break;//down
                case 0xB6:Sauce::Terminal::RelativeSetCursor(true,-1,0);break;//left
            }
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
    Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(123456789));
    Sauce::Terminal::NewLine();
    Sauce::Terminal::ReturnCaret();
    Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(-123456789));
    Sauce::Terminal::NewLine();
    Sauce::Terminal::ReturnCaret();
    double test=4.50;
    Sauce::Terminal::String(Sauce::Convert::To_String::From_Decimal(test,2));
    Sauce::Interrupts::InitializeIDT();

    while(1){
        asm volatile("hlt");
    }
}
