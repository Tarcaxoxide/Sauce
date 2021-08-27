#include <Graphics.hpp>

namespace Sauce{
    namespace Graphics{
        uint8_t* GraphicsAddress = (uint8_t*)0xA0000;

        void PlacePixel(uint16_t X,uint16_t Y,uint16_t color){
            GraphicsAddress[(MAX_Xpos*Y)+X]=color;
        }
        void PlaceRectangle(uint16_t startX,uint16_t startY,uint16_t stopX,uint16_t stopY,uint16_t color){
            for(uint16_t iX=startX;iX<stopX;iX++){
                for(uint16_t iY=startY;iY<stopY;iY++){
                    PlacePixel(iX,iY,color);
                }
            }
        }
    };
};