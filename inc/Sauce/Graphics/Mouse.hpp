#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace Graphics{
        class Mouse_cl : public Terminal_cl {
            Point64_t Cursor{0,0,0};
            void PutChar(wchar_t chr);
            public:
                Mouse_cl(Point64_t InitialPosition);
        };
    };
};