#ifndef __std_memcpy
#define __std_memcpy
#include<Sauce/Memory/Memory.hpp>
namespace std{
	template<typename T> inline void memcpy(const T* srcPtr,const T* destPtr,size_t s){
		Sauce::Memory::memcpy((void*)srcPtr,(void*)destPtr,s,sizeof(T));
	}
};
#endif