#pragma once

#include<Sauce/Graphics/Terminal.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
            public:
                Shell_cl(size_t X,size_t Y);
        };
    };
};