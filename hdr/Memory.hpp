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
            MemorySegmentHeader* NextSegment=0;
            MemorySegmentHeader* PreviousSegment=0;
            MemorySegmentHeader* NextFreeSegment=0;
            MemorySegmentHeader* PreviousFreeSegment=0;
            uint64_t TheAlignment;
            uint64_t MemorySegmentAddress;
            bool Free;
        };

        void memset(void* address,uint64_t val,uint64_t size);
        void InitializeHeap(uint64_t HeapAddress,uint64_t HeapLength);
        void* realloc(void* address,uint64_t size);
        void* alloc(uint64_t size,uint64_t alighnment=0x0000000000000001);
        void* calloc(uint64_t size,uint64_t alighnment);
        void* malloc(uint64_t size);
        void memcpy(void* Source,void* Destination,uint64_t size);
        void free(void* address);
        void CombinedSegments(MemorySegmentHeader* a,MemorySegmentHeader* b);
    };
};