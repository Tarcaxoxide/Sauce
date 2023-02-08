#pragma once
namespace _std{
    template<typename T>
    struct remove_extent { using type = T; };
    template<typename T>
    struct remove_extent<T[]> { using type = T; };
    template<typename T, size_t N>
    struct remove_extent<T[N]> { using type = T; };
};
