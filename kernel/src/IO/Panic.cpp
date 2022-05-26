#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Panic]\n\0");
            
            /*Not Handled By Terminal Anymore, Please Implement in Shell*///GlobalTerminal->PutString(str);
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};