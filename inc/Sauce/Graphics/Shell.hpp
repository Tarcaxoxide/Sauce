#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Math.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
            
            public:
                Shell_cl(size_t X,size_t Y);
                void PutChar(const unsigned char chr);
        };
    };
};