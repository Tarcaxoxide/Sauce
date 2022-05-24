#pragma once
#include<stddef.h>
#include<stdint.h>

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>


namespace Sauce{
    namespace Global{
        extern Sauce::Graphics::Terminal_cl* Terminal;
        extern Sauce::Graphics::Shell_cl* Shell;
        extern Sauce::Memory::PageFrameAllocator Allocator;
    };
};