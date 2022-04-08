#pragma once

#include<stddef.h>
#include<stdint.h>

namespace Sauce{
    namespace Memory{
        struct Bitmap_t{
            size_t Size;
            uint8_t* Buffer;
            bool operator[](uint64_t index);
            bool Get(uint64_t index);
            bool Set(uint64_t index,bool value);
            void Flip(uint64_t index);
        };
    };
};