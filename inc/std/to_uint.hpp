#ifndef __std_uint
#define __std_uint
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	inline int64_t to_uint(string V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_uint",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToUint64(V);}
};
#endif