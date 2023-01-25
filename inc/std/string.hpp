
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Utility/Conversion.hpp>
#ifndef std_string
#define std_string
    namespace std{
        typedef Sauce::Memory::List_cl<char> string;
        inline string to_string(uint64_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(uint32_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(uint16_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(uint8_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(int64_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(int32_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(int16_t V){return Sauce::Utility::Conversion::ToString(V);}
        inline string to_string(int8_t V){return Sauce::Utility::Conversion::ToString(V);}
    };
#endif