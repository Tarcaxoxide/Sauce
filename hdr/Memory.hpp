#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Terminal.hpp>
#include <Convert.hpp>

namespace Sauce{
    namespace Memory{
        struct MemoryMapEntry{
            uint64_t BaseAddress;
            uint64_t Region_Length;
            uint32_t Region_Type;
            uint32_t ExtendedAttributes;
        };
        struct MemoryMapEntryMap{
            MemoryMapEntry** MemoryMapEntries;
            uint8_t MemoryMapEntryCount;
        };
        void PrintMemoryMap(MemoryMapEntry* MemoryMap);
        void PrintMemoryMap_All();
        MemoryMapEntryMap GetMemoryRegions(uint32_t Type=1);
    };
};