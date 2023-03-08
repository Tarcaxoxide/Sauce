#include<Sauce/Graphics/Mouse.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Math.hpp>


uint8_t Glyphs[][13*13]={
				//Top Left (Cue 0)
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
				},
				//Top Right (Cue 2)
				{
					0,1,2,3,4,5,6,7,8,9,9,9,9,
					0,9,8,7,6,5,4,3,2,1,0,0,9,
					0,0,0,0,0,0,0,0,0,1,0,0,9,
					0,0,0,0,0,0,0,0,2,0,1,1,9,
					0,0,0,0,0,0,0,3,0,2,0,2,8,
					0,0,0,0,0,0,4,0,3,0,0,3,7,
					0,0,0,0,0,5,0,4,0,0,0,4,6,
					0,0,0,0,6,0,5,0,0,0,0,5,5,
					0,0,0,7,0,6,0,0,0,0,0,6,4,
					0,0,8,0,7,0,0,0,0,0,0,7,3,
					0,9,0,8,0,0,0,0,0,0,0,8,2,
					0,0,9,0,0,0,0,0,0,0,0,9,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0
				},
				{
					0,0,0,0,0,0,0,0,0,9,9,9,9,
					0,0,0,0,0,0,0,0,0,0,0,0,9,
					0,0,0,0,0,0,0,0,0,1,0,0,9,
					0,0,0,0,0,0,0,0,2,0,1,0,9,
					0,0,0,0,0,0,0,3,0,2,0,0,0,
					0,0,0,0,0,0,4,0,3,0,0,0,0,
					0,0,0,0,0,5,0,4,0,0,0,0,0,
					0,0,0,0,6,0,5,0,0,0,0,0,0,
					0,0,0,7,0,6,0,0,0,0,0,0,0,
					0,0,8,0,7,0,0,0,0,0,0,0,0,
					0,9,0,8,0,0,0,0,0,0,0,0,0,
					0,0,9,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0
				},
				//Bottom Right (Cue 4)
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,9,0,0,0,0,0,0,0,0,9,1,
					0,9,0,8,0,0,0,0,0,0,0,8,2,
					0,0,8,0,7,0,0,0,0,0,0,7,3,
					0,0,0,7,0,6,0,0,0,0,0,6,4,
					0,0,0,0,6,0,5,0,0,0,0,5,5,
					0,0,0,0,0,5,0,4,0,0,0,4,6,
					0,0,0,0,0,0,4,0,3,0,0,3,7,
					0,0,0,0,0,0,0,3,0,2,0,2,8,
					0,0,0,0,0,0,0,0,2,0,1,1,9,
					0,0,0,0,0,0,0,0,0,1,0,0,9,
					0,9,8,7,6,5,4,3,2,1,0,0,9,
					0,1,2,3,4,5,6,7,8,9,9,9,9
				},
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,9,0,0,0,0,0,0,0,0,0,0,
					0,9,0,8,0,0,0,0,0,0,0,0,0,
					0,0,8,0,7,0,0,0,0,0,0,0,0,
					0,0,0,7,0,6,0,0,0,0,0,0,0,
					0,0,0,0,6,0,5,0,0,0,0,0,0,
					0,0,0,0,0,5,0,4,0,0,0,0,0,
					0,0,0,0,0,0,4,0,3,0,0,0,0,
					0,0,0,0,0,0,0,3,0,2,0,0,0,
					0,0,0,0,0,0,0,0,2,0,1,0,9,
					0,0,0,0,0,0,0,0,0,1,0,0,9,
					0,0,0,0,0,0,0,0,0,0,0,0,9,
					0,0,0,0,0,0,0,0,0,9,9,9,9
				},
				//Bottom Left (Cue 6)
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,
					1,9,0,0,0,0,0,0,0,0,9,0,0,
					2,8,0,0,0,0,0,0,0,8,0,9,0,
					3,7,0,0,0,0,0,0,7,0,8,0,0,
					4,6,0,0,0,0,0,6,0,7,0,0,0,
					5,5,0,0,0,0,5,0,6,0,0,0,0,
					6,4,0,0,0,4,0,5,0,0,0,0,0,
					7,3,0,0,3,0,4,0,0,0,0,0,0,
					8,2,0,2,0,3,0,0,0,0,0,0,0,
					9,1,1,0,2,0,0,0,0,0,0,0,0,
					9,0,0,1,0,0,0,0,0,0,0,0,0,
					9,0,0,1,2,3,4,5,6,7,8,9,0,
					9,9,9,9,8,7,6,5,4,3,2,1,0
				},
				{
					0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,9,0,0,
					0,0,0,0,0,0,0,0,0,8,0,9,0,
					0,0,0,0,0,0,0,0,7,0,8,0,0,
					0,0,0,0,0,0,0,6,0,7,0,0,0,
					0,0,0,0,0,0,5,0,6,0,0,0,0,
					0,0,0,0,0,4,0,5,0,0,0,0,0,
					0,0,0,0,3,0,4,0,0,0,0,0,0,
					0,0,0,2,0,3,0,0,0,0,0,0,0,
					9,0,1,0,2,0,0,0,0,0,0,0,0,
					9,0,0,1,0,0,0,0,0,0,0,0,0,
					9,0,0,0,0,0,0,0,0,0,0,0,0,
					9,9,9,9,0,0,0,0,0,0,0,0,0
				}
};


