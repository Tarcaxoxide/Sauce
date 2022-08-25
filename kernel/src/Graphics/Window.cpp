#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace Graphics{
        Window_cl::Window_cl(Point64_t Size,Point64_t Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,"Window",Offset){
            Sauce::IO::Debug::Print_Call("Shell_cl::Shell_cl",Sauce::IO::Debug::SHELL);
            Clear();
            Sauce::IO::Debug::Print_Return("this",Sauce::IO::Debug::SHELL);
        }
        
    };
};