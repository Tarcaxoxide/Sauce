#pragma once

#include<Sauce/Common.h>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace IO{
        class Terminal{
            //size_t Cursor_X;
            //size_t Cursor_Y;
            Sauce::Point64_t Cursor;
            DataStructure* DFBL;
            GOP_PixelStructure Fcolor;
            GOP_PixelStructure Bcolor;
            GOP_PixelStructure DoubleBuffer[200];
            Point64_t OldMousePosition {0,0,0};
            private:
                void RemoveMouse(size_t X,size_t Y);
                void PlaceMouse(size_t X,size_t Y);
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
            uint64_t MaxY(uint64_t Margin=0);
            uint64_t MaxX(uint64_t Margin=0);
            uint8_t CharX();
            uint8_t CharY();
            void Mouse(Point64_t NewMousePosition);
            void SetCursor(size_t X,size_t Y);
        };
        extern Terminal* GlobalTerminal;
        static const GOP_PixelStructure GOP_RED={0x00,0x00,0xff,0xff};
        static const GOP_PixelStructure GOP_GREEN={0x00,0xff,0x00,0xff};
        static const GOP_PixelStructure GOP_BLUE={0xff,0x00,0x00,0xff};
        static const GOP_PixelStructure GOP_YELLOW={0x00,0xff,0xff,0xff};
        static const GOP_PixelStructure GOP_PURPLE={0xff,0x00,0xff,0xff};
        static const GOP_PixelStructure GOP_CYAN={0xff,0xff,0x00,0xff};
        static const GOP_PixelStructure GOP_WHITE={0xff,0xff,0xff,0xff};
        static const GOP_PixelStructure GOP_BLACK={0x00,0x00,0x00,0xff};
    };
};