#ifndef _std_cout
#define _std_cout
#include<Sauce/Memory/List.hpp>
#include<_std/string.hpp>
namespace _std{
    struct cout_st{
        cout_st& operator<<(_std::string nstr);
    };
    extern const char* endl;
    extern cout_st cout;
};
#endif