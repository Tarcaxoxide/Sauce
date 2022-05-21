#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
            Point64_t Cursor{0,0,0};
            public:
                Shell_cl(size_t X,size_t Y);
                void PutChar(unsigned char chr);
        };
    };
};