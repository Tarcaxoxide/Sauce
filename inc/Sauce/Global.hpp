#ifndef __Sauce_Global
#define __Sauce_Global
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
#include<Sauce/Network/AM78C973/Driver.hpp>
#include<Sauce/Filesystem/Directory.hpp>
#include<Sauce/IO/RTC.hpp>
namespace Sauce{
	namespace Global{
		extern Sauce::Kernel_cl* Kernel;
		namespace Graphics{
			extern Sauce::Graphics::Basic::Terminal_cl* Terminal; //<- represents the entire screen. effectively a "double buffer"
			extern Sauce::Graphics::Basic::Terminal_cl* Screen; //<- the actual screen(hopefully).
			extern Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
			extern Sauce::Graphics::Shell_cl* Shell;
			extern Sauce::Graphics::Mouse_cl* Mouse;
		};
		namespace Memory{
			extern Sauce::Memory::Management::PageFrameAllocator_cl PageFrameAllocator;
			extern Sauce::Memory::Management::PageTableManager_cl PageTableManager;
		};
		namespace Filesystem{
			extern Sauce::Filesystem::Directory::Directory_st* Root;
		};
		namespace Hardware{
			extern Sauce::IO::RTC::RTC_cl RTC;
		};
		namespace Storage{
			extern Sauce::Memory::List_cl<Sauce::Storage::AHCIDriver_cl*> AHCIDrivers;
		};
		namespace Network{
			extern Sauce::Memory::List_cl<Sauce::Network::AM78C973::Driver_cl*> AM78C973Drivers;
		};
	};
};
#endif