#include<Sauce/Memory/Memory.hpp>
#include<_std/memcpy.hpp>
#pragma once
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    inline void memset(T* address,T value,uint64_t size){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcpy",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Memory::memset(address,value,size);
    }
};
