#include<_std/forward.hpp>
#pragma once
namespace _std{
  template <typename>
  class function;

  template <typename Result, typename... Arguments>
  class function<Result (Arguments...)>
  {
  public:
      template <typename Functor>
      function (Functor f):functionPtr(f){}
      function() = default;
      Result operator() (Arguments&&... args) const{
            return functionPtr (forward<Arguments> (args)...);
      }
      
      Result(*functionPtr)(Arguments...) = nullptr;
  };
};
