#ifndef __std_unique_ptr
#define __std_unique_ptr
#include<std/forward.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
    template<typename T>
    class unique_ptr{
    private:
        T * ptr = nullptr;public:
        unique_ptr() : ptr(nullptr){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
        }
        unique_ptr(T * ptr) 
            :ptr(ptr){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
        }
        unique_ptr(const unique_ptr & obj) = delete;
        unique_ptr& operator=(const unique_ptr & obj) = delete;
        unique_ptr(unique_ptr && dyingObj){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::unique_ptr",_NAMESPACE_,_ALLOW_PRINT_);
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        void operator=(unique_ptr && dyingObj){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::operator=",_NAMESPACE_,_ALLOW_PRINT_);
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }
        T* operator->(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::operator->",_NAMESPACE_,_ALLOW_PRINT_);
            return this->ptr;
        }
        T& operator*(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"unique_ptr::operator*",_NAMESPACE_,_ALLOW_PRINT_);
            return *(this->ptr);
        }
    };
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_unique",_NAMESPACE_,_ALLOW_PRINT_);
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
};
#endif