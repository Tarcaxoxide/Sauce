#include<_std/remove_reference.hpp>
#include<_std/conditional.hpp>
#include<_std/is_array.hpp>
#include<_std/add_pointer.hpp>
#include<_std/remove_extent.hpp>
#include<_std/is_function.hpp>
#include<_std/remove_cv.hpp>
#pragma once
namespace _std{
    template<typename T>
    struct decay {
    private:
        typedef typename remove_reference<T>::type U;
    public:
        typedef typename conditional<
            is_array<U>::value,
            typename add_pointer<typename remove_extent<U>::type>::type,
            typename conditional<
                is_function<U>::value,
                typename add_pointer<U>::type,
                typename remove_cv<U>::type
            >::type
        >::type type;
    };
};
