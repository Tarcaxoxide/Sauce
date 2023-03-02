#ifndef __std_forward
#define __std_forward
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	template<typename T>
	T&& forward(T&& param){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"forward",_NAMESPACE_,_ALLOW_PRINT_);
		return static_cast<T&&>(param);
	}
};
#endif