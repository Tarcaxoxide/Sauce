#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        class PageFrameAllocator_cl{
            public:
            Bitmap_t PageBitmap;
            void ReadEfiMemoryMap(Sauce::IO::Debug::Debugger_st* pDebugger,EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize);
            void FreePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address);
            void LockPage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address);
            void FreePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount);
            void LockPages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount);
            void* RequestPage(Sauce::IO::Debug::Debugger_st* pDebugger);
            uint64_t GetFreeRAM(Sauce::IO::Debug::Debugger_st* pDebugger);
            uint64_t GetUsedRAM(Sauce::IO::Debug::Debugger_st* pDebugger);
            uint64_t GetReservedRAM(Sauce::IO::Debug::Debugger_st* pDebugger);
            uint64_t GetTotalRAM(Sauce::IO::Debug::Debugger_st* pDebugger);
            private:
            void InitializeBitmap(Sauce::IO::Debug::Debugger_st* pDebugger,size_t bitmapSize,void* bufferAddress);
            void ReservePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address);
            void ReleasePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address);
            void ReservePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount);
            void ReleasePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount);
        };
    };
};