#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Graphics{
        class Window_cl : public Terminal_cl {
            Sauce::Memory::List_cl<Sauce::Graphics::Window_cl> SubWindows;
            public:
        };
    };
};
