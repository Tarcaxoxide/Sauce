#ifndef __Sauce_Graphics_Window
#define __Sauce_Graphics_Window
#include<Sauce/Graphics/Shell/Shell.hpp>
#include<Sauce/Graphics/Font.hpp>
namespace Sauce{
	namespace Graphics{
		class Window_cl : public Shell::Shell_cl {
			public:
			Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
			void Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location);
			void Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
			void Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location);
			void Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location);
			void Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
			void Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location);
			void Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location);
			void Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation);
			void Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location);
		};
		
	};
};
#endif