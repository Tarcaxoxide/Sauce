#ifndef __Sauce_Graphics_Shell_Lisp_Tokenizer
#define __Sauce_Graphics_Shell_Lisp_Tokenizer
#include<std/string.hpp>
#include<std/list.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Lisp{
				std::list<std::string> Tokenizer(const std::string input);
			};
		};
	};
};
#endif