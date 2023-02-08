#include<Sauce/Memory/Memory.hpp>
#pragma once
namespace _std{
    template<typename T> inline void memcpy(const T* srcPtr,const T* destPtr,size_t s){
        Sauce::Memory::memcpy((void*)srcPtr,(void*)destPtr,s,sizeof(T));
    }
};
