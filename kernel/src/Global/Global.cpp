#include<Sauce/Global/Global.hpp>



namespace Sauce{
    namespace Global{
        Sauce::Graphics::Terminal_cl* Terminal=nullptr;
        Sauce::Graphics::Shell_cl* Shell=nullptr;
        Sauce::Memory::PageFrameAllocator_cl PageFrameAllocator;
        Sauce::Graphics::Mouse_cl* Mouse=nullptr;
        Sauce::Memory::PageTableManager_cl PageTableManager = NULL;
    };
};



