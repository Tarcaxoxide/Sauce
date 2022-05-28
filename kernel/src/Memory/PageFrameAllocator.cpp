#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t pageBitmapIndex=0;
        uint64_t freeMemory;
        uint64_t reservedMemory;
        uint64_t usedMemory;
        bool Initialized=false;
        void PageFrameAllocator_cl::ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::ReadEfiMemoryMap]\n\0");
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
        void PageFrameAllocator_cl::InitializeBitmap(size_t bitmapSize,void* bufferAddress){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::InitializeBitmap]\n\0");
            PageBitmap.Size=bitmapSize;
            PageBitmap.Buffer = (uint8_t*)bufferAddress;
            for(int i=0;i<bitmapSize;i++){
                *(uint8_t*)(PageBitmap.Buffer + i) = 0;
            }
        }
        void PageFrameAllocator_cl::FreePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::FreePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                usedMemory-=4096;
            }
        }
        void PageFrameAllocator_cl::LockPage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::LockPage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                usedMemory+=4096;
            }
        }
        void PageFrameAllocator_cl::ReleasePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::ReleasePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                reservedMemory-=4096;
            }
        }
        void PageFrameAllocator_cl::ReservePage(void* address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::ReservePage]\n\0");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                reservedMemory+=4096;
            }
        }
        void PageFrameAllocator_cl::FreePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::FreePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                FreePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::LockPages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::LockPages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                LockPage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::ReservePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::ReservePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                ReservePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::ReleasePages(void* address,uint64_t pageCount){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::ReleasePages]\n\0");
            for(size_t t=0;t<pageCount;t++){
                ReleasePage((void*)((uint64_t)address+(t*4096)));
            }
        }
        uint64_t PageFrameAllocator_cl::GetFreeRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::GetFreeRAM]\n\0");
            return freeMemory;
        }
        uint64_t PageFrameAllocator_cl::GetUsedRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::GetUsedRAM]\n\0");
            return usedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetReservedRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::GetReservedRAM]\n\0");
            return reservedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetTotalRAM(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::GetTotalRAM]\n\0");
            return GetFreeRAM()+GetUsedRAM()+GetReservedRAM();
        }
        void* PageFrameAllocator_cl::RequestPage(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageFrameAllocator_cl::RequestPage]\n\0");
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