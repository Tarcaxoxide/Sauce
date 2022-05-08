#pragma once

#include<Sauce/Common.h>
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
                void RemoveMouse(size_t X,size_t Y); // internal commands for managing the mouse pointer. not to be confused with the cursor which is for text.
                void PlaceMouse(size_t X,size_t Y);  // internal commands for managing the mouse pointer. not to be confused with the cursor which is for text.
            public:
            bool DisableMouse=false;
            Terminal(DataStructure* DFBL);
            void PutChar(const char chr);// places chr.
            void PutCharAt(const char chr,size_t X,size_t Y);// places at X*Y;
            void PutString(const char* str);// places an entire "string".
            void NewLine(); // like ... '\n' except we don't include the functionality of '\r' as well.
            bool ForwardChar(); // Go Right 1 character, return true if successful.
            bool BackwardChar(); // Go Left 1 character, return true if successful.
            bool UpwardChar(); // Go up 1 character, return true if successful.
            bool DownwardChar(); // Go down 1 character, return true if successful.
            void TopChar(); // Go to the first position in the current column.
            void BottomChar(); // Go to the last position in the current column.
            void FrontChar(); // Go to the first position in the current row.
            void BackChar(); // Go to the last position in the current row.
            void ReturnCaret(); // like... '\r'.
            void BackSpace(); // like... '\b'.
            void Clear(); // Clears the terminal.
            void Fill(const char chr); // Fills the entire screen with chr.
            void FillColumn(const char chr,size_t Column);//Fills an entire column with chr.
            void FillRow(const char chr,size_t Row); //Fills an entire row with chr.
            void SetColor(GOP_PixelStructure Fcolor,GOP_PixelStructure Bcolor);
            void SetColor(GOP_PixelStructure Fcolor);
            uint64_t MaxY(uint64_t Margin=0); // returns maximum position in column.
            uint64_t MaxX(uint64_t Margin=0); // returns maximum position in row.
            uint8_t CharX(); // returns character width.
            uint8_t CharY(); // returns character height.
            void Mouse(Point64_t* NewMousePosition);
            void SetCursor(size_t X,size_t Y);
            void PutPoint(Sauce::uPoint8_t aPoint); // these are for printing out points as text.
            void PutPoint(Sauce::uPoint16_t aPoint); // these might be removed later in favor of
            void PutPoint(Sauce::uPoint32_t aPoint); // just converting the points to a string,
            void PutPoint(Sauce::uPoint64_t aPoint); // but well see.
            void PutPoint(Sauce::Point8_t aPoint);
            void PutPoint(Sauce::Point16_t aPoint);
            void PutPoint(Sauce::Point32_t aPoint);
            void PutPoint(Sauce::Point64_t aPoint);
        };
        extern Terminal* GlobalTerminal;
        extern const GOP_PixelStructure GOP_RED;   //Some standard predefined colors.
        extern const GOP_PixelStructure GOP_GREEN; //Some standard predefined colors.
        extern const GOP_PixelStructure GOP_BLUE;  //Some standard predefined colors.
        extern const GOP_PixelStructure GOP_YELLOW;//Some standard predefined colors.
        extern const GOP_PixelStructure GOP_PURPLE;//Some standard predefined colors.
        extern const GOP_PixelStructure GOP_CYAN;  //Some standard predefined colors.
        extern const GOP_PixelStructure GOP_WHITE; //Some standard predefined colors.
        extern const GOP_PixelStructure GOP_BLACK; //Some standard predefined colors.
    };
};