#pragma once

#include<_std/exception.hpp>

namespace _std{
    template<typename T>
    struct is_const{
        bool value=false;
        is_const(){
            try{
                T xx;
                xx = (T)0x00;
            }catch(const exception& e){
                value=true;
            }
        }
    };
};