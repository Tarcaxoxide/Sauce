#ifndef __std_functional
#define __std_functional
#include<std/forward.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace std{
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
          Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"function::operator()",_NAMESPACE_,_ALLOW_PRINT_);
          return functionPtr (forward<Arguments> (args)...);
      }
      Result(*functionPtr)(Arguments...) = nullptr;
  };
};
#endif