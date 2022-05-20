#include<Sauce/Graphics/Shell.hpp>


namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(size_t X,size_t Y)
        :Terminal_cl((X*Y),X){
            Clear();
        }

        void Shell_cl::PutChar(const unsigned char chr){
            // TODO:: use custom font to print characters
        }
        
    };
};