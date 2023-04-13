#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/Graphics/Shell/Language/Lexer.hpp>
#include<Sauce/Graphics/Shell/Language/Parser.hpp>
#include<Sauce/Graphics/Shell/Language/Printer.hpp>
#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::list<std::string> READ(std::string input){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"READ",_NAMESPACE_,_ALLOW_PRINT_);
					std::list<std::string> Result;
					Sauce::Graphics::Shell::Language::Lexer_cl Lexer(input);
					std::string token = Lexer.Next();
					while(token.Size()){
						Result.AddLast(token);
						Debugger.Print(token);
						token = Lexer.Next();
					}
					return Result;
				}
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> EVAL(Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> input){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"EVAL",_NAMESPACE_,_ALLOW_PRINT_);
					return input;
				}
				std::string PRINT(Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> input){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"PRINT",_NAMESPACE_,_ALLOW_PRINT_);
					return Sauce::Graphics::Shell::Language::Print_str(input);
				}
				std::string Exec(std::string e){ //"rep"
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Exec",_NAMESPACE_,_ALLOW_PRINT_);
					std::list<std::string> tokens = READ(e);
					Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> AST = Sauce::Graphics::Shell::Language::Parser(tokens);
					Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Result = EVAL(AST);
					std::string strResult = PRINT(Result);
					return strResult;
				}
			};
		};
	};
};
