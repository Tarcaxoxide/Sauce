#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Terminal.hpp>

void* operator new[](size_t);
void operator delete[](void*, size_t);


static inline void __STOP__(){
    while(true){
        asm volatile("cli"); // stop interrupts.
        asm volatile("hlt"); // halt the cpu.
    }
}

