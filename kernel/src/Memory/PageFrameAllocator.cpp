#include<Sauce/Memory/PageFrameAllocator.hpp>

namespace Sauce{
    PageFrameAllocator GlobalAllocator;
    uint64_t freeMemory;
    uint64_t reservedMemory;
    uint64_t usedMemory;
    bool Initialized=false;
    void PageFrameAllocator::ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
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
        
        LockPages(&PageBitmap,PageBitmap.Size/4096 + 1);
        for(int i=0;i<mMapEntries;i++){
            EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
            if(descriptor->type != EfiMemoryType_EfiConventionalMemory){
                ReservePages(descriptor->physAddr,descriptor->numPages);
            }
        }
        // reserve pages of unusable/reserved memory

    }
    void PageFrameAllocator::InitializeBitmap(size_t bitmapSize,void* bufferAddress){
        PageBitmap.Size=bitmapSize;
        PageBitmap.Buffer = (uint8_t*)bufferAddress;
        for(int i=0;i<bitmapSize;i++){
            *(uint8_t*)(PageBitmap.Buffer + i) = 0;
        }
    }
    void PageFrameAllocator::FreePage(void* address){
        uint64_t index = (uint64_t)address / 4096;
        if(PageBitmap[index] == false)return;
        if(PageBitmap.Set(index,false)){
            freeMemory+=4096;
            usedMemory-=4096;
        }
    }
    void PageFrameAllocator::LockPage(void* address){
        uint64_t index = (uint64_t)address / 4096;
        if(PageBitmap[index] == true)return;
        if(PageBitmap.Set(index,true)){
            freeMemory-=4096;
            usedMemory+=4096;
        }
    }

    void PageFrameAllocator::ReleasePage(void* address){
        uint64_t index = (uint64_t)address / 4096;
        if(PageBitmap[index] == false)return;
        if(PageBitmap.Set(index,false)){
            freeMemory+=4096;
            reservedMemory-=4096;
        }
    }
    void PageFrameAllocator::ReservePage(void* address){
        uint64_t index = (uint64_t)address / 4096;
        if(PageBitmap[index] == true)return;
        if(PageBitmap.Set(index,true)){
            freeMemory-=4096;
            reservedMemory+=4096;
        }
    }
    void PageFrameAllocator::FreePages(void* address,uint64_t pageCount){
        for(size_t t=0;t<pageCount;t++){
            FreePage((void*)((uint64_t)address+(t*4096)));
        }
    }
    void PageFrameAllocator::LockPages(void* address,uint64_t pageCount){
        for(size_t t=0;t<pageCount;t++){
            LockPage((void*)((uint64_t)address+(t*4096)));
        }
    }
    void PageFrameAllocator::ReservePages(void* address,uint64_t pageCount){
        for(size_t t=0;t<pageCount;t++){
            ReservePage((void*)((uint64_t)address+(t*4096)));
        }
    }
    void PageFrameAllocator::ReleasePages(void* address,uint64_t pageCount){
        for(size_t t=0;t<pageCount;t++){
            ReleasePage((void*)((uint64_t)address+(t*4096)));
        }
    }
    uint64_t PageFrameAllocator::GetFreeRAM(){
        return freeMemory;
    }
    uint64_t PageFrameAllocator::GetUsedRAM(){
        return usedMemory;
    }
    uint64_t PageFrameAllocator::GetReservedRAM(){
        return reservedMemory;
    }
    void* PageFrameAllocator::RequestPage(){
        for(uint64_t index=0;index<PageBitmap.Size*8;index++){
            if(PageBitmap[index] == true)continue;
            LockPage((void*)(index*4096));
            return (void*)(index*4096);
        }
        //TODO::Page Frame Swap to file
        return NULL;
    }
};