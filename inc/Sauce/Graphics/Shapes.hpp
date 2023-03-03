#ifndef __Sauce_Graphics_Shapes
#define __Sauce_Graphics_Shapes
#include<Sauce/Common.hpp>
#include<std/memset.hpp>
#include<Sauce/Types.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shapes{
			GOP_PixelStructure* MakeShapeBuffer(Sauce::Point64_t Size){
				if(Size.X<0||Size.Y<0||Size.Z<0)return nullptr;
				GOP_PixelStructure* NewShapeBuffer = new GOP_PixelStructure[(Size.X)*(Size.Y)*(Size.Z+1)];
				std::memset(NewShapeBuffer,0,(Size.X)*(Size.Y)*(Size.Z+1));
				return NewShapeBuffer;
			}
		};
	};
};
#endif