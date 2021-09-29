#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Container.hpp> //for vector
#include <Misc.hpp>


namespace Sauce{
    namespace Math{
        class Matrix{
            public:
                uint32_t _columns;
                uint32_t _rows;
                Sauce::Container::Vector<float> _values;
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
    };
};