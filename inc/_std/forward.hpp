#pragma once
namespace _std{
    template<typename T>
    T&& forward(T&& param){
        return static_cast<T&&>(param);
    }
};
