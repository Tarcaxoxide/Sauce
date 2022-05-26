#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
namespace Sauce{
    namespace Graphics{
        GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0x00,0x00,0xFF};
        GOP_PixelStructure Terminal_cl::BackgroundColor{0x10,0x10,0x10,0xFF};
        
        Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Point64_t Offset){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Terminal_cl]\n\0");
            this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
            MyOffset=Offset;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetColor]\n\0");
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            return true;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetColor]\n\0");
            this->ForegroundColor=ForegroundColor;
            return true;
        }
        bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::RowFill]\n\0");
            if(RowIndex > PixelsPerLine)return false;
            PixelPointer.X=RowIndex;
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                PixelBuffer[Sauce::ind(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::ColumnFill]\n\0");
            if(ColumnIndex > PixelsPerLine)return false;
            PixelPointer.Y=ColumnIndex;
            for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                PixelBuffer[Sauce::ind(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Fill]\n\0");
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    PixelBuffer[Sauce::ind(PixelPointer.X,PixelPointer.Y,PixelsPerLine)]=TheColor;
                }
            }
            return true;
        }
        bool Terminal_cl::RowClear(size_t RowIndex){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::RowClear]\n\0");
            return RowFill(RowIndex,BackgroundColor);
        }
        bool Terminal_cl::ColumnClear(size_t ColumnIndex){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::ColumnClear]\n\0");
            return ColumnFill(ColumnIndex,BackgroundColor);
        }
        bool Terminal_cl::Clear(){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Clear]\n\0");
            return Fill(BackgroundColor);
        }
        bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetCursor]\n\0");
            PixelPointer={X,Y,Z};
            return true;
        }
        bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Point64_t Offset){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::CopyTo]\n\0");
            Offset.X+=MyOffset.X;
            Offset.Y+=MyOffset.Y;
            Offset.Z+=MyOffset.Z;
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y))return false;
            for(PixelPointer.Y=0;PixelPointer.Y<PixelsBufferHeight;PixelPointer.Y++){
                for(PixelPointer.X=0;PixelPointer.X<PixelsPerLine;PixelPointer.X++){
                    OtherPixelBuffer[Sauce::ind(PixelPointer.X+Offset.X,PixelPointer.Y+Offset.Y,OtherPixelsPerLine)]=PixelBuffer[Sauce::ind(PixelPointer.X,PixelPointer.Y,PixelsPerLine)];
                }
            }
            return true;
        }
        bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::CopyFrom]\n\0");
            return OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
        }
        uPoint64_t Terminal_cl::Size(){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Size]\n\0");
            return {PixelsPerLine,PixelsBufferHeight,0};
        }
        bool Terminal_cl::Move(Point64_t Offset){
            if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Move]\n\0");
            MyOffset=Offset;
            return true;
        }
    };
};