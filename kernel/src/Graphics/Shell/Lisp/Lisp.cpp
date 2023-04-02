#include<Sauce/Graphics/Shell/Lisp/Lisp.hpp>
#include<Sauce/Graphics/Shell/Lisp/Tokenizer.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Lisp{
				std::string Read(std::string input){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Read",_NAMESPACE_,_ALLOW_PRINT_);
					Debugger.Print(input);
					std::list<std::string> tokens = Tokenizer(input);
					std::string Result="";
					for(size_t i=0;i<tokens.Size();i++){
						Debugger.Print(tokens[i]);
						Result+=tokens[i];
						Result+=",";
					}
					Debugger.Print(Result);
					return Result;
				}
				std::string Eval(std::string input){
					return input;
				}
				std::string Print(std::string input){
					return input;
				}
				std::string Exec(std::string input){
					std::string ast = Read(input);
					std::string result = Eval(ast);
					return Print(result);
				}
			};
		};
	};
};