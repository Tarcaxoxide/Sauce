#include<Sauce/Memory/DynamicArray.hpp>
#include<_std/string.hpp>
#pragma once
namespace _std{
    struct cout_st{
        cout_st& operator<<(_std::string nstr);
    };
    extern const char* endl;
    extern cout_st cout;
};
