#pragma once
#include<Sauce/Memory/DynamicArray.hpp>
namespace _std{
    template<typename TY>
    struct vector: public Sauce::Memory::List_cl<TY>{};
};