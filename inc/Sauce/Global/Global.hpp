#pragma once
#include<stddef.h>
#include<stdint.h>

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Storage/AHCI.hpp>


namespace Sauce{
    namespace Global{
        extern Sauce::Graphics::Terminal_cl* Terminal;
        extern Sauce::Graphics::Shell_cl* Shell;
        extern Sauce::Memory::PageFrameAllocator_cl PageFrameAllocator;
        extern Sauce::Graphics::Mouse_cl* Mouse;
        extern Sauce::Memory::PageTableManager_cl PageTableManager;
        extern Sauce::Storage::AHCIDriver_cl* AHCIDriver;
    };
};