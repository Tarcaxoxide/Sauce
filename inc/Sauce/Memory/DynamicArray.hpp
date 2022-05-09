#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        template<typename T>
        class DynamicArray_cl{
            T* Array={nullptr};
            size_t Array_Size;
            size_t Array_Capacity;
            size_t StageSize;
            T* NULL_T;
            public:
            bool AddLast(T nValue){
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    T* nArray = new T[Array_Capacity];
                    Array_Size=0;
                    for(;Array_Size<(Array_Capacity-StageSize);Array_Size++){
                        nArray[Array_Size]=Array[Array_Size];
                    }
                    nArray[Array_Size++]=nValue; // i forget if it should be ++V or V++ , i'll test V++ first.
                    delete[] Array;
                    Array = nArray;
                }else{
                    Array[Array_Size++]=nValue;
                }
                return true;
            }
            bool AddFirst(T nValue){
                if(Array_Size+1 > Array_Capacity){
                    Array_Capacity+=StageSize;
                    T* nArray = new T[Array_Capacity];
                    Array_Size=0;
                    nArray[Array_Size++]=nValue; // i forget if it should be ++V or V++ , i'll test V++ first.
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
            bool AddLast(T* nValue){
                T* ValuePtr = nValue;
                while(*ValuePtr){
                    if(!AddLast(*ValuePtr))return false;
                    ValuePtr++;
                }
                return true;
            }
            bool AddFirst(T* nValue){
                T* ValuePtr = nValue;
                while(*ValuePtr){
                    if(!AddFirst(*ValuePtr))return false;
                    ValuePtr++;
                }
                return true;
            }
            bool RemoveLast(){
                if(Array_Size == 0)return false;
                if(Array_Size-1 < Array_Capacity-StageSize){
                    Array_Capacity-=StageSize;
                    T* nArray = new T[Array_Capacity];
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
            bool RemoveFirst(){
                if(Array_Size == 0)return false;
                if(Array_Size-1 > Array_Capacity){
                    Array_Capacity-=StageSize;
                    T* nArray = new T[Array_Capacity];
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
            T& Last(){
                return Array[Array_Size-1];
            }
            T& First(){
                return Array[0];
            }
            T& operator[](size_t TargetIndex){
                if(TargetIndex > Array_Size)return NULL_T;
                return Array[TargetIndex];
            }
            T* operator*(){
                if(Last() != (T)0)AddLast((T)0);
                return Array;
            }
            size_t Size(){
                return Array_Size;
            }
            bool operator=(T* nValue){
                Clear();
                T* ValuePtr = nValue;
                while(*ValuePtr){
                    AddLast(*ValuePtr);
                    ValuePtr++;
                }
                return true;
            }
            
            bool Clear(){
                while(RemoveLast());// remove until we can't anymore
                return true;
            }
            DynamicArray_cl<T>(T &NIL,size_t StageSize=16){
                this->StageSize=StageSize; // stage value determines by how much we increase or decrease the actual arrays size in memory.
                                           // you should probably set this to fit the application but we have a default of 8 just to be sure.
                Array = new T[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
                NULL_T=&NIL;
            }
            DynamicArray_cl<T>(T nValue,T &NIL,size_t StageSize=16){
                Array = new T[StageSize];
                Array_Capacity=StageSize;
                Array_Size=0;
                NULL_T=&NIL;
                AddLast(nValue);
            }
            ~DynamicArray_cl(){
                Clear();
                delete[] Array; // do the final delete;
            }
        };

        template<typename TT>
        class List_cl{
            DynamicArray_cl<TT> Contents;
            TT* Ret=NULL;
            public:
            List_cl(){}
            List_cl(TT* nValue){(*this)=nValue;}
            List_cl(const TT* nValue){(*this)=(TT*)nValue;}
            TT* operator=(TT* nValue){
                Contents=nValue;
                return nValue;
            }
            bool AddFirst(TT nValue){
                return Contents.AddFirst(nValue);
            }
            bool AddLast(TT nValue){
                return Contents.AddLast(nValue);
            }
            bool RemoveFirst(){
                return Contents.RemoveFirst();
            }
            bool RemoveLast(){
                return Contents.RemoveLast();
            }
            TT& First(){
                Contents.First();
            }
            TT& Last(){
                Contents.Last();
            }
            TT& operator[](size_t TargetIndex){
                return Contents[TargetIndex];
            }
            TT* Raw(){
                return *Contents;
            }
            size_t Size(){
                return Contents.Size();
            }
        };
    };
};