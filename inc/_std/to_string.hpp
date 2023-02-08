#include<_std/string.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#pragma once

namespace _std{
    inline string to_string(uint64_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint32_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint16_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(uint8_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int64_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int32_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int16_t V){return Sauce::Utility::Conversion::ToString(V);}
    inline string to_string(int8_t V){return Sauce::Utility::Conversion::ToString(V);}
};