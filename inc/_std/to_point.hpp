#pragma once
#include<_std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Types.hpp>
namespace _std{
    inline  Sauce::Point64_st to_point(string V){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_point",_NAMESPACE_,_ALLOW_PRINT_);
        Debugger.Print(V);
        Sauce::Point64_st R = Sauce::Utility::Conversion::ToPoint64(V);
        Debugger.Print(Sauce::Utility::Conversion::ToString(R));
        return R;
    }
};