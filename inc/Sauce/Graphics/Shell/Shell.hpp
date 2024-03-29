#ifndef __Sauce_Graphics_Shell
#define __Sauce_Graphics_Shell
#include<Sauce/Graphics/Frame.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
		class Shell_cl {
			public:
				Sauce::Graphics::Basic::Frame_st Frame;
			private:
				Sauce::Point64_st Cursor{0,0,0};
				std::string CharBuffer;
			public:
				Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
				void PutChar(char chr,bool AddToBuffer);
				void PutString(std::string str,bool AddToBuffer);
				bool GoDown(size_t amount=1);
				bool GoUp(size_t amount=1);
				bool GoRight(size_t amount=1);
				bool GoLeft(size_t amount=1);
				void GoFarDown();
				void GoFarUp();
				void GoFarRight();
				void GoFarLeft();
				void ParseAndRunCommand();
				void ShellClear(bool ClearScreen);
				bool Clear();
				bool SetColor(GOP_PixelStructure ForegroundColor,GOP_PixelStructure BackgroundColor);
				Sauce::Point64_st Size();
			};
		};
	};
};
#endif