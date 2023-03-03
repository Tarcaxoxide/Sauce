#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Math.hpp>


uint8_t Glyphs[][13*13]={
				{
					9,9,9,9,8,7,6,5,4,3,2,1,0,
					9,0,0,1,2,3,4,5,6,7,8,9,0,
					9,0,0,1,0,0,0,0,0,0,0,0,0,
					9,1,1,0,2,0,0,0,0,0,0,0,0,
					8,2,0,2,0,3,0,0,0,0,0,0,0,
					7,3,0,0,3,0,4,0,0,0,0,0,0,
					6,4,0,0,0,4,0,5,0,0,0,0,0,
					5,5,0,0,0,0,5,0,6,0,0,0,0,
					4,6,0,0,0,0,0,6,0,7,0,0,0,
					3,7,0,0,0,0,0,0,7,0,8,0,0,
					2,8,0,0,0,0,0,0,0,8,0,9,0,
					1,9,0,0,0,0,0,0,0,0,9,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0
				},
				{
					9,9,9,9,0,0,0,0,0,0,0,0,0,
					9,0,0,0,0,0,0,0,0,0,0,0,0,
					9,0,0,1,0,0,0,0,0,0,0,0,0,
					9,0,1,0,2,0,0,0,0,0,0,0,0,
					0,0,0,2,0,3,0,0,0,0,0,0,0,
					0,0,0,0,3,0,4,0,0,0,0,0,0,
					0,0,0,0,0,4,0,5,0,0,0,0,0,
					0,0,0,0,0,0,5,0,6,0,0,0,0,
					0,0,0,0,0,0,0,6,0,7,0,0,0,
					0,0,0,0,0,0,0,0,7,0,8,0,0,
					0,0,0,0,0,0,0,0,0,8,0,9,0,
					0,0,0,0,0,0,0,0,0,0,9,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0
				}
};


namespace Sauce{
	namespace Graphics{
		void Mouse_cl::PutChar(size_t chr){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Mouse_cl::PutChar",_NAMESPACE_,_ALLOW_PRINT_);
			for(size_t X=0;X<13;X++){
				for(size_t Y=0;Y<13;Y++){
					GOP_PixelStructure FGC_Text = ForegroundColor;
					FGC_Text.Alpha=(ForegroundColor.Alpha/9)*Glyphs[chr][Sauce::Math::index(X-1,Y-1,13)];
					if(FGC_Text.Alpha)FGC_Text.Alpha+=1;//if it's not 0 then add 1 because division always rounds down and 0xFF isn't evenly dividable by 9
					PixelBuffer[Sauce::Math::index(X,Y,PixelsPerLine)]=Blend(FGC_Text,BackgroundColor);
				}
			}
		}
		Mouse_cl::Mouse_cl(Sauce::Point64_st InitialPosition)
		:Terminal_cl((13*13),13,InitialPosition){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Mouse_cl::Mouse_cl",_NAMESPACE_,_ALLOW_PRINT_);
			Clear();
			PutChar(0);
			Sauce::IO::PS2MouseInitialize(InitialPosition);
		}
		void Mouse_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
			Clear();
			PutChar(1);
		}
		void Mouse_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
			Clear();
			PutChar(0);
		}
		void Mouse_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){}
		void Mouse_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){}
		void Mouse_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){}
		void Mouse_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){}
	};

};
