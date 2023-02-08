#pragma once
namespace _std{
    template<typename T> struct remove_const                { typedef T type; };
    template<typename T> struct remove_const<const T>       { typedef T type; };
};
