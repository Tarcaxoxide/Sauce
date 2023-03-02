#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Memory{
		namespace Management{
			PageMapIndexer::PageMapIndexer(uint64_t virtualAddress){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageMapIndexer::PageMapIndexer",_NAMESPACE_,_ALLOW_PRINT_);
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
};