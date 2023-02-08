#pragma once

#include<_std/move.hpp>

namespace _std{
    template<typename T> void swap(T& t1, T& t2) {
        T temp = move(t1); // or T temp(_std::move(t1));
        t1 = move(t2);
        t2 = move(temp);
    }
};
