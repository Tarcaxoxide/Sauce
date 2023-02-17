#pragma once
#include<Sauce/Fauxon/DataTypes/TokenDataType.hpp>
#include<_std/string.hpp>

namespace Sauce{
    namespace Fauxon{
        DataTypes::TokenList_st Tokenize(_std::string sourceCode);
    };
};
