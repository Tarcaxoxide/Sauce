#pragma once
#include<Sauce/Fauxon/DataTypes/AbstractSyntaxTreeDataType.hpp>
#include<_std/string.hpp>
#include<Sauce/Fauxon/DataTypes/TokenDataType.hpp>
namespace Sauce{
    namespace Fauxon{
        struct Parser_st{
            Sauce::Fauxon::DataTypes::TokenList_st Tokens;
            Sauce::Fauxon::DataTypes::Program_st Parse(_std::string sourceCode);
            Sauce::Fauxon::DataTypes::Statement_st* Parse_Statement();
            Sauce::Fauxon::DataTypes::Statement_st* Parse_Expression();
            Sauce::Fauxon::DataTypes::Statement_st* Parse_PrimaryExpression();
            Sauce::Fauxon::DataTypes::TokenDataType_st at();
            Sauce::Fauxon::DataTypes::TokenDataType_st eat();
            bool eof();
        };
    };
};