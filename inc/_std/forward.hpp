#pragma once
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    template<typename T>
    T&& forward(T&& param){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"forward",_NAMESPACE_,_ALLOW_PRINT_);
        return static_cast<T&&>(param);
    }
};
