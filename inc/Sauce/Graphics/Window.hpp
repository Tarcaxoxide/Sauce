#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Graphics{
        class Window_cl : public Terminal_cl {
            public:
                Shell_cl(Point64_t Size, Point64_t Offset={0,0,0});
                void DrawLine(Point64_t PointA, Point64_t PointB);
                void DrawSquare(Point64_t TopLeft, Point64_t BottomRight);
                void DrawCircle(Point64_t Center, size_t Radius);
        };
    };
};