#ifndef __Sauce_Memory_Memory
#define __Sauce_Memory_Memory
#include<Sauce/Memory/efiMemory.hpp>
namespace Sauce{
	namespace IO{
		namespace Debug{
			struct Debugger_st;
		};
	};
};

namespace Sauce{
	namespace Memory{
		uint64_t GetMemorySize(Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize);
		void memset(void* address,uint8_t value,uint64_t size);
		void memcpy(const void* srcPtr,const void* destPtr,size_t s);
		void memcpy(const void* srcPtr,const void* destPtr,size_t s,size_t ts);
		int64_t memcmp(const void* aptr,const void* bptr,size_t s);
	};
};
#endif