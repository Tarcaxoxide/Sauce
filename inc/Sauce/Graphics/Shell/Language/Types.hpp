#ifndef __Sauce_Graphics_Shell_Language_Types
#define __Sauce_Graphics_Shell_Language_Types
#include<stddef.h>
#include<stdint.h>
#include<std/string.hpp>
#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				namespace Types{
					class Value{
						public:
							virtual std::string inspect();
							virtual ~Value();
					};
					class ListValue:public Value{
						std::list<Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value>> m_list;
						public:
							virtual std::string inspect();
							ListValue(){}
							void push(Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> item){m_list.push_back(item);}
							virtual ~ListValue();
					};
					class SymbolValue: public Value{
						std::string m_str;
						public:
							virtual std::string inspect();
							SymbolValue(std::string str):m_str(str){}
							virtual ~SymbolValue();
					};
				};
			};
		};
	};
};
#endif