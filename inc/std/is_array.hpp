#ifndef __std_is_array
#define __std_is_array
namespace std{
    template <typename T, size_t N=0>
    struct is_array{
        bool value=N;
    };
};
#endif