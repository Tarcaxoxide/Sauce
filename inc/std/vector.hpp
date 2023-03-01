#ifndef __std_vector
#define __std_vector
#include<Sauce/Memory/List.hpp>
namespace std{
    template<typename T>
    struct vector: public Sauce::Memory::List_cl<T>{};
};
#endif