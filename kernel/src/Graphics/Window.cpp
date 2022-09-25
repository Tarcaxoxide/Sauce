#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace Graphics{
        Window_cl::Window_cl(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Shell_cl(pDebugger,Size,Offset){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Window_cl::Window_cl",_NAMESPACE_);
        }
	};
};
