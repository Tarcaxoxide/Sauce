#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
	namespace Utility{
        size_t strlen(char* str);
        void split(char* path, char delimiter,Sauce::Memory::List_cl<const char*> &result);
    };
};