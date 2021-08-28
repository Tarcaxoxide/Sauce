#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack

extern "C" uint64_t _HeadOfheap;


void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
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

void NotifyKernelOfTimer(float rate){
    Sauce::Interrupts::PIT_Counter+=0x0000000000000001;
        //Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Sauce::Interrupts::PIT_Counter));
        //Sauce::Terminal::String(":");
        //Sauce::Terminal::String(Sauce::Convert::To_String::From_Decimal(rate,10));
        //Sauce::Terminal::String("\n\r");
    if(Sauce::Interrupts::PIT_Counter > 0x1000000000000000){
        Sauce::Interrupts::PIT_Counter=0;
    }
}

void tests(){
    
    Sauce::Graphics::PlaceEmptySquare(20,20,100,100,1);
    Sauce::Graphics::PlaceEmptySquare(10,10,115,115,2);
    //void PlaceRectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color);
}

void Kernel_Main(){
    Sauce::Interrupts::InitializeIDT();
    Sauce::IO::init_serial();
    Sauce::Filesystem::InitializeFilesystem();
    //Sauce::Memory::InitializeHeap(_HeadOfheap,0x1000000);
    tests();

    while(1){
        asm volatile("hlt");
    }
}
