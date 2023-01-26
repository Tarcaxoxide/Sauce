#pragma once

#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<_std/string.hpp>

namespace Sauce{
	namespace Utility{
        namespace Manipulate{
            size_t strlen(char* str);
            bool strcmp(const char* strA,const char* strB);
            Sauce::Memory::List_cl<char*> split(char* path, char delimiter);
            Sauce::Memory::List_cl<_std::string> split(Sauce::Memory::List_cl<char>, char delimiter);
            void swap_address(void** AddressA,void** AddressB);
        };
    };
};