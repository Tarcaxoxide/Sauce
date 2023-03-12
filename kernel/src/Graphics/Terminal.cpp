#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Utility/Manipulations.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Math.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Basic{
			Terminal_cl::Terminal_cl(int64_t PixelBufferTotalSize,int64_t PixelsPerLine,Sauce::Point64_st Offset,GOP_PixelStructure* PixelBuffer):Frame(PixelBufferTotalSize,PixelsPerLine,PixelBuffer){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Terminal_cl",_NAMESPACE_,_ALLOW_PRINT_);
				SetID("GenericTerminal");
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetColor",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.SetColor(ForegroundColor,BackgroundColor);
			}
			bool Terminal_cl::ReverseColor(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ReverseColor",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.ReverseColor();
			}
			bool Terminal_cl::SetColor(GOP_PixelStructure ForegroundColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetColor",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.SetColorForeground(ForegroundColor);
			}
			bool Terminal_cl::RowFill(int64_t RowIndex,GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowFill",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.RowFill(RowIndex,Frame.Blend(TheColor,Frame.BackgroundColor));
			}
			bool Terminal_cl::PutPixel(Sauce::Point64_st Location,GOP_PixelStructure TheColor,bool blend){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::PutPixel",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.PutPixel(Location,blend?Frame.Blend(TheColor,Frame.BackgroundColor):TheColor);
			}
			bool Terminal_cl::PullPixel(Sauce::Point64_st Location,GOP_PixelStructure& ThatColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::PullPixel",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.PullPixel(Location,ThatColor);
			}
			bool Terminal_cl::ColumnFill(int64_t ColumnIndex,GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ColumnFill",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.ColumnFill(ColumnIndex,Frame.Blend(TheColor,Frame.BackgroundColor));
			}
			
			bool Terminal_cl::Fill(GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Fill",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.Fill(TheColor);
			}
			bool Terminal_cl::RowClear(int64_t RowIndex){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::RowClear",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.RowClear(RowIndex);
			}
			bool Terminal_cl::ColumnClear(int64_t ColumnIndex){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::ColumnClear",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.ColumnClear(ColumnIndex);
			}
			bool Terminal_cl::Clear(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Clear",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.Clear();
			}
			bool Terminal_cl::SetCursor(int64_t X,int64_t Y,int64_t Z){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::SetCursor",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.SetPointer({X,Y,Z});
			}
			bool Terminal_cl::CopyTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyTo",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.CopyTo(OtherPixelBuffer,OtherPixelBufferTotalSize,OtherPixelsPerLine,Offset);
			}
			bool Terminal_cl::CopyFrom(Terminal_cl* OtherTerminal){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyFrom",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.CopyFrom(OtherTerminal->Frame);
			}
			bool Terminal_cl::DrawTo(GOP_PixelStructure* OtherPixelBuffer,int64_t OtherPixelBufferTotalSize,int64_t OtherPixelsPerLine,Sauce::Point64_st Offset){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyTo",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.DrawTo(OtherPixelBuffer,OtherPixelBufferTotalSize,OtherPixelsPerLine,Offset);
			}
			bool Terminal_cl::DrawFrom(Terminal_cl* OtherTerminal){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::CopyFrom",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.DrawFrom(OtherTerminal->Frame);
			}
			Sauce::Point64_st Terminal_cl::Size(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Size",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.Size();
			}
			bool Terminal_cl::Move(Sauce::Point64_st Offset){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Move",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.Move(Offset);
			}
			void Terminal_cl::SetID(std::string nID){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::setID",_NAMESPACE_,_ALLOW_PRINT_);
				int64_t i=0;
				ID=nID;
			}
			bool Terminal_cl::Is_Over(Sauce::Point64_st Location){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::Is_Mouse_Over",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.Is_Over(Location);
			}
			bool Terminal_cl::BorderSet(GOP_PixelStructure TheColor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Terminal_cl::BorderSet",_NAMESPACE_,_ALLOW_PRINT_);
				return Frame.BorderSet(TheColor);
			}
		};
	};
};
