#ifndef __std_is_const
#define __std_is_const
#include<std/exception.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
	template<typename T>
	struct is_const{
		bool value=false;
		is_const(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"is_const::is_const",_NAMESPACE_,_ALLOW_PRINT_);
			try{
				T xx;
				xx = (T)0x00;
			}catch(const exception& e){ // ?Does this even work?
				value=true;
			}
		}
	};
};
#endif