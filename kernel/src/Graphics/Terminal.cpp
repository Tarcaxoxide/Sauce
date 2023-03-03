#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Utility/Manipulations.hpp>
#include<std/swap.hpp>
#include<std/memcpy.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			Terminal_cl::Terminal_cl(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Terminal_cl",_NAMESPACE_,_ALLOW_PRINT_);
				if(PixelBuffer == nullptr){this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];}else{this->PixelBuffer=PixelBuffer;}
				this->PixelBufferTotalSize=PixelBufferTotalSize;
				this->PixelsPerLine=PixelsPerLine;
				PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
				MyOffset=Offset;
				SetID("GenericTerminal");
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetColor",_NAMESPACE_,_ALLOW_PRINT_);
				this->ForegroundColor=ForegroundColor;
				this->BackgroundColor=BackgroundColor;
				return true;
			}
			void Terminal_cl::ReverseColor(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ReverseColor",_NAMESPACE_,_ALLOW_PRINT_);
				GOP_PixelStructure tmp=ForegroundColor;
				ForegroundColor=BackgroundColor;
				BackgroundColor=tmp;
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetColor",_NAMESPACE_,_ALLOW_PRINT_);
				this->ForegroundColor=ForegroundColor;
				return true;
			}
			bool Terminal_cl::RowFill(int64_t RowIndex,GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowFill",_NAMESPACE_,_ALLOW_PRINT_);
				if(RowIndex > PixelsPerLine){
					return false;
				}
				PixelPointer.X=RowIndex;
				for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=Blend(TheColor,BackgroundColor);
				}
				return true;
			}
			bool Terminal_cl::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::PutPixel",_NAMESPACE_,_ALLOW_PRINT_);
				PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=Blend(TheColor,BackgroundColor);
				return true;
			}
			GOP_PixelStructure Terminal_cl::Blend(GOP_PixelStructure Front,GOP_PixelStructure Back){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Blend",_NAMESPACE_,_ALLOW_PRINT_);
				double Alpha = ((double)Front.Alpha)/2.55;
				//if(opacity > 9){
				//	Alpha=Front.Alpha/2.55;
				//}else{
				//	Alpha=opacity*11.1111111111111111;
				//}
				uint8_t Rnew = (Front.Red * Alpha) + (Back.Red * (1.0 - Alpha));
				uint8_t Gnew = (Front.Green * Alpha) + (Back.Green * (1.0 - Alpha));
				uint8_t Bnew = (Front.Blue * Alpha) + (Back.Blue * (1.0 - Alpha));
				return {Bnew,Gnew,Rnew,Back.Alpha};
			}
			bool Terminal_cl::ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ColumnFill",_NAMESPACE_,_ALLOW_PRINT_);
				if(ColumnIndex > PixelsPerLine){
					return false;
				}
				PixelPointer.Y=ColumnIndex;
				for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
					PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=Blend(TheColor,BackgroundColor);
				}
				return true;
			}
			bool Terminal_cl::ShiftUp(int64_t Rows){
				PixelPointer.X=0;
				if(Rows > PixelsBufferHeight)return false;
				int64_t Y=PixelsBufferHeight-1;
				for(;Y;Y--){
					if(Y-Rows < 0)break;//don't write off the screen XD.
					std::memcpy(PixelBuffer+Sauce::Math::index(0,Y,PixelsPerLine),PixelBuffer+Sauce::Math::index(0,Y-Rows,PixelsPerLine),PixelsPerLine);
					RowFill(Y,BackgroundColor);
				}
				for(;Y;Y--){
					RowFill(Y,BackgroundColor);
				}
				return true;
			}
			bool Terminal_cl::ShiftDown(int64_t Rows){return false;/*Unimplemented*/}
			bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Fill",_NAMESPACE_,_ALLOW_PRINT_);
				RowFill(0,TheColor);
				PixelPointer.X=0;
				for(PixelPointer.Y=1;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y-1,PixelsPerLine),PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),PixelsPerLine);
				}
				return true;
			}
			bool Terminal_cl::RowClear(int64_t RowIndex){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowClear",_NAMESPACE_,_ALLOW_PRINT_);
				bool Ret=RowFill(RowIndex,BackgroundColor);
				return Ret;
			}
			bool Terminal_cl::ColumnClear(int64_t ColumnIndex){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ColumnClear",_NAMESPACE_,_ALLOW_PRINT_);
				bool Ret = ColumnFill(ColumnIndex,BackgroundColor);
				return Ret;
			}
			bool Terminal_cl::Clear(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Clear",_NAMESPACE_,_ALLOW_PRINT_);
				bool Ret = Fill(BackgroundColor);
				PixelPointer.X=0;
				PixelPointer.Y=0;
				PixelPointer.Z=0;
				return Ret;
			}
			bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetCursor",_NAMESPACE_,_ALLOW_PRINT_);
				PixelPointer={X,Y,Z};
				return true;
			}
			bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyTo",_NAMESPACE_,_ALLOW_PRINT_);
				Offset.X+=MyOffset.X;
				Offset.Y+=MyOffset.Y;
				Offset.Z+=MyOffset.Z;
				if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y)){
					return false;
				}
				PixelPointer.X=0;
				for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
					std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),OtherPixelBuffer+Sauce::Math::index(PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine),PixelsPerLine);
					// changed to memcpy, it's a wee bit janky around the edges but eh at least it's faster right :)
				}
				return true;
			}
			bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyFrom",_NAMESPACE_,_ALLOW_PRINT_);
				return OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
			}
			Sauce::Point64_st Terminal_cl::Size(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Size",_NAMESPACE_,_ALLOW_PRINT_);
				return {PixelsPerLine,PixelsBufferHeight,0};
			}
			bool Terminal_cl::Move(Sauce::Point64_st Offset){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Move",_NAMESPACE_,_ALLOW_PRINT_);
				MyOffset=Offset;
				return true;
			}
			void Terminal_cl::SetID(std::string nID){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::setID",_NAMESPACE_,_ALLOW_PRINT_);
				int64_t i=0;
				ID=nID;
			}
			bool Terminal_cl::Is_Over(Sauce::Point64_st Location){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Is_Mouse_Over",_NAMESPACE_,_ALLOW_PRINT_);
				bool Vertical=(Location.Y > MyOffset.Y/*below of my top?*/) && (Location.Y < MyOffset.Y+PixelsBufferHeight/*above of my bottom?*/);
				bool Horizontal=(Location.X > MyOffset.X/*right of my left*/) && (Location.X < MyOffset.X+PixelsPerLine/*left of my right*/);
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
		};
	};
};
