#ifndef __std_string
#define __std_string
#include<Sauce/Memory/List.hpp>
namespace std{
	typedef Sauce::Memory::List_cl<char> string;
	typedef Sauce::Memory::List_cl<unsigned char> ustring;
};
#endif