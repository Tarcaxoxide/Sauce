#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        void* heapBegin;
        void* heapEnd;
        HeapSegmentHeader* LastSegmentHeader;
        size_t DynMemAl=0;

        void HeapSegmentHeader::CombinedForward(){}
        void HeapSegmentHeader::CombinedBackward(){}
        HeapSegmentHeader* HeapSegmentHeader::Split(size_t Length){
            if(Length > DynMemAl)return NULL;
            int64_t  splitSegmentLength = this->Length - Length - sizeof(HeapSegmentHeader);
            if(splitSegmentLength < DynMemAl)return NULL;
            HeapSegmentHeader* nSplitHeader = (HeapSegmentHeader*)((size_t)this+Length+sizeof(HeapSegmentHeader));
            NextSegment->LastSegment = nSplitHeader;
            nSplitHeader->NextSegment = NextSegment;
            NextSegment = nSplitHeader;
            nSplitHeader->LastSegment=this;
            nSplitHeader->Length=splitSegmentLength;
            nSplitHeader->free=free;
            this->Length = Length;

            if(LastSegmentHeader == this)LastSegmentHeader=nSplitHeader;
            return nSplitHeader;
        }
        
        void InitalizeHeap(void* heapAddress,size_t PageCount,size_t SizeAlignment){
            DynMemAl=SizeAlignment;
            void* pos = heapAddress;

            for(size_t i=0;i<PageCount;i++){
                Sauce::Memory::GlobalPageTableManager.MapMemory(pos,Sauce::Memory::GlobalAllocator.RequestPage());
                pos = (void*)((size_t)pos + 0x1000);
            }
            size_t heapLength=PageCount*0x1000;

            heapBegin = heapAddress;
            heapEnd = (void*)((size_t)heapBegin +heapLength);
            HeapSegmentHeader* startSegment = (HeapSegmentHeader*)heapAddress;
            startSegment->Length=heapLength-sizeof(HeapSegmentHeader);
            startSegment->NextSegment = NULL;
            startSegment->LastSegment = NULL;
            startSegment->free=true;
            LastSegmentHeader = startSegment;
        }
        void* malloc(size_t size){
            
            if(size%DynMemAl > 0){ // is not a multiple of 0x10
                size-=(size%DynMemAl);
                size+=DynMemAl;
            }
            if(size == 0)return NULL;
            HeapSegmentHeader* currentSegment = (HeapSegmentHeader*)heapBegin;
            while(true){
                if(currentSegment->free){
                    if(currentSegment->Length > size){
                        currentSegment->Split(size);// do something with the return?
                        currentSegment->free=false;
                        return (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                    }else if(currentSegment->Length == size){
                        currentSegment->free=false;
                        return (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                    }
                }
                if(currentSegment->NextSegment == NULL)break;
                currentSegment = currentSegment->NextSegment;
            }
            Sauce::Memory::ExpandHeap(size);
            return malloc(size);
        }
        void free(void* address){}
        void ExpandHeap(size_t length){}
    };
};