#pragma once

#include<_std/remove_reference.hpp>

namespace _std{
    namespace detail {
    template <typename T>
    struct type_identity { using type = T; };
    template <typename T>
    auto try_add_pointer(int) -> type_identity<typename _std::remove_reference<T>::type*>;
    template <typename T>
    auto try_add_pointer(...) -> type_identity<T>;
    }
    template <class T>
    struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};
};