#include<_std/bool_type.hpp>
#pragma once
namespace _std{
    template <typename T> struct is_reference      : false_type {};
    template <typename T> struct is_reference<T&>  : true_type {};
    template <typename T> struct is_reference<T&&> : true_type {};
};
