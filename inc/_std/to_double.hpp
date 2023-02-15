#pragma once
#include<_std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    inline long double to_double(string V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_int",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToDouble(V);}
};