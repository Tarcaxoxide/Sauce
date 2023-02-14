#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        namespace Management{
            uint64_t pageBitmapIndex=0;
            uint64_t freeMemory;
            uint64_t reservedMemory;
            uint64_t usedMemory;
            bool Initialized=false;
            void PageFrameAllocator_cl::ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::ReadEfiMemoryMap",_NAMESPACE_,_ALLOW_PRINT_);
                if(Initialized){return;}
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
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::InitializeBitmap",_NAMESPACE_,_ALLOW_PRINT_);
                PageBitmap.Size=bitmapSize;
                PageBitmap.Buffer = (uint8_t*)bufferAddress;
                for(int i=0;i<bitmapSize;i++){
                    *(uint8_t*)(PageBitmap.Buffer + i) = 0;
                }
            }
            void PageFrameAllocator_cl::FreePage(void* address){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::FreePage",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t index = (uint64_t)address / 4096;
                if(PageBitmap[index] == false)return;
                if(PageBitmap.Set(index,false)){
                    if(index < pageBitmapIndex)pageBitmapIndex=index;
                    freeMemory+=4096;
                    usedMemory-=4096;
                }
            }
            void PageFrameAllocator_cl::LockPage(void* address){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::LockPage",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t index = (uint64_t)address / 4096;
                if(PageBitmap[index] == true)return;
                if(PageBitmap.Set(index,true)){
                    freeMemory-=4096;
                    usedMemory+=4096;
                }
            }
            void PageFrameAllocator_cl::ReleasePage(void* address){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::ReleasePage",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t index = (uint64_t)address / 4096;
                if(PageBitmap[index] == false)return;
                if(PageBitmap.Set(index,false)){
                    if(index < pageBitmapIndex)pageBitmapIndex=index;
                    freeMemory+=4096;
                    reservedMemory-=4096;
                }
            }
            void PageFrameAllocator_cl::ReservePage(void* address){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::ReservePage",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t index = (uint64_t)address / 4096;
                if(PageBitmap[index] == true)return;
                if(PageBitmap.Set(index,true)){
                    freeMemory-=4096;
                    reservedMemory+=4096;
                }
            }
            void PageFrameAllocator_cl::FreePages(void* address,uint64_t pageCount){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::FreePages",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t t=0;t<pageCount;t++){
                    FreePage((void*)((uint64_t)address+(t*4096)));
                }
            }
            void PageFrameAllocator_cl::LockPages(void* address,uint64_t pageCount){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::LockPages",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t t=0;t<pageCount;t++){
                    LockPage((void*)((uint64_t)address+(t*4096)));
                }
            }
            void PageFrameAllocator_cl::ReservePages(void* address,uint64_t pageCount){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::ReservePages",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t t=0;t<pageCount;t++){
                    ReservePage((void*)((uint64_t)address+(t*4096)));
                }
            }
            void PageFrameAllocator_cl::ReleasePages(void* address,uint64_t pageCount){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::ReleasePages",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t t=0;t<pageCount;t++){
                    ReleasePage((void*)((uint64_t)address+(t*4096)));
                }
            }
            uint64_t PageFrameAllocator_cl::GetFreeRAM(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::GetFreeRAM",_NAMESPACE_,_ALLOW_PRINT_);
                return freeMemory;
            }
            uint64_t PageFrameAllocator_cl::GetUsedRAM(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::GetUsedRAM",_NAMESPACE_,_ALLOW_PRINT_);
                return usedMemory;
            }
            uint64_t PageFrameAllocator_cl::GetReservedRAM(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::GetReservedRAM",_NAMESPACE_,_ALLOW_PRINT_);
                return reservedMemory;
            }
            uint64_t PageFrameAllocator_cl::GetTotalRAM(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::GetTotalRAM",_NAMESPACE_,_ALLOW_PRINT_);
                size_t Ret = GetFreeRAM()+GetUsedRAM()+GetReservedRAM();
                return Ret;
            }
            void* PageFrameAllocator_cl::RequestPage(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PageFrameAllocator_cl::RequestPage",_NAMESPACE_,_ALLOW_PRINT_);
                for(;pageBitmapIndex<PageBitmap.Size*8;pageBitmapIndex++){
                    if(PageBitmap[pageBitmapIndex] == true)continue;
                    void* TheAddress = (void*)(pageBitmapIndex*4096);
                    LockPage(TheAddress);
                    return TheAddress;
                }
                //TODO::Page Frame Swap to file
                return NULL;
            }
        };
    };
};