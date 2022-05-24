#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            Sauce::IO::Debug::COM1_Console.Write((char*)str);
            Sauce::IO::Debug::COM1_Console.Write((char*)"\n\0");
            
            /*Not Handled By Terminal Anymore, Please Implement in Shell*///GlobalTerminal->PutString(str);
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};