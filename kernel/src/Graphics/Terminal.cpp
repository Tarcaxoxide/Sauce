#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Utility/Manipulations.hpp>
namespace Sauce{
    namespace Graphics{
        //GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0xFF,0xFF,0xFF};
        //GOP_PixelStructure Terminal_cl::BackgroundColor{0x00,0x00,0x00,0xFF};
        
        Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Terminal_cl",_NAMESPACE_);
            
            if(PixelBuffer == nullptr){this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];}else{this->PixelBuffer=PixelBuffer;}
            
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
            MyOffset=Offset;
            SetID((char*)"GenericTerminal");
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::SetColor",_NAMESPACE_);
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            return true;
        }
        void Terminal_cl::ReverseColor(){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::ReverseColor",_NAMESPACE_);
            GOP_PixelStructure tmp=ForegroundColor;
            ForegroundColor=BackgroundColor;
            BackgroundColor=tmp;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::SetColor",_NAMESPACE_);
            this->ForegroundColor=ForegroundColor;
            return true;
        }
        bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::RowFill",_NAMESPACE_);
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
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::PutPixel",_NAMESPACE_);
            PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=TheColor;
            return true;
        }
        bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::ColumnFill",_NAMESPACE_);
            if(ColumnIndex > PixelsPerLine){
                return false;
            }
            PixelPointer.Y=ColumnIndex;
            for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Fill",_NAMESPACE_);
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
            }
            return true;
        }
        bool Terminal_cl::RowClear(size_t RowIndex){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::RowClear",_NAMESPACE_);
            bool Ret=RowFill(RowIndex,BackgroundColor);
            return Ret;
        }
        bool Terminal_cl::ColumnClear(size_t ColumnIndex){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::ColumnClear",_NAMESPACE_);
            bool Ret = ColumnFill(ColumnIndex,BackgroundColor);
            return Ret;
        }
        bool Terminal_cl::Clear(){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Clear",_NAMESPACE_);
            bool Ret = Fill(BackgroundColor);
            PixelPointer.X=0;
            PixelPointer.Y=0;
            PixelPointer.Z=0;
            return Ret;
        }
        bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::SetCursor",_NAMESPACE_);
            PixelPointer={X,Y,Z};
            return true;
        }
        bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::CopyTo",_NAMESPACE_);
            Offset.X+=MyOffset.X;
            Offset.Y+=MyOffset.Y;
            Offset.Z+=MyOffset.Z;
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y)){
                return false;
            }
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    if(ID != (char*)"Mouse" && Sauce::Global::Mouse->Is_Mouse_Over(PixelPointer))continue;
                    OtherPixelBuffer[Sauce::Math::index(PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine)]=PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)];
                }
            }
            return true;
        }
        bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::CopyFrom",_NAMESPACE_);
            bool Ret = OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
            return Ret;
        }
        bool Terminal_cl::SwapTo(GOP_PixelStructure* OtherPixelBuffer){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::SwapTo",_NAMESPACE_);
            Sauce::Utility::swap_address((void**)&PixelBuffer,(void**)&OtherPixelBuffer);
            return true;
        }
        bool Terminal_cl::SwapFrom(Terminal_cl* OtherTerminal){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::SwapFrom",_NAMESPACE_);
            bool Ret = OtherTerminal->SwapTo(PixelBuffer);
            return Ret;
        }
		Sauce::uPoint64_st Terminal_cl::Size(){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Size",_NAMESPACE_);
            return {PixelsPerLine,PixelsBufferHeight,0};
        }
        bool Terminal_cl::Move(Sauce::Point64_st Offset){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Move",_NAMESPACE_);
            MyOffset=Offset;
            return true;
        }
        void Terminal_cl::SetID(Sauce::string nID){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::setID",_NAMESPACE_);
            size_t i=0;
            ID=nID;
        }
        bool Terminal_cl::Is_Mouse_Over(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Is_Mouse_Over",_NAMESPACE_);
            return (Location.Y > MyOffset.Y && Location.Y < MyOffset.Y+PixelsBufferHeight\
                    && Location.X > MyOffset.X && Location.X < MyOffset.X+PixelsPerLine);
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Left_Down",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Click Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Right_Down",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Click Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Center_Down",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Click Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Left_Up",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Release Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Right_Up",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Release Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Center_Up",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Release Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Left_Drag",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Drag Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Right_Drag",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Drag Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Mouse_Center_Drag",_NAMESPACE_);
            if(Is_Mouse_Over(Location)){
                Debugger.Print("Drag Detected");
            }
        }
        void Terminal_cl::Notify_Of_Keyboard_Press(Sauce::Keyboard_st KeyData){
            Sauce::IO::Debug::Debugger_st Debugger("Terminal_cl::Notify_Of_Keyboard_Press",_NAMESPACE_);
        }
    };
};
