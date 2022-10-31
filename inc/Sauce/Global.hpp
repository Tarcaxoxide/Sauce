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
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Storage/FileSystem/VirtualFileSystem.hpp>
#include<Sauce/Commands.hpp>

namespace Sauce{
    namespace Global{
        extern Sauce::Graphics::Terminal_cl* Terminal; //<- represents the entire screen. effectively a "double buffer"
        extern Sauce::Graphics::Terminal_cl* Screen; //<- the actual screen(hopefully).
        extern Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
        extern Sauce::Graphics::Shell_cl* Shell;
        extern Sauce::Memory::PageFrameAllocator_cl PageFrameAllocator;
        extern Sauce::Graphics::Mouse_cl* Mouse;
        extern Sauce::Memory::PageTableManager_cl PageTableManager;
        extern Sauce::Storage::AHCIDriver_cl* AHCIDriver;
        extern Sauce::Storage::FileSystem::VirtualFileSystem::FilesystemManager_cl FilesystemManager;
        extern Sauce::Commands::Command_st BaseCommand;
    };
};