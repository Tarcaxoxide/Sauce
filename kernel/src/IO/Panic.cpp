#include<Sauce/IO/Panic.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            GlobalTerminal->SetColor(GOP_BLUE,{0x00,0x00,0x40,0xff});
            GlobalTerminal->Clear();
            GlobalTerminal->SetCursor(10,10);
            GlobalTerminal->PutString(str);
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};