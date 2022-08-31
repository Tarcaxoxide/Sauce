#pragma once

#include<Sauce/Common.h>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Graphics{
        class Terminal_cl{
            protected:
                GOP_PixelStructure* PixelBuffer=nullptr;
                size_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
                /*static*/ GOP_PixelStructure ForegroundColor{0xFF,0xFF,0xFF,0xFF},BackgroundColor{0x00,0x00,0x00,0x00};
				Sauce::Math::Point64_t PixelPointer{0,0,0};
				Sauce::Math::Point64_t MyOffset{0,0,0};
                char* name;
            public:
                Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,const char* name,Sauce::Math::Point64_t Offset={0,0,0});
                bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
                bool SetColor(GOP_PixelStructure ForegroundColor);
                void ReverseColor();
                bool RowFill(size_t RowIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool Fill(GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
                bool RowClear(size_t RowIndex);
                bool ColumnClear(size_t ColumnIndex);
                bool Clear();
                bool SetCursor(int64_t X,int64_t Y,int64_t Z=0);
                bool CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Sauce::Math::Point64_t Offset={0,0,0});
                bool CopyFrom(Terminal_cl* OtherTerminal);
				Sauce::Math::uPoint64_t Size();
                bool Move(Sauce::Math::Point64_t Offset);
                //Mouse related functions
                bool Is_Mouse_Over(Sauce::Math::Point64_t Location);
				void Notify_Of_Mouse_Left_Down(Sauce::Math::Point64_t Location);
                void Notify_Of_Mouse_Right_Down(Sauce::Math::Point64_t Location);
                void Notify_Of_Mouse_Center_Down(Sauce::Math::Point64_t Location);
				void Notify_Of_Mouse_Left_Up(Sauce::Math::Point64_t Location);
				void Notify_Of_Mouse_Right_Up(Sauce::Math::Point64_t Location);
				void Notify_Of_Mouse_Center_Up(Sauce::Math::Point64_t Location);
                void Notify_Of_Mouse_Left_Drag(Sauce::Math::Point64_t Location,Sauce::Math::Point64_t OldLocation);
				void Notify_Of_Mouse_Right_Drag(Sauce::Math::Point64_t Location,Sauce::Math::Point64_t OldLocation);
				void Notify_Of_Mouse_Center_Drag(Sauce::Math::Point64_t Location,Sauce::Math::Point64_t OldLocation);
		};
    };
};



/*
(just ignore this XD , i keep forgetting this.)
    Rows are horizontal.
    Columns are vertical.
*/

