#ifndef __std_is_reference
#define __std_is_reference
#include<std/bool_type.hpp>
namespace std{
    template <typename T> struct is_reference      : false_type {};
    template <typename T> struct is_reference<T&>  : true_type {};
    template <typename T> struct is_reference<T&&> : true_type {};
};
#endif