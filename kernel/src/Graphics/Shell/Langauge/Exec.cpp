#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
#include<std/list.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{

				std::list<std::string> READ(std::string input){
					std::list<std::string> Result;
					Sauce::Graphics::Shell::Language::Lexer_cl Lexer(input);
					std::string token = Lexer.Next();
					while(token.Size()){
						Result.AddLast(token);
						token = Lexer.Next();
					}
					return Result;
				}
				std::string EVAL(std::string input){return input;}
				std::string PRINT(std::string input){return input;}
				std::string Exec(std::string e){ //"rep"
					std::list<std::string> tokens = READ(e);
					//TODO: continue implementing XD...
					return "UNFINISHED";
				}
			};
		};
	};
};