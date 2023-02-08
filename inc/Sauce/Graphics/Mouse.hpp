#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/List.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#pragma once

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
