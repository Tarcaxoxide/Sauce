#include<Sauce/Graphics/Frame.hpp>
#include<Sauce/Math.hpp>
#include<std/memcpy.hpp>

namespace Sauce{
	namespace Graphics{
		namespace Basic{
			Frame_st::Frame_st(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,GOP_PixelStructure* Buffer){
				//if you don't provide a buffer we create one, else we use the one you provide and we assume your not inaccurate about it's dimensions :)
				if(Buffer == nullptr){PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];}else{PixelBuffer=Buffer;}
				this->PixelBufferTotalSize=PixelBufferTotalSize;
				this->PixelsPerLine=PixelsPerLine;
				PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
				this->Offset=Offset;
			}
			Frame_st::Frame_st(const Frame_st& Other){
				PixelBufferTotalSize=Other.PixelBufferTotalSize;
				PixelsPerLine=Other.PixelsPerLine;
				PixelsBufferHeight=Other.PixelsBufferHeight;
				BorderColor=Other.BorderColor;
				PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
				std::memcpy(Other.PixelBuffer,PixelBuffer,PixelBufferTotalSize);
				SetPointer({0,0,0});
				BorderDraw();
			}
			Frame_st::~Frame_st(){
				delete PixelBuffer;
				PixelBuffer=nullptr;
			}
			bool Frame_st::SetPointer(Sauce::Point64_st pointer){
				if(pointer.X>PixelsPerLine || pointer.X < 0)return false;
				if(pointer.Y>PixelsBufferHeight || pointer.Y < 0)return false;
				PixelPointer=pointer;
				return true;
			}
			bool Frame_st::Is_Over(Sauce::Point64_st Location){
				bool Vertical=(Location.Y > Offset.Y/*below of my top?*/) && (Location.Y < Offset.Y+PixelsBufferHeight/*above of my bottom?*/);
				bool Horizontal=(Location.X > Offset.X/*right of my left*/) && (Location.X < Offset.X+PixelsPerLine/*left of my right*/);
				/*
					# = top left and bottom right corners of myself.
					1/0 = is over/is not over.
					000000000000
					0#1111111110
					011111111110
					011111111110
					011111111110
					0111111111#0
					000000000000
				*/
				return Vertical && Horizontal;
			}
			GOP_PixelStructure Frame_st::Blend(GOP_PixelStructure Front,GOP_PixelStructure Back){
				long double Alpha = ((long double)Front.Alpha)/((long double)0xFF);
				uint8_t Rnew = (Front.Red * Alpha) + (Back.Red * ((1.0+Sauce::Math::MINIMAL_LONG_DOUBLE) - Alpha));
				uint8_t Gnew = (Front.Green * Alpha) + (Back.Green * ((1.0+Sauce::Math::MINIMAL_LONG_DOUBLE) - Alpha));
				uint8_t Bnew = (Front.Blue * Alpha) + (Back.Blue * ((1.0+Sauce::Math::MINIMAL_LONG_DOUBLE) - Alpha));
				return {Bnew,Gnew,Rnew,(uint8_t)Sauce::Math::maximum((long double)Back.Alpha,(long double)Front.Alpha)};
			}
			Sauce::Point64_st Frame_st::Size(){
				return {PixelsPerLine,PixelsBufferHeight,0};
			}
			bool Frame_st::Move(Sauce::Point64_st Location){
				Offset=Location;
				return true;
			}
			bool Frame_st::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
				this->ForegroundColor=ForegroundColor;
				this->BackgroundColor=BackgroundColor;
				return true;
			}
			bool Frame_st::SetColorForeground(GOP_PixelStructure ForegroundColor){
				this->ForegroundColor=ForegroundColor;
				return true;
			}
			bool Frame_st::SetColorBackground(GOP_PixelStructure BackgroundColor){
				this->BackgroundColor=BackgroundColor;
				return true;
			}
			bool Frame_st::ReverseColor(){
				GOP_PixelStructure tmp=ForegroundColor;
				ForegroundColor=BackgroundColor;
				BackgroundColor=tmp;
				return true;
			}
			bool Frame_st::RowFill(int64_t RowIndex,GOP_PixelStructure TheColor){
				if(RowIndex >= PixelsBufferHeight || RowIndex < 0)return false;
				PixelPointer.Y=RowIndex;
				for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
					PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
				}
				return true;
			}
			bool Frame_st::ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor){
				if(ColumnIndex >= PixelsPerLine || ColumnIndex < 0){
					return false;
				}
				PixelPointer.X=ColumnIndex;
				for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
				}
				return true;
			}
			bool Frame_st::Fill(GOP_PixelStructure TheColor){
				if(!RowFill(0,TheColor))return false;
				PixelPointer.X=0;
				for(PixelPointer.Y=1;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y-1,PixelsPerLine),PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),PixelsPerLine);
				}
				return true;
			}
			bool Frame_st::Clear(){
				if(!Fill(BackgroundColor))return false;
				PixelPointer.X=0;
				PixelPointer.Y=0;
				PixelPointer.Z=0;
				if(!BorderDraw())return false;
				return true;
			}
			bool Frame_st::RowClear(int64_t RowIndex){
				if(!RowFill(RowIndex,BackgroundColor))return false;
				if(!BorderDraw())return false;
				return true;
			}
			bool Frame_st::ColumnClear(int64_t ColumnIndex){
				if(!ColumnFill(ColumnIndex,BackgroundColor))return false;
				if(!BorderDraw())return false;
				return true;
			}
			bool Frame_st::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor){
				if(Location.X > PixelsPerLine||Location.Y > PixelsBufferHeight)return false;
				if(Location.X < 0||Location.Y < 0)return false;
				PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=TheColor;
				return true;
			}
			bool Frame_st::PutPixel(Sauce::Point64_st Location){
				if(Location.X > PixelsPerLine||Location.Y > PixelsBufferHeight)return false;
				if(Location.X < 0||Location.Y < 0)return false;
				PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=ForegroundColor;
				return true;
			}
			bool Frame_st::PullPixel(Sauce::Point64_st Location,GOP_PixelStructure& ThatColor){
				if(Location.X > PixelsPerLine||Location.Y > PixelsBufferHeight)return false;
				if(Location.X < 0||Location.Y < 0)return false;
				ThatColor=PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)];
				return true;
			}
			bool Frame_st::DrawTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st OtherOffset){
				OtherOffset.X+=Offset.X;
				OtherOffset.Y+=Offset.Y;
				OtherOffset.Z+=Offset.Z;
				if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(OtherOffset.X*OtherOffset.Y))return false;
				for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
						if(PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)].Alpha == 0x00)continue;
						OtherPixelBuffer[Sauce::Math::index(PixelPointer.X+OtherOffset.X,PixelPointer.Y+OtherOffset.Y,OtherPixelsPerLine)]=Blend(PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)],OtherPixelBuffer[Sauce::Math::index(PixelPointer.X+OtherOffset.X,PixelPointer.Y+OtherOffset.Y,OtherPixelsPerLine)]);
					}
				}
				return true;
			}
			bool Frame_st::DrawTo(Frame_st& Other){
				return CopyTo(Other.PixelBuffer,Other.PixelBufferTotalSize,Other.PixelsPerLine,Other.Offset);
			}
			bool Frame_st::DrawFrom(Frame_st& Other){
				return Other.DrawTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,Offset);
			}
			bool Frame_st::CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st OtherOffset){
				OtherOffset.X+=Offset.X;
				OtherOffset.Y+=Offset.Y;
				OtherOffset.Z+=Offset.Z;
				if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(OtherOffset.X*OtherOffset.Y))return false;
				PixelPointer.X=0;
				for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),OtherPixelBuffer+Sauce::Math::index(PixelPointer.X+OtherOffset.X,PixelPointer.Y+OtherOffset.Y,OtherPixelsPerLine),PixelsPerLine);
					// changed to memcpy, it's a wee bit janky around the edges but eh at least it's faster right :)
				}
				return true;
			}
			bool Frame_st::CopyTo(Frame_st& Other){
				return CopyTo(Other.PixelBuffer,Other.PixelBufferTotalSize,Other.PixelsPerLine,Other.Offset);
			}
			bool Frame_st::CopyFrom(Frame_st& Other){
				return Other.CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,Offset);
			}
			bool Frame_st::Resize(Sauce::Point64_st nSize){
				Frame_st tmp(nSize.X*nSize.Y,nSize.X);
				if(!tmp.SetColor(ForegroundColor,BackgroundColor))return false;
				for(tmp.PixelPointer.X=0;tmp.PixelPointer.X<tmp.PixelsPerLine;tmp.PixelPointer.X++){
					for(tmp.PixelPointer.Y=0;tmp.PixelPointer.Y<tmp.PixelsBufferHeight;tmp.PixelPointer.Y++){
						long double intermediateX=((long double)tmp.PixelPointer.X)/((long double)tmp.PixelsPerLine);
						long double intermediateY=((long double)tmp.PixelPointer.Y)/((long double)tmp.PixelsBufferHeight);
						int64_t sourceX=intermediateX*PixelsPerLine;
						int64_t sourceY=intermediateY*PixelsBufferHeight;
						GOP_PixelStructure Pixel;
						if(!PullPixel({sourceX,sourceY,0},Pixel))return false;
						if(!tmp.PutPixel({tmp.PixelPointer.X,tmp.PixelPointer.Y,0},Pixel))return false;
					}
				}
				delete PixelBuffer;
				PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
				PixelBufferTotalSize=tmp.PixelBufferTotalSize;
				PixelsPerLine=tmp.PixelsPerLine;
				PixelsBufferHeight=tmp.PixelsBufferHeight;
				std::memcpy(tmp.PixelBuffer,PixelBuffer,PixelBufferTotalSize);
				SetPointer({0,0,0});
				if(!BorderDraw())return false;
				return true;
			}
			bool Frame_st::BorderDraw(){
				if(!RowFill(0,BorderColor))return false;
				if(!RowFill(PixelsBufferHeight-1,BorderColor))return false;
				if(!ColumnFill(0,BorderColor))return false;
				if(!ColumnFill(PixelsPerLine-1,BorderColor))return false;
				return true;
			}
			bool Frame_st::BorderSet(GOP_PixelStructure TheColor){
				BorderColor=TheColor;
				return BorderDraw();
			}
		};
	};
};