#ifndef __std_to_int
#define __std_to_int
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	inline int64_t to_int(string V){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_int",_NAMESPACE_,_ALLOW_PRINT_);
		Debugger.Print(V);
		int64_t R = Sauce::Utility::Conversion::ToInt64(V);
		Debugger.Print(Sauce::Utility::Conversion::ToString(R));
		return R;
	}
};
#endif