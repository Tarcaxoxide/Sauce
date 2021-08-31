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
            uint64_t MemorySegmentAddress;
            uint64_t Alignment;
            MemorySegmentHeader* NextSegment;
            MemorySegmentHeader* NextFreeSegment;
            MemorySegmentHeader* PreviousFreeSegment;
            MemorySegmentHeader* PreviousSegment;
            bool Free;
        };


        static bool MemoryRegionsGot = false;
        static uint64_t UsableMemoryRegionCount=0;
        static MemoryMapEntry* UsableMemoryRegions[10];


        void memset(void* address,uint64_t val,uint64_t size);
        void InitializeHeap(uint64_t HeapAddress,uint64_t HeapLength);
        void* realloc(void* address,uint64_t size);
        void* calloc(uint64_t size,uint64_t alighnment);
        void* alloc(uint64_t size,uint32_t Alignment);
        void* malloc(uint64_t size,uint32_t Alignment);
        void memcpy(void* Source,void* Destination,uint64_t size);
        void free(void* address);
        void allocarr(char** pointers, int bytes, int slots);
        void CombinedSegments(MemorySegmentHeader* a,MemorySegmentHeader* b);
        MemoryMapEntry** GetUsableMemoryRegions();
        uint64_t GetFreeHeap();
        
    };
};