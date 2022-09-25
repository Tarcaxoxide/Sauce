#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        PageMapIndexer::PageMapIndexer(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t virtualAddress){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageMapIndexer::PageMapIndexer",_NAMESPACE_);
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