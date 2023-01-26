#pragma once

namespace _std{
    template< bool B, typename T, typename F >
    struct conditional{
        #if B
            T type;
        #else
            F type;
        #endif
    };
};