#include<Sauce/Graphics/Terminal.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			Terminal_cl::Terminal_cl(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer):Frame(PixelBufferTotalSize,PixelsPerLine,PixelBuffer){
				SetID("GenericTerminal");
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
				return Frame.SetColor(ForegroundColor,BackgroundColor);
			}
			bool Terminal_cl::ReverseColor(){
				return Frame.ReverseColor();
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
				return Frame.SetColorForeground(ForegroundColor);
			}
			bool Terminal_cl::RowFill(int64_t RowIndex,GOP_PixelStructure TheColor){
				return Frame.RowFill(RowIndex,Frame.Blend(TheColor,Frame.BackgroundColor));
			}
			bool Terminal_cl::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor,bool blend){
				return Frame.PutPixel(Location,blend?Frame.Blend(TheColor,Frame.BackgroundColor):TheColor);
			}
			bool Terminal_cl::PullPixel(Sauce::Point64_st Location,GOP_PixelStructure& ThatColor){
				return Frame.PullPixel(Location,ThatColor);
			}
			bool Terminal_cl::ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor){
				return Frame.ColumnFill(ColumnIndex,Frame.Blend(TheColor,Frame.BackgroundColor));
			}
			
			bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
				return Frame.Fill(TheColor);
			}
			bool Terminal_cl::RowClear(int64_t RowIndex){
				return Frame.RowClear(RowIndex);
			}
			bool Terminal_cl::ColumnClear(int64_t ColumnIndex){
				return Frame.ColumnClear(ColumnIndex);
			}
			bool Terminal_cl::Clear(){
				return Frame.Clear();
			}
			bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
				return Frame.SetPointer({X,Y,Z});
			}
			bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset){
				return Frame.CopyTo(OtherPixelBuffer,OtherPixelBufferTotalSize,OtherPixelsPerLine,Offset);
			}
			bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
				return Frame.CopyFrom(OtherTerminal->Frame);
			}
			bool Terminal_cl::DrawTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset){
				return Frame.DrawTo(OtherPixelBuffer,OtherPixelBufferTotalSize,OtherPixelsPerLine,Offset);
			}
			bool Terminal_cl::DrawFrom(Terminal_cl* OtherTerminal){
				return Frame.DrawFrom(OtherTerminal->Frame);
			}
			Sauce::Point64_st Terminal_cl::Size(){
				return Frame.Size();
			}
			bool Terminal_cl::Move(Sauce::Point64_st Offset){
				return Frame.Move(Offset);
			}
			void Terminal_cl::SetID(std::string nID){
				int64_t i=0;
				ID=nID;
			}
			bool Terminal_cl::Is_Over(Sauce::Point64_st Location){
				return Frame.Is_Over(Location);
			}
			bool Terminal_cl::BorderSet(GOP_PixelStructure TheColor){
				return Frame.BorderSet(TheColor);
			}
		};
	};
};
