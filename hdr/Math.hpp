#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Container.hpp>
#include <Misc.hpp>


namespace Sauce{
    namespace Math{
        class Matrix{
            public:
                uint32_t _columns;
                uint32_t _rows;
                Sauce::Container::DynamicArray<float> _values;
            public:
                Matrix(uint32_t columns,uint32_t rows);
                float* At(uint32_t column,uint32_t row);
                Matrix Multiply(Matrix& target);
                Matrix Multiply(float Scaler);
                Matrix Add(Matrix& target);
                Matrix Add(float Scaler);
                Matrix Inverse();
                Matrix Negative();
                Matrix Transpose();
        };
        void Move_By_Factor(uint64_t* Value,uint64_t ByValue);
        //struct Vertex{
        //    size_t X,Y,Z;
        //};
        //typedef Sauce::Container::Vector<Vertex> Vertices;
    };
};