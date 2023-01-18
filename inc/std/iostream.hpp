#pragma once
#include<Sauce/Memory/DynamicArray.hpp>
#include<std/string.hpp>

namespace std{
    std::string operator<<(std::string A,const char* B);
    std::string operator<<(const char* B,std::string A);
    std::string operator<<(std::string A,std::string B);
};

namespace std{
    struct cout_st{
        std::string operator<<(std::string str);
    };
};

namespace std{
    extern const char* endl;
    extern cout_st cout;
};