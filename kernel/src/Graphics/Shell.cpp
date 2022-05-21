#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(size_t X,size_t Y)
        :Terminal_cl((X*Y),X){
            Clear();
        }
        void Shell_cl::PutChar(unsigned char chr){
            for(size_t X=0;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
                for(size_t Y=0;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
                    GOP_PixelStructure ThisColor{0,0,0,0xFF};
                    
                    ThisColor.Red=ForegroundColor.Red/9;
                    ThisColor.Green=ForegroundColor.Green/9;
                    ThisColor.Blue=ForegroundColor.Blue/9;
                    ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X,Y,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X,Y,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X,Y,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Alpha=Sauce::Graphics::SauceFont::Glyphs[chr][Sauce::ind(X,Y,Sauce::Graphics::SauceFont::GlyphWidth)];

                    if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                        PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                    }else{
                        PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                    }
                }
            }
            Cursor.X+=Sauce::Graphics::SauceFont::GlyphWidth;
        }
        
    };
};