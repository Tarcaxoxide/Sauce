#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>

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

inline void* operator new(size_t size){return Sauce::Memory::malloc(size);}
inline void* operator new[](size_t size){return Sauce::Memory::malloc(size);}
inline void operator delete(void* ptr){Sauce::Memory::free(ptr);}
inline void operator delete[](void* ptr){Sauce::Memory::free(ptr);}

inline void operator delete(void* ptr,size_t Sz){Sauce::Memory::free(ptr);}
inline void operator delete[](void* ptr,size_t Sz){Sauce::Memory::free(ptr);}