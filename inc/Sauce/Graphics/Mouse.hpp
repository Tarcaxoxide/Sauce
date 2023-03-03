#ifndef __Sauce_Graphics_Mouse
#define __Sauce_Graphics_Mouse
#include<Sauce/Graphics/Terminal.hpp>
namespace Sauce{
	namespace Graphics{
		class Mouse_cl : public Basic::Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
			void PutChar(size_t chr);
			size_t CurrentChr;
			public:
				Mouse_cl(Sauce::Point64_st InitialPosition);
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