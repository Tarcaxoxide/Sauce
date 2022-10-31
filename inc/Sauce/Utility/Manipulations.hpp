#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
	namespace Utility{
        size_t strlen(char* str);
        bool strcmp(const char* strA,const char* strB);
        Sauce::Memory::List_cl<char*> split(char* path, char delimiter);
        Sauce::Memory::List_cl<Sauce::Memory::List_cl<char>> split(Sauce::Memory::List_cl<char>, char delimiter);
        Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>> split(Sauce::Memory::List_cl<wchar_t>, wchar_t delimiter);
        void swap_address(void** AddressA,void** AddressB);
    };
};