#include<Sauce/Graphics/Window.hpp>
#include<Sauce/Types.hpp>

namespace Sauce{
	namespace Graphics{
		Window_cl::Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
		:Shell_cl(Size,Offset){
		}

		void Window_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
			PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
			//PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
			PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
			//PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
			PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
			//PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
	};
};
