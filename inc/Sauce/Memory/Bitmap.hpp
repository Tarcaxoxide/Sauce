#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        struct Bitmap_t{
            size_t Size;
            uint8_t* Buffer=nullptr;
            bool operator[](uint64_t index); // same as get but with fancy [index] thing, returns true on success.
            bool Get(uint64_t index); // get the value at the index, returns value of bit at index.
            bool Set(uint64_t index,bool value); //set the value at the index, return true on success.
            bool Flip(uint64_t index); // if the bit at index is true than change it to false and if it's false than change it to true, returns true on success.
        };
    };
};