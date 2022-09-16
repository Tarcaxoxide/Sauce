#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
	namespace Utility{
        size_t strlen(char* str);
        Sauce::Memory::List_cl<char*> split(char* path, char delimiter);
        void swap_address(void** AddressA,void** AddressB);
    };
};