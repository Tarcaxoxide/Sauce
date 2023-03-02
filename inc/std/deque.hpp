#ifndef __std_deque
#define __std_deque
#include<Sauce/Memory/List.hpp>
namespace std{
	template<typename T>
	struct deque: public Sauce::Memory::List_cl<T>{};
};
#endif