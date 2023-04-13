#include<Sauce/Graphics/Shell/Language/Parser.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Reader_cl::next(){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Reader_cl::next()",_NAMESPACE_,_ALLOW_PRINT_);
					if(m_index<(int64_t)m_tokens.Size())return m_tokens[m_index++];
					return "";
				}
				std::string Reader_cl::peek(int64_t offset){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Reader_cl::peek()",_NAMESPACE_,_ALLOW_PRINT_);
					if(m_index+offset<(int64_t)m_tokens.Size() && m_index+offset > -1)return m_tokens[m_index+offset];
					return "";
				}
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_list(Reader_cl &reader){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Read_list",_NAMESPACE_,_ALLOW_PRINT_);
					reader.next();
					Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::ListValue> list({});
					while(reader.peek().Size() && reader.peek()[0] != ')'){
						list->push(Read_form(reader));
					}
					reader.next();
					return list.As<Sauce::Graphics::Shell::Language::Types::Value>();
				}
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_atom(Reader_cl &reader){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Read_atom",_NAMESPACE_,_ALLOW_PRINT_);
					Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::SymbolValue> Symbol(reader.next());
					return Symbol.As<Sauce::Graphics::Shell::Language::Types::Value>();
				}
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_form(Reader_cl &reader){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Read_form",_NAMESPACE_,_ALLOW_PRINT_);
					std::string token = reader.peek();
					if(!token.Size()){
						Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::SymbolValue> Result(std::string(""));
						return Result.As<Sauce::Graphics::Shell::Language::Types::Value>();
					};
					switch(token[0]){
						case '(':return Read_list(reader);
						default:return Read_atom(reader);
					}
				}
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Parser(std::list<std::string> tokens){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Parser",_NAMESPACE_,_ALLOW_PRINT_);
					Sauce::Graphics::Shell::Language::Reader_cl reader(tokens);
					return Read_form(reader);
				}
			};
		};
	};
};