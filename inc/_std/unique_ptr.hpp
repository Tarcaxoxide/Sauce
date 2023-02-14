#include<_std/forward.hpp>
#pragma once
#include<Sauce/IO/Debug/Debug.hpp>
namespace _std{
    template<typename T>
    class unique_ptr{
    private:
        T * ptr = nullptr;public:
        unique_ptr() : ptr(nullptr){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
        }
        unique_ptr(T * ptr) 
            :ptr(ptr){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
        }
        unique_ptr(const unique_ptr & obj) = delete;
        unique_ptr& operator=(const unique_ptr & obj) = delete;
        unique_ptr(unique_ptr && dyingObj){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        void operator=(unique_ptr && dyingObj){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::operator=",_NAMESPACE_,_ALLOW_PRINT_);
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        T* operator->(){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::operator->",_NAMESPACE_,_ALLOW_PRINT_);
            return this->ptr;
        }
        T& operator*(){
            Sauce::IO::Debug::Debugger_st Debugger("unique_ptr::operator*",_NAMESPACE_,_ALLOW_PRINT_);
            return *(this->ptr);
        }
    };
    template<typename T, typename... Args>
    _std::unique_ptr<T> make_unique(Args&&... args){
        Sauce::IO::Debug::Debugger_st Debugger("make_unique",_NAMESPACE_,_ALLOW_PRINT_);
        return _std::unique_ptr<T>(new T(_std::forward<Args>(args)...));
    }
};