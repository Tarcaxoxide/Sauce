#include <Sauce/Global.hpp>

#include<Sauce/Memory/SmartPtr.hpp>

namespace Sauce{
	namespace Global{
		Sauce::Core::Kernel_cl* Kernel;
		namespace Graphics{
			Sauce::Graphics::Basic::Terminal_cl* Terminal=nullptr;
			Sauce::Graphics::Basic::Terminal_cl* Screen;
			Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
			Sauce::Graphics::Shell::Shell_cl* Shell;
			Sauce::Graphics::Mouse_cl* Mouse=nullptr;
		};
		namespace Memory{
			Sauce::Memory::Management::PageFrameAllocator_cl PageFrameAllocator;
			Sauce::Memory::Management::PageTableManager_cl PageTableManager=NULL;
		};
		namespace Filesystem{
			Sauce::Filesystem::Blob::Blob_st RootDirectory(Sauce::Memory::SmartPtr_cl<char,9>('.'),Sauce::Memory::SmartPtr_cl<char,4>('\0'),Sauce::Filesystem::Header::Classification_en::Classification_Directory);
		};
		namespace Hardware{
			Sauce::IO::RTC::RTC_cl RTC;
		};
		namespace Storage{
			Sauce::Memory::List_cl<Sauce::Storage::AHCIDriver_cl*> AHCIDrivers;
		};
		namespace Network{};
	};
};



