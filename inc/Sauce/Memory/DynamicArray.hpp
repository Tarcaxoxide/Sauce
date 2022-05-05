#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        
        template<class TT>
        struct LinkList_st{
            TT Value;
            LinkList_st<TT>** First=NULL;
            LinkList_st<TT>* Previews=NULL;
            LinkList_st<TT>* Next=NULL;
            LinkList_st<TT>** Last=NULL;
            TT operator*(){
                return Value;
            }
            bool PeekBackward(){
                return (Previews != NULL);
            }
            bool PeekForward(){
                return (Next != NULL);
            }
            void operator=(LinkList_st* NewSelf){
                Value=NewSelf->Value;
                First=NewSelf->First;
                Previews=NewSelf->Previews;
                Next=NewSelf->Next;
                Last=NewSelf->Last;
            }
            TT operator++(){Value++;return Value;}
            TT operator--(){Value--;return Value;}
            TT operator+=(TT newValue){Value+=newValue;return Value;}
            TT operator-=(TT newValue){Value-=newValue;return Value;}
            TT operator/=(TT newValue){Value/=newValue;return Value;}
            TT operator*=(TT newValue){Value*=newValue;return Value;}
            TT operator%=(TT newValue){Value%=newValue;return Value;}
            TT operator&=(TT newValue){Value&=newValue;return Value;}
            TT operator=(TT newValue){Value=newValue;return Value;}
        };

        template<class TT>
        struct DynamicArray_st{
            LinkList_st<TT>* Current=NULL;
            LinkList_st<TT>* First=NULL;
            LinkList_st<TT>* Last=NULL;
            size_t Size=0;
            DynamicArray_st<TT>(TT newValue){
                Current = new LinkList_st<TT>;
                First=Current;
                Last=Current;

                Current->First=&First;
                Current->Previews=NULL;
                Current->Next=NULL;
                Current->Last=&Last;

                Current->Value=newValue;
                Current=Current;
                Size=1;
            }
            ~DynamicArray_st<TT>(){
                LinkList_st<TT>* Target = First; // 'Target' exist to check if there is a next element to be removed.
                for(;Target->PeekForward();){ // we iterate from the first element to the second from last element removing them all. 
                    RemoveFirst();
                    Target=First;
                }
                delete[] Last; // we delete the last element since it's next would be null and so it wont be picked up in the for loop.
            }
            void AddFirst(TT newValue){
                LinkList_st<TT>* NewVariable = new LinkList_st<TT>; // we create a new element.
                First->Previews=NewVariable; // the previews first element's previews element pointer is set to this new element.
                NewVariable->Next=First; // this new element's next element pointer is set to previews first element.
                First=NewVariable; // the first element pointer is set to the new element.
                NewVariable->First=&First; // the first and last pointers of the new element are set.  
                NewVariable->Last=&Last;   
                NewVariable->Value=newValue; // the value of the new element is set.
                Size++;
            }
            void AddLast(TT newValue){
                LinkList_st<TT>* NewVariable = new LinkList_st<TT>; // we create a new element.
                Last->Next=NewVariable; // the previews last element's next pointer is set to the new element.
                NewVariable->Previews=Last; // the new element's previews pointer is set to the previews last element.
                Last=NewVariable; // the last element pointer is set to the new element.
                NewVariable->First=&First; // the first and last pointers of the new element are set.  
                NewVariable->Last=&Last;
                NewVariable->Value=newValue; // the value of the new element is set.
                Size++;
            }
            void RemoveFirst(){
                LinkList_st<TT>* NewFirst = First->Next;
                if(Current == First)Current=First->Next;
                delete[] First;
                First=NewFirst;
                First->Previews=NULL;
                Size--;
            }
            void RemoveLast(){
                LinkList_st<TT>* NewLast = Last->Previews;
                if(Current == Last)Current=Last->Previews;
                delete[] Last;
                Last=NewLast;
                Last->Next=NULL;
                Size--;
            }
            bool PeekForward(){
                return Current->PeekForward();
            }
            bool PeekBackward(){
                return Current->PeekBackward();
            }
            bool GoForward(){
                if(PeekForward()){
                    Current=Current->Next;
                    return true;
                }
                return false;
            }
            bool GoBackward(){
                if(PeekBackward()){
                    Current=Current->Previews;
                    return true;
                }
                return false;
            }
            void GoToFirst(){
                Current=First;
            }
            void GoToLast(){
                Current=Last;
            }
            TT operator*(){
                return (TT)*(*Current);
            }
            LinkList_st<TT>* operator()(){
                return Current;
            }
        };
    };
};