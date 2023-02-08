#include<_std/exception.hpp>
#pragma once
namespace _std{
    template<typename T>
    struct is_const{
        bool value=false;
        is_const(){
            try{
                T xx;
                xx = (T)0x00;
            }catch(const exception& e){ // ?Does this even work?
                value=true;
            }
        }
    };
};
