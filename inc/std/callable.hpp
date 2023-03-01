#ifndef __std_callable
#define __std_callable
#include<std/unique_ptr.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
    struct callable_base{
      callable_base() = default;
      virtual ~callable_base(){}
      virtual bool invoke(int, char*) = 0;
      virtual unique_ptr<callable_base> clone() = 0;
    };
    template<typename T>
    struct callable : callable_base{
      T m_t;
      callable(T const& t) : m_t(t){}
      callable(T&& t) : m_t(move(t)){}
      bool invoke(int a, char* b) override{
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"callable::invoke",_NAMESPACE_,_ALLOW_PRINT_);
        return m_t(a, b);
      }
      unique_ptr<callable_base> clone() override{
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"callable::clone",_NAMESPACE_,_ALLOW_PRINT_);
        return make_unique<callable>(m_t);
      }
    };
};
#endif