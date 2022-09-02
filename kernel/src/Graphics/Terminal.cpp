#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global/Global.hpp>
namespace Sauce{
    namespace Graphics{
        //GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0xFF,0xFF,0xFF};
        //GOP_PixelStructure Terminal_cl::BackgroundColor{0x00,0x00,0x00,0xFF};
        
        Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::Terminal_cl",Sauce::IO::Debug::TERMINAL);
            this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
            MyOffset=Offset;
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::TERMINAL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\"this\")\n\0");
            Sauce::IO::Debug::Print_Spammy_Return("<this>",Sauce::IO::Debug::TERMINAL);
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::SetColor",Sauce::IO::Debug::TERMINAL);
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        void Terminal_cl::ReverseColor(){
            GOP_PixelStructure tmp=ForegroundColor;
            ForegroundColor=BackgroundColor;
            BackgroundColor=tmp;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::SetColor",Sauce::IO::Debug::TERMINAL);
            this->ForegroundColor=ForegroundColor;
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::RowFill",Sauce::IO::Debug::TERMINAL);
            if(RowIndex > PixelsPerLine){
                Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
                return false;
            }
            PixelPointer.X=RowIndex;
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor){
            PixelBuffer[Sauce::Math::index(Location.X,Location.Y,PixelsPerLine)]=TheColor;
            return true;
        }
        bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::ColumnFill",Sauce::IO::Debug::TERMINAL);
            if(ColumnIndex > PixelsPerLine){
                Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
                return false;
            }
            PixelPointer.Y=ColumnIndex;
            for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::Fill",Sauce::IO::Debug::TERMINAL);
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
            }
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::RowClear(size_t RowIndex){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::RowClear",Sauce::IO::Debug::TERMINAL);
            bool Ret=RowFill(RowIndex,BackgroundColor);
            Ret? Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL) : Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
            return Ret;
        }
        bool Terminal_cl::ColumnClear(size_t ColumnIndex){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::ColumnClear",Sauce::IO::Debug::TERMINAL);
            bool Ret = ColumnFill(ColumnIndex,BackgroundColor);
            Ret? Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL) : Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
            return Ret;
        }
        bool Terminal_cl::Clear(){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::Clear",Sauce::IO::Debug::TERMINAL);
            bool Ret = Fill(BackgroundColor);
            PixelPointer.X=0;
            PixelPointer.Y=0;
            PixelPointer.Z=0;
            Ret? Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL) : Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
            return Ret;
        }
        bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::SetCursor",Sauce::IO::Debug::TERMINAL);
            PixelPointer={X,Y,Z};
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::CopyTo",Sauce::IO::Debug::TERMINAL);
            Offset.X+=MyOffset.X;
            Offset.Y+=MyOffset.Y;
            Offset.Z+=MyOffset.Z;
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y)){
                Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
                return false;
            }
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    OtherPixelBuffer[Sauce::Math::index(PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine)]=PixelBuffer[Sauce::Math::index(PixelPointer.X,PixelPointer.Y,PixelsPerLine)];
                }
            }
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::CopyFrom",Sauce::IO::Debug::TERMINAL);
            bool Ret = OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
            Ret? Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL) : Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::TERMINAL);
            return Ret;
        }
		Sauce::uPoint64_st Terminal_cl::Size(){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::Size",Sauce::IO::Debug::TERMINAL);
            Sauce::IO::Debug::Print_Spammy_Return("Width:",Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Utility::ToString(PixelsPerLine),Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Spammy_Return(",Height:",Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Utility::ToString(PixelsBufferHeight),Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            return {PixelsPerLine,PixelsBufferHeight,0};
        }
        bool Terminal_cl::Move(Sauce::Point64_st Offset){
            Sauce::IO::Debug::Print_Spammy_Call("Terminal_cl::Move",Sauce::IO::Debug::TERMINAL);
            MyOffset=Offset;
            Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::TERMINAL);
            return true;
        }
        void Terminal_cl::setID(const char* nID){
            size_t i=0;
            while( nID[i++] != '\0' && i<63 ){
                ID[i]=nID[i];
            }
        }

        bool Terminal_cl::Is_Mouse_Over(Sauce::Point64_st Location){
            return (Location.Y > MyOffset.Y && Location.Y < MyOffset.Y+PixelsBufferHeight\
                    && Location.X > MyOffset.X && Location.X < MyOffset.X+PixelsPerLine);
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Left button down",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Right button down",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Center button down",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Left button up",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Right button up",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Center button up",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
        void Terminal_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("},{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Left button dragged",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("},{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Right button dragged",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
		void Terminal_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
            if(Is_Mouse_Over(Location)){
                Sauce::IO::Debug::Print_Detail(ID,Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Start);
                Sauce::IO::Debug::Print_Detail(",{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(Location.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("},{",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.X),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("x",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail(Sauce::Utility::ToString(OldLocation.Y),Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::Middle);
                Sauce::IO::Debug::Print_Detail("}, Center button dragged",Sauce::IO::Debug::MOUSE && Sauce::IO::Debug::TERMINAL,Sauce::IO::Debug::StartOfPrint::End);
            }
        }
        void Terminal_cl::Notify_Of_Keyboard_Press(Sauce::Keyboard_st KeyData){}
    };
};
