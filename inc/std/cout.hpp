#ifndef std_cout
#define std_cout
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
namespace std{
    struct cout_st{
        cout_st& operator<<(std::string nstr);
    };
    extern const char* endl;
    extern cout_st cout;
};
#endif