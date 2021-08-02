#pragma once

#include<stdint.h>
#include<stddef.h>
#include "KeyboardMaps.hpp"

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA 0xa1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

namespace Sauce{
	namespace IO{
		void outb(unsigned short port,unsigned char val);
		unsigned char inb(unsigned short port);
		void RemapPic();
	};
	namespace Interrupts{
		struct IDT64{
			uint16_t offset_low;
			uint16_t selector;
			uint8_t ist;
			uint8_t types_attr;
			uint16_t offset_mid;
			uint32_t offset_high;
			uint32_t zero;
		};
	};
	namespace Interrupts{
		void InitializeIDT();
		void MapIDT(size_t index,uint64_t (*This_isr));
	};
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
	    	COLOR_WHITE = 15,
	    };
		struct Char{
	        uint8_t character;
	        uint8_t color;
	    };
		static struct Char* buffer = (struct Char*)0xB8000;
	};

	namespace Terminal{
	    void Fill(char character);
		void Clear();
		void FillRow(size_t Row,char character);
		void FillColumn(size_t column,char character);
		void ClearRow(size_t Row);
	    void Character(char character);
		void SetCharacterAt(size_t X,size_t Y,char character);
		void SetCharacterAt(size_t X,size_t Y,Char character);
		Char GetCharacterAt(size_t X,size_t Y);
	    void String(char* string);
	    void Setcolor(uint8_t foreground,uint8_t background);
		size_t StringLength(char* string);
		void NewLine();
		void ReturnCaret();
		void SetCursor(bool adjust=false,size_t X=0,size_t Y=0);
		void SetRealCursor(size_t X,size_t Y);
	};
	namespace Convert{
		namespace To_uint16{
			uint16_t From_KeyCode(uint8_t KeyCode,size_t KeySet=0);
		};
		namespace To_String{
			char* From_uint8(uint8_t value);
			char* From_uint16(uint16_t value);
			char* From_uint32(uint32_t value);
			char* From_uint64(uint64_t value);
			
		};
	};
};

