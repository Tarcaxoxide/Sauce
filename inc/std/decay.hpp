#ifndef __std_decay
#define __std_decay
#include<std/remove_reference.hpp>
#include<std/conditional.hpp>
#include<std/is_array.hpp>
#include<std/add_pointer.hpp>
#include<std/remove_extent.hpp>
#include<std/is_function.hpp>
#include<std/remove_cv.hpp>
namespace std{
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
#endif