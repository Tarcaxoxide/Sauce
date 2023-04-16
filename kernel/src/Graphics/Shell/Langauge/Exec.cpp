#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/Graphics/Shell/Language/Lexer.hpp>

#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Exec(std::string input){ //"rep"
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Exec",_NAMESPACE_,_ALLOW_PRINT_);
					Sauce::Graphics::Shell::Language::Lexer_cl Lexer(input);
					std::string token = Lexer.Next();
					std::string Result="";
					while(token.Size()){
						Result+=token;
						Result+="\n\r";
						Debugger.Print(token);
						token = Lexer.Next();
					}
					return Result;
				}
			};
		};
	};
};
