#pragma once

namespace _std{
    template<class T>
    struct remove_extent { using type = T; };
    template<class T>
    struct remove_extent<T[]> { using type = T; };
    template<class T, size_t N>
    struct remove_extent<T[N]> { using type = T; };
};