#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>

namespace Sauce{
    namespace Memory{
        struct HeapSegmentHeader{
            size_t Length;
            HeapSegmentHeader* NextSegment;
            HeapSegmentHeader* LastSegment;
            bool free;
            void CombinedForward();
            void CombinedBackward();
            HeapSegmentHeader* Split(size_t splitLength);
        };
        void InitalizeHeap(void* heapAddress,size_t PageCount,size_t SizeAlignment=0x10);
        void* malloc(size_t size);
        void free(void* address);
        void ExpandHeap(size_t length);
    };
};