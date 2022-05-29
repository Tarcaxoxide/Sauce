#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        void Panic(const char* str){
            Sauce::IO::Debug::Print_Call("Panic",true,true);
            
            while(true){
                asm volatile("cli;hlt");
            }
            Sauce::IO::Debug::Print_Return("void",true,true); // Unlikely that we would return but just in case.
        }
    };
};