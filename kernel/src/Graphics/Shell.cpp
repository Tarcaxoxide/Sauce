#include<Sauce/Graphics/Shell.hpp>


namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(size_t X,size_t Y)
        Terminal_cl((X*Y),X){
            Fill({0x40,0x40,0x40,0xFF});
        }
    };
};