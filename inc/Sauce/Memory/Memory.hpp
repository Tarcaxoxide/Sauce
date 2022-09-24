#pragma once

#include<Sauce/Types.hpp>
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
        uint64_t GetMemorySize(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize);
        void memset(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint8_t value,uint64_t size);
        void memcpy(Sauce::IO::Debug::Debugger_st* pDebugger,const void* srcPtr,const void* destPtr,size_t s);
        int64_t memcmp(Sauce::IO::Debug::Debugger_st* pDebugger,const void* aptr,const void* bptr,size_t s);
    };
};