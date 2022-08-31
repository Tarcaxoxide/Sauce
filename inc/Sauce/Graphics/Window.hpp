#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Graphics{
        class Window_cl : public Terminal_cl {
            Sauce::Memory::List_cl<Sauce::Graphics::Window_cl> SubWindows;
            public:
        };
    };
};
