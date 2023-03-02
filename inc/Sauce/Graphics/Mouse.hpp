#ifndef __Sauce_Graphics_Mouse
#define __Sauce_Graphics_Mouse
#include<Sauce/Graphics/Terminal.hpp>
namespace Sauce{
	namespace Graphics{
		class Mouse_cl : public Basic::Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
			void PutChar(size_t chr);
			public:
				Mouse_cl(Sauce::Point64_st InitialPosition);
		};
	};
};
#endif