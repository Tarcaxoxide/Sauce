#ifndef __Sauce_Utility_Manipulation
#define __Sauce_Utility_Manipulation
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Utility{
		namespace Manipulate{
			size_t strlen(char* str);
			bool strcmp(const char* strA,const char* strB);
			Sauce::Memory::List_cl<char*> split(char* path, char delimiter);
			Sauce::Memory::List_cl<std::string> split(Sauce::Memory::List_cl<char>, char delimiter);
			void swap_address(void** AddressA,void** AddressB);
		};
	};
};
#endif