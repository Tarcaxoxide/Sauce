#include<Sauce/Fauxon/Parser.hpp>
#include<Sauce/Fauxon/Tokenize.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Fauxon{
        Sauce::Fauxon::DataTypes::Program_st Parser_st::Parse(_std::string sourceCode){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Parser_st::Parse",_NAMESPACE_,_ALLOW_PRINT_);
            Debugger.Print(sourceCode);
            Tokens.Clear();
            Tokens = Tokenize(sourceCode);
            Debugger.Print(Tokens.toString());
            Sauce::Fauxon::DataTypes::Program_st Program;
            while(!this->eof()){
                Program.Body.AddLast(this->Parse_Statement());
            }
            return Program;
        }
        Sauce::Fauxon::DataTypes::Statement_st* Parser_st::Parse_Statement(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Parser_st::Parse_Statement",_NAMESPACE_,_ALLOW_PRINT_);
            return this->Parse_Expression();
        }
        Sauce::Fauxon::DataTypes::Statement_st* Parser_st::Parse_Expression(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Parser_st::Parse_Expression",_NAMESPACE_,_ALLOW_PRINT_);
            return this->Parse_PrimaryExpression();
        }
        Sauce::Fauxon::DataTypes::Statement_st* Parser_st::Parse_PrimaryExpression(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Parser_st::Parse_PrimaryExpression",_NAMESPACE_,_ALLOW_PRINT_);
            Sauce::Fauxon::DataTypes::TokenDataType_st tk = this->at();
            switch((Sauce::Fauxon::DataTypes::TokenSubKind_en::TokenSubKind_en)tk.Header.SubKind){
                case Sauce::Fauxon::DataTypes::TokenSubKind_en::__WORD:{
                    Debugger.Print("__WORD");
                    Sauce::Fauxon::DataTypes::Statement_st* R = new Sauce::Fauxon::DataTypes::Statement_st(tk);
                    this->eat();
                    return R;
                }break;
                case Sauce::Fauxon::DataTypes::TokenSubKind_en::__WHOLE_NUMBER:{
                    Debugger.Print("__WHOLE_NUMBER");
                    Sauce::Fauxon::DataTypes::Statement_st* R = new Sauce::Fauxon::DataTypes::Statement_st(tk);
                    this->eat();
                    return R;
                }break;
                case Sauce::Fauxon::DataTypes::TokenSubKind_en::__DECIMAL_NUMBER:{
                    Debugger.Print("__DECIMAL_NUMBER");
                    Sauce::Fauxon::DataTypes::Statement_st* R = new Sauce::Fauxon::DataTypes::Statement_st(tk);
                    this->eat();
                    return R;
                }break;
                case Sauce::Fauxon::DataTypes::TokenSubKind_en::__POINT_NUMBER:{
                    Debugger.Print("__POINT_NUMBER");
                    Sauce::Fauxon::DataTypes::Statement_st* R = new Sauce::Fauxon::DataTypes::Statement_st(tk);
                    this->eat();
                    return R;
                }break;
                default:{
                    Debugger.Print("Unexpected token");
                    _std::string msg="Unexpected token ";
                    msg+=tk.toString();
                    this->eat();
                    return new Sauce::Fauxon::DataTypes::Error_st(msg);
                }break;
            }
            return nullptr;//should ever get to this point but the compiler is complaining so i gave it something.
        }
        Sauce::Fauxon::DataTypes::TokenDataType_st Parser_st::at(){
            return Tokens.First();
        }
        Sauce::Fauxon::DataTypes::TokenDataType_st Parser_st::eat(){
            Sauce::Fauxon::DataTypes::TokenDataType_st tk=this->at();
            Tokens.RemoveFirst();
            return tk;
        }
        bool Parser_st::eof(){
            return Tokens.First().Header.SubKind == (uint64_t)Sauce::Fauxon::DataTypes::TokenSubKind_en::__EOF;
        }
    };
};