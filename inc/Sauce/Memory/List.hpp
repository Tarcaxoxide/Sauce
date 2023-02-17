//#include<Sauce/Types.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/Memory/Memory.hpp>
#pragma once
namespace Sauce{
    namespace Memory{
        template<typename TT,size_t StageSize=32>
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
                bool AddFirst(const TT nValue){
                    if(++Array_Size > Array_Capacity){
                        Array_Capacity+=StageSize;
                    }
                    void* nArray = Sauce::Memory::malloc(Array_Capacity*(sizeof(TT)));
                    Sauce::Memory::memset(nArray,0,Array_Capacity*(sizeof(TT)));
                    Sauce::Memory::memcpy(Array,(void*)(((TT*)nArray)+1),Array_Size);
                    ((TT*)nArray)[0]=nValue;
                    delete[] ((TT*)Array);
                    Array = nArray;
                    
                    return true;
                }
                bool AddLast(const TT nValue){
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
                bool RemoveFirst(){
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
                bool RemoveLast(){
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
            public://Secondary functions
                bool AddFirst(const TT* nValue){
                    TT* ValuePtr = (TT*)nValue;
                    while(*ValuePtr){
                        if(!AddFirst(*ValuePtr))return false;
                        ValuePtr++;
                    }
                    return true;
                }
                inline bool AddFirst(const List_cl<TT>& nValue){
                    for(size_t i=0;i<nValue.Size();i++){
                        if(!AddFirst(nValue[i]))return false;
                    }
                    return true;
                }
                inline bool push_front(const TT* nValue){return AddFirst(nValue);}
                inline bool push_front(const List_cl<TT>& nValue){return AddFirst(nValue);}
                inline bool pop_front(){return RemoveFirst();}
                bool AddLast(const TT* nValue){
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
                TT& Get(size_t index)const{
                    size_t target=IndexGaurd(index); // no more out of range errors :) doesn't mean your program will run well though. (Last+1 == First)
                    return ((TT*)Array)[target];
                }
                void BitGet(size_t index,size_t bitAddress,bool& Value)const{
                    uint8_t bitIndex = bitAddress%8;
                    uint8_t bitIndexer = 0b10000000 >> bitIndex;
                    Value=((((uint8_t*)Array)[IndexGaurd(index)] & bitIndexer) > 0);
                }
                void BitSet(size_t index,size_t bitAddress,bool Value){
                    uint8_t bitIndex = bitAddress%8;
                    uint8_t bitIndexer = 0b10000000 >> bitIndex;
                    ((uint8_t*)Array)[IndexGaurd(index)] &= ~bitIndexer;
                    if(Value)((uint8_t*)Array)[IndexGaurd(index)] |= bitIndexer;
                }
                void BitFlip(size_t index,size_t bitAddress){
                    bool Value;
                    BitGet(index,bitAddress,Value);
                    BitSet(index,bitAddress,!Value);
                }
                TT& First()const{
                    return Get(0); // the first element, it's always the 0th element *shrug* unless shift_value is specified but that's taken care of.
                }
                TT& front()const{
                    return First(); // the first element, it's always the 0th element *shrug* unless shift_value is specified but that's taken care of.
                }
                TT& Last()const{
                    return Get(Array_Size-1);
                }
                TT& back()const{
                    return Last();
                }
                void* Raw()const{
                    return Array;
                }
                TT* RawTyped()const{
                    return ((TT*)Raw());
                }
                size_t Count()const{
                    return Array_Size;
                }
                size_t Capacity()const{
                    return Array_Capacity;
                }
                size_t Size()const{
                    return Count(); // Size calls count because it's the count of how many elements there are.
                }
                void Flip(){
                    List_cl<TT> Other(*this);
                    Clear();
                    for(size_t i=0;i<Other.Size();i++){
                        AddFirst(Other[i]);
                    }
                }
                void Clear(){
                    Sauce::Memory::memset(Array,0,Array_Capacity);// we'll be a good neighbor and clean up our mess.
                    if(Array != nullptr){
                        delete[] ((TT*)Array);
                        Array=nullptr;
                    }
                    Array_Capacity=0;
                    Array_Size=0;
                }
                bool Compare(const List_cl<TT>& OtherValue)const{
                    if(OtherValue.Size() != Array_Size)return false;
                    for(size_t i=0;i<Array_Size;i++){
                        if(Get(i) != OtherValue[i])return false;
                    }
                    return true;
                }
                bool Compare(const TT** OtherValues)const{
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
                void ForEach(void (*CallBack)(TT &Item)){ //void Function(TT &item){/*Do something with item*/}
                    for(size_t i=0;i<Array_Size;i++){
                        (*CallBack)(Get(i));
                    }
                }
                void ForEach(void (*CallBack)(TT &Item,size_t& index)){ //void Function(TT &item){/*Do something with item*/}
                    for(size_t i=0;i<Array_Size;i++){
                        (*CallBack)(Get(i),i);
                    }
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
                bool Push(TV& OtherValue){
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
                TT* operator=(const TT* nValue){
                    Clear();
                    AddLast(nValue);
                    return RawTyped();
                }
                TT* operator=(const TT nValue){
                    Clear();
                    AddLast(nValue);
                    return RawTyped();
                }
                TT* operator+=(const TT* nValue){
                    AddLast(nValue);
                    return RawTyped();
                }
                TT* operator+=(const TT nValue){
                    AddLast(nValue);
                    return RawTyped();
                }
                TT* operator+=(const List_cl<TT>& nValue){
                    AddLast(nValue);
                    return RawTyped();
                }
                TT* operator+(const TT* nValue)const{
                    List_cl<TT> tmp(RawTyped());
                    tmp+=nValue;
                    return tmp.RawTyped();
                }
                TT* operator+(const TT nValue)const{
                    List_cl<TT> tmp(RawTyped());
                    tmp+=nValue;
                    return tmp.RawTyped();
                }
                TT* operator+(const List_cl<TT>& nValue)const{
                    List_cl<TT> tmp(RawTyped());
                    tmp+=nValue;
                    return tmp.RawTyped();
                }
                TT& operator[](size_t TargetIndex)const{
                    return Get(TargetIndex);
                }
                bool operator==(const TT* OtherValue)const{
                    List_cl<TT> OtherTmp(OtherValue);
                    return Compare(OtherTmp);
                }
                bool operator==(List_cl<TT> OtherValue)const{
                    return Compare(OtherValue);
                }
                bool operator!=(const TT* OtherValue)const{
                    List_cl<TT> OtherTmp(OtherValue);
                    return !Compare(OtherTmp);
                }
                bool operator!=(const TT** OtherValues)const{
                    return !Compare(OtherValues);
                }
                bool operator!=(const List_cl<TT>& OtherValue)const{
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
