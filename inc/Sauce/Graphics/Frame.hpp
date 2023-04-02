#ifndef __Sauce_Graphics_Basic_Frame
#define __Sauce_Graphics_Basic_Frame
#include<Sauce/Common.hpp>
#include<Sauce/Types.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			struct Frame_st{
				GOP_PixelStructure* PixelBuffer=nullptr;
				int64_t PixelBufferTotalSize,PixelsPerLine,PixelsBufferHeight;
				GOP_PixelStructure ForegroundColor{0xFF,0xFF,0xFF,0xFF},BackgroundColor{0x00,0x00,0x00,0x00},BorderColor{0x00,0x00,0x00,0x00};
				Sauce::Point64_st PixelPointer{0,0,0};
				Sauce::Point64_st Offset{0,0,0};
				Frame_st(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,GOP_PixelStructure* Buffer=nullptr);
				Frame_st(const Frame_st& Other);
				~Frame_st();
				bool SetPointer(Sauce::Point64_st pointer);
				bool Is_Over(Sauce::Point64_st Location);
				GOP_PixelStructure Blend(GOP_PixelStructure Front,GOP_PixelStructure Back);
				Sauce::Point64_st Size();
				bool Move(Sauce::Point64_st Location);
				bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
				bool SetColorForeground(GOP_PixelStructure ForegroundColor);
				bool SetColorBackground(GOP_PixelStructure BackgroundColor);
				bool ReverseColor();
				bool RowFill(int64_t RowIndex,GOP_PixelStructure TheColor);
				bool ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor);
				bool Fill(GOP_PixelStructure TheColor);
				bool Clear();
				bool RowClear(int64_t RowIndex);
				bool ColumnClear(int64_t ColumnIndex);
				bool PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor);
				bool PutPixel(Sauce::Point64_st Location);
				bool PullPixel(Sauce::Point64_st Location,GOP_PixelStructure& ThatColor);
				bool DrawTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st OtherOffset);
				bool DrawTo(Frame_st& Other);
				bool DrawFrom(Frame_st& Other);
				bool CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st OtherOffset);
				bool CopyTo(Frame_st& Other);
				bool CopyFrom(Frame_st& Other);
				bool Resize(Sauce::Point64_st nSize);
				bool BorderDraw();
				bool BorderSet(GOP_PixelStructure TheColor);
			};
		};
	};
};
#endif