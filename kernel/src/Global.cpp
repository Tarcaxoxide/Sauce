#include <Sauce/Global.hpp>



namespace Sauce{
	namespace Global{
		Sauce::Kernel_cl* Kernel;
		Sauce::Graphics::Basic::Terminal_cl* Terminal=nullptr;
		Sauce::Graphics::Basic::Terminal_cl* Screen;
		Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
		Sauce::Graphics::Shell_cl* Shell;
		Sauce::Memory::Management::PageFrameAllocator_cl PageFrameAllocator;
		Sauce::Graphics::Mouse_cl* Mouse=nullptr;
		Sauce::Memory::Management::PageTableManager_cl PageTableManager=NULL;
		Sauce::Storage::AHCIDriver_cl* AHCIDriver=nullptr;
	};
};



