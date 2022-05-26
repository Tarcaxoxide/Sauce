#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t pageBitmapIndex=0;
        uint64_t freeMemory;
        uint64_t reservedMemory;
        uint64_t usedMemory;
        bool Initialized=false;
        void PageFrameAllocator::ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::ReadEfiMemoryMap]\n\0");
            if(Initialized)return;
            Initialized=true;
            uint64_t mMapEntries = mMapSize/mDescriptorSize;
            void* LargestFreeMemorySegment=NULL;
            size_t LargestFreeMemorySegmentSize=0;
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                if(descriptor->type == EfiMemoryType_EfiConventionalMemory){
                    if(descriptor->numPages*4096 > LargestFreeMemorySegmentSize){
                        LargestFreeMemorySegment=descriptor->physAddr;
                        LargestFreeMemorySegmentSize=descriptor->numPages*4096;
                    }
                }

            }
            uint64_t memorySize = GetMemorySize(mMap,mMapEntries,mDescriptorSize);
            freeMemory=memorySize;
            uint64_t bitmapSize = memorySize / 4096 / 8 + 1;
            InitializeBitmap(bitmapSize,LargestFreeMemorySegment);

            ReservePages(0,memorySize/4096+1);
            
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                if(descriptor->type == EfiMemoryType_EfiConventionalMemory){
                    ReleasePages(descriptor->physAddr,descriptor->numPages);
                }
            }
            ReservePages(0,0x100);// reserver between 0 and 0x100000 , protect the bios!
            LockPages(PageBitmap.Buffer,PageBitmap.Size/4096 + 1);
            // reserve pages of unusable/reserved memory
        }
        void PageFrameAllocator::InitializeBitmap(size_t bitmapSize,void* bufferAddress){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::InitializeBitmap]\n\0");
            PageBitmap.Size=bitmapSize;
            PageBitmap.Buffer = (uint8_t*)bufferAddress;
            for(int i=0;i<bitmapSize;i++){
                *(uint8_t*)(PageBitmap.Buffer + i) = 0;
            }
        }
        void PageFrameAllocator::FreePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::FreePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                usedMemory-=4096;
            }
        }
        void PageFrameAllocator::LockPage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::LockPage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                usedMemory+=4096;
            }
        }
        void PageFrameAllocator::ReleasePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::ReleasePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                reservedMemory-=4096;
            }
        }
        void PageFrameAllocator::ReservePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::ReservePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                reservedMemory+=4096;
            }
        }
        void PageFrameAllocator::FreePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::FreePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                FreePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator::LockPages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::LockPages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                LockPage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator::ReservePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::ReservePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                ReservePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator::ReleasePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::ReleasePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                ReleasePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        uint64_t PageFrameAllocator::GetFreeRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::GetFreeRAM]\n\0");
            return freeMemory;
        }
        uint64_t PageFrameAllocator::GetUsedRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::GetUsedRAM]\n\0");
            return usedMemory;
        }
        uint64_t PageFrameAllocator::GetReservedRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::GetReservedRAM]\n\0");
            return reservedMemory;
        }
        uint64_t PageFrameAllocator::GetTotalRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::GetTotalRAM]\n\0");
            return GetFreeRAM()+GetUsedRAM()+GetReservedRAM();
        }
        void* PageFrameAllocator::RequestPage(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator::RequestPage]\n\0");
            for(;pageBitmapIndex<PageBitmap.Size*8;pageBitmapIndex++){
                if(PageBitmap[pageBitmapIndex] == true)continue;
                LockPage((void*)(pageBitmapIndex*4096));
                return (void*)(pageBitmapIndex*4096);
            }
            //TODO::Page Frame Swap to file
            return NULL;
        }
    };
};