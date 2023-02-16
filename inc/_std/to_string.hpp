#pragma once
#include<_std/string.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Utility/Conversion.hpp>
namespace _std{
    template<typename TT>
    inline string to_string(TT V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
};