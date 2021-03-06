#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/efiMemory.hpp>


namespace Sauce{
    namespace Memory{
        uint64_t GetMemorySize(Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize);
        void memset(void* address,uint8_t value,uint64_t size);
        int64_t memcmp(const void* aptr,const void* bptr,size_t s);
    };
};