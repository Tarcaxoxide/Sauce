#ifndef __Sauce_Memory_List
#define __Sauce_Memory_List
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Memory{
		template<typename TT,size_t StageSize=16>
		class List_cl{
			void* Array{nullptr};
			size_t Array_Size{0};
			size_t Array_Capacity{0};
			size_t Shift_Value{0};
			public://*structures
				List_cl(){
					Clear();
				}
				List_cl(const List_cl<TT>& nValue){
					Clear();
					AddLast(nValue);
				}
				List_cl(const TT * nValue){
					Clear();
					AddLast(nValue);
				}
				List_cl(const TT * nValueA,const TT * nValueB){
					Clear();
					AddLast(nValueA);
					AddLast(nValueB);
				}
				List_cl(const List_cl<TT>& nValueA,const List_cl<TT>& nValueB){
					Clear();
					AddLast(nValueA);
					AddLast(nValueB);
				}
				List_cl(const TT nValue){
					Clear();
					AddLast(nValue);
				}
				List_cl(const TT nValueA,const TT nValueB){
					Clear();
					AddLast(nValueA);
					AddLast(nValueB);
				}
				~List_cl(){
					Clear();
				}
			public://Main functions
				inline bool AddFirst(const TT nValue){
					if(++Array_Size > Array_Capacity){
						Array_Capacity+=StageSize;
					}
					void* nArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
					Sauce::Memory::memset(nArray,0,Array_Capacity*(sizeof(TT)));
					void* dest = (void*)(((TT*)nArray)+1);
					Sauce::Memory::memcpy(Array,dest,Array_Size-1);
					((TT*)nArray)[0]=nValue;
					delete[] ((TT*)Array);
					Array = nArray;
					
					return true;
				}
				inline bool AddLast(const TT nValue){
					if(++Array_Size > Array_Capacity){
						Array_Capacity+=StageSize;
						void* nArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
						Sauce::Memory::memset(nArray,0,Array_Capacity*(sizeof(TT)));
						Sauce::Memory::memcpy(Array,nArray,Array_Size-1);
						((TT*)nArray)[Array_Size-1]=nValue;
						delete[] ((TT*)Array);
						Array = nArray;
					}else{
						((TT*)Array)[Array_Size-1]=nValue;
					}
					return true;
				}
				inline bool RemoveFirst(){
					if(Array_Size == 0)return false;
					if(--Array_Size > Array_Capacity){
						Array_Capacity-=StageSize;
					}
					void* nArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
					Sauce::Memory::memset(nArray,0,Array_Capacity);
					Sauce::Memory::memcpy((void*)(((TT*)Array)+1),nArray,Array_Capacity);
					delete[] ((TT*)Array);
					Array = nArray;
					return true;
				}
				inline bool RemoveLast(){
					if(Array_Size == 0)return false;
					if(--Array_Size > Array_Capacity){
						Array_Capacity-=StageSize;
					}
					void* nArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
					Sauce::Memory::memset(nArray,0,Array_Capacity);
					Sauce::Memory::memcpy(Array,nArray,Array_Capacity);
					delete[] ((TT*)Array);
					Array = nArray;
					return true;
				}
				inline bool RemoveAt(size_t index){
					if(Array_Size == 0)return false;
					if(Array_Size < index)return false;
					if(index == 0)return RemoveFirst();
					if(index == Array_Size-1)return RemoveLast();
					size_t oArray_Capacity;
					TT* oArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
					Sauce::Memory::memcpy(Array,oArray,Array_Capacity);
					Clear();
					for(size_t i=0;i<oArray_Capacity;i++){
						if(i==index)continue;
						AddLast(oArray[i]);
					}
					delete oArray;
					return true;
				}
				//bool AddAt(size_t index){
				//	//Todo
				//}
				inline bool AddFirst(const TT* nValue){
					List_cl<TT> tmp(nValue);
					tmp.Flip();
					for(size_t i=0;i<tmp.Size();i++){
						if(!AddFirst(tmp[i]))return false;
					}
					return true;
				}
				inline bool AddFirst(const List_cl<TT>& nValue){
					List_cl<TT> tmp(nValue);
					tmp.Flip();
					for(size_t i=0;i<tmp.Size();i++){
						if(!AddFirst(tmp[i]))return false;
					}
					return true;
				}
				inline bool push_front(const TT* nValue){return AddFirst(nValue);}
				inline bool push_front(const List_cl<TT>& nValue){return AddFirst(nValue);}
				inline bool pop_front(){return RemoveFirst();}
				inline bool AddLast(const TT* nValue){
					//TT* ValuePtr = nValue;
					while(*nValue){
						if(!AddLast(*nValue))return false;
						nValue++;
					}
					return true;
				}
				inline bool AddLast(const List_cl<TT>& nValue){
					for(size_t i=0;i<nValue.Size();i++){
						if(!AddLast(nValue[i]))return false;
					}
					return true;
				}
				inline bool push_back(const TT* nValue){return AddLast(nValue);}
				inline bool push_back(const List_cl<TT>& nValue){return AddLast(nValue);}
				inline bool pop_back(){return RemoveLast();}
				inline size_t IndexGaurd(size_t i)const{return (Shift_Value+i)%(Array_Size);}
				inline TT& Get(size_t index)const{
					size_t target=IndexGaurd(index); // no more out of range errors :) doesn't mean your program will run well though. (Last+1 == First)
					return ((TT*)Array)[target];
				}
				inline void BitGet(size_t index,size_t bitAddress,bool& Value)const{
					uint8_t bitIndex = bitAddress%(8*sizeof(TT));
					uint8_t bitIndexer = 0b10000000 >> bitIndex;
					Value=((((uint8_t*)Array)[IndexGaurd(index)] & bitIndexer) > 0);
				}
				inline void BitSet(size_t index,size_t bitAddress,bool Value){
					if(index > Size())AddLast((TT)0);
					uint8_t bitIndex = bitAddress%(8*sizeof(TT));
					uint8_t bitIndexer = 0b10000000 >> bitIndex;
					((uint8_t*)Array)[IndexGaurd(index)] &= ~bitIndexer;
					if(Value)((uint8_t*)Array)[IndexGaurd(index)] |= bitIndexer;
				}
				inline void BitFlip(size_t index,size_t bitAddress){
					bool Value;
					BitGet(index,bitAddress,Value);
					BitSet(index,bitAddress,!Value);
				}
				inline TT& at(size_t index)const{return Get(index);}
				inline List_cl<TT,StageSize> Section(size_t start,size_t length)const{
					List_cl<TT,StageSize> Result;
					for(size_t i=0;i<length;i++){
						Result.AddLast(Get(start+i));
					}
					return Result;
				}
				inline List_cl<TT,StageSize> Substr(size_t start,size_t length)const{return Section(start,length);}
				TT& First()const{
					return Get(0); // the first element, it's always the 0th element *shrug* unless shift_value is specified but that's taken care of.
				}
				inline TT& front()const{
					return First(); // the first element, it's always the 0th element *shrug* unless shift_value is specified but that's taken care of.
				}
				inline TT& Last()const{
					return Get(Array_Size-1);
				}
				inline TT& back()const{
					return Last();
				}
				inline void* Raw()const{
					return Array;
				}
				inline TT* RawTyped()const{
					return ((TT*)Array);
				}
				inline size_t Count()const{
					return Array_Size;
				}
				inline size_t Capacity()const{
					return Array_Capacity;
				}
				inline size_t Size()const{
					return Count(); // Size calls count because it's the count of how many elements there are.
				}
				inline void Flip(){
					//flip the array, the back is now the front and the front is now the back :)
					List_cl<TT> Other(*this);
					Clear();
					for(size_t i=0;i<Other.Size();i++){
						AddFirst(Other[i]);
					}
				}
				inline void Clear(){
					if(Array != nullptr){
						delete[] ((TT*)Array);
						Array=nullptr;
					}
					Array_Capacity=0;
					Array_Size=0;
				}
				inline bool Compare(const List_cl<TT>& OtherValue)const{
					if(OtherValue.Size() != Array_Size)return false;
					for(size_t i=0;i<Array_Size;i++){
						if(Get(i) != OtherValue[i])return false;
					}
					return true;
				}
				inline bool Compare(const TT** OtherValues)const{
					//Example Usage of this operator:
					//Equation.Compare(new const char*[]{"1","2","3",nullptr})
					//new is required because otherwise it complains about taking a pointer to a temporary array.
					//nullptr is to always be the last element because we look for it in the loop...
					//we can't use the usual null termination because one exist for each of the elements.
					for(size_t i=0;OtherValues[i] != nullptr;i++){
						if(Compare(List_cl<TT>(OtherValues[i]))){delete[] OtherValues;return true;}
					}
					delete[] OtherValues;//we obviously delete this pointer so the end user doesn't have to deal with that.
					return false;
				}
				template<typename F>
				inline void ForEach(F&& LAMBDA){
					//void [...](TT& Item,size_t& Index){...}
					for(size_t i=0;i<Array_Size;i++){
						LAMBDA(Get(i),i);
					}
				}
				template<typename TV>
				inline bool Pop(TV& OtherValue){
					if(!Size())return false;
					uint64_t sizeOfExternal=sizeof(TV);
					uint64_t sizeOfInternal=sizeof(TT);
					TV Etmp;
					uint8_t* EtmpPtr=(uint8_t*)&Etmp;
					TT Itmp;
					uint8_t* ItmpPtr = (uint8_t*)&Itmp;
					Itmp=Last();
					for(size_t a=0;a<sizeOfExternal;a++){
						Itmp=Last();
						if(!RemoveLast())break;
						for(size_t b=0;(b<sizeOfInternal && b<sizeOfExternal);b++){
							EtmpPtr[a]=ItmpPtr[b];
						}
					}
					OtherValue=Etmp;
					return true;
				}
				template<typename TV>
				inline bool Push(TV& OtherValue){
					if(Size() >= 0xFFFFFFFFFFFFFFF0)return false;
					uint64_t sizeOfExternal=sizeof(TV);
					uint64_t sizeOfInternal=sizeof(TT);
					TV Etmp;
					uint8_t* EtmpPtr=(uint8_t*)&Etmp;
					TT Itmp;
					uint8_t* ItmpPtr = (uint8_t*)&Itmp;
					Etmp=OtherValue;
					for(size_t a=0;a<sizeOfExternal;a++){
						for(size_t b=0;(b<sizeOfInternal && b<sizeOfExternal);b++){
							ItmpPtr[b]=EtmpPtr[a];
						}
						AddLast(Itmp);
					}
					return true;
				}
			public://Operators
				inline TT* operator=(const TT* nValue){
					Clear();
					AddLast(nValue);
					return RawTyped();
				}
				inline TT* operator=(const TT nValue){
					Clear();
					AddLast(nValue);
					return RawTyped();
				}
				inline TT* operator+=(const TT* nValue){
					AddLast(nValue);
					return RawTyped();
				}
				inline TT* operator+=(const TT nValue){
					AddLast(nValue);
					return RawTyped();
				}
				inline TT* operator+=(const List_cl<TT>& nValue){
					AddLast(nValue);
					return RawTyped();
				}
				inline TT* operator+(const TT* nValue)const{
					List_cl<TT> tmp(RawTyped());
					tmp+=nValue;
					return tmp.RawTyped();
				}
				inline TT* operator+(const TT nValue)const{
					List_cl<TT> tmp(RawTyped());
					tmp+=nValue;
					return tmp.RawTyped();
				}
				inline TT* operator+(const List_cl<TT>& nValue)const{
					List_cl<TT> tmp(RawTyped());
					tmp+=nValue;
					return tmp.RawTyped();
				}
				inline TT& operator[](size_t TargetIndex)const{
					return Get(TargetIndex);
				}
				inline bool operator==(const TT* OtherValue)const{
					List_cl<TT> OtherTmp(OtherValue);
					return Compare(OtherTmp);
				}
				inline bool operator==(List_cl<TT> OtherValue)const{
					return Compare(OtherValue);
				}
				inline bool operator!=(const TT* OtherValue)const{
					List_cl<TT> OtherTmp(OtherValue);
					return !Compare(OtherTmp);
				}
				inline bool operator!=(const TT** OtherValues)const{
					return !Compare(OtherValues);
				}
				inline bool operator!=(const List_cl<TT>& OtherValue)const{
					return !Compare(OtherValue);
				}
				inline List_cl<TT>& operator<<(const List_cl<TT>& OtherValue){
					AddLast(OtherValue.RawTyped());
					return *this;
				}
				inline List_cl<TT>& operator<<(const TT* OtherValue){
					AddLast(OtherValue);
					return *this;
				}
		};
	};
};
#endif