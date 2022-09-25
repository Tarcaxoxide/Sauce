#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            Sauce::IO::Debug::Debugger_st Debugger("Panic",_NAMESPACE_);
            
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};