#pragma once

#include<_std/forward.hpp>

namespace _std{
    template<typename T>
    class unique_ptr{
    private:
        T * ptr = nullptr;public:
        unique_ptr() : ptr(nullptr){
        }
        unique_ptr(T * ptr) 
            :ptr(ptr){
        }
        unique_ptr(const unique_ptr & obj) = delete;
        unique_ptr& operator=(const unique_ptr & obj) = delete;
        unique_ptr(unique_ptr && dyingObj){
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        void operator=(unique_ptr && dyingObj){
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        T* operator->(){
            return this->ptr;
        }
        T& operator*(){
            return *(this->ptr);
        }
    };
    template<typename T, typename... Args>
    _std::unique_ptr<T> make_unique(Args&&... args){
        return _std::unique_ptr<T>(new T(_std::forward<Args>(args)...));
    }
};