#pragma once
#include<Sauce/Fauxon/DataTypes/BaseDataType.hpp>
#include<_std/string.hpp>
#include<Sauce/Types.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace TokenSubKind_en{
                enum TokenSubKind_en:uint64_t{
                    /*''*/__NULL=0,
                    /*'a..z|A..Z&...'*/__WORD,
                    /*'0..9&...'*/__WHOLE_NUMBER,
                    /*'WHOLE_NUMBER.WHOLE_NUMBER'*/__DECIMAL_NUMBER,
                    /*'WHOLE_NUMBER.WHOLE_NUMBER.WHOLE_NUMBER'*/__POINT_NUMBER,
                    /*'+'*/__PLUS,
                    /*'-'*/__MINUS,
                    /*'*'*/__MULTIPLY,
                    /*'/'*/__DIVIDE,
                    /*'('*/__LEFT_ROUND_BRACE,
                    /*')'*/__RIGHT_ROUND_BRACE,
                    /*'['*/__LEFT_SQUARE_BRACE,
                    /*']'*/__RIGHT_SQUARE_BRACE,
                    /*'{'*/__LEFT__CURLY_BRACE,
                    /*'}'*/__RIGHT_CURLY_BRACE,
                    /*','*/__COMMA,
                    /*'.'*/__DOT,
                    /*':'*/__COLON,
                    /*';'*/__SEMICOLON,
                    /*'''*/__APOSTROPHE,
                    /*'"'*/__QUOTE,
                    /*'`'*/__BACKTICK,
                    /*'\'*/__BACKSLASH,
                    /*'='*/__EQUALS,
                    /*'!'*/__NOT,
                    /*'<'*/__LESS,
                    /*'>'*/__MORE,
                    /*'=='*/__EQUALS_EQUALS,
                    /*'!='*/__NOT_EQUALS,
                    /*'>='*/__MORE_EQUALS,
                    /*'<='*/__LESS_EQUALS,
                    /*'><'*/__BIGGEST,
                    /*'<>'*/__SMALLEST,
                    /*'WORD'*/__ERROR,
                    __EOF
                };
                _std::string toString(TokenSubKind_en SubKind);
            };
            struct TokenDataType_st:public BaseDataType_st{
                TokenSubKind_en::TokenSubKind_en RawKind;//used for translation.
                void* Value{nullptr};
                ~TokenDataType_st();
                TokenDataType_st(const TokenDataType_st& Other);
                TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind);
                TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,_std::string Vin);
                TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,long double Vin);
                TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,int64_t Vin);
                TokenDataType_st(TokenSubKind_en::TokenSubKind_en SubKind,Sauce::Point64_st Vin);
                _std::string toString()const;
                void append(const TokenDataType_st& Other);
                void add(const TokenDataType_st& Other);
                void subtract(const TokenDataType_st& Other);
                void multiply(const TokenDataType_st& Other);
                void divide(const TokenDataType_st& Other);
            };
            struct TokenList_st:public Sauce::Memory::List_cl<TokenDataType_st>{
                _std::string toString();
            };
        };
    };
};




/*
loopLabel:
Foo();
Bar();
if(!condition)goto loopLabel;
*/