#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Utility/Manipulations.hpp>
#include<_std/swap.hpp>
#include<_std/memcpy.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace Graphics{
        namespace Basic{
            Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer){
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
            bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowFill",_NAMESPACE_,_ALLOW_PRINT_);
                if(RowIndex > PixelsPerLine){
                    return false;
                }
                PixelPointer.X=RowIndex;
                for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                    PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
                return true;
            }
            bool Terminal_cl::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::PutPixel",_NAMESPACE_,_ALLOW_PRINT_);
                PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=TheColor;
                return true;
            }
            GOP_PixelStructure Terminal_cl::Blend(GOP_PixelStructure Front,GOP_PixelStructure Back,uint8_t opacity){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Blend",_NAMESPACE_,_ALLOW_PRINT_);
            	double Alpha;
                if(opacity > 9){
                    Alpha=Front.Alpha/2.55;
                }else{
                    Alpha=opacity*11.1111111111111111;
                }
            	uint8_t Rnew = (Front.Red * Alpha) + (Back.Red * (1.0 - Alpha));
            	uint8_t Gnew = (Front.Green * Alpha) + (Back.Green * (1.0 - Alpha));
            	uint8_t Bnew = (Front.Blue * Alpha) + (Back.Blue * (1.0 - Alpha));
            	return {Bnew,Gnew,Rnew,0xFF};
            }
            bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ColumnFill",_NAMESPACE_,_ALLOW_PRINT_);
                if(ColumnIndex > PixelsPerLine){
                    return false;
                }
                PixelPointer.Y=ColumnIndex;
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
                return true;
            }
            bool Terminal_cl::ShiftUp(size_t Rows){
                PixelPointer.X=0;
                if(Rows > PixelsBufferHeight)return false;
                int64_t Y=PixelsBufferHeight-1;
                for(;Y;Y--){
                    if(Y-Rows < 0)break;//don't write off the screen XD.
                    _std::memcpy(PixelBuffer+Sauce::Math::index(0,Y,PixelsPerLine),PixelBuffer+Sauce::Math::index(0,Y-Rows,PixelsPerLine),PixelsPerLine);
                    RowFill(Y,BackgroundColor);
                }
                for(;Y;Y--){
                    RowFill(Y,BackgroundColor);
                }
                return true;
            }
            bool Terminal_cl::ShiftDown(size_t Rows){return false;/*Unimplemented*/}
            bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Fill",_NAMESPACE_,_ALLOW_PRINT_);
                RowFill(0,TheColor);
                PixelPointer.X=0;
                for(PixelPointer.Y=1;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                    _std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y-1,PixelsPerLine),PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),PixelsPerLine);
                }
                return true;
            }
            bool Terminal_cl::RowClear(size_t RowIndex){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowClear",_NAMESPACE_,_ALLOW_PRINT_);
                bool Ret=RowFill(RowIndex,BackgroundColor);
                return Ret;
            }
            bool Terminal_cl::ColumnClear(size_t ColumnIndex){
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
            bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyTo",_NAMESPACE_,_ALLOW_PRINT_);
                Offset.X+=MyOffset.X;
                Offset.Y+=MyOffset.Y;
                Offset.Z+=MyOffset.Z;
                if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y)){
                    return false;
                }
                PixelPointer.X=0;
                for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                    _std::memcpy(PixelBuffer+Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine),OtherPixelBuffer+Sauce::Math::index(PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine),PixelsPerLine);
                    // changed to memcpy, it's a wee bit janky around the edges but eh at least it's faster right :)
                }
                return true;
            }
            bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyFrom",_NAMESPACE_,_ALLOW_PRINT_);
                return OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
            }
            bool Terminal_cl::Swap(Terminal_cl* Other){
                if(Other->MyOffset != MyOffset)return false;
                _std::swap(Other->PixelBuffer,PixelBuffer);
                return true;
            }
		    Sauce::uPoint64_st Terminal_cl::Size(){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Size",_NAMESPACE_,_ALLOW_PRINT_);
                return {PixelsPerLine,PixelsBufferHeight,0};
            }
            bool Terminal_cl::Move(Sauce::Point64_st Offset){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Move",_NAMESPACE_,_ALLOW_PRINT_);
                MyOffset=Offset;
                return true;
            }
            void Terminal_cl::SetID(_std::string nID){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::setID",_NAMESPACE_,_ALLOW_PRINT_);
                size_t i=0;
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
            void Terminal_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Left_Down",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Click Detected");
                }
            }
            void Terminal_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Right_Down",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Click Detected");
                }
            }
            void Terminal_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Center_Down",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Click Detected");
                }
            }
		    void Terminal_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Left_Up",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Release Detected");
                }
            }
		    void Terminal_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Right_Up",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Release Detected");
                }
            }
		    void Terminal_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Center_Up",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Release Detected");
                }
            }
            void Terminal_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Left_Drag",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Drag Detected");
                }
            }
		    void Terminal_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Right_Drag",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Drag Detected");
                }
            }
		    void Terminal_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Mouse_Center_Drag",_NAMESPACE_,_ALLOW_PRINT_);
                if(Sauce::Global::Mouse->Is_Over(Location)){
                    Debugger.Print("Drag Detected");
                }
            }
            void Terminal_cl::Notify_Of_Keyboard_Press(Sauce::Keyboard_st KeyData){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Notify_Of_Keyboard_Press",_NAMESPACE_,_ALLOW_PRINT_);
            }
        };
    };
};
