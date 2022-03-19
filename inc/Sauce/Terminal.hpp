#pragma once

#include<Sauce/Common.h>
#include<Sauce/Memory/Memory.hpp>

namespace Sauce{
    class Terminal{
        size_t Cursor_X;
        size_t Cursor_Y;
        DataStructure* DFBL;
        GOP_PixelStructure Fcolor;
        GOP_PixelStructure Bcolor;
        public:
        Terminal(DataStructure* DFBL);
        void PutChar(char chr);
        void PutCharAt(char chr,size_t X,size_t Y);
        void PutString(char* str);
        void NewLine();
        void ReturnCaret();
        void BackSpace();
        void Clear();
        void Fill(char chr);
        void FillColumn(char chr,size_t Column);
        void FillRow(char chr,size_t Row);
        void SetColor(GOP_PixelStructure Fcolor,GOP_PixelStructure Bcolor);
        void SetColor(GOP_PixelStructure Fcolor);
        void SetCursor(size_t X,size_t Y);
    };
};