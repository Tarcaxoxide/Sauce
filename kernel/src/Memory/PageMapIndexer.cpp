#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        PageMapIndexer::PageMapIndexer(uint64_t virtualAddress){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageMapIndexer::PageMapIndexer]\n\0");
            virtualAddress >>= 12;
            P_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PT_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PD_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PDP_i = virtualAddress & 0x1ff;
        }
    };
};