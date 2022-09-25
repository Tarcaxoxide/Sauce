#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Graphics{
        class Window_cl : public Shell_cl {
            public:
            Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
        };
    };
};
