#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/Memory.hpp>
namespace Sauce{
    namespace IO{
        GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0x00,0x00,0xFF};
        GOP_PixelStructure Terminal_cl::BackgroundColor{0x10,0x10,0x10,0xFF};
        Terminal_cl* GlobalTerminal;

        Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Terminal_cl]\n\0");
            this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetColor]\n\0");
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            return true;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetColor]\n\0");
            this->ForegroundColor=ForegroundColor;
            return true;
        }
        bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::RowFill]\n\0");
            if(RowIndex > PixelsBufferHeight)return false;
            TextCursor.X=RowIndex;
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::ColumnFill]\n\0");
            if(ColumnIndex > PixelsPerLine)return false;
            TextCursor.Y=ColumnIndex;
            for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Fill]\n\0");
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                    PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
                }
            }
            return true;
        }
        bool Terminal_cl::RowClear(size_t RowIndex){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::RowClear]\n\0");
            return RowFill(RowIndex,BackgroundColor);
        }
        bool Terminal_cl::ColumnClear(size_t ColumnIndex){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::ColumnClear]\n\0");
            return ColumnFill(ColumnIndex,BackgroundColor);
        }
        bool Terminal_cl::Clear(){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::Clear]\n\0");
            return Fill(BackgroundColor);
        }
        bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::SetCursor]\n\0");
            Terminal_cl::TextCursor={X,Y,Z};
            return true;
        }
        bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,size_t VerticalOffset,size_t HorizontalOffset){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[Terminal_cl::CopyTo]\n\0");
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize)return false;
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                    OtherPixelBuffer[Sauce::ind(TextCursor.X+HorizontalOffset,TextCursor.Y+VerticalOffset,PixelsPerLine)]=PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)];
                }
            }
            return true;
        }
    };
};