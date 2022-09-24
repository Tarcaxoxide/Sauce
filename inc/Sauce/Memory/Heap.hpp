#pragma once

#include<Sauce/Types.hpp>
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
            void CombinedForward(Sauce::IO::Debug::Debugger_st* pDebugger);
            void CombinedBackward(Sauce::IO::Debug::Debugger_st* pDebugger);
            HeapSegmentHeader* Split(Sauce::IO::Debug::Debugger_st* pDebugger,size_t splitLength);
        };
        void InitalizeHeap(Sauce::IO::Debug::Debugger_st* pDebugger,void* heapAddress,size_t PageCount);
        void* malloc(Sauce::IO::Debug::Debugger_st* pDebugger,size_t size);
        void free(Sauce::IO::Debug::Debugger_st* pDebugger,void* address);
        void ExpandHeap(Sauce::IO::Debug::Debugger_st* pDebugger,size_t length);
    };
};

inline void* operator new(size_t size){return Sauce::Memory::malloc(nullptr,size);}
inline void* operator new[](size_t size){return Sauce::Memory::malloc(nullptr,size);}
inline void operator delete(void* ptr){Sauce::Memory::free(nullptr,ptr);}
inline void operator delete[](void* ptr){Sauce::Memory::free(nullptr,ptr);}

inline void operator delete(void* ptr,size_t Sz){Sauce::Memory::free(nullptr,ptr);}
inline void operator delete[](void* ptr,size_t Sz){Sauce::Memory::free(nullptr,ptr);}