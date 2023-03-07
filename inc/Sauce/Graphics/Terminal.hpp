#ifndef __Sauce_Graphics_Basic_Terminal
#define __Sauce_Graphics_Basic_Terminal
#include<Sauce/Common.hpp>
#include<std/string.hpp>
#include<Sauce/Graphics/Frame.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			class Terminal_cl{
				protected:
					Frame_st Frame;
				public:
					std::string ID;
					Terminal_cl(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,Sauce::Point64_st Offset={0,0,0},GOP_PixelStructure* PixelBuffer=nullptr);
					bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
					bool SetColor(GOP_PixelStructure ForegroundColor);
					bool ReverseColor();
					bool RowFill(int64_t RowIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool Fill(GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF});
					bool PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor={0xFF,0xFF,0xFF,0xFF},bool blend=true);
					bool PullPixel(Sauce::Point64_st Location,GOP_PixelStructure& ThatColor);
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