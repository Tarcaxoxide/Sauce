#pragma once
#include<Sauce/Memory/DynamicArray.hpp>
#include<_std/string.hpp>

namespace _std /*_GLIBCXX_VISIBILITY(default)*/{
    //I don't know what this does yet but i'm going to put it here for later.
    struct cout_st{
        cout_st& operator<<(_std::string nstr);
    };
    extern const char* endl;
    extern cout_st cout;
};
