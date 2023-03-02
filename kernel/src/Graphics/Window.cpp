#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		Window_cl::Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
		:Shell_cl(Size,Offset){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Window_cl",_NAMESPACE_,_ALLOW_PRINT_);
		}
	};
};
