#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Global.hpp>
#include<std/deque.hpp>
#include<std/functional.hpp>
#include<std/iostream.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Memory/List.hpp>

namespace Sauce{
	namespace Graphics{
		Shell_cl::Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
		:Terminal_cl((Size.X*Size.Y),Size.X,Offset){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::Shell_cl",_NAMESPACE_,_ALLOW_PRINT_);
			ShellClear(true);
		}
		void Shell_cl::PutChar(char chr,bool AddToBuffer){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::PutChar",_NAMESPACE_,_ALLOW_PRINT_);
			size_t chrindex = (size_t)chr;
			if(AddToBuffer)Sauce::Global::Kernel->DrawUI();
			switch(chrindex){
				case '\n':{
					if(AddToBuffer){
						if(!CharBuffer.Size())break;
						//CharBuffer.AddLast(chr);
						ParseAndRunCommand();
					}
					if(!GoDown()){
						ShiftUp(2*Sauce::Graphics::SauceFont::GlyphHeight);
						GoUp();
						Debugger.Print("Reached Bottoom.");
					}
				}break;
				case '\b':{
					if(AddToBuffer){
						if(!CharBuffer.RemoveLast())break;
					}
					if(!GoLeft()){
						if(GoUp()){
							GoFarRight();
						}
					}else{
						PutChar(' ',false);
						GoLeft();
					}
				}break;
				case '\r':{
					GoFarLeft();
					if(AddToBuffer)CharBuffer.Clear();
				}break;
				default:{
					if(AddToBuffer)CharBuffer.AddLast(chr);
					for(size_t X=2;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
						for(size_t Y=2;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
							GOP_PixelStructure FGC_Text = ForegroundColor;
							FGC_Text.Alpha=(ForegroundColor.Alpha/9)*Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)];
							if(FGC_Text.Alpha)FGC_Text.Alpha+=1;//if it's not 0 then add 1 because division always rounds down and 0xFF isn't evenly dividable by 9
							PixelBuffer[Sauce::Math::index(X+Cursor.X,Y+Cursor.Y,PixelsPerLine)]=Blend(FGC_Text,BackgroundColor);
						}
					}
					if(!GoRight()){
						if(GoDown()){
							GoFarLeft();
						}else{
							//at bottom?
							ShiftUp(2*Sauce::Graphics::SauceFont::GlyphHeight);
							GoUp();
						}
					}
				}break;
			}
		}
		void Shell_cl::PutString(std::string str,bool AddToBuffer){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::PutString",_NAMESPACE_,_ALLOW_PRINT_);
			for(size_t i=0;i<str.Size();i++){
				PutChar(str[i],AddToBuffer);
			}
			Sauce::Global::Kernel->DrawUI();
		}
		bool Shell_cl::GoDown(size_t amount){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoDown",_NAMESPACE_,_ALLOW_PRINT_);
			if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
				return false;
			}
			Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
			return true;
		}
		bool Shell_cl::GoUp(size_t amount){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoUp",_NAMESPACE_,_ALLOW_PRINT_);
			if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
				return false;
			}
			Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
			return true;
		}
		bool Shell_cl::GoRight(size_t amount){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoRight",_NAMESPACE_,_ALLOW_PRINT_);
			if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
				return false;
			}
			Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
			return true;
		}
		bool Shell_cl::GoLeft(size_t amount){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoLeft",_NAMESPACE_,_ALLOW_PRINT_);
			if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
				return false;
			}
			Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
			return true;
		}
		void Shell_cl::GoFarDown(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoFarDown",_NAMESPACE_,_ALLOW_PRINT_);
			Cursor.Y=PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
		}
		void Shell_cl::GoFarUp(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoFarUp",_NAMESPACE_,_ALLOW_PRINT_);
			Cursor.Y=0;
		}
		void Shell_cl::GoFarRight(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoFarRight",_NAMESPACE_,_ALLOW_PRINT_);
			Cursor.X=PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
		}
		void Shell_cl::GoFarLeft(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::GoFarLeft",_NAMESPACE_,_ALLOW_PRINT_);
			Cursor.X=0;
		}
		void Shell_cl::ParseAndRunCommand(){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::ParseAndRunCommand",_NAMESPACE_,_ALLOW_PRINT_);
			PutString("\n\r",false);
			
			//PutString(CharBuffer,false);

			if(CharBuffer.Compare(new const char*[]{"hi","Hi","HI","hI","hello","Hello","HEllo","HELlo","HELLo","HELLO",nullptr})){
				PutString("The kernel says hi!\n\r",false);
				PutString(Sauce::Utility::Conversion::HexToString((uint16_t)0x1234567890ABCDEF),false);
				PutString("\n\r",false);
			}
			
			ShellClear(false);
		}
		void Shell_cl::ShellClear(bool ClearScreen){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Shell_cl::ShellClear",_NAMESPACE_,_ALLOW_PRINT_);
			CharBuffer.Clear();
			if(ClearScreen){
				Cursor.X=0;
				Cursor.Y=0;
				Cursor.Z=0;
				Clear();
			}
		}
	};
};
