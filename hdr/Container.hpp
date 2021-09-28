#pragma once
#include <stdint.h>
#include <stddef.h>

#include <Overrides.hpp>

#ifndef BIOS_STUFF
#define BIOS_STUFF
    extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
    extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack
    extern "C" uint8_t IsGraphical;
#endif

namespace Sauce{
    namespace Container{
        template <typename T> class Vector{
            T* arr;
            size_t capacity;
            size_t current;
            public:
                Vector(){
                    arr = new T[1];
                    capacity = 1;
                    current = 0;
                }
                void Push(T data){
                    if(current == capacity){
                        T* temp = new T[capacity+1];
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
                        // TODO: Throw !ERROR!
                    }
                }
                void Pop(){
                    current--;
                }
                size_t Size(){
                    return current;
                }
                size_t Capacity(){
                    return capacity;
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
    };
};