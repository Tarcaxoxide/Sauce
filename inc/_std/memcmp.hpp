#include<Sauce/Memory/Memory.hpp>
#pragma once
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    inline int64_t memcmp(const void* aptr,const void* bptr,size_t s){
        Sauce::IO::Debug::Debugger_st Debugger("memcmp",_NAMESPACE_,_ALLOW_PRINT_);
        return Sauce::Memory::memcmp(aptr,bptr,s);
    }
};
