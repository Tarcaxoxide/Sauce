#pragma once
#include<Sauce/Memory/DynamicArray.hpp>
#include<std/string.hpp>

namespace std _GLIBCXX_VISIBILITY(default){
    struct cout_st{
        std::string operator<<(std::string str);
    };
    extern const char* endl;
    extern cout_st cout;
};
