#ifndef __Sauce_Graphics_Basic_Terminal
#define __Sauce_Graphics_Basic_Terminal
#include<Sauce/Common.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			class Terminal_cl{
				protected:
					GOP_PixelStructure* PixelBuffer=nullptr;
					int64_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
					GOP_PixelStructure ForegroundColor{0xFF,0xFF,0xFF,0xFF},BackgroundColor{0x00,0x00,0x00,0x00};
					Sauce::Point64_st PixelPointer{0,0,0};
					Sauce::Point64_st MyOffset{0,0,0};
				public:
					std::string ID;
					Terminal_cl(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,Sauce::Point64_st Offset={0,0,0},GOP_PixelStructure* PixelBuffer=nullptr);
					bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
					bool SetColor(GOP_PixelStructure ForegroundColor);
					void ReverseColor();
					bool RowFill(int64_t RowIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool ShiftUp(int64_t Rows);
					bool ShiftDown(int64_t Rows);
					bool Fill(GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					GOP_PixelStructure Blend(GOP_PixelStructure Front,GOP_PixelStructure Back);
					bool RowClear(int64_t RowIndex);
					bool ColumnClear(int64_t ColumnIndex);
					bool Clear();
					bool SetCursor(int64_t X,int64_t Y,int64_t Z=0);
					bool CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset={0,0,0});
					bool CopyFrom(Terminal_cl* OtherTerminal);
					Sauce::Point64_st Size();
					bool Move(Sauce::Point64_st Offset);
					void SetID(std::string nID);
					bool Is_Over(Sauce::Point64_st Location);
			};
		};
	};
};
#endif