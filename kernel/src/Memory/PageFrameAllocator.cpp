#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t pageBitmapIndex=0;
        uint64_t freeMemory;
        uint64_t reservedMemory;
        uint64_t usedMemory;
        bool Initialized=false;
        void PageFrameAllocator_cl::ReadEfiMemoryMap(Sauce::IO::Debug::Debugger_st* pDebugger,EFI_MEMORY_DESCRIPTOR* mMap,size_t mMapSize,size_t mDescriptorSize){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::ReadEfiMemoryMap");
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
            uint64_t memorySize = GetMemorySize(&Debugger,mMap,mMapEntries,mDescriptorSize);
            freeMemory=memorySize;
            uint64_t bitmapSize = memorySize / 4096 / 8 + 1;
            InitializeBitmap(&Debugger,bitmapSize,LargestFreeMemorySegment);

            ReservePages(&Debugger,0,memorySize/4096+1);
            
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                if(descriptor->type == EfiMemoryType_EfiConventionalMemory){
                    ReleasePages(&Debugger,descriptor->physAddr,descriptor->numPages);
                }
            }
            ReservePages(&Debugger,0,0x100);// reserver between 0 and 0x100000 , protect the bios!
            LockPages(&Debugger,PageBitmap.Buffer,PageBitmap.Size/4096 + 1);
            // reserve pages of unusable/reserved memory
        }
        void PageFrameAllocator_cl::InitializeBitmap(Sauce::IO::Debug::Debugger_st* pDebugger,size_t bitmapSize,void* bufferAddress){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::InitializeBitmap");
            PageBitmap.Size=bitmapSize;
            PageBitmap.Buffer = (uint8_t*)bufferAddress;
            for(int i=0;i<bitmapSize;i++){
                *(uint8_t*)(PageBitmap.Buffer + i) = 0;
            }
        }
        void PageFrameAllocator_cl::FreePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::FreePage");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(&Debugger,index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                usedMemory-=4096;
            }
        }
        void PageFrameAllocator_cl::LockPage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::LockPage");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(&Debugger,index,true)){
                freeMemory-=4096;
                usedMemory+=4096;
            }
        }
        void PageFrameAllocator_cl::ReleasePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::ReleasePage");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == false)return;
            if(PageBitmap.Set(&Debugger,index,false)){
                if(index < pageBitmapIndex)pageBitmapIndex=index;
                freeMemory+=4096;
                reservedMemory-=4096;
            }
        }
        void PageFrameAllocator_cl::ReservePage(Sauce::IO::Debug::Debugger_st* pDebugger,void* address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::ReservePage");
            uint64_t index = (uint64_t)address / 4096;
            if(PageBitmap[index] == true)return;
            if(PageBitmap.Set(&Debugger,index,true)){
                freeMemory-=4096;
                reservedMemory+=4096;
            }
        }
        void PageFrameAllocator_cl::FreePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::FreePages");
            for(size_t t=0;t<pageCount;t++){
                FreePage(&Debugger,(void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::LockPages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::LockPages");
            for(size_t t=0;t<pageCount;t++){
                LockPage(&Debugger,(void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::ReservePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::ReservePages");
            for(size_t t=0;t<pageCount;t++){
                ReservePage(&Debugger,(void*)((uint64_t)address+(t*4096)));
            }
        }
        void PageFrameAllocator_cl::ReleasePages(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint64_t pageCount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::ReleasePages");
            for(size_t t=0;t<pageCount;t++){
                ReleasePage(&Debugger,(void*)((uint64_t)address+(t*4096)));
            }
        }
        uint64_t PageFrameAllocator_cl::GetFreeRAM(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::GetFreeRAM");
            return freeMemory;
        }
        uint64_t PageFrameAllocator_cl::GetUsedRAM(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::GetUsedRAM");
            return usedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetReservedRAM(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::GetReservedRAM");
            return reservedMemory;
        }
        uint64_t PageFrameAllocator_cl::GetTotalRAM(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::GetTotalRAM");
            size_t Ret = GetFreeRAM(&Debugger)+GetUsedRAM(&Debugger)+GetReservedRAM(&Debugger);
            return Ret;
        }
        void* PageFrameAllocator_cl::RequestPage(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageFrameAllocator_cl::RequestPage");
            for(;pageBitmapIndex<PageBitmap.Size*8;pageBitmapIndex++){
                if(PageBitmap[pageBitmapIndex] == true)continue;
                void* TheAddress = (void*)(pageBitmapIndex*4096);
                LockPage(&Debugger,TheAddress);
                return TheAddress;
            }
            //TODO::Page Frame Swap to file
            return NULL;
        }
    };
};