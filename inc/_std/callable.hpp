#pragma once

#include<_std/unique_ptr.hpp>

namespace _std{
    struct callable_base{
      callable_base() = default;
      virtual ~callable_base() { }
      virtual bool invoke(int, char*) = 0;
      virtual unique_ptr<callable_base> clone() = 0;
    };
    template<typename T>
    struct callable : callable_base{
      T m_t;
      callable(T const& t) : m_t(t) {}
      callable(T&& t) : m_t(move(t)) {}
      bool invoke(int a, char* b) override{
        return m_t(a, b);
      }
      unique_ptr<callable_base> clone() override{
        return make_unique<callable>(m_t);
      }
    };
};