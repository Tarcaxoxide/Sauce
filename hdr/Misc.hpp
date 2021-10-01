#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Terminal.hpp>

#ifndef __OVER_RIDES__
#define __OVER_RIDES__
    void* operator new[](size_t);
    void operator delete[](void*, size_t);
#endif

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
extern "C" uint8_t IsGraphical;

void STOP(bool fail);
void REBOOT();

