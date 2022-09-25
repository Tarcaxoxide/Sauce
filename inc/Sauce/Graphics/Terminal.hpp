#pragma once

#include<Sauce/Common.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Graphics{
        class Terminal_cl{
            protected:
                GOP_PixelStructure* PixelBuffer=nullptr;
                size_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
                GOP_PixelStructure ForegroundColor{0xFF,0xFF,0xFF,0xFF},BackgroundColor{0x00,0x00,0x00,0x00};
				Sauce::Point64_st PixelPointer{0,0,0};
				Sauce::Point64_st MyOffset{0,0,0};
            public:
                char ID[64]{'\0'};
                Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Sauce::Point64_st Offset={0,0,0},GOP_PixelStructure* PixelBuffer=nullptr);
                bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
                bool SetColor(GOP_PixelStructure ForegroundColor);
                void ReverseColor();
                bool RowFill(size_t RowIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool Fill(GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool RowClear(size_t RowIndex);
                bool ColumnClear(size_t ColumnIndex);
                bool Clear();
                bool SetCursor(int64_t X,int64_t Y,int64_t Z=0);
                bool CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Point64_st Offset={0,0,0});
                bool CopyFrom(Terminal_cl* OtherTerminal);
                bool SwapTo(GOP_PixelStructure* OtherPixelBuffer);
                bool SwapFrom(Terminal_cl* OtherTerminal);
				Sauce::uPoint64_st Size();
                bool Move(Sauce::Point64_st Offset);
                void setID(const char* nID);
                //Mouse related functions
                bool Is_Mouse_Over(Sauce::Point64_st Location);
				void Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location);
                void Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location);
                void Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location);
				void Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location);
				void Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location);
				void Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location);
                void Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
				void Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
				void Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
                void Notify_Of_Keyboard_Press(Sauce::Keyboard_st KeyData);
        };
    };
};



/*
(just ignore this XD , i keep forgetting this.)
    Rows are horizontal.
    Columns are vertical.
*/

