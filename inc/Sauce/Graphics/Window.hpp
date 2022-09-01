#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Graphics{
        class Window_cl : public Shell_cl {
            public:
            Window_cl(Sauce::Math::Point64_t Size,Sauce::Math::Point64_t Offset={0,0,0});
        };
    };
};
