#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Lexer_cl::Next(){
					std::string Result="";
					while(m_index<m_input.Size()){
						switch(m_input[m_index]){
							case ' ':case '\n':case '\t':case '\r':{m_index++;}break;
							case '"':{
								size_t start=m_index;
								while(++m_index<m_input.Size()&&m_input[m_index]!='"'){}
								size_t length=m_index-start;m_index++;
								return m_input.Substr(start,length+1);
							}break;
							case '`':{
								size_t start=m_index;
								while(++m_index<m_input.Size()&&m_input[m_index]!='`'){}
								size_t length=m_index-start;m_index++;
								return m_input.Substr(start,length+1);
							}break;
							case '\'':{
								size_t start=m_index;
								while(++m_index<m_input.Size()&&m_input[m_index]!='\''){}
								size_t length=m_index-start;m_index++;
								return m_input.Substr(start,length+1);
							}break;
							case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':{
								size_t start=m_index;
								while(++m_index<m_input.Size()&&(m_input[m_index]=='.'
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
								return m_input.Substr(start,length);
							}break;
							case '.':case '~':case '+':case '-':case '*':case '/':case '=':case '(':case ')':case '{':case '}':case '<':case '>':case '[':case ']':{
								return m_input.Substr(m_index++,1);
							}break;
							default:{
								size_t start=m_index;
								while(++m_index<m_input.Size()&&!(m_input[m_index]==' '
																||m_input[m_index]=='\n'
																||m_input[m_index]=='\t'
																||m_input[m_index]=='\r'
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
								return m_input.Substr(start,length);
							}break;
						}
					}
					return Result;
				}
			};
		};
	};
};