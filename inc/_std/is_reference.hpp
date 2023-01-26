#pragma once

#include<_std/bool_type.hpp>

namespace _std{
    template <class T> struct is_reference      : false_type {};
    template <class T> struct is_reference<T&>  : true_type {};
    template <class T> struct is_reference<T&&> : true_type {};
};