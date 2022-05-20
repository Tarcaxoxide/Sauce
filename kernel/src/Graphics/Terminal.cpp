#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/Memory.hpp>
namespace Sauce{
    namespace Graphics{
        GOP_PixelStructure Terminal_cl::ForegroundColor{0xFF,0x00,0x00,0xFF};
        GOP_PixelStructure Terminal_cl::BackgroundColor{0x10,0x10,0x10,0xFF};
        Terminal_cl* GlobalTerminal;

        Terminal_cl::Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Point64_t Offset){
            this->PixelBuffer=new GOP_PixelStructure[PixelBufferTotalSize];
            this->PixelBufferTotalSize=PixelBufferTotalSize;
            this->PixelsPerLine=PixelsPerLine;
            PixelsBufferHeight=(PixelBufferTotalSize/PixelsPerLine);
            MyOffset=Offset;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
            this->ForegroundColor=ForegroundColor;
            this->BackgroundColor=BackgroundColor;
            return true;
        }
        bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
            this->ForegroundColor=ForegroundColor;
            return true;
        }
        bool Terminal_cl::RowFill(size_t RowIndex,GOP_PixelStructure TheColor){
            if(RowIndex > PixelsPerLine)return false;
            TextCursor.X=RowIndex;
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor){
            if(ColumnIndex > PixelsPerLine)return false;
            TextCursor.Y=ColumnIndex;
            for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
            }
            return true;
        }
        bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                    PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)]=TheColor;
                }
            }
            return true;
        }
        bool Terminal_cl::RowClear(size_t RowIndex){
            return RowFill(RowIndex,BackgroundColor);
        }
        bool Terminal_cl::ColumnClear(size_t ColumnIndex){
            return ColumnFill(ColumnIndex,BackgroundColor);
        }
        bool Terminal_cl::Clear(){
            return Fill(BackgroundColor);
        }
        bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
            Terminal_cl::TextCursor={X,Y,Z};
            return true;
        }
        bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Point64_t Offset){
            Offset.X+=MyOffset.X;
            Offset.Y+=MyOffset.Y;
            Offset.Z+=MyOffset.Z;
            if(OtherPixelBufferTotalSize < PixelBufferTotalSize+(Offset.X*Offset.Y))return false;
            for(TextCursor.Y=0;TextCursor.Y<PixelsBufferHeight;TextCursor.Y++){
                for(TextCursor.X=0;TextCursor.X<PixelsPerLine;TextCursor.X++){
                    OtherPixelBuffer[Sauce::ind(TextCursor.X+Offset.X,TextCursor.Y+Offset.Y,OtherPixelsPerLine)]=PixelBuffer[Sauce::ind(TextCursor.X,TextCursor.Y,PixelsPerLine)];
                }
            }
            return true;
        }
        bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
            return OtherTerminal->CopyTo(PixelBuffer,PixelBufferTotalSize,PixelsPerLine,MyOffset);
        }
        uPoint64_t Terminal_cl::Size(){
            return {PixelsPerLine,PixelsBufferHeight,0};
        }
    };
};