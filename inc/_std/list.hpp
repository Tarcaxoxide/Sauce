#include<Sauce/Memory/List.hpp>
#pragma once
namespace _std{
    template<typename T>
    struct list: public Sauce::Memory::List_cl<T>{};
};
