#pragma once

#include<Sauce/Math/Types.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        struct HeapSegmentHeader{
            size_t Length;
            HeapSegmentHeader* NextSegment=nullptr;
            HeapSegmentHeader* LastSegment=nullptr;
            bool free;
            void CombinedForward();
            void CombinedBackward();
            HeapSegmentHeader* Split(size_t splitLength);
        };
        void InitalizeHeap(void* heapAddress,size_t PageCount);
        void* malloc(size_t size);
        void free(void* address);
        void ExpandHeap(size_t length);
    };
};

void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* ptr);
void operator delete[](void* ptr);

void operator delete(void* ptr,size_t Sz);
void operator delete[](void* ptr,size_t Sz);
