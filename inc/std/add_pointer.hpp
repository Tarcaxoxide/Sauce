#ifndef __std_detail
#define __std_detail
#include<std/remove_reference.hpp>
namespace std{
    namespace detail {
    template <typename T>
    struct type_identity { using type = T; };
    template <typename T>
    auto try_add_pointer(int) -> type_identity<typename std::remove_reference<T>::type*>;
    template <typename T>
    auto try_add_pointer(...) -> type_identity<T>;
    }
    template <typename T>
    struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};
};
#endif