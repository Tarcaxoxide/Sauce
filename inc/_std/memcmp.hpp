#include<Sauce/Memory/Memory.hpp>
#pragma once
namespace _std{
    inline int64_t memcmp(const void* aptr,const void* bptr,size_t s){
        return Sauce::Memory::memcmp(aptr,bptr,s);
    }
};
