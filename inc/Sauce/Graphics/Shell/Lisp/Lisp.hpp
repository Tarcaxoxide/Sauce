#ifndef __Sauce_Graphics_Shell_Lisp_Lisp
#define __Sauce_Graphics_Shell_Lisp_Lisp
#include<std/string.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Lisp{
				std::string Read(std::string input);
				std::string Eval(std::string input);
				std::string Print(std::string input);
				std::string Exec(std::string input);
			};
		};
	};
};
#endif