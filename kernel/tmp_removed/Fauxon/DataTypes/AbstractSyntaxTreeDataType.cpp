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
                        case AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION:{Result="__BINARY_EXPRESSION";}break;
                        case AbstractSyntaxTreeSubKind_en::__ERROR:{Result="__ERROR";}break;
                    }
                    Debugger.Print(Result);
                    return Result;
                }
            };
            ///
            Statement_st::Statement_st(const TokenDataType_st& _StatementValue)
            :BaseDataType_st(Kind_en::__STATEMENT,(uint64_t)AbstractSyntaxTreeSubKind_en::__LITERAL),
             StatementValue(_StatementValue){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Statement_st::Statement_st",_NAMESPACE_,_ALLOW_PRINT_);
                Debugger.Print(StatementValue.toString());
            }
            Statement_st::Statement_st(const Statement_st& Other)
            :BaseDataType_st(Other.Header.Kind,Other.Header.SubKind),
             StatementValue(Other.StatementValue){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Statement_st::Statement_st(Copy Constructor)",_NAMESPACE_,_ALLOW_PRINT_);
                Debugger.Print(Other.StatementValue.toString());
            }
            Statement_st::Statement_st(AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en SubKind)
            :BaseDataType_st(Kind_en::__STATEMENT,(uint64_t)SubKind),
             StatementValue(TokenSubKind_en::__NULL){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Statement_st::Statement_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            _std::string Statement_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Statement_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="{";
                Result+=DataTypes::Kind_en::toString(Header.Kind);
                Result+=DataTypes::AbstractSyntaxTreeSubKind_en::toString((DataTypes::AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en)Header.SubKind);
                Result+=":";
                Result+=StatementValue.toString();
                Result+="}";
                Debugger.Print(Result);
                return Result;
            }
            ///
            Error_st::Error_st(_std::string errorMessage)
            :Statement_st(AbstractSyntaxTreeSubKind_en::__ERROR),
             Message(TokenSubKind_en::__ERROR,errorMessage){}
             _std::string Error_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Error_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="{";
                Result+=DataTypes::Kind_en::toString(Header.Kind);
                Result+=DataTypes::AbstractSyntaxTreeSubKind_en::toString((DataTypes::AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en)Header.SubKind);
                Result+=":";
                Result+=Message.toString();
                Result+="}";
                Debugger.Print(Result);
                return Result;
             }
            ///
            BinaryExpression_st::BinaryExpression_st(const Statement_st& _Left,const Statement_st& _Operator,const Statement_st& _Right)
            :Statement_st(AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION),
             Left(_Left),
             Operator(_Operator),
             Right(_Right){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::BinaryExpression_st",_NAMESPACE_,_ALLOW_PRINT_);
                Debugger.Print(Left.toString());
                Debugger.Print(Operator.toString());
                Debugger.Print(Right.toString());
            }
            BinaryExpression_st::BinaryExpression_st(const BinaryExpression_st& Other)
            :Statement_st(AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION),
             Left(Other.Left),
             Operator(Other.Operator),
             Right(Other.Right){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::BinaryExpression_st(Copy Constructor)",_NAMESPACE_,_ALLOW_PRINT_);
                Debugger.Print(Left.toString());
                Debugger.Print(Operator.toString());
                Debugger.Print(Right.toString());
            }
            BinaryExpression_st::~BinaryExpression_st(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::~BinaryExpression_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            _std::string BinaryExpression_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"BinaryExpression_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="{";
                Result+=DataTypes::Kind_en::toString(Header.Kind);
                Result+=DataTypes::AbstractSyntaxTreeSubKind_en::toString((DataTypes::AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en)Header.SubKind);
                Result+=":";
                Result+=Left.toString();
                Result+=",";
                Result+=Operator.toString();
                Result+=",";
                Result+=Right.toString();
                Result+="}";
                Debugger.Print(Result);
                return Result;
             }
            ///
            Program_st::Program_st(void):Statement_st(AbstractSyntaxTreeSubKind_en::__PROGRAM){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::Program_st",_NAMESPACE_,_ALLOW_PRINT_);
            }
            Program_st::Program_st(const Program_st& Other):Statement_st(AbstractSyntaxTreeSubKind_en::__PROGRAM){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::Program_st(Copy Constructor)",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t i=0;i<Other.Body.Size();i++){
                    switch((AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en)Other.Body[i]->Header.SubKind){
                        case AbstractSyntaxTreeSubKind_en::__PROGRAM:{
                            Body.AddLast(new Program_st(*((Program_st*)Other.Body[i])));
                        }break;
                        case AbstractSyntaxTreeSubKind_en::__LITERAL:{
                            Body.AddLast(new Statement_st(*((Statement_st*)Other.Body[i])));
                        }break;
                        case AbstractSyntaxTreeSubKind_en::__BINARY_EXPRESSION:{
                            Body.AddLast(new BinaryExpression_st(*((BinaryExpression_st*)Other.Body[i])));
                        }break;
                    }
                    Debugger.Print(Body.Last()->toString());
                }
            }
            Program_st::~Program_st(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::~Program_st",_NAMESPACE_,_ALLOW_PRINT_);
                for(size_t i=0;i<Body.Size();i++)delete Body[i];
                Body.Clear();
            }
            _std::string Program_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Program_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="{";
                Result+=DataTypes::Kind_en::toString(Header.Kind);
                Result+=DataTypes::AbstractSyntaxTreeSubKind_en::toString((DataTypes::AbstractSyntaxTreeSubKind_en::AbstractSyntaxTreeSubKind_en)Header.SubKind);
                Result+=":";
                for(size_t i=0;i<Body.Size();i++){
                    Result+=Body[i]->toString()+_std::string((i<Body.Size()-1?",":""));
                }
                Result+="}";
                Debugger.Print(Result);
                return Result;
             }
            ///
        };
    };
};