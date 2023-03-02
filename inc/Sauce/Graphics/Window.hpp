#ifndef __Sauce_Graphics_Window
#define __Sauce_Graphics_Window
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Graphics/Font.hpp>
namespace Sauce{
	namespace Graphics{
		class Window_cl : public Shell_cl {
			public:
			Window_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
		};
	};
};
#endif