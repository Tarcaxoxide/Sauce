#ifndef __Sauce_Memory_SmartPtr
#define __Sauce_Memory_SmartPtr
#include<Sauce/Memory/List.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Memory{
		struct DumbPtr_str{
			void* Ptr{nullptr};
			size_t ReferenceCount=0;
		};
		extern Sauce::Memory::List_cl<DumbPtr_str> _DumbPtrs;
		template<typename PtrType,size_t count=1>
		class SmartPtr_cl{
			constexpr static Sauce::Memory::List_cl<DumbPtr_str>& DumbPtrs=_DumbPtrs;
			size_t DumbPtrId{0};
			public:
				//SmartPtr_cl(void){
				//	for(size_t i=0;i<DumbPtrs.Size();i++){
				//		if(DumbPtrs[i].Ptr == nullptr && DumbPtrs[i].ReferenceCount == 0){
				//			//DumbPtrs[i].Ptr=Sauce::Memory::malloc(count*(sizeof(PtrType)));
				//			DumbPtrs[i].ReferenceCount++;
				//			DumbPtrId=i;
				//			return;
				//		}
				//	}
				//	DumbPtrs.push_back(DumbPtr_str{nullptr,1});
				//	DumbPtrId=DumbPtrs.Size()-1;
				//}
				SmartPtr_cl(PtrType v){
					for(size_t i=0;i<DumbPtrs.Size();i++){
						if(DumbPtrs[i].Ptr == nullptr && DumbPtrs[i].ReferenceCount == 0){
							DumbPtrs[i].Ptr=Sauce::Memory::malloc(count*(sizeof(PtrType)));
							DumbPtrs[i].ReferenceCount++;
							DumbPtrId=i;
							return;
						}
					}
					void* p = Sauce::Memory::malloc(count*sizeof(PtrType));
					DumbPtrs.push_back(DumbPtr_str{p,1});
					DumbPtrId=DumbPtrs.Size()-1;
					for(size_t i=0;i<count;i++)(*this)[i]=v;
				}
				SmartPtr_cl(const SmartPtr_cl& ref){
					DumbPtrId=ref.DumbPtrId;
					DumbPtrs[DumbPtrId].ReferenceCount++;
				}
				~SmartPtr_cl(){
					DumbPtrs[DumbPtrId].ReferenceCount--;
					if(DumbPtrs[DumbPtrId].ReferenceCount==0 && DumbPtrs[DumbPtrId].Ptr != nullptr){
						delete ((PtrType*)DumbPtrs[DumbPtrId].Ptr);
						DumbPtrs[DumbPtrId].Ptr=nullptr;
					}
				}
				inline PtrType& operator*(){return *((PtrType*)DumbPtrs[DumbPtrId].Ptr);}
				inline PtrType* operator->(){return ((PtrType*)DumbPtrs[DumbPtrId].Ptr);}
				inline PtrType& operator[](size_t index){return ((PtrType*)DumbPtrs[DumbPtrId].Ptr)[index];}
				inline PtrType* Dumb(){return ((PtrType*)DumbPtrs[DumbPtrId].Ptr);}
				template<typename NewPtrType>
				inline SmartPtr_cl<NewPtrType> As(){
					return *((SmartPtr_cl<NewPtrType>*)this);
				}
		};
	};
};
#endif