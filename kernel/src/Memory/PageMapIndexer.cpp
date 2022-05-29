#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        PageMapIndexer::PageMapIndexer(uint64_t virtualAddress){
            Sauce::IO::Debug::Print_Spammy_Call("PageMapIndexer::PageMapIndexer",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::INDEXER);
            virtualAddress >>= 12;
            P_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PT_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PD_i = virtualAddress & 0x1ff;
            virtualAddress >>= 9;
            PDP_i = virtualAddress & 0x1ff;
            Sauce::IO::Debug::Print_Spammy_Return("this",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::INDEXER);
        }
    };
};