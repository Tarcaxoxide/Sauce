#include<Sauce/IO/Debug/Serial.hpp>
namespace Sauce{
    namespace IO{
        void Panic(const char* msg){
            DefaultSerialWrite("PANIC!");
            DefaultSerialWrite(msg);
            asm volatile("cli;hlt");
        }
    };
};