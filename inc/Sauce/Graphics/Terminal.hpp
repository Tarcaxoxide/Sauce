#pragma once

#include<Sauce/Common.h>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace Graphics{
        class Terminal_cl{
            protected:
                GOP_PixelStructure* PixelBuffer=nullptr;
                size_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
                static GOP_PixelStructure ForegroundColor,BackgroundColor;
                Point64_t TextCursor{0,0,0};
                Point64_t MyOffset{0,0,0};
            public:
                Terminal_cl(size_t PixelBufferTotalSize,size_t PixelsPerLine,Point64_t Offset={0,0,0});
                bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
                bool SetColor(GOP_PixelStructure ForegroundColor);
                bool RowFill(size_t RowIndex,GOP_PixelStructure TheColor=ForegroundColor);
                bool ColumnFill(size_t ColumnIndex,GOP_PixelStructure TheColor=ForegroundColor);
                bool Fill(GOP_PixelStructure TheColor=ForegroundColor);
                bool RowClear(size_t RowIndex);
                bool ColumnClear(size_t ColumnIndex);
                bool Clear();
                bool SetCursor(int64_t X,int64_t Y,int64_t Z=0);
                bool CopyTo(GOP_PixelStructure* OtherPixelBuffer,size_t OtherPixelBufferTotalSize,size_t OtherPixelsPerLine,Point64_t Offset={0,0,0});
                bool CopyFrom(Terminal_cl* OtherTerminal);
                uPoint64_t Size();
        };
        extern Terminal_cl* GlobalTerminal;
    };
};



/*
(just ignore this XD , i keep forgetting this.)
    Rows are horizontal.
    Columns are vertical.
*/

