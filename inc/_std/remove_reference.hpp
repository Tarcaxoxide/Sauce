#pragma once
namespace _std{
    template <typename T>
    struct remove_reference { typedef T type; };
    template <typename T>
    struct remove_reference<const T> { typedef const T type; };
    template <typename T>
    struct remove_reference<T&> { typedef T type; };
    template <typename T>
    struct remove_reference<const T&> { typedef const T type; };
};