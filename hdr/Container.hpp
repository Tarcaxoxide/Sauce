#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Misc.hpp>
#include <Utils.hpp>

namespace Sauce{
    namespace Container{
        template <typename T> class DynamicArray{
            T* arr=NULL;
            size_t capacity=0;
            size_t current=0;
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
                    current--;
                    arr[current]=NULL;
                }
                //TODO:: Implement Pop_front() to remove the first element from the list
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

                T* operator()(){
                    return (T*)(const T*)arr;
                }
                void Resize(size_t newSize){
                    T* temp = new T[newSize+1]; // Create a temprary space of size newSize
                    for(size_t i = 0; i < newSize;i++){
                        temp[i] = arr[i]; // copy the data over to the temporary space
                    }
                    temp[newSize]=NULL;
                    delete[] arr; // delete the old space
                    capacity = newSize; // make the current capacity be the same as the newSize
                    arr = new T[newSize+1]; // create a new space.
                    for(size_t i = 0; i < newSize;i++){
                        arr[i] = temp[i]; // copy the data back over
                    }
                    arr[newSize]=NULL;
                    delete[] temp;
                }
        };
        typedef DynamicArray<char> String;
        struct StringList{
            String Words;
            //TODO:: Implement Push(Word) to add a new word to the list.
            //TODO:: Implement Pop() to remove last word from list and Pop_front() to remove the first word.
            //TODO:: Implement Clear() to remove all words from list.
            //TODO:: Implement Size() to get the count of words in the list.
            //TODO:: Implement operator[]() to get specific word from list.
            //TODO:: Implement operator==() to check if a word exist in the list and return the index+1 (0 for false)

        };
    };
};
