#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Lexer_cl::Next(){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Lexer_cl::Next()",_NAMESPACE_,_ALLOW_PRINT_);
					while(m_index<(int64_t)m_input.Size()){
						switch(m_input[m_index]){
							case ' ':case '\n':case '\t':case '\r':{m_index++;}break;
							case '"':{
								size_t start=m_index;
								while(++m_index<(int64_t)m_input.Size()&&(m_input[m_index]!='"'||m_input[m_index-1]=='\\')){}
								size_t length=m_index-start;m_index++;
								std::string Result = m_input.Substr(start,length+1);
								Debugger.Print(Result);
								return Result;
							}break;
							case '`':{
								size_t start=m_index;
								while(++m_index<(int64_t)m_input.Size()&&(m_input[m_index]!='`'||m_input[m_index-1]=='\\')){}
								size_t length=m_index-start;m_index++;
								std::string Result = m_input.Substr(start,length+1);
								Debugger.Print(Result);
								return Result;
							}break;
							case '\'':{
								size_t start=m_index;
								while(++m_index<(int64_t)m_input.Size()&&(m_input[m_index]!='\''||m_input[m_index-1]=='\\')){}
								size_t length=m_index-start;m_index++;
								std::string Result = m_input.Substr(start,length+1);
								Debugger.Print(Result);
								return Result;
							}break;
							case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':{
								size_t start=m_index;
								while(++m_index<(int64_t)m_input.Size()&&(m_input[m_index]=='.'
																||m_input[m_index]=='0'
																||m_input[m_index]=='1'
																||m_input[m_index]=='2'
																||m_input[m_index]=='3'
																||m_input[m_index]=='4'
																||m_input[m_index]=='5'
																||m_input[m_index]=='6'
																||m_input[m_index]=='7'
																||m_input[m_index]=='8'
																||m_input[m_index]=='9'
																)){}
								size_t length=m_index-start;
								std::string Result = m_input.Substr(start,length);
								Debugger.Print(Result);
								return Result;
							}break;
							case ',':case '.':case '~':case '+':case '-':case '*':case '/':case '=':case '(':case ')':case '{':case '}':case '<':case '>':case '[':case ']':{
								std::string Result = m_input.Substr(m_index++,1);
								if(m_input[m_index] == '@' && m_input[m_index-1] == '~')Result+=m_input.Substr(m_index++,1);
								Debugger.Print(Result);
								return Result;
							}break;
							default:{
								size_t start=m_index;
								while(++m_index<(int64_t)m_input.Size()&&!(m_input[m_index]==' '
																||m_input[m_index]=='\n'
																||m_input[m_index]=='\t'
																||m_input[m_index]=='\r'
																||m_input[m_index]==','
																||m_input[m_index]=='"'
																||m_input[m_index]=='`'
																||m_input[m_index]=='\''
																||m_input[m_index]=='('
																||m_input[m_index]==')'
																||m_input[m_index]=='{'
																||m_input[m_index]=='}'
																||m_input[m_index]=='<'
																||m_input[m_index]=='>'
																||m_input[m_index]=='['
																||m_input[m_index]==']'
																||m_input[m_index]=='~'
																||m_input[m_index]=='+'
																||m_input[m_index]=='-'
																||m_input[m_index]=='*'
																||m_input[m_index]=='/'
																||m_input[m_index]=='='
																)){}
								size_t length=m_index-start;
								std::string Result = m_input.Substr(start,length);
								Debugger.Print(Result);
								return Result;
							}break;
						}
					}
					Debugger.Print("EOL");
					return "";
				}
			};
		};
	};
};