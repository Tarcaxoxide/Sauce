#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/Memory.hpp>

namespace Sauce{
    namespace Memory{
        class PageFrameAllocator{
            public:
            Bitmap_t PageBitmap;
            void ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize);
            void FreePage(void* address);
            void LockPage(void* address);
            void FreePages(void* address,uint64_t pageCount);
            void LockPages(void* address,uint64_t pageCount);
            void* RequestPage();
            uint64_t GetFreeRAM();
            uint64_t GetUsedRAM();
            uint64_t GetReservedRAM();
            uint64_t GetTotalRAM();
            private:
            void InitializeBitmap(size_t bitmapSize,void* bufferAddress);
            void ReservePage(void* address);
            void ReleasePage(void* address);
            void ReservePages(void* address,uint64_t pageCount);
            void ReleasePages(void* address,uint64_t pageCount);
        };
    };
};