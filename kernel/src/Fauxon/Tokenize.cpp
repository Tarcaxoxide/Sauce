#include<Sauce/Fauxon/Tokenize.hpp>
#include<_std/to_string.hpp>
#include<_std/to_int.hpp>
#include<_std/to_double.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace Fauxon{
        DataTypes::TokenList_st Tokenize(_std::string sourceCode){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Tokenize",_NAMESPACE_,_ALLOW_PRINT_);
            Debugger.Print(sourceCode);
            DataTypes::TokenList_st Tokens;
            return Tokens;
        }
    };
};
