#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/IO/Debug/Console.hpp>


uint8_t Glyphs[][13*13]={
                {
                    9,9,9,9,8,7,6,5,4,3,2,1,0,
                    9,0,0,1,2,3,4,5,6,7,8,9,0,
                    9,0,0,0,0,0,0,0,0,0,0,0,0,
                    9,1,0,0,0,0,0,0,0,0,0,0,0,
                    8,2,0,0,0,0,0,0,0,0,0,0,0,
                    7,3,0,0,0,0,0,0,0,0,0,0,0,
                    6,4,0,0,0,0,0,0,0,0,0,0,0,
                    5,5,0,0,0,0,0,0,0,0,0,0,0,
                    4,6,0,0,0,0,0,0,0,0,0,0,0,
                    3,7,0,0,0,0,0,0,0,0,0,0,0,
                    2,8,0,0,0,0,0,0,0,0,0,0,0,
                    1,9,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0
                }
};


namespace Sauce{
    namespace Graphics{
        void Mouse_cl::PutChar(wchar_t chr){
            size_t chrindex = (size_t)chr;
            if(chrindex > 255)chrindex-=8236; //<- get out of here you stupid "wide characters",
                                              // i'll deal with you later but for now i'm not insane enough.
            switch(chrindex){
                case '\n':{GoDown();}break;
                case '\b':{GoLeft();}break;
                default:{
                    for(size_t X=2;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
                        for(size_t Y=2;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
                            GOP_PixelStructure ThisColor{0,0,0,0xFF};
                            ThisColor.Red=ForegroundColor.Red/9;
                            ThisColor.Green=ForegroundColor.Green/9;
                            ThisColor.Blue=ForegroundColor.Blue/9;
                            ThisColor.Red*=Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Green*=Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Blue*=Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            ThisColor.Alpha=Glyphs[chrindex][Sauce::ind(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
                            if(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00){
                                PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=BackgroundColor;
                            }else{
                                PixelBuffer[Sauce::ind(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                            }
                        }
                    }
                    if(!GoRight()){
                        if(GoDown()){
                            GoFarLeft();
                        }
                    }
                }break;
            }

        }
        Mouse_cl::Mouse_cl(Point64_t InitialPosition)
        :Terminal_cl((13*13),13,Offset){
            PutChar(0);
        }
    };

};