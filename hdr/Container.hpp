#pragma once
#ifndef BIOS_STUFF
#define BIOS_STUFF
    extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
    extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
    extern "C" uint8_t IsGraphical;
#endif

#include <stdint.h>
#include <stddef.h>
#include <Misc.hpp>

namespace Sauce{
    namespace Container{
        template <typename T> class Vector{
            T* arr;
            T* result;
            size_t capacity;
            size_t current;
            public:
                Vector(){
                    arr = new T[1];
                    capacity = 1;
                    current = 0;
                }
                //~Vector(){
                //    delete[] arr; //we should be a good citizen of the system and clean up our mess when we are done.
                //}
                void Push(T data){
                    if(current == capacity){
                        T* temp = new T[(capacity+1)*sizeof(T)];
                        for(size_t i = 0; i < capacity;i++){
                            temp[i] = arr[i];
                        }
                        delete[] arr;
                        capacity+=1;
                        arr = temp;
                    }
                    arr[current] = data;
                    current++;
                }
                T* operator[](size_t index){
                    if(index < current){
                        return &arr[index];
                    }else{
                        Sauce::STOP(true); // stop, we have failed somewhere.
                    }
                }
                void Pop(){
                    --current;
                }
                size_t Size(){
                    return current;
                }
                size_t Capacity(){
                    return capacity;
                }
                void Clear(){
                    while(current){
                        Pop();
                    }
                }
                T* Raw(){
                    delete[] result;
                    result = new T[current];
                    for(size_t I=0;I<current;I++)
                        result[I] = arr[I];
                    return (T*)result;
                }
                void Resize(size_t newSize,T data){
                    T* temp = new T[newSize*sizeof(T)];
                    for(size_t i = 0; i < capacity;i++){
                        temp[i] = arr[i];
                    }
                    delete[] arr;
                    capacity = newSize;
                    arr = temp;
                }
        };

        typedef Vector<char> String;
    };
};