#include<Sauce/Panic.hpp>

namespace Sauce{
    void Panic(char* str){
        GlobalTerminal->SetColor(GOP_BLUE,{0x00,0x00,0x40,0xff});
        GlobalTerminal->Clear();
        GlobalTerminal->SetCursor(10,10);
        GlobalTerminal->PutString(str);
        while(true){
            asm volatile("cli;hlt");
        }
    }
};