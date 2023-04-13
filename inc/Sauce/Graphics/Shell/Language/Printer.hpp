#ifndef __Sauce_Graphics_Shell_Language_Printer
#define __Sauce_Graphics_Shell_Language_Printer
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
				std::string Print_str(Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> value);
			};
		};
	};
};
#endif