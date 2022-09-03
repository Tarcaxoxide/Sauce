#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace Graphics{
        Window_cl::Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
        :Shell_cl(Size,Offset){
            Sauce::IO::Debug::Print_Call("Window_cl::Window_cl",Sauce::IO::Debug::WINDOW);

            Sauce::IO::Debug::Print_Return("<this>",Sauce::IO::Debug::WINDOW);
        }
	};
};
