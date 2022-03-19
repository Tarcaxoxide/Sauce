#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/efiMemory.hpp>


namespace Sauce{
    uint64_t GetMemorySize(Sauce::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize);
    void memset(void* address,uint8_t value,uint64_t size);
};