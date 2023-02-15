#include<Sauce/Fauxon/DataTypes/TokenDataType.hpp>
#include<_std/to_string.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace TokenSubKind_en{
                _std::string toString(TokenSubKind_en SubKind){
                    _std::string Result="";
                    switch(SubKind){
                        case TokenSubKind_en::__NULL:{Result="__NULL";}break;
                        case TokenSubKind_en::__WORD:{Result="__WORD";}break;
                        case TokenSubKind_en::__WHOLE_NUMBER:{Result="__WHOLE_NUMBER";}break;
                        case TokenSubKind_en::__DECIMAL_NUMBER:{Result="__DECIMAL_NUMBER";}break;
                        case TokenSubKind_en::__PLUS:{Result="__PLUS";}break;
                        case TokenSubKind_en::__MINUS:{Result="__MINUS";}break;
                        case TokenSubKind_en::__MULTIPLY:{Result="__MULTIPLY";}break;
                        case TokenSubKind_en::__DIVIDE:{Result="__DIVIDE";}break;
                        case TokenSubKind_en::__LEFT_ROUND_BRACE:{Result="__LEFT_ROUND_BRACE";}break;
                        case TokenSubKind_en::__RIGHT_ROUND_BRACE:{Result="__RIGHT_ROUND_BRACE";}break;
                        case TokenSubKind_en::__LEFT_SQUARE_BRACE:{Result="__LEFT_SQUARE_BRACE";}break;
                        case TokenSubKind_en::__RIGHT_SQUARE_BRACE:{Result="__RIGHT_SQUARE_BRACE";}break;
                        case TokenSubKind_en::__LEFT__CURLY_BRACE:{Result="__LEFT__CURLY_BRACE";}break;
                        case TokenSubKind_en::__RIGHT_CURLY_BRACE:{Result="__RIGHT_CURLY_BRACE";}break;
                        case TokenSubKind_en::__COMMA:{Result="__COMMA";}break;
                        case TokenSubKind_en::__DOT:{Result="__DOT";}break;
                        case TokenSubKind_en::__COLON:{Result="__COLON";}break;
                        case TokenSubKind_en::__SEMICOLON:{Result="__SEMICOLON";}break;
                        case TokenSubKind_en::__APOSTROPHE:{Result="__APOSTROPHE";}break;
                        case TokenSubKind_en::__QUOTE:{Result="__QUOTE";}break;
                        case TokenSubKind_en::__BACKTICK:{Result="__BACKTICK";}break;
                        case TokenSubKind_en::__BACKSLASH:{Result="__BACKSLASH";}break;
                        case TokenSubKind_en::__EQUALS:{Result="__EQUALS";}break;
                        case TokenSubKind_en::__NOT:{Result="__NOT";}break;
                        case TokenSubKind_en::__LESS:{Result="__LESS";}break;
                        case TokenSubKind_en::__MORE:{Result="__MORE";}break;
                        case TokenSubKind_en::__EQUALS_EQUALS:{Result="__EQUALS_EQUALS";}break;
                        case TokenSubKind_en::__NOT_EQUALS:{Result="__NOT_EQUALS";}break;
                        case TokenSubKind_en::__MORE_EQUALS:{Result="__MORE_EQUALS";}break;
                        case TokenSubKind_en::__LESS_EQUALS:{Result="__LESS_EQUALS";}break;
                        case TokenSubKind_en::__BIGGEST:{Result="__BIGGEST";}break;
                        case TokenSubKind_en::__SMALLEST:{Result="__SMALLEST";}break;
                        case TokenSubKind_en::__ERROR:{Result="__ERROR";}break;
                    };
                    return Result;
                }
            };
                
            TokenDataType_st::TokenDataType_st(void):BaseDataType_st(Kind_en::__TOKEN,(uint64_t)TokenSubKind_en::__NULL){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::TokenDataType_st(void)",_NAMESPACE_,_ALLOW_PRINT_);
            }
            TokenDataType_st::TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind):BaseDataType_st(Kind_en::__TOKEN,(uint64_t)SubKind){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::TokenDataType_st(SubKind)",_NAMESPACE_,_ALLOW_PRINT_);
            }
            TokenDataType_st::TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,_std::string Vin):BaseDataType_st(Kind_en::__TOKEN,(uint64_t)SubKind){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::TokenDataType_st(SubKind,Word)",_NAMESPACE_,_ALLOW_PRINT_);
                RawKind=TokenSubKind_en::__WORD;
                Value = new _std::string(Vin);
            }
            TokenDataType_st::TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,long double Vin):BaseDataType_st(Kind_en::__TOKEN,(uint64_t)SubKind){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::TokenDataType_st(SubKind,Decimal)",_NAMESPACE_,_ALLOW_PRINT_);
                RawKind=TokenSubKind_en::__DECIMAL_NUMBER;
                Value = new long double(Vin);
            }
            TokenDataType_st::TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,int64_t Vin):BaseDataType_st(Kind_en::__TOKEN,(uint64_t)SubKind){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::TokenDataType_st(SubKind,Number)",_NAMESPACE_,_ALLOW_PRINT_);
                RawKind=TokenSubKind_en::__WHOLE_NUMBER;
                Value = new int64_t(Vin);
            }
            _std::string TokenDataType_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenDataType_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="(";
                if(RawKind == TokenSubKind_en::__WORD)Result+=(*((_std::string*)Value));
                else if(RawKind == TokenSubKind_en::__WHOLE_NUMBER)Result+=_std::to_string((*((int64_t*)Value)));
                else if(RawKind == TokenSubKind_en::__DECIMAL_NUMBER)Result+=_std::to_string((*((long double*)Value)));
                Result+=")";
                Debugger.Print(Result);
                return Result;
            }

            
            _std::string TokenList_st::toString(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TokenList_st::toString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="[";
                for(size_t i=0;i<Size();i++){
                    Result+=(*this)[i].toString();
                }
                Result+="]";
                Debugger.Print(Result);
                return Result;
            }
        };
    };
};