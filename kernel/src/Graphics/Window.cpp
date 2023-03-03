#include<Sauce/Graphics/Window.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Graphics{
		Window_cl::Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset)
		:Shell_cl(Size,Offset){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Window_cl",_NAMESPACE_,_ALLOW_PRINT_);
		}

		void Window_cl::Notify_Of_Mouse_Left_Down(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Down",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Left_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Drag",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Left_Up(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Up",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0xFF,0x00,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Down(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Down",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Drag",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Center_Up(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Up",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0xFF,0x00,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Down(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Down",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Drag(Sauce::Point64_st Location,Sauce::Point64_st OldLocation){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Drag",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
		void Window_cl::Notify_Of_Mouse_Right_Up(Sauce::Point64_st Location){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Window_cl::Notify_Of_Mouse_Left_Up",_NAMESPACE_,_ALLOW_PRINT_);
			PutPixel(Location,{0x00,0x00,0xFF,0xFF});
		}
	};
};
