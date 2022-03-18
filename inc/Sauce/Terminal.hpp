#pragma once

#include<Sauce/Common.h>

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
        void Fill(char chr);
        void FillRow(size_t Row,char character);
        void FillColumn(size_t column,char character);
        void Clear();
        void ClearRow(size_t Row);
        void ClearColumn(size_t column);
        void SetColor(GOP_PixelStructure Fcolor,GOP_PixelStructure Bcolor);
        void SetColor(GOP_PixelStructure Fcolor);
        void SetCursor(size_t X,size_t Y);
    };
};