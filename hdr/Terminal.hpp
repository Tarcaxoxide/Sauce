#pragma once

#include <stdint.h>
#include <stddef.h>
#include <IO.hpp>

namespace Sauce{
    namespace Terminal{
	    enum {
	        COLOR_BLACK = 0,
	    	COLOR_BLUE = 1,
	    	COLOR_GREEN = 2,
	    	COLOR_CYAN = 3,
	    	COLOR_RED = 4,
	    	COLOR_MAGENTA = 5,
	    	COLOR_BROWN = 6,
	    	COLOR_LIGHT_GRAY = 7,
	    	COLOR_DARK_GRAY = 8,
	    	COLOR_LIGHT_BLUE = 9,
	    	COLOR_LIGHT_GREEN = 10,
	    	COLOR_LIGHT_CYAN = 11,
	    	COLOR_LIGHT_RED = 12,
	    	COLOR_PINK = 13,
	    	COLOR_YELLOW = 14,
	    	COLOR_WHITE = 15
	    };
		struct Char{
	        uint8_t character;
	        uint8_t color;
	    };
		static struct Char* buffer = (struct Char*)0xB8000;
	    void Fill(char character);
		void Clear();
		void FillRow(size_t Row,char character);
		void FillColumn(size_t column,char character);
		void ClearRow(size_t Row);
		void ClearColumn(size_t Column);
	    void Character(char character);
		void SetCharacterAt(size_t X,size_t Y,char character);
		void SetCharacterAt(size_t X,size_t Y,Char character);
		Char GetCharacterAt(size_t X,size_t Y);
	    void String(char* string);
	    void Setcolor(uint8_t foreground,uint8_t background);
		uint8_t Getcolor();
		size_t StringLength(char* string);
		void NewLine();
		void ReturnCaret();
		void SetCursor(bool adjust=false,size_t X=0,size_t Y=0);
		void RelativeSetCursor(bool adjust=false,long int X=0,long int Y=0);
		void SetRealCursor(size_t X,size_t Y);
		void BackSpace();
		bool IsSpace();
	};
};