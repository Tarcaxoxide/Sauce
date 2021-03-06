#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Graphics{
        Shell_cl::Shell_cl(Point64_t Size,Point64_t Offset)
        :Terminal_cl((Size.X*Size.Y),Size.X,Offset){
            Clear();
        }
        void Shell_cl::PutChar(wchar_t chr){
            size_t chrindex = (size_t)chr;
            if(chrindex > 255)chrindex-=8236; //<- get out of here you stupid "wide characters",
                                              // i'll deal with you later but for now i'm not insane enough.

            for(size_t X=2;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
                for(size_t Y=2;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
                    GOP_PixelStructure ThisColor{0,0,0,0xFF};

                    ThisColor.Red=ForegroundColor.Red/9;
                    ThisColor.Green=ForegroundColor.Green/9;
                    ThisColor.Blue=ForegroundColor.Blue/9;
                    ThisColor.Red*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Green*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Blue*=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                    ThisColor.Alpha=Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];

                    if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                        PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                    }else{
                        PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                    }
                }
            }
            Cursor.X+=Sauce::Graphics::SauceFont::GlyphWidth-2;
        }
        
    };
};