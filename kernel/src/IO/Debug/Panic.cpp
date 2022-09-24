#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(Sauce::IO::Debug::Debugger_st* pDebugger,const char* str){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Panic");
            
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};