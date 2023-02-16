#include<Sauce/Fauxon/DataTypes/AbstractSyntaxTreeDataType.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace AbstractSyntaxTreeSubKind_en{
                _std::string toString(AbstractSyntaxTreeSubKind_en SubKind){
                    Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"AbstractSyntaxTreeSubKind_en::toString",_NAMESPACE_,_ALLOW_PRINT_);
                    _std::string Result="";
                    switch(SubKind){
                        case AbstractSyntaxTreeSubKind_en::__NULL:{Result="__NULL";}break;
                        case AbstractSyntaxTreeSubKind_en::__LITERAL:{Result="__LITERAL";}break;
                        case AbstractSyntaxTreeSubKind_en::__PROGRAM:{Result="__PROGRAM";}break;
                        case AbstractSyntaxTreeSubKind_en::__IDENTIFIER:{Result="__IDENTIFIER";}break;
                        case AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION:{Result="__BINARY_EXPRESSION";}break;
                    }
                    Debugger.Print(Result);
                    return Result;
                }
            };
            ///
            Statement_st::Statement_st(const TokenDataType_st& _StatementValue)
            :BaseDataType_st(Kind_en::__STATEMENT,(uint64_t)AbstractSyntaxTreeSubKind_en::__LITERAL),
             StatementValue(_StatementValue){
            }
            Statement_st::Statement_st(const Statement_st& Other)
            :BaseDataType_st(Other.Header.Kind,Other.Header.SubKind),
             StatementValue(Other.StatementValue){
                
            }
            Statement_st::Statement_st(AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en SubKind)
            :BaseDataType_st(Kind_en::__STATEMENT,(uint64_t)SubKind),
             StatementValue(TokenSubKind_en::__NULL){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Statement_st::Statement_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            ///
            BinaryExpression_st::BinaryExpression_st(const Statement_st& _Left,const Statement_st& _Operator,const Statement_st& _Right)
            :Statement_st(AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION),
             Left(_Left),
             Operator(_Operator),
             Right(_Right){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::BinaryExpression_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            BinaryExpression_st::BinaryExpression_st(const BinaryExpression_st& Other)
            :Statement_st(AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION),
             Left(Other.Left),
             Operator(Other.Operator),
             Right(Other.Right){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::BinaryExpression_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            BinaryExpression_st::~BinaryExpression_st(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::~BinaryExpression_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            ///
            Program_st::Program_st(void):Statement_st(AbstractSyntaxTreeSubKind_en::__PROGRAM){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::Program_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            Program_st::Program_st(const Program_st& Other):Statement_st(AbstractSyntaxTreeSubKind_en::__PROGRAM){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::Program_st",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t i=0;i<Other.Body.Size();i++)Body.AddLast(Other.Body[i]);
            }
            Program_st::~Program_st(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::~Program_st",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t i=0;i<Body.Size();i++)delete Body[i];
                Body.Clear();
            }
            ///
        };
    };
};