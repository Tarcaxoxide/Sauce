#ifndef __std_to_string
#define __std_to_string
#include<std/string.hpp>
#include<Sauce/Utility/Conversion.hpp>
namespace std{
	template<typename TT>
	inline string to_string(TT V){return Sauce::Utility::Conversion::ToString(V);}
};
#endif