#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t pageBitmapIndex=0;
        uint64_t freeMemory;
        uint64_t reservedMemory;
        uint64_t usedMemory;
        bool Initialized=false;
        void PageFrameAllocator_cl::ReadEfiMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::ReadEfiMemoryMap",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            if(Initialized){Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);return;}
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
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::InitializeBitmap(size_t bitmapSize,void* bufferAddress){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::InitializeBitmap",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            PageBitmap.Size=bitmapSize;
            PageBitmap.Buffer = (uint8_t*)bufferAddress;
            for(int i=0;i<bitmapSize;i++){
                *(uint8_t*)(PageBitmap.Buffer + i) = 0;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::FreePage(void* address){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::FreePage",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                usedMemory-=4096;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::LockPage(void* address){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::LockPage",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                usedMemory+=4096;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::ReleasePage(void* address){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::ReleasePage",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                reservedMemory-=4096;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::ReservePage(void* address){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::ReservePage",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(index,true)){
                freeMemory-=4096;
                reservedMemory+=4096;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::FreePages(void* address,uint64_t pageCount){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::FreePages",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            for(size_t t=0;t<pageCount;t++){
                FreePage((void*)((uint64_t)address+(t*4096)));
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::LockPages(void* address,uint64_t pageCount){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::LockPages",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            for(size_t t=0;t<pageCount;t++){
                LockPage((void*)((uint64_t)address+(t*4096)));
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::ReservePages(void* address,uint64_t pageCount){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::ReservePages",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            for(size_t t=0;t<pageCount;t++){
                ReservePage((void*)((uint64_t)address+(t*4096)));
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        void PageFrameAllocator_cl::ReleasePages(void* address,uint64_t pageCount){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::ReleasePages",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            for(size_t t=0;t<pageCount;t++){
                ReleasePage((void*)((uint64_t)address+(t*4096)));
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
        }
        uint64_t PageFrameAllocator_cl::GetFreeRAM(){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::GetFreeRAM",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(freeMemory),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            return freeMemory;
        }
        uint64_t PageFrameAllocator_cl::GetUsedRAM(){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::GetUsedRAM",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(usedMemory),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            return usedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetReservedRAM(){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::GetReservedRAM",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(reservedMemory),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            return reservedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetTotalRAM(){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::GetTotalRAM",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            size_t Ret = GetFreeRAM()+GetUsedRAM()+GetReservedRAM();
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(Ret),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            return Ret;
        }
        void* PageFrameAllocator_cl::RequestPage(){
            Sauce::IO::Debug::Print_Spammy_Call("PageFrameAllocator_cl::RequestPage",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            for(;pageBitmapIndex<PageBitmap.Size*8;pageBitmapIndex++){
                if(PageBitmap[pageBitmapIndex] == true)continue;
                void* TheAddress = (void*)(pageBitmapIndex*4096);
                LockPage(TheAddress);
                Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::HexToString((uint64_t)TheAddress),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
                return TheAddress;
            }
            //TODO::Page Frame Swap to file
            Sauce::IO::Debug::Print_Spammy_Return("NULL",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::ALLOCATOR);
            return NULL;
        }
    };
};