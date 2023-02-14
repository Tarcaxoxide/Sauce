#pragma once
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Graphics/Window.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/Memory/List.hpp>
#include<Sauce/Kernel.hpp>
namespace Sauce{
    namespace Global{
        extern Sauce::Kernel_cl* Kernel;
        extern Sauce::Graphics::Basic::Terminal_cl* Terminal; //<- represents the entire screen. effectively a "double buffer"
        extern Sauce::Graphics::Basic::Terminal_cl* Screen; //<- the actual screen(hopefully).
        extern Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
        extern Sauce::Graphics::Shell_cl* Shell;
        extern Sauce::Memory::Management::PageFrameAllocator_cl PageFrameAllocator;
        extern Sauce::Graphics::Mouse_cl* Mouse;
        extern Sauce::Memory::Management::PageTableManager_cl PageTableManager;
        extern Sauce::Storage::AHCIDriver_cl* AHCIDriver;
    };
};