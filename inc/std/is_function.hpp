#ifndef __std_is_function
#define __std_is_function
#include<std/integral_constant.hpp>
#include<std/is_const.hpp>
#include<std/is_reference.hpp>
namespace std{
    template<typename T>
    struct is_function : integral_constant<bool,!is_const<const T>::value && !is_reference<T>::value>{};
};
#endif