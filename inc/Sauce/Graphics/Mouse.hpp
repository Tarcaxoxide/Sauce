#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Graphics{
        class Mouse_cl : public Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
            void PutChar(size_t chr);
            public:
                Mouse_cl(Sauce::Point64_st InitialPosition);
        };
    };
};
