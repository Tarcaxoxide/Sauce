#include <Graphics.hpp>

namespace Sauce{
    namespace Graphics{
        uint8_t* GraphicsAddress = (uint8_t*)0xA0000;

        void PlacePixel(uint16_t X,uint16_t Y,uint16_t color){
            GraphicsAddress[(MAX_Xpos*Y)+X]=color;
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint16(((MAX_Xpos*Y)+X)));
            Sauce::Terminal::String("=");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint16(color));
            Sauce::Terminal::String("\n\r");
        }
        void PlaceRectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color){
            for(uint16_t iX=startX;iX<stopX;iX++){
                for(uint16_t iY=startY;iY<stopY;iY++){
                    PlacePixel(iX,iY,color);
                }
            }
        }
        void PlaceVector(_Vector Vector,uint16_t color){
            uint16_t X,Y,StopX,StopY;
            if(Vector.StopX > Vector.StartX){
                StopX=Vector.StopX;
                X=Vector.StartX;
            }else{
                StopX=Vector.StartX;
                X=Vector.StopX;
            }
            if(Vector.StopY > Vector.StartY){
                StopY=Vector.StopY;
                Y=Vector.StartY;
            }else{
                StopY=Vector.StartY;
                Y=Vector.StopY;
            }
            while(1){
                PlacePixel(X,Y,color);

                if(X<StopX)X++;
                if(Y<StopY)Y++;
                if( (!(Y<StopY)) && (!(X<StopX)) )break;
            }
        }
        void PlaceEmptySquare(uint16_t Xs,uint16_t Ys,uint16_t Xp,uint16_t Yp,uint16_t color){
            PlaceVector({Xp+(1*Xs),Yp+(1*Ys),Xp+(1*Xs),Yp+(2*Ys)},color);
            PlaceVector({Xp+(1*Xs),Yp+(2*Ys),Xp+(2*Xs),Yp+(2*Ys)},color);
            PlaceVector({Xp+(2*Xs),Yp+(2*Ys)+1,Xp+(2*Xs),Yp+(1*Ys)},color);
            PlaceVector({Xp+(2*Xs),Yp+(1*Ys),Xp+(1*Xs),Yp+(1*Ys)},color);
        }
    };
};