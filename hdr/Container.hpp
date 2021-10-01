#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Misc.hpp>

namespace Sauce{
    namespace Container{
        template <typename T> class DynamicArray{
            T* arr;
            T* result;
            size_t capacity;
            size_t current;
            public:
                DynamicArray(){
                    arr = new T[1];
                    capacity = 1;
                    current = 0;
                }
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
                        STOP(1); // stop, we have failed somewhere.
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
        typedef DynamicArray<char> String;
    };
};