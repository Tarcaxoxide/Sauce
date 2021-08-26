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
    namespace Memory{
        struct MemorySegmentHeader{
            uint64_t MemoryLength;
            MemorySegmentHeader* NextSegment;
            MemorySegmentHeader* PreviousSegment;
            MemorySegmentHeader* NextFreeSegment;
            MemorySegmentHeader* PreviousFreeSegment;
            bool Free;
        };
        struct AlighnedMemorySegmentHeader{
            uint64_t MemorySegmentAddress;
            uint64_t TheAlignment;
        };
        void memset(void* address,uint64_t val,uint64_t size);
        void InitializeHead(uint64_t HeapAddress,uint64_t HeapLength);
        void* malloc(uint64_t size);
        void* calloc(uint64_t size);
        void* realloc(void* address,uint64_t size);
        void* aligned_alloc(uint64_t alighnment, uint64_t size);
        void* Sauce_alloc(uint64_t size,uint64_t alighnment=0);
        void memcpy(void* Source,void* Destination,uint64_t size);
        void free(void* address);
        void CombinedSegments(MemorySegmentHeader* a,MemorySegmentHeader* b);
    };
};