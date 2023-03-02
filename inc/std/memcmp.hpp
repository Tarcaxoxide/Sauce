#ifndef __std_memcmp
#define __std_memcmp
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	inline int64_t memcmp(const void* aptr,const void* bptr,size_t s){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcmp",_NAMESPACE_,_ALLOW_PRINT_);
		return Sauce::Memory::memcmp(aptr,bptr,s);
	}
};
#endif