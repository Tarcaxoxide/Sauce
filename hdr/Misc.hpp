
#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>
#include <Terminal.hpp>
#include <Convert.hpp>
void* operator new[](size_t);
void operator delete[](void*, size_t);


extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
extern "C" uint8_t IsGraphical;

#ifndef __MISC__
#define __MISC__
    namespace Sauce{
        enum ERROR_CODES: uint64_t {
            Nothing=0,
            Index_too_big, //1
            Shape_mismatch, //2
            Out_of_memory, //3
            Combined_segment_with_null, //4
            Alignment_unspecified, //5
            Size_unspecified, //6
            User_Executed //7
        };
        void STOP(ERROR_CODES code);
        void REBOOT();
    };
#endif