#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Utility/Manipulations.hpp>
namespace Sauce{
    namespace Graphics{
        //GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0xFF,0xFF,0xFF};
        //GOP_PixelStructure Terminal_cl::BackgroundColor{0x00,0x00,0x00,0xFF};
        
        Terminal_cl::Terminal_cl(Sauce::IO::Debug::Debugger_st* pDebugger,size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Terminal_cl");
            
            if(PixelBuffer == nullptr){this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];}else{this->PixelBuffer=PixelBuffer;}
            
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
            MyOffset=Offset;
        }
        bool Terminal_cl::SetColor(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::SetColor");
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            return true;
        }
        void Terminal_cl::ReverseColor(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::ReverseColor");
            GOP_PixelStructure tmp=ForegroundColor;
            ForegroundColor=BackgroundColor;
            BackgroundColor=tmp;
        }
        bool Terminal_cl::SetColor(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure ForegroundColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::SetColor");
            this->ForegroundColor=ForegroundColor;
            return true;
        }
        bool Terminal_cl::RowFill(Sauce::IO::Debug::Debugger_st* pDebugger,size_t RowIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::RowFill");
            if(RowIndex > PixelsPerLine){
                return false;
            }
            PixelPointer.X=RowIndex;
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                PixelBuffer[Sauce::Math::index(&Debugger,PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::PutPixel(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::PutPixel");
            PixelBuffer[Sauce::Math::index(&Debugger,Location.X,Location.Y,PixelsPerLine)]=TheColor;
            return true;
        }
        bool Terminal_cl::ColumnFill(Sauce::IO::Debug::Debugger_st* pDebugger,size_t ColumnIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::ColumnFill");
            if(ColumnIndex > PixelsPerLine){
                return false;
            }
            PixelPointer.Y=ColumnIndex;
            for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                PixelBuffer[Sauce::Math::index(&Debugger,PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::Fill(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Fill");
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    PixelBuffer[Sauce::Math::index(&Debugger,PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
            }
            return true;
        }
        bool Terminal_cl::RowClear(Sauce::IO::Debug::Debugger_st* pDebugger,size_t RowIndex){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::RowClear");
            bool Ret=RowFill(&Debugger,RowIndex,BackgroundColor);
            return Ret;
        }
        bool Terminal_cl::ColumnClear(Sauce::IO::Debug::Debugger_st* pDebugger,size_t ColumnIndex){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::ColumnClear");
            bool Ret = ColumnFill(&Debugger,ColumnIndex,BackgroundColor);
            return Ret;
        }
        bool Terminal_cl::Clear(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Clear");
            bool Ret = Fill(&Debugger,BackgroundColor);
            PixelPointer.X=0;
            PixelPointer.Y=0;
            PixelPointer.Z=0;
            return Ret;
        }
        bool Terminal_cl::SetCursor(Sauce::IO::Debug::Debugger_st* pDebugger,int64_t X,int64_t Y,int64_t Z){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::SetCursor");
            PixelPointer={X,Y,Z};
            return true;
        }
        bool Terminal_cl::CopyTo(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::CopyTo");
            Offset.X+=MyOffset.X;
            Offset.Y+=MyOffset.Y;
            Offset.Z+=MyOffset.Z;
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y)){
                return false;
            }
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    OtherPixelBuffer[Sauce::Math::index(&Debugger,PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine)]=PixelBuffer[Sauce::Math::index(&Debugger,PixelPointer.X,PixelPointer.Y,PixelsPerLine)];
                }
            }
            return true;
        }
        bool Terminal_cl::CopyFrom(Sauce::IO::Debug::Debugger_st* pDebugger,Terminal_cl* OtherTerminal){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::CopyFrom");
            bool Ret = OtherTerminal->CopyTo(&Debugger,PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
            return Ret;
        }
        bool Terminal_cl::SwapTo(Sauce::IO::Debug::Debugger_st* pDebugger,GOP_PixelStructure* OtherPixelBuffer){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::SwapTo");
            Sauce::Utility::swap_address((void**)&PixelBuffer,(void**)&OtherPixelBuffer);
            return true;
        }
        bool Terminal_cl::SwapFrom(Sauce::IO::Debug::Debugger_st* pDebugger,Terminal_cl* OtherTerminal){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::SwapFrom");
            bool Ret = OtherTerminal->SwapTo(&Debugger,PixelBuffer);
            return Ret;
        }
		Sauce::uPoint64_st Terminal_cl::Size(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Size");
            return {PixelsPerLine,PixelsBufferHeight,0};
        }
        bool Terminal_cl::Move(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Offset){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Move");
            MyOffset=Offset;
            return true;
        }
        void Terminal_cl::setID(Sauce::IO::Debug::Debugger_st* pDebugger,const char* nID){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::setID");
            size_t i=0;
            while( nID[i++] != '\0' && i<63 ){
                ID[i]=nID[i];
            }
        }
        bool Terminal_cl::Is_Mouse_Over(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Is_Mouse_Over");
            return (Location.Y > MyOffset.Y && Location.Y < MyOffset.Y+PixelsBufferHeight\
                    && Location.X > MyOffset.X && Location.X < MyOffset.X+PixelsPerLine);
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Left_Down");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Click Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Right_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Right_Down");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Click Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Center_Down(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Center_Down");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Click Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Left_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Left_Up");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Release Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Right_Up");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Release Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Up(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Center_Up");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Release Detected");
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Left_Drag");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Drag Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Right_Drag");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Drag Detected");
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Drag(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Mouse_Center_Drag");
            if(Is_Mouse_Over(&Debugger,Location)){
                Debugger.Print("Drag Detected");
            }
        }
        void Terminal_cl::Notify_Of_Keyboard_Press(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Keyboard_st KeyData){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Terminal_cl::Notify_Of_Keyboard_Press");
        }
    };
};
