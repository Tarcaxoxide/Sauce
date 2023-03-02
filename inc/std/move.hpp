#ifndef __std_move
#define __std_move
#include<std/remove_reference.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	template <typename T>
	typename remove_reference<T>::type&& move(T&& arg){
	  Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"move",_NAMESPACE_,_ALLOW_PRINT_);
	  return static_cast<typename remove_reference<T>::type&&>(arg);
	}
};
#endif