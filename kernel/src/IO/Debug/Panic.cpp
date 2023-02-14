#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            Sauce::IO::Debug::Debugger_st Debugger("Panic",_NAMESPACE_,_ALLOW_PRINT_);
            while(true){
                asm volatile("cli;hlt");
            }
        }
    };
};