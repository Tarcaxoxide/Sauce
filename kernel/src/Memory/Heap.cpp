#include<Sauce/Memory/Heap.hpp>
#include<Sauce/Global.hpp>
namespace Sauce{
	namespace Memory{
		void* heapBegin;
		void* heapEnd;
		HeapSegmentHeader* LastSegmentHeader;
		void HeapSegmentHeader::CombinedForward(){
			if(NextSegment == nullptr)return;
			if(!NextSegment->free)return;
			if(NextSegment == LastSegmentHeader)LastSegmentHeader=this;
			if(NextSegment->NextSegment != nullptr){
				NextSegment->NextSegment->LastSegment=this;
			}
			Length = Length + NextSegment->Length + sizeof(HeapSegmentHeader);
			NextSegment = NextSegment->NextSegment;
		}
		void HeapSegmentHeader::CombinedBackward(){
			if(LastSegment != nullptr && LastSegment->free)LastSegment->CombinedForward();
		}
		HeapSegmentHeader* HeapSegmentHeader::Split(size_t splitLength){
			if(splitLength > 0x10){return nullptr;}
			int64_t  splitSegmentLength = Length - splitLength - (sizeof(HeapSegmentHeader));
			if(splitSegmentLength > 0x10){return nullptr;}
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
		void InitalizeHeap(void* heapAddress,size_t PageCount){
			void* pos = heapAddress;

			for(size_t i=0;i<PageCount;i++){
				Sauce::Global::Memory::PageTableManager.MapMemory(pos,Sauce::Global::Memory::PageFrameAllocator.RequestPage());
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
		void* malloc(size_t size){
			if(size%0x10 > 0){ // is not a multiple of 0x10
				size-=(size%0x10);
				size+=0x10;
			}
			if(size == 0){return NULL;}
			HeapSegmentHeader* currentSegment = (HeapSegmentHeader*)heapBegin;
			while(true){
				if(currentSegment->free){
					if(currentSegment->Length > size){
						currentSegment->Split(size);// do something with the return?
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
			Sauce::Memory::ExpandHeap(size);
			void* TheAddress = malloc(size);
			return TheAddress;
		}
		void free(void* address){
			HeapSegmentHeader* segment = (HeapSegmentHeader*)address - 1;
			segment->free=true;
			segment->CombinedForward();
			segment->CombinedBackward();
		}
		void ExpandHeap(size_t length){
			if(length%0x1000){
				length-=length%0x1000;
				length+=0x1000;
			}
			size_t pageCount = length/0x1000;
			HeapSegmentHeader* newSegment = (HeapSegmentHeader*)heapEnd;
			for(size_t i=0;i<pageCount;i++){
				Sauce::Global::Memory::PageTableManager.MapMemory(heapEnd,Sauce::Global::Memory::PageFrameAllocator.RequestPage());
				heapEnd = (void*)((size_t)heapEnd+0x1000);
			}
			newSegment->free=true;
			newSegment->LastSegment=LastSegmentHeader;
			LastSegmentHeader->NextSegment=newSegment;
			LastSegmentHeader = newSegment;
			newSegment->NextSegment=NULL;
			newSegment->Length = length - sizeof(HeapSegmentHeader);
			newSegment->CombinedBackward();
		}
	};
};

void* operator new(size_t size){return Sauce::Memory::malloc(size);}
void* operator new[](size_t size){return Sauce::Memory::malloc(size);}
void operator delete(void* ptr){Sauce::Memory::free(ptr);}
void operator delete[](void* ptr){Sauce::Memory::free(ptr);}
void operator delete(void* ptr,size_t Sz){Sauce::Memory::free(ptr);}
void operator delete[](void* ptr,size_t Sz){Sauce::Memory::free(ptr);}