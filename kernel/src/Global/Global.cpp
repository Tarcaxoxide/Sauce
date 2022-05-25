#include<Sauce/Global/Global.hpp>



namespace Sauce{
    namespace Global{
        Sauce::Graphics::Terminal_cl* Terminal=nullptr;
        Sauce::Graphics::Shell_cl* Shell=nullptr;
        Sauce::Memory::PageFrameAllocator Allocator;
        Sauce::Graphics::Mouse_cl* Mouse=nullptr;
    };
};



