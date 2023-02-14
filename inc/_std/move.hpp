#include<_std/remove_reference.hpp>
#pragma once
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    template <typename T>
    typename remove_reference<T>::type&& move(T&& arg){
      Sauce::IO::Debug::Debugger_st Debugger("move",_NAMESPACE_,_ALLOW_PRINT_);
      return static_cast<typename remove_reference<T>::type&&>(arg);
    }
};
