#include "Sauce.hpp"


extern "C" void Kernel_Main(){
    Sauce::Terminal::Clear();
    Sauce::Terminal::Setcolor(Sauce::Terminal::COLOR_LIGHT_GREEN, Sauce::Terminal::COLOR_BLACK);
    Sauce::Terminal::String("Hello World!\n\r");
}



