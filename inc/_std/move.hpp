#include<_std/remove_reference.hpp>
#pragma once
namespace _std{
    template <typename T>
    typename remove_reference<T>::type&& move(T&& arg){
      return static_cast<typename remove_reference<T>::type&&>(arg);
    }
};
