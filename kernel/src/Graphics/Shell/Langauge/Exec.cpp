#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>

#include<Sauce/IO/Debug/Serial.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Exec(std::string input){ //"rep"
					Sauce::Graphics::Shell::Language::Lexer_cl Lexer(input);
					std::string token = Lexer.Next();
					std::string Result="";
					
					while(token.Size()){
						Result+=token;

						//Why! Are! You! Like! This! <(?.?)>
						if(token == "1"){Result+=" (one).";}
						if(token == "2"){Result+=" (two).";}
						if(token == "3"){Result+=" (three).";}
						
						if(token.Size())Result+="\n\r";
						token = Lexer.Next();
					}
					return Result;
				}
			};
		};
	};
};
