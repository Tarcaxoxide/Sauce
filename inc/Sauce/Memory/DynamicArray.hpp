#pragma once

#include<Sauce/Math/Types.hpp>
#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        template<typename TT,size_t StageSize=16>
        class List_cl{
            TT* Array{nullptr};
            size_t Array_Size{0};
            size_t Array_Capacity{0};
            size_t Shift_Value{0};
            public:
            //*structors
            List_cl(){
                Clear();
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
                Clear(false);
            }
            bool AddFirst(const TT nValue){
                if(++Array_Size > Array_Capacity){
                    Array_Capacity+=StageSize;
                }
                TT* nArray = new TT[Array_Capacity];
                Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                Sauce::Memory::memcpy(Array,nArray+1,Array_Capacity);
                nArray[0]=nValue;
                delete[] Array;
                Array = nArray;
                return true;
            }
            bool AddFirst(const TT* nValue){
                TT* ValuePtr = nValue;
                while(*ValuePtr){
                    if(!AddFirst(*ValuePtr))return false;
                    ValuePtr++;
                }
                return true;
            }
            bool AddLast(const TT nValue){
                if(++Array_Size > Array_Capacity){
                    Array_Capacity+=StageSize;
                    TT* nArray = new TT[Array_Capacity];
                    Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                    Sauce::Memory::memcpy(Array,nArray,Array_Size-1);
                    nArray[Array_Size-1]=nValue;
                    delete[] Array;
                    Array = nArray;
                }else{
                    Array[Array_Size-1]=nValue;
                }
                return true;
            }
            bool AddLast(const TT* nValue){
                //TT* ValuePtr = nValue;
                while(*nValue){
                    if(!AddLast(*nValue))return false;
                    nValue++;
                }
                return true;
            }
            bool RemoveFirst(){
                if(Array_Size == 0)return false;
                if(--Array_Size > Array_Capacity){
                    Array_Capacity-=StageSize;
                }
                TT* nArray = new TT[Array_Capacity];
                Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                Sauce::Memory::memcpy(Array+1,nArray,Array_Capacity);
                delete[] Array;
                Array = nArray;
                return true;
            }
            bool RemoveLast(){
                if(Array_Size == 0)return false;
                if(--Array_Size > Array_Capacity){
                    Array_Capacity-=StageSize;
                }
                TT* nArray = new TT[Array_Capacity];
                Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                Sauce::Memory::memcpy(Array,nArray,Array_Capacity);
                delete[] Array;
                Array = nArray;
                return true;
            }
            TT& Get(size_t index){
                size_t target=(Shift_Value+index)%(Array_Size+1); // no more out of range errors :) doesn't mean your program will run well though. (Last+1 == First)
                return Array[target];
            }
            TT& First(){
                return Get(0); // the first element, it's always the 0th element *shrug* unless shift_value is specified but that's taken care of.
            }
            TT& Last(){
                return Get(Array_Size);
            }
            TT* Raw(){
                return Array;
            }
            size_t Count(){
                return Array_Size;
            }
            size_t Capacity(){
                return Array_Capacity;
            }
            size_t Size(){
                return Count(); // Size calls count because it's the count of how many elements there are.
            }
            void Clear(bool CreateNew=true){
                Sauce::Memory::memset(Array,0,Array_Capacity);// we'll be a good neighbor and clean up our mess.
                if(Array != nullptr)delete[] Array;
                if(!CreateNew)return;
                Array = new TT[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
                Shift_Value=0;
            }
            bool Compare(List_cl<TT> OtherValue){
                for(size_t i=0;i<Array_Size;i++){
                    if(Get(i) != OtherValue[i])return false;
                }
                return true;
            }
            bool Compare(const TT** OtherValues){
                //Example Usage of this operator:
                //Equation.Compare(new const char*[]{"1","2","3",nullptr})
                //new is required because otherwise it complains about taking a pointer to a temporary array.
                //nullptr is to always be the last element because we look for it in the loop...
                //we can't use the usual null termination because one exist for each of the elements.
                for(size_t i=0;OtherValues[i] != nullptr;i++){
                    List_cl<TT> OtherTmp(OtherValues[i]);
                    if(Compare(OtherTmp)){delete[] OtherValues;return true;}
                }
                delete[] OtherValues;//we obviously delete this pointer so the end user doesn't have to deal with that.
                return false;
            }
            void Flip(){
                TT* nArray = new TT[Array_Size];
                Sauce::Memory::memset((void*)nArray,0,Array_Size);
                for(size_t i=0;i<Array_Size;i++){
                    //first we copy the data to a new array while also reversing it's order.
                    nArray[(Array_Size-1)-i]=Array[i];
                }
                Sauce::Memory::memset((void*)Array,0,Array_Capacity);
                for(size_t i=0;i<Array_Size;i++){
                    //then we put the reversed data back into the original array.
                    Array[i]=nArray[i];
                }
                delete[] nArray;
            }
            void ForEach(void (*CallBack)(TT &Item)){ //void Function(TT &item){/*Do something with item*/}
                for(size_t i=0;i<Array_Size;i++){
                    (*CallBack)(Get(i));
                }
            }
            TT* operator=(const TT* nValue){
                Clear();
                AddLast(nValue);
                return Raw();
            }
            TT* operator+=(const TT* nValue){
                AddLast(nValue);
                return Raw();
            }
            TT* operator=(const TT nValue){
                Clear();
                AddLast(nValue);
                return Raw();
            }
            TT* operator+=(const TT nValue){
                AddLast(nValue);
                return Raw();
            }
            TT* operator+(const TT* nValue){
                List_cl<TT> tmp(Raw());
                tmp+=nValue;
                return tmp.Raw();
            }
            TT* operator+(const TT nValue){
                List_cl<TT> tmp(Raw());
                tmp+=nValue;
                return tmp.Raw();
            }
            TT& operator[](size_t TargetIndex){
                return Get(TargetIndex);
            }
            bool operator==(const TT* OtherValue){
                List_cl<TT> OtherTmp(OtherValue);
                return Compare(OtherTmp);
            }
            bool operator==(const TT** OtherValues){
                return Compare(OtherValues);
            }
            bool operator==(List_cl<TT> OtherValue){
                return Compare(OtherValue);
            }
            bool operator!=(const TT* OtherValue){
                List_cl<TT> OtherTmp(OtherValue);
                return !Compare(OtherTmp);
            }
            bool operator!=(List_cl<TT> OtherValue){
                return !Compare(OtherValue);
            }
            template<typename TV>
            bool Pop(TV& OtherValue){
                if(!Size())return false;
                uint64_t sizeOfExternal=sizeof(TV);
                uint64_t sizeOfInternal=sizeof(TT);
                TV Etmp;
                uint8_t* EtmpPtr=(uint8_t*)&Etmp;
                TT Itmp;
                uint8_t* ItmpPtr = (uint8_t*)&Itmp;
                Itmp=Last();
                for(size_t i=0;(i<sizeOfInternal && i<sizeOfExternal);i++){
                    EtmpPtr[i] = ItmpPtr[i];
                }
                OtherValue=Etmp;
                RemoveLast();
                return true;
            }
            template<typename TV>
            bool Push(TV OtherValue){
                if(Size() >= 0xFFFFFFFFFFFFFFF0)return false;
                uint64_t sizeOfExternal=sizeof(TV);
                uint64_t sizeOfInternal=sizeof(TT);
                TV Etmp;
                uint8_t* EtmpPtr=(uint8_t*)&Etmp;
                TT Itmp;
                uint8_t* ItmpPtr = (uint8_t*)&Itmp;
                Etmp=OtherValue;
                for(size_t i=0;(i<sizeOfInternal && i<sizeOfExternal);i++){
                    ItmpPtr[i] = EtmpPtr[i];
                }
                AddLast(Itmp);
                return true;
            }
            inline List_cl<TT>& operator<<(List_cl<TT>& OtherValue){
                AddLast(OtherValue.Raw());
                return *this;
            }
            inline List_cl<TT>& operator<<(const TT* OtherValue){
                AddLast(OtherValue);
                return *this;
            }
        };
    };
};