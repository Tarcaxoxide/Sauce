#pragma once
#include<_std/string.hpp>
#include<Sauce/Types.hpp>
#include<_std/list.hpp>
#include<Sauce/Fauxon/DataTypes/BaseDataType.hpp>
#include<Sauce/Fauxon/DataTypes/TokenDataType.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace AbstractSyntaxTreeSubKind_en{
                enum AbstractSyntaxTreeSubKind_en:uint64_t{
                    __NULL=0,
                    __LITERAL,
                    __PROGRAM,
                    __BINARY_EXPRESSION,
                    __ERROR
                };
                _std::string toString(AbstractSyntaxTreeSubKind_en SubKind);
            };
            ///
            struct Statement_st:public BaseDataType_st{
                TokenDataType_st StatementValue;
                Statement_st(const TokenDataType_st& StatementValue);
                Statement_st(const Statement_st& Other);
                Statement_st(AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en SubKind);
                _std::string toString();
            };
            ///
            struct Error_st:public Statement_st{
                TokenDataType_st Message;
                Error_st(_std::string errorMessage);
                _std::string toString();
            };
            ///
            struct BinaryExpression_st:public Statement_st{
                Statement_st Left;
                Statement_st Operator;
                Statement_st Right;
                BinaryExpression_st(const Statement_st& Left,const Statement_st& Operator,const Statement_st& Right);
                BinaryExpression_st(const BinaryExpression_st& Other);
                ~BinaryExpression_st();
                _std::string toString();
            };
            ///
            struct Program_st:public Statement_st{
                _std::list<Statement_st*> Body;
                Program_st(void);
                Program_st(const Program_st& Other);
                ~Program_st();
                _std::string toString();
            };
        };
    };
};