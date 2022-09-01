#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Graphics{
        class Mouse_cl : public Terminal_cl {
			Sauce::Math::Point64_t Cursor{0,0,0};
            void PutChar(size_t chr);
            public:
                Mouse_cl(Sauce::Math::Point64_t InitialPosition);
        };
    };
};
