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
            List_cl(const TT nValue){
                Clear();
                AddLast(nValue);
            }
            ~List_cl(){
                Clear(false);
            }
            bool AddFirst(const TT nValue){
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    TT* nArray = new TT[Array_Capacity];
                    Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                    Array_Size=0;
                    nArray[Array_Size++]=nValue;
                    for(;Array_Size<(Array_Capacity-StageSize);Array_Size++){
                        nArray[Array_Size]=Array[Array_Size-1];// we shuffle the array forward to make room for the new element.
                    }
                    delete[] Array;
                    Array = nArray;
                }else{
                    size_t oldArray_Size=Array_Size;
                    Array_Size=1;
                    for(;Array_Size<(oldArray_Size+1);Array_Size++){
                        Array[Array_Size]=Array[Array_Size-1]; // we shuffle the array forward to make room for the new element.
                    }
                    Array[0]=nValue;
                }
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
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    TT* nArray = new TT[Array_Capacity];
                    Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                    Array_Size=0;
                    for(;Array_Size<(Array_Capacity-StageSize);Array_Size++){
                        nArray[Array_Size]=Array[Array_Size];
                    }
                    nArray[Array_Size++]=nValue; 
                    delete[] Array;
                    Array = nArray;
                }else{
                    Array[Array_Size++]=nValue;
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
                if(Array_Size-1 > Array_Capacity){
                    Array_Capacity-=StageSize;
                    TT* nArray = new TT[Array_Capacity];
                    Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                    Array_Size=1;
                    for(;Array_Size<(Array_Capacity-StageSize);Array_Size++){
                        nArray[Array_Size-1]=Array[Array_Size];// we shuffle the array forward to make room for the new element.
                    }
                    delete[] Array;
                    Array = nArray;
                }else{
                    size_t oldArray_Size=Array_Size;
                    Array_Size=1;
                    for(;Array_Size<(oldArray_Size+1);Array_Size++){
                        Array[Array_Size-1]=Array[Array_Size]; // we shuffle the array forward to make room for the new element.
                    }
                    Array_Size--;
                }
                return true;
            }
            bool Remove(size_t Index){
                if(Array_Size-1 == 0)return false;
                // A B C {D} E F G
                // F      I      B
                size_t Array_Front_Size = Index;
                size_t Array_Back_Size = (Array_Capacity-1)-Index;
                size_t nArray_Capacity=Array_Capacity-1;
                TT* FArray = new TT[Array_Front_Size];
                TT* BArray = new TT[Array_Back_Size];
                for(size_t i=0;i<Array_Back_Size;i++){
                    FArray[i] = Array[i];
                }
                for(size_t i=0;i<Array_Back_Size;i++){
                    BArray[i] = Array[i+Index];
                }
                delete[] Array;
                Array = new TT[nArray_Capacity];
                for(size_t i=0;i<Array_Back_Size;i++){
                    Array[i] = FArray[i];
                }
                for(size_t i=0;i<Array_Back_Size;i++){
                    Array[i+Index] = BArray[i];
                }
                delete[] BArray;
                delete[] FArray;
                Array_Size--;
                Array_Capacity--;
                return true;
            }
            bool RemoveLast(){
                if(Array_Size == 0)return false;
                if(Array_Size-1 < Array_Capacity-StageSize){
                    Array_Capacity-=StageSize;
                    TT* nArray = new TT[Array_Capacity];
                    Sauce::Memory::memset((void*)nArray,0,Array_Capacity);
                    Array_Size=0;
                    for(;Array_Size<Array_Capacity;Array_Size++){
                        nArray[Array_Size] = Array[Array_Size];
                    }
                    delete[] Array;
                    Array = nArray;
                }else{
                    Array_Size--;
                }
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
            TT* c_str(){
                return Raw(); // c_str calls raw because they are functionally the same but raw is less "string" specific.
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
            void Flip(bool All=false){
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
                //Example Usage of this operator:
                //Equation == new const char*[]{"1","2","3",nullptr}
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
            bool operator>>(TT& OtherValue){
                OtherValue = Last();
                return RemoveLast();
            }
            bool operator<<(TT OtherValue){
                AddLast(OtherValue);
                return true;
            }
        };
    };
    typedef Sauce::Memory::List_cl<char> string;
};