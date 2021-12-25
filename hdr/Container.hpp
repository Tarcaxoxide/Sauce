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
                        T* temp = new T[(capacity+1)*sizeof(T)]; // create a temporary space
                        for(size_t i = 0; i < capacity;i++){
                            temp[i] = arr[i]; // copy over the data to the temporary space
                        }
                        delete[] arr; // delete the old space'
                        arr  = new T[(capacity+1)*sizeof(T)]; // Create a new space
                        for(size_t i = 0; i < capacity;i++){
                            arr[i] = temp[i]; // copy the data back over
                        }
                        capacity++;// increase the capacity
                    }
                    arr[current] = data; // add the data push
                    current++;// increase the current.
                }
                T* operator[](size_t index){
                    if(!(index < current)){
                        Sauce::STOP(Sauce::Index_too_big); // stop, we have failed somewhere.
                    }
                    return &arr[index];
                }
                void Pop(){
                    arr[current--]=(T)NULL;
                }
                size_t Size(){
                    return current;
                }
                size_t Capacity(){
                    return capacity;
                }
                void Clear(){
                    //current=0;
                    while(current){
                        Pop();
                    }
                    //Resize(1);
                }
                T* Raw(){
                    delete[] result; // Delete the temporary space.
                    result = new T[current]; // Create a new temporary space.
                    for(size_t I=0;I<current;I++) // copy the data over to the temporary space
                        result[I] = arr[I];
                    return (T*)result; // return a pointer to the temporary space
                }
                const T* Value(){
                    delete[] result; // Delete the temporary space.
                    result = new T[current]; // Create a new temporary space.
                    for(size_t I=0;I<current;I++) // copy the data over to the temporary space
                        result[I] = arr[I];
                    return (const T*)result; // return a pointer to the temporary space
                }
                void Resize(size_t newSize){
                    T* temp = new T[newSize*sizeof(T)]; // Create a temprary space of size newSize
                    for(size_t i = 0; i < newSize;i++){
                        temp[i] = arr[i]; // copy the data over to the temporary space
                    }
                    delete[] arr; // delete the old space
                    capacity = newSize; // make the current capacity be the same as the newSize
                    arr = new T[newSize*sizeof(T)]; // create a new space.
                    for(size_t i = 0; i < newSize;i++){
                        arr[i] = temp[i]; // copy the data back over
                    }
                    delete[] temp;
                }
        };
        typedef DynamicArray<char> String;
    };
};
