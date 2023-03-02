#ifndef __std_memset
#define __std_memset
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	template<typename T>
	inline void* memset(T* address,T value,uint64_t size){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcpy",_NAMESPACE_,_ALLOW_PRINT_);
		Sauce::Memory::memset(address,value,size);
		return address;
	}
};
	#ifdef __clang__
	void *memset(void *dest, int c, size_t count){/*because clang isn't happy with using std::memset XD*/
		Sauce::Memory::memset(dest,c,count);
		return dest;
	}
	#endif
#endif