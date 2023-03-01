#ifndef __std_list
#define __std_list
#include<Sauce/Memory/List.hpp>
namespace std{
    template<typename T>
    struct list: public Sauce::Memory::List_cl<T>{};
};
#endif