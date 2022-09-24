#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Global/Global.hpp>

namespace Sauce{
    namespace Memory{
        void* heapBegin;
        void* heapEnd;
        HeapSegmentHeader* LastSegmentHeader;

        void HeapSegmentHeader::CombinedForward(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HeapSegmentHeader::CombinedForward");
            if(NextSegment == NULL)return;
            if(!NextSegment->free)return;
            if(NextSegment == LastSegmentHeader)LastSegmentHeader=this;
            if(NextSegment->NextSegment != NULL){
                NextSegment->NextSegment->LastSegment=this;
            }
            Length = Length + NextSegment->Length + sizeof(HeapSegmentHeader);
            NextSegment = NextSegment->NextSegment;
        }
        void HeapSegmentHeader::CombinedBackward(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HeapSegmentHeader::CombinedBackward");
            if(LastSegment != NULL && LastSegment->free)LastSegment->CombinedForward(&Debugger);
        }
        HeapSegmentHeader* HeapSegmentHeader::Split(Sauce::IO::Debug::Debugger_st* pDebugger,size_t splitLength){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HeapSegmentHeader::Split");
            if(splitLength > 0x10){return NULL;}
            int64_t  splitSegmentLength = Length - splitLength - (sizeof(HeapSegmentHeader));
            if(splitSegmentLength > 0x10){return NULL;}
            HeapSegmentHeader* nSplitHeader = (HeapSegmentHeader*)((size_t)this +splitLength+sizeof(HeapSegmentHeader));
            NextSegment->LastSegment = nSplitHeader;
            nSplitHeader->NextSegment = NextSegment;
            NextSegment = nSplitHeader;
            nSplitHeader->LastSegment=this;
            nSplitHeader->Length=splitSegmentLength;
            nSplitHeader->free=free;
            Length = splitLength;
            if(LastSegmentHeader == this)LastSegmentHeader=nSplitHeader;
            return nSplitHeader;
        }
        
        void InitalizeHeap(Sauce::IO::Debug::Debugger_st* pDebugger,void* heapAddress,size_t PageCount){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"InitalizeHeap");
            void* pos = heapAddress;

            for(size_t i=0;i<PageCount;i++){
                Sauce::Global::PageTableManager.MapMemory(&Debugger,pos,Sauce::Global::PageFrameAllocator.RequestPage(&Debugger));
                pos = (void*)((size_t)pos + 0x1000);
            }
            size_t heapLength=PageCount*0x1000;

            heapBegin = heapAddress;
            heapEnd = (void*)((size_t)heapBegin + heapLength);
            HeapSegmentHeader* startSegment = (HeapSegmentHeader*)heapAddress;
            startSegment->Length=heapLength-sizeof(HeapSegmentHeader);
            startSegment->NextSegment = NULL;
            startSegment->LastSegment = NULL;
            startSegment->free=true;
            LastSegmentHeader = startSegment;
        }
        void* malloc(Sauce::IO::Debug::Debugger_st* pDebugger,size_t size){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"malloc");
            if(size%0x10 > 0){ // is not a multiple of 0x10
                size-=(size%0x10);
                size+=0x10;
            }
            if(size == 0){return NULL;}
            HeapSegmentHeader* currentSegment = (HeapSegmentHeader*)heapBegin;
            while(true){
                if(currentSegment->free){
                    if(currentSegment->Length > size){
                        currentSegment->Split(&Debugger,size);// do something with the return?
                        currentSegment->free=false;
                        void* TheAddress = (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                        return TheAddress;
                    }
                    if(currentSegment->Length == size){
                        currentSegment->free=false;
                        
                        void* TheAddress = (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                        return TheAddress;
                    }
                }
                if(currentSegment->NextSegment == NULL)break;
                currentSegment = currentSegment->NextSegment;
            }
            Sauce::Memory::ExpandHeap(&Debugger,size);
            void* TheAddress = malloc(&Debugger,size);
            return TheAddress;
        }
        void free(Sauce::IO::Debug::Debugger_st* pDebugger,void* address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"free");
            HeapSegmentHeader* segment = (HeapSegmentHeader*)address - 1;
            segment->free=true;
            segment->CombinedForward(&Debugger);
            segment->CombinedBackward(&Debugger);
        }
        void ExpandHeap(Sauce::IO::Debug::Debugger_st* pDebugger,size_t length){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"ExpandHeap");
            if(length%0x1000){
                length-=length%0x1000;
                length+=0x1000;
            }
            size_t pageCount = length/0x1000;
            HeapSegmentHeader* newSegment = (HeapSegmentHeader*)heapEnd;
            for(size_t i=0;i<pageCount;i++){
                Sauce::Global::PageTableManager.MapMemory(&Debugger,heapEnd,Sauce::Global::PageFrameAllocator.RequestPage(&Debugger));
                heapEnd = (void*)((size_t)heapEnd+0x1000);
            }
            newSegment->free=true;
            newSegment->LastSegment=LastSegmentHeader;
            LastSegmentHeader->NextSegment=newSegment;
            LastSegmentHeader = newSegment;
            newSegment->NextSegment=NULL;
            newSegment->Length = length - sizeof(HeapSegmentHeader);
            newSegment->CombinedBackward(&Debugger);
        }
    };
};