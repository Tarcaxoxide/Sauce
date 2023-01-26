#pragma once

#include<_std/integral_constant.hpp>
#include<_std/is_const.hpp>
#include<_std/is_reference.hpp>

namespace _std{
    template<class T>
    struct is_function : integral_constant<bool,!is_const<const T>::value && !is_reference<T>::value> {};
};