namespace Sauce{
	namespace Graphics{
		void Mouse_cl::PutChar(size_t chr){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Mouse_cl::PutChar",_NAMESPACE_,_ALLOW_PRINT_);
			for(int64_t X=0;X<13;X++){
				for(int64_t Y=0;Y<13;Y++){
					GOP_PixelStructure FGC_Text = Frame.ForegroundColor;
					FGC_Text.Alpha=(FGC_Text.Alpha/9)*Glyphs[chr][Sauce::Math::index(X,Y,13)];
					if(FGC_Text.Alpha)FGC_Text.Alpha+=1;//if it's not 0 then add 1 because division always rounds down and 0xFF isn't evenly dividable by 9
					Frame.PutPixel({X,Y,0},Blend(FGC_Text,Frame.BackgroundColor));
				}
			}
		}
		Mouse_cl::Mouse_cl(Sauce::Point64_st InitialPosition)
		:Terminal_cl((13*13),13,InitialPosition){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Mouse_cl::Mouse_cl",_NAMESPACE_,_ALLOW_PRINT_);
			if(CurrentChr==0){
				Clear();
				PutChar(DirectionalCue+0);
			}else{
				CurrentChr--;
			}
			Sauce::IO::PS2MouseInitialize(InitialPosition);
		}
		Sauce::Point64_st Mouse_cl::Focus(){
			switch(DirectionalCue){
				case 0:{
					return Frame.Offset;
				}break;
				case 2:{
					return {Frame.Offset.X+13,Frame.Offset.Y,Frame.Offset.Z};
				}break;
				case 4:{
					return {Frame.Offset.X+13,Frame.Offset.Y+13,Frame.Offset.Z};
				}break;
				case 6:{
					return {Frame.Offset.X,Frame.Offset.Y+13,Frame.Offset.Z};
				}break;
			}
			return Frame.Offset;
		}
		void Mouse_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
			CurrentChr++;
			Clear();
			PutChar(DirectionalCue+1);
		}
		void Mouse_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
			if(--CurrentChr==0){
				Clear();
				PutChar(DirectionalCue+0);
			}
		}
		void Mouse_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
			CurrentChr++;
			Clear();
			PutChar(DirectionalCue+1);
		}
		void Mouse_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
			if(--CurrentChr==0){
				Clear();
				PutChar(DirectionalCue+0);
			}
		}
		void Mouse_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
			CurrentChr++;
			Clear();
			PutChar(DirectionalCue+1);
		}
		void Mouse_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){}
		void Mouse_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
			if(--CurrentChr==0){
				Clear();
				PutChar(DirectionalCue+0);
			}
		}
		bool Mouse_cl::Move(Sauce::Point64_st Offset){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Mouse_cl::Move",_NAMESPACE_,_ALLOW_PRINT_);
			if(DirectionalSensitivity > 0){
				if(DirectionalCue == 0){
					if(Offset.X<Frame.Offset.X && XCue--<-DirectionalSensitivity){
						DirectionalCue=0;
						XCue=0;
					}else if(Offset.X>Frame.Offset.X && XCue++>DirectionalSensitivity){
						DirectionalCue=2;
						XCue=0;
					}else if(Offset.Y>Frame.Offset.Y && YCue++>DirectionalSensitivity){
							DirectionalCue=6;
							YCue=0;
					}else if(Offset.Y<Frame.Offset.Y && YCue--<-DirectionalSensitivity){
						DirectionalCue=0;
						YCue=0;
					}
				}else if(DirectionalCue == 2){
					if(Offset.X<Frame.Offset.X && XCue--<-DirectionalSensitivity){
						DirectionalCue=0;
						XCue=0;
					}else if(Offset.X>Frame.Offset.X && XCue++>DirectionalSensitivity){
						DirectionalCue=2;
						XCue=0;
					}else if(Offset.Y>Frame.Offset.Y && YCue++>DirectionalSensitivity){
						DirectionalCue=4;
					}else if(Offset.Y<Frame.Offset.Y && YCue--<-DirectionalSensitivity){
						DirectionalCue=2;
						YCue=0;
					}
				}else if(DirectionalCue == 4){
					if(Offset.X<Frame.Offset.X && XCue--<-DirectionalSensitivity){
						DirectionalCue=6;
						XCue=0;
					}else if(Offset.X>Frame.Offset.X && XCue++>DirectionalSensitivity){
						DirectionalCue=4;
						XCue=0;
					}else if(Offset.Y>Frame.Offset.Y && YCue++>DirectionalSensitivity){
						DirectionalCue=4;
						YCue=0;
					}else if(Offset.Y<Frame.Offset.Y && YCue--<-DirectionalSensitivity){
						DirectionalCue=2;
						YCue=0;
					}
				}else if(DirectionalCue == 6){
					if(Offset.X<Frame.Offset.X && XCue--<-DirectionalSensitivity){
						DirectionalCue=6;
						XCue=0;
					}else if(Offset.X>Frame.Offset.X && XCue++>DirectionalSensitivity){
						DirectionalCue=4;
						XCue=0;
					}else if(Offset.Y>Frame.Offset.Y && YCue++>DirectionalSensitivity){
						DirectionalCue=6;
						YCue=0;
					}else if(Offset.Y<Frame.Offset.Y && YCue--<-DirectionalSensitivity){
						DirectionalCue=0;
						YCue=0;
					}
				}
			}
			if(DirectionalCue!=OldDirectionalCue){
				OldDirectionalCue=DirectionalCue;
				ReDraw();
			}
			Frame.Offset=Offset;
			return true;
		}
		void Mouse_cl::ReDraw(){
			Clear();
			if(CurrentChr==0){
				PutChar(DirectionalCue+0);
			}else{
				PutChar(DirectionalCue+1);
			}
		}
		void Mouse_cl::CycleDirectionClockwise(){
			switch(DirectionalCue){
				case 0:{
					DirectionalCue=2;
				}break;
				case 2:{
					DirectionalCue=4;
				}break;
				case 4:{
					DirectionalCue=6;
				}break;
				case 6:{
					DirectionalCue=0;
				}break;
			}
		}
		void Mouse_cl::CycleDirectionCounterClockwise(){
			switch(DirectionalCue){
				case 0:{
					DirectionalCue=6;
				}break;
				case 2:{
					DirectionalCue=0;
				}break;
				case 4:{
					DirectionalCue=2;
				}break;
				case 6:{
					DirectionalCue=4;
				}break;
			}
		}
	};

};