#include<Sauce/Graphics/Shell.hpp>


namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(size_t X,size_t Y)
        :Terminal_cl((X*Y),X){
            Clear();
        }

        void Shell_cl::PutChar(const unsigned char chr){
            for(size_t X=0;X<16;X++){
                for(size_t Y=0;Y<16;Y++){
                    PixelBuffer[Sauce::ind(X,Y,16)]=ForegroundColor;
                }
            }
        }
        
    };
};