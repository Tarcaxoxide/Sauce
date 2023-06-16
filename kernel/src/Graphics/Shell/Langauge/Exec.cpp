#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Exec(std::string input){ //"rep"
					Sauce::Graphics::Shell::Language::Lexer_cl Lexer(input);
					std::string token = Lexer.Next();
					std::string Result="";

					while(token.Size()){
						if(token == "0")token="zero";
						if(token == "1")token="one";

						Result+=token;
						if(token.Size())Result+="\n\r";
						token = Lexer.Next();
					}
					return Result;
				}
			};
		};
	};
};
