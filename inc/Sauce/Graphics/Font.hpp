#ifndef __Sauce_Graphics_Font
#define __Sauce_Graphics_Font
#include<stddef.h>
#include<stdint.h>
#include<std/string.hpp>
namespace Sauce{
	namespace Graphics{
		namespace SauceFont{
			const static int64_t GlyphWidth=13;
			const static int64_t GlyphHeight=13;
			const static int64_t GlyphSize=GlyphWidth*GlyphHeight;
			const static int64_t EncodingSize=(GlyphWidth*2)+((GlyphHeight-2)*2);
			extern uint8_t Glyphs[][GlyphSize];

			inline void Encode(std::ustring& Data,std::ustring& Glyph){
				//EXPERIMENTAL //I hope i got these calculations correct XD will test later when i have something to use it with.
				while(Data.Size()<48)Data.AddLast('\0');
				Glyph[1-1]=Data[1-1];
				Glyph[2-1]=Data[2-1];
				Glyph[3-1]=Data[3-1];
				Glyph[4-1]=Data[4-1];
				Glyph[5-1]=Data[5-1];
				Glyph[6-1]=Data[6-1];
				Glyph[7-1]=Data[7-1];
				Glyph[8-1]=Data[8-1];
				Glyph[9-1]=Data[9-1];
				Glyph[10-1]=Data[10-1];
				Glyph[11-1]=Data[11-1];
				Glyph[12-1]=Data[12-1];
				Glyph[13-1]=Data[13-1];
				Glyph[26-1]=Data[14-1];
				Glyph[39-1]=Data[15-1];
				Glyph[52-1]=Data[16-1];
				Glyph[65-1]=Data[17-1];
				Glyph[78-1]=Data[18-1];
				Glyph[91-1]=Data[19-1];
				Glyph[104-1]=Data[20-1];
				Glyph[117-1]=Data[21-1];
				Glyph[130-1]=Data[22-1];
				Glyph[143-1]=Data[23-1];
				Glyph[156-1]=Data[24-1];
				Glyph[169-1]=Data[25-1];
				Glyph[168-1]=Data[26-1];
				Glyph[167-1]=Data[27-1];
				Glyph[166-1]=Data[28-1];
				Glyph[165-1]=Data[29-1];
				Glyph[164-1]=Data[30-1];
				Glyph[163-1]=Data[31-1];
				Glyph[162-1]=Data[32-1];
				Glyph[161-1]=Data[33-1];
				Glyph[160-1]=Data[34-1];
				Glyph[159-1]=Data[35-1];
				Glyph[158-1]=Data[36-1];
				Glyph[157-1]=Data[37-1];
				Glyph[144-1]=Data[38-1];
				Glyph[131-1]=Data[39-1];
				Glyph[118-1]=Data[40-1];
				Glyph[105-1]=Data[41-1];
				Glyph[92-1]=Data[42-1];
				Glyph[79-1]=Data[43-1];
				Glyph[66-1]=Data[44-1];
				Glyph[53-1]=Data[45-1];
				Glyph[40-1]=Data[46-1];
				Glyph[27-1]=Data[47-1];
				Glyph[14-1]=Data[48-1];
			}
			inline void Decode(std::ustring& Data,std::ustring& Glyph){
				//EXPERIMENTAL //I hope i got these calculations correct XD will test later when i have something to use it with.
				while(Data.Size()<48)Data.AddLast('\0');
				Data[1-1]=Glyph[1-1];
				Data[2-1]=Glyph[2-1];
				Data[3-1]=Glyph[3-1];
				Data[4-1]=Glyph[4-1];
				Data[5-1]=Glyph[5-1];
				Data[6-1]=Glyph[6-1];
				Data[7-1]=Glyph[7-1];
				Data[8-1]=Glyph[8-1];
				Data[9-1]=Glyph[9-1];
				Data[10-1]=Glyph[10-1];
				Data[11-1]=Glyph[11-1];
				Data[12-1]=Glyph[12-1];
				Data[13-1]=Glyph[13-1];
				Data[14-1]=Glyph[26-1];
				Data[15-1]=Glyph[39-1];
				Data[16-1]=Glyph[52-1];
				Data[17-1]=Glyph[65-1];
				Data[18-1]=Glyph[78-1];
				Data[19-1]=Glyph[91-1];
				Data[20-1]=Glyph[104-1];
				Data[21-1]=Glyph[117-1];
				Data[22-1]=Glyph[130-1];
				Data[23-1]=Glyph[143-1];
				Data[24-1]=Glyph[156-1];
				Data[25-1]=Glyph[169-1];
				Data[26-1]=Glyph[168-1];
				Data[27-1]=Glyph[167-1];
				Data[28-1]=Glyph[166-1];
				Data[29-1]=Glyph[165-1];
				Data[30-1]=Glyph[164-1];
				Data[31-1]=Glyph[163-1];
				Data[32-1]=Glyph[162-1];
				Data[33-1]=Glyph[161-1];
				Data[34-1]=Glyph[160-1];
				Data[35-1]=Glyph[159-1];
				Data[36-1]=Glyph[158-1];
				Data[37-1]=Glyph[157-1];
				Data[38-1]=Glyph[144-1];
				Data[39-1]=Glyph[131-1];
				Data[40-1]=Glyph[118-1];
				Data[41-1]=Glyph[105-1];
				Data[42-1]=Glyph[92-1];
				Data[43-1]=Glyph[79-1];
				Data[44-1]=Glyph[66-1];
				Data[45-1]=Glyph[53-1];
				Data[46-1]=Glyph[40-1];
				Data[47-1]=Glyph[27-1];
				Data[48-1]=Glyph[14-1];
			}
		};
	};
};
#endif
/*
	1 2 3 4 5 6 7 8 9 0 1 2 3
	. . . . . . . . . . . . . 1
	. 9 9 9 9 9 9 9 9 9 9 9 . 2
	. 9 5 0 0 0 0 0 0 0 5 9 . 3
	. 9 0 5 0 0 0 0 0 5 0 9 . 4
	. 9 0 0 5 0 0 0 5 0 0 9 . 5
	. 9 0 0 0 5 0 5 0 0 0 9 . 6
	. 9 0 0 0 0 5 0 0 0 0 9 . 7
	. 9 0 0 0 5 0 5 0 0 0 9 . 8
	. 9 0 0 5 0 0 0 5 0 0 9 . 9
	. 9 0 5 0 0 0 0 0 5 0 9 . 0
	. 9 5 0 0 0 0 0 0 0 5 9 . 1
	. 9 9 9 9 9 9 9 9 9 9 9 . 2
	. . . . . . . . . . . . . 3
*/