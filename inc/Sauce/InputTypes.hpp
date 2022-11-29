#pragma once

#include<Sauce/Math/Types.hpp>

namespace Sauce{
    namespace InputTypes{
        struct Mouse_st{
            bool RightButton;
            bool LeftButton;
            bool CenterButton;
        	Point64_st* Position;
            bool Good;
        };
    };
};