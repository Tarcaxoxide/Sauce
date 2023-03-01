#ifndef __std_remove_volatile
#define __std_remove_volatile
namespace std{
    template<typename T> struct remove_volatile             { typedef T type; };
    template<typename T> struct remove_volatile<volatile T> { typedef T type; };
};
#endif