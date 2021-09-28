#include <Math.hpp>

namespace Sauce{
    namespace Math{
        Matrix::Matrix(uint32_t columns,uint32_t rows)
        :_columns(columns),
         _rows(rows),
         _values({}){
            _values.Resize(_columns*_rows,0.0f);

        }
        float* Matrix::At(uint32_t column,uint32_t row){
            return _values[row*_columns + column];
        }
        Matrix Matrix::Multiply(Matrix& target){
            //assert(_columns == target._rows);
                if(_columns != target._rows)__STOP__(); // temporary replacement
            
            Matrix output(target._columns,_rows);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    float result = 0.0f;
                    for(uint32_t k = 0; k < _columns;k++)
                        result+= (*At(k,y)) * (*target.At(x,k));
                    *output.At(x,y) = result;
                }
            return output;
        }
        Matrix Matrix::Multiply(float Scaler){
            Matrix output(_columns,_rows);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    *output.At(x,y) = (*At(x,y))*Scaler;
                }
            return output;
        }
        Matrix Matrix::Add(float Scaler){
            Matrix output(_columns,_rows);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    *output.At(x,y) = (*At(x,y))+Scaler;
                }
            return output;
        }
        Matrix Matrix::Add(Matrix& target){
            //assert(_rows == target._rows && _columns == target._columns);
                if(_rows != target._rows || _columns != target._columns)__STOP__(); // temporary replacement
            
            Matrix output(target._columns,_rows);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    *output.At(x,y) = (*At(x,y))+(*target.At(x,y));
                }
            return output;
        }
        Matrix Matrix::Inverse(){
            Matrix output(_columns,_rows);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    *output.At(x,y) = ((*At(x,y)) - (*At(x,y)) - (*At(x,y)));
                }
            return output;
        }
        Matrix Matrix::Transpose(){
            Matrix output(_rows,_columns);
            for(uint32_t y =0;y < output._rows;y++)
                for(uint32_t x =0;x < output._rows;x++){
                    *output.At(y,x) = (*At(x,y));
                }
            return output;
        }
    };
};