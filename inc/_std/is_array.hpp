#pragma once

namespace _std{
    template <typename T, size_t N=0>
    struct is_array{
        bool value=N;
    };
};