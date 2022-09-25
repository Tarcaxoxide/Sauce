#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Mouse.hpp>


uint8_t Glyphs[][13*13]={
                {
                    9,9,9,9,8,7,6,5,4,3,2,1,0,
                    9,0,0,1,2,3,4,5,6,7,8,9,0,
                    9,0,0,1,0,0,0,0,0,0,0,0,0,
                    9,1,1,0,2,0,0,0,0,0,0,0,0,
                    8,2,0,2,0,3,0,0,0,0,0,0,0,
                    7,3,0,0,3,0,4,0,0,0,0,0,0,
                    6,4,0,0,0,4,0,5,0,0,0,0,0,
                    5,5,0,0,0,0,5,0,6,0,0,0,0,
                    4,6,0,0,0,0,0,6,0,7,0,0,0,
                    3,7,0,0,0,0,0,0,7,0,8,0,0,
                    2,8,0,0,0,0,0,0,0,8,0,9,0,
                    1,9,0,0,0,0,0,0,0,0,9,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0
                }
};


namespace Sauce{
    namespace Graphics{
        void Mouse_cl::PutChar(size_t chr){
            Sauce::IO::Debug::Debugger_st Debugger("Mouse_cl::PutChar",_NAMESPACE_);
            for(size_t X=0;X<13;X++){
                for(size_t Y=0;Y<13;Y++){
                    GOP_PixelStructure ThisColor{0,0,0,0xFF};
                    ThisColor.Red=ForegroundColor.Red/9;
                    ThisColor.Green=ForegroundColor.Green/9;
                    ThisColor.Blue=ForegroundColor.Blue/9;
                    ThisColor.Red*=Glyphs[chr][Sauce::Math::index(X-1,Y-1,13)];
                    ThisColor.Green*=Glyphs[chr][Sauce::Math::index(X-1,Y-1,13)];
                    ThisColor.Blue*=Glyphs[chr][Sauce::Math::index(X-1,Y-1,13)];
                    ThisColor.Alpha=Glyphs[chr][Sauce::Math::index(X-1,Y-1,13)];
                    if(!(ThisColor.Red == 0x00 && ThisColor.Blue == 0x00 && ThisColor.Green == 0x00 && ThisColor.Alpha == 0x00)){
                        PixelBuffer[Sauce::Math::index(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=ThisColor;
                    }
                }
            }
        }
        Mouse_cl::Mouse_cl(Sauce::Point64_st InitialPosition)
        :Terminal_cl((13*13),13,InitialPosition){
            Sauce::IO::Debug::Debugger_st Debugger("Mouse_cl::Mouse_cl",_NAMESPACE_);
            Clear();
            PutChar(0);
            Sauce::IO::PS2MouseInitialize(InitialPosition);
        }
    };

};
