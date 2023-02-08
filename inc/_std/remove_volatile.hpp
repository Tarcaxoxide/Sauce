#pragma once
namespace _std{
    template<typename T> struct remove_volatile             { typedef T type; };
    template<typename T> struct remove_volatile<volatile T> { typedef T type; };
};
