#ifndef __std_memcpy
#define __std_memcpy
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	template<typename T> inline void memcpy(const T* srcPtr,const T* destPtr,size_t s){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcpy",_NAMESPACE_,_ALLOW_PRINT_);
		Sauce::Memory::memcpy((void*)srcPtr,(void*)destPtr,s,sizeof(T));
	}
};
#endif