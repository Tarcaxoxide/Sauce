#include<Sauce/Memory/Memory.hpp>
#pragma once
namespace _std{
    inline void memset(void* address,uint8_t value,uint64_t size);{
        Sauce::Memory::memset(address,value,size);
    }
};
