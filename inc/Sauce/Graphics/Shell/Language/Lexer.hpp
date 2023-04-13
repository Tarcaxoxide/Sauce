#ifndef __Sauce_Graphics_Shell_Language_Lexer
#define __Sauce_Graphics_Shell_Language_Lexer
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				class Lexer_cl{
					std::string m_input;
					int64_t m_index;
					public:
						Lexer_cl(std::string input):m_input(input),m_index(0){}
						std::string Next();
					private:
				};
			};
		};
	};
};
#endif