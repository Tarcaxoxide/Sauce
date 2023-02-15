#pragma once
#include<_std/string.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Utility/Conversion.hpp>
namespace _std{
    inline string to_string(uint64_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint32_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint16_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint8_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int64_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int32_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int16_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int8_t V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(long double V){Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"to_string",_NAMESPACE_,_ALLOW_PRINT_);return Sauce::Utility::Conversion::ToString(V);}
};