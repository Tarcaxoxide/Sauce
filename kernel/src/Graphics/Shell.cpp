#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(size_t X,size_t Y)
        :Terminal_cl((X*Y),X){
            Clear();
        }

        void Shell_cl::PutChar(unsigned char chr){
            for(size_t X=0;X<7;X++){
                for(size_t Y=0;Y<7;Y++){
                    GOP_PixelStructure ThisColor{0,0,0,0xFF};
                    
                    ThisColor.Red=ForegroundColor.Red/9;
                    ThisColor.Green=ForegroundColor.Green/9;
                    ThisColor.Blue=ForegroundColor.Blue/9;
                    ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X+Cursor.X,Y+Cursor.Y,7)];
                    ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X+Cursor.X,Y+Cursor.Y,7)];
                    ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X+Cursor.X,Y+Cursor.Y,7)];

                    PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                }
            }
            Cursor.X+=7;
        }
        
    };
};