#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Terminal.hpp>

#ifndef __OVER_RIDES__
#define __OVER_RIDES__
    void* operator new[](size_t);
    void operator delete[](void*, size_t);
#endif

#ifndef SpecialSauceFunctions
#define SpecialSauceFunctions
    namespace Sauce{
        void STOP(bool fail);
        void REBOOT();
    };
#endif
