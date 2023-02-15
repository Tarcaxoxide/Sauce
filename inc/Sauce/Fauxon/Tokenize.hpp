#pragma once
#include<Sauce/Fauxon/DataTypes/TokenDataType.hpp>
#include<_std/string.hpp>

namespace Sauce{
    namespace Fauxon{
        void Tokenize(_std::string sourceCode,DataTypes::TokenList_st& Tokens);
    };
};
