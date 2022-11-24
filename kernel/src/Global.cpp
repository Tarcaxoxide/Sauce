#include <Sauce/Global.hpp>



namespace Sauce{
    namespace Global{
        Sauce::Kernel_cl* Kernel;
        Sauce::Graphics::Terminal_cl* Terminal=nullptr;
        Sauce::Graphics::Terminal_cl* Screen;
        Sauce::Memory::List_cl<Sauce::Graphics::Window_cl*> Windows;
        Sauce::Memory::PageFrameAllocator_cl PageFrameAllocator;
        Sauce::Graphics::Mouse_cl* Mouse=nullptr;
        Sauce::Memory::PageTableManager_cl PageTableManager=NULL;
        Sauce::Storage::AHCIDriver_cl* AHCIDriver=nullptr;
    };
};



