#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            Sauce::IO::Debug::COM1_Console.Write((char*)str);
            Sauce::IO::Debug::COM1_Console.Write((char*)"\n\0");
            GlobalTerminal->SetColor({0xFF,0x00,0x00,0xFF},{0x00,0x00,0x40,0xFF});
            GlobalTerminal->Clear();
            GlobalTerminal->SetCursor(10,10);
            /*Not Handled By Terminal Anymore, Please Implement in Shell*///GlobalTerminal->PutString(str);
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};