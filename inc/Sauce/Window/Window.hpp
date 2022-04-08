#pragma once

#include<Sauce/Math.hpp>

namespace Sauce{
    namespace Window{
        struct Window_t{
            Sauce::uPoint64_t Size;
            Window_t* SubWindows=NULL;
            void* Content=NULL;
        };
    };
};