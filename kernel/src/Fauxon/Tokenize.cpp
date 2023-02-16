#include<Sauce/Fauxon/Tokenize.hpp>
#include<_std/to_string.hpp>
#include<_std/to_int.hpp>
#include<_std/to_double.hpp>
#include<_std/to_point.hpp>
#include<Sauce/IO/Debug/Debug.hpp>


bool isNumberic(char x){
    if(x == '1')return true;
    if(x == '2')return true;
    if(x == '3')return true;
    if(x == '4')return true;
    if(x == '5')return true;
    if(x == '6')return true;
    if(x == '7')return true;
    if(x == '8')return true;
    if(x == '9')return true;
    if(x == '0')return true;
    return false;
}

bool isAlphabetic(char x){
    if(x == 'q')return true;
    if(x == 'w')return true;
    if(x == 'e')return true;
    if(x == 'r')return true;
    if(x == 't')return true;
    if(x == 'y')return true;
    if(x == 'u')return true;
    if(x == 'i')return true;
    if(x == 'o')return true;
    if(x == 'p')return true;
    if(x == 'a')return true;
    if(x == 's')return true;
    if(x == 'd')return true;
    if(x == 'f')return true;
    if(x == 'g')return true;
    if(x == 'h')return true;
    if(x == 'j')return true;
    if(x == 'k')return true;
    if(x == 'l')return true;
    if(x == 'z')return true;
    if(x == 'x')return true;
    if(x == 'c')return true;
    if(x == 'v')return true;
    if(x == 'b')return true;
    if(x == 'n')return true;
    if(x == 'm')return true;
    if(x == 'Q')return true;
    if(x == 'W')return true;
    if(x == 'E')return true;
    if(x == 'R')return true;
    if(x == 'T')return true;
    if(x == 'Y')return true;
    if(x == 'U')return true;
    if(x == 'I')return true;
    if(x == 'O')return true;
    if(x == 'P')return true;
    if(x == 'A')return true;
    if(x == 'S')return true;
    if(x == 'D')return true;
    if(x == 'F')return true;
    if(x == 'G')return true;
    if(x == 'H')return true;
    if(x == 'J')return true;
    if(x == 'K')return true;
    if(x == 'L')return true;
    if(x == 'Z')return true;
    if(x == 'X')return true;
    if(x == 'C')return true;
    if(x == 'V')return true;
    if(x == 'B')return true;
    if(x == 'N')return true;
    if(x == 'M')return true;
    return false;
}

namespace Sauce{
    namespace Fauxon{
        void Tokenize(_std::string sourceCode,DataTypes::TokenList_st& Tokens){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Tokenize",_NAMESPACE_,_ALLOW_PRINT_);
            Tokens.Clear();
            for(size_t i=0;i<sourceCode.Size();i++){
                if(sourceCode[i] == '\n')continue;
                if(sourceCode[i] == '\t')continue;
                if(sourceCode[i] == '\r')continue;
                if(sourceCode[i] == ' ')continue;
                if(isAlphabetic(sourceCode[i])){
                    _std::string tmp="";
                    while(isAlphabetic(sourceCode[i])||isNumberic(sourceCode[i])||sourceCode[i]=='_'){
                        tmp+=sourceCode[i++];
                    }
                    Debugger.Print("Word?");
                    Debugger.Print(tmp);
                    Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__WORD,tmp));
                }else if(isNumberic(sourceCode[i])){
                    _std::string tmp="";
                    size_t dot_count=0;
                    while(isNumberic(sourceCode[i])||sourceCode[i] == '.'){
                        if(sourceCode[i] == '.'){
                            dot_count++;
                        }
                        tmp+=sourceCode[i++];
                    }
                    Debugger.Print("Number?");
                    Debugger.Print(tmp);
                    if(dot_count > 2){
                        _std::string msg="Malformed decimal or number '";
                        msg+=tmp;
                        msg+="' at index ";
                        msg+=_std::to_string(i);
                        Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__ERROR,msg));
                    }else if(dot_count == 1){
                        Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__DECIMAL_NUMBER,_std::to_double(tmp)));
                    }else if(dot_count == 2){
                        Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__POINT_NUMBER,_std::to_point(tmp)));
                    }
                    else{
                        Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__WHOLE_NUMBER,_std::to_int(tmp)));
                    }
                }else{
                    switch(sourceCode[i]){
                        case '+':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__PLUS));}break;
                        case '-':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__MINUS));}break;
                        case '*':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__MULTIPLY));}break;
                        case '/':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__DIVIDE));}break;
                        case '(':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__LEFT_ROUND_BRACE));}break;
                        case ')':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__RIGHT_ROUND_BRACE));}break;
                        case '[':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__LEFT_SQUARE_BRACE));}break;
                        case ']':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__RIGHT_SQUARE_BRACE));}break;
                        case '{':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__LEFT__CURLY_BRACE));}break;
                        case '}':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__RIGHT_CURLY_BRACE));}break;
                        case ',':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__COMMA));}break;
                        case '.':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__DOT));}break;
                        case ':':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__COLON));}break;
                        case ';':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__SEMICOLON));}break;
                        case '\'':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__APOSTROPHE));}break;
                        case '"':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__QUOTE));}break;
                        case '`':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__BACKTICK));}break;
                        case '\\':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__BACKSLASH));}break;
                        case '=':{
                            if(Tokens.Size()){
                                switch(((Sauce::Fauxon::DataTypes::TokenSubKind_en::TokenSubKind_en)Tokens.Last().Header.SubKind)){
                                    case Sauce::Fauxon::DataTypes::TokenSubKind_en::__EQUALS:{
                                        Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__EQUALS_EQUALS;
                                    }break;
                                    case Sauce::Fauxon::DataTypes::TokenSubKind_en::__NOT:{
                                        Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__NOT_EQUALS;
                                    }break;
                                    case Sauce::Fauxon::DataTypes::TokenSubKind_en::__MORE:{
                                        Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__MORE_EQUALS;
                                    }break;
                                    case Sauce::Fauxon::DataTypes::TokenSubKind_en::__LESS:{
                                        Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__LESS_EQUALS;
                                    }break;
                                    default:{
                                        Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__EQUALS));
                                    }break;
                                }
                            }else{
                                Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__EQUALS));
                            }
                        }break;
                        case '!':{Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__NOT));}break;
                        case '<':{
                            if(Tokens.Size() && ((Sauce::Fauxon::DataTypes::TokenSubKind_en::TokenSubKind_en)Tokens.Last().Header.SubKind) == Sauce::Fauxon::DataTypes::TokenSubKind_en::__MORE){
                                Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__BIGGEST;
                            }else{
                                Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__LESS));
                            }
                        }break;
                        case '>':{
                            if(Tokens.Size() && ((Sauce::Fauxon::DataTypes::TokenSubKind_en::TokenSubKind_en)Tokens.Last().Header.SubKind) == Sauce::Fauxon::DataTypes::TokenSubKind_en::__LESS){
                                Tokens.Last().Header.SubKind=Sauce::Fauxon::DataTypes::TokenSubKind_en::__SMALLEST;
                            }else{
                                Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__MORE));
                            }
                        }break;
                        default:{
                            _std::string msg="Unidentified token '";
                            msg+=sourceCode[i];
                            msg+="' at index ";
                            msg+=_std::to_string(i);
                            Tokens.AddLast(DataTypes::TokenDataType_st(Sauce::Fauxon::DataTypes::TokenSubKind_en::__ERROR,msg));
                        }break;
                    }
                }
            }
        }
    };
};