#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace Graphics{
        Window_cl::Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Shell_cl(Size,Offset){
            Sauce::IO::Debug::Debugger_st Debugger("Window_cl::Window_cl",_NAMESPACE_);
        }
	};
};
