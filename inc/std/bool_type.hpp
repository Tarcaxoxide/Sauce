#ifndef __std_bool_type
#define __std_bool_type
#include<std/integral_constant.hpp>
namespace std{
    typedef integral_constant<bool, false> false_type;
    typedef integral_constant<bool, true> true_type; 
};
#endif