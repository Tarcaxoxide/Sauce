#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        template<typename TT,size_t StageSize=16>
        class List_cl{
            TT* Array=nullptr;
            size_t Array_Size;
            size_t Array_Capacity;
            public:
            //*structors
            List_cl(){
                Array = new TT[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
            }
            List_cl(TT* nValue){
                Array = new TT[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
                AddLast(nValue);
            }
            List_cl(TT nValue){
                Array = new TT[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
                AddLast(nValue);
            }
            ~List_cl(){
                Clear();
                delete[] Array;
            }
            TT* operator=(TT* nValue){
                Clear();
                AddLast(nValue);
                return nValue;
            }
            bool AddFirst(TT nValue){
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    TT* nArray = new TT[Array_Capacity];
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
            bool AddFirst(TT* nValue){
                TT* ValuePtr = nValue;
                while(*ValuePtr){
                    if(!AddFirst(*ValuePtr))return false;
                    ValuePtr++;
                }
                return true;
            }
            bool AddLast(TT nValue){
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    TT* nArray = new TT[Array_Capacity];
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
            bool AddLast(TT* nValue){
                TT* ValuePtr = nValue;
                while(*ValuePtr){
                    if(!AddLast(*ValuePtr))return false;
                    ValuePtr++;
                }
                return true;
            }
            bool RemoveFirst(){
                if(Array_Size == 0)return false;
                if(Array_Size-1 > Array_Capacity){
                    Array_Capacity-=StageSize;
                    TT* nArray = new TT[Array_Capacity];
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
            bool RemoveLast(){
                if(Array_Size == 0)return false;
                if(Array_Size-1 < Array_Capacity-StageSize){
                    Array_Capacity-=StageSize;
                    TT* nArray = new TT[Array_Capacity];
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
            TT& First(){
                return Array[0];
            }
            TT& Last(){
                return Array[Array_Size-1];
            }
            TT& operator[](size_t TargetIndex){
                return Array[TargetIndex];
            }
            bool operator==(TT* OtherValue){
                for(size_t i=0;i<Array_Size;i++){
                    if(Array[i] != Array[i])return false;
                }
                return true;
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
                return Count();
            }
            void Clear(){
                while(RemoveLast());
            }
            void ForEach(void (*CallBack)(TT &Item)){ //void Function(TT &item){/*Do something with item*/}
                for(size_t i=0;i<Array_Size;i++){
                    (*CallBack)(Array[i]);
                }
            }
        };
    };
};