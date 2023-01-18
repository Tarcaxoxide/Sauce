#pragma once
#include<Sauce/Memory/DynamicArray.hpp>
#include<std/string.hpp>

namespace std{
    struct cout_st{
        std::string operator<<(std::string str);
        std::string operator<<(const char* str);
    };
};

namespace std{
    extern const char* endl;
    extern cout_st cout;
};