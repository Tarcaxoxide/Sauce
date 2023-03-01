#ifndef __std_terminate
#define __std_terminate
#include<Sauce/IO/Debug/Panic.hpp>
namespace std{
    void terminate(){
        Sauce::IO::Panic("std::terminate");
        while(true){
            asm volatile("cli");
            asm volatile("hlt");
        }
    }
};
#endif