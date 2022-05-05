#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/Heap.hpp>

namespace Sauce{
    namespace Memory{
        
        template<class TT>
        struct LinkList_st{
            TT Value;
            void** First=NULL;
            void* Previews=NULL;
            void* Next=NULL;
            void** Last=NULL;
        };

        template<class TT>
        struct DynamicArray_st{
            LinkList_st<TT>* Array=NULL;
            LinkList_st<TT>* First=NULL;
            LinkList_st<TT>* Last=NULL;
            DynamicArray_st<TT>(){
                Array = new LinkList_st<TT>;
                First=Array;
                Last=Array;

                Array->First=&First;
                Array->Previews=NULL;
                Array->Next=NULL;
                Array->Last=&Last;

                Array->Value=(TT)0x000000000000000000;
            }
            ~DynamicArray_st<TT>(){
                
            }
            void AddFirst(TT newValue){
                LinkList_st<TT>* NewVariable = new LinkList_st<TT>;
                First->Previews=NewVariable;
                NewVariable->Next=First;
                First=NewVariable;
                NewVariable->First=&First;
                NewVariable->Last=&Last;
                NewVariable->Value=newValue;
            }
            void AddLast(TT newValue){
                LinkList_st<TT>* NewVariable = new LinkList_st<TT>;
                Last->Next=NewVariable;
                NewVariable->Previews=Last;
                Last=NewVariable;
                NewVariable->First=&First;
                NewVariable->Last=&Last;
                NewVariable->Value=newValue;
            }
        };
    };
};