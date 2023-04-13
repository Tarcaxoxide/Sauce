#ifndef __Sauce_Graphics_Shell_Language_Parser
#define __Sauce_Graphics_Shell_Language_Parser
#include<stddef.h>
#include<stdint.h>
#include<std/string.hpp>
#include<Sauce/Graphics/Shell/Language/Types.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
#include<std/list.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				class Reader_cl{
					std::list<std::string> m_tokens;
					int64_t m_index;
					public:
						Reader_cl(std::list<std::string> tokens):m_tokens(tokens),m_index(0){}
						std::string next();
						std::string peek(int64_t offset=0);
					private:
				};
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_list(Reader_cl &reader);
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_atom(Reader_cl &reader);
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Read_form(Reader_cl &reader);
				Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> Parser(std::list<std::string> tokens);
			};
		};
	};
};
#endif