#ifndef __std_remove_const
#define __std_remove_const
namespace std{
	template<typename T> struct remove_const				{ typedef T type; };
	template<typename T> struct remove_const<const T>	   { typedef T type; };
};
#endif