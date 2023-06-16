#include<Sauce/Graphics/Shell/Shell.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Graphics/Shell/Language/Exec.hpp>
#include<Sauce/IO/Debug/Serial.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			Shell_cl::Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
			:Terminal_cl((Size.X*Size.Y),Size.X,Offset){
				ShellClear(true);
			}
			void Shell_cl::PutChar(char chr,bool AddToBuffer){
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
							//ShiftUp(2*Sauce::Graphics::SauceFont::GlyphHeight);
							GoUp();
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
						for(int64_t X=2;X<Sauce::Graphics::SauceFont::GlyphWidth;X++){
							for(int64_t Y=2;Y<Sauce::Graphics::SauceFont::GlyphHeight;Y++){
								GOP_PixelStructure FGC_Text = Frame.ForegroundColor;
								FGC_Text.Alpha=((Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)]*0x1C)+3)==3?0:((Sauce::Graphics::SauceFont::Glyphs[chrindex][Sauce::Math::index(X-1,Y-1,Sauce::Graphics::SauceFont::GlyphWidth)]*0x1C)+3);
								Frame.PutPixel({X+Cursor.X,Y+Cursor.Y,0},Frame.Blend(FGC_Text,Frame.BackgroundColor));
							}
						}
						if(!GoRight()){
							if(GoDown()){
								GoFarLeft();
							}else{
								//at bottom?
								//ShiftUp(2*Sauce::Graphics::SauceFont::GlyphHeight);
								GoUp();
							}
						}
					}break;
				}
			}
			void Shell_cl::PutString(std::string str,bool AddToBuffer){
				for(size_t i=0;i<str.Size();i++){
					PutChar(str[i],AddToBuffer);
				}
				Sauce::Global::Kernel->DrawUI();
			}
			bool Shell_cl::GoDown(size_t amount){
				if((Cursor.Y+(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) > (Frame.PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) ){
					return false;
				}
				Cursor.Y+=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
				return true;
			}
			bool Shell_cl::GoUp(size_t amount){
				if((Cursor.Y-(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount) < 0){
					return false;
				}
				Cursor.Y-=(Sauce::Graphics::SauceFont::GlyphHeight-2)*amount;
				return true;
			}
			bool Shell_cl::GoRight(size_t amount){
				if((Cursor.X+(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) > (Frame.PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) ){
					return false;
				}
				Cursor.X+=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
				return true;
			}
			bool Shell_cl::GoLeft(size_t amount){
				if((Cursor.X-(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount) < 0){
					return false;
				}
				Cursor.X-=(Sauce::Graphics::SauceFont::GlyphWidth-2)*amount;
				return true;
			}
			void Shell_cl::GoFarDown(){
				Cursor.Y=Frame.PixelsBufferHeight-(Sauce::Graphics::SauceFont::GlyphHeight-2);
			}
			void Shell_cl::GoFarUp(){
				Cursor.Y=0;
			}
			void Shell_cl::GoFarRight(){
				Cursor.X=Frame.PixelsPerLine-(Sauce::Graphics::SauceFont::GlyphWidth-2);
			}
			void Shell_cl::GoFarLeft(){
				Cursor.X=0;
			}
			void Shell_cl::ParseAndRunCommand(){
				PutString("\n\r",false);
				PutString(Sauce::Graphics::Shell::Language::Exec(CharBuffer),false);
				ShellClear(false);
			}
			void Shell_cl::ShellClear(bool ClearScreen){
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
};
