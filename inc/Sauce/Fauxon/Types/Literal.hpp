#pragma once
#include<_std/string.hpp>
#include<Sauce/Types.hpp>

namespace Sauce{
    namespace Fauxon{
        struct Literal_st{
            enum Type_en{
                __NULL,
                __STRING,
                __DECIMAL_NUMBER,
                __WHOLE_NUMBER,
                __POINT_NUMBER,
                __OPERATOR
            };
            Type_en Type{Type_en::__NULL};
            void* Value{nullptr};
            Literal_st(const Literal_st& Copy){
                Type = Copy.Type;
                switch(Copy.Type){
                    Type_en::__NULL:{}break;
                    Type_en::__STRING:{
                        _std::string nValue = (*((_std::string*)Value));
                        Value = new _std::string(nValue);
                    }break;
                    Type_en::__OPERATOR:{
                        _std::string nValue = (*((_std::string*)Value));
                        Value = new _std::string(nValue);
                    }break;
                    Type_en::__DECIMAL_NUMBER:{
                        long double nValue = (*((long double*)Value));
                        Value = new long double(nValue);
                    }break;
                    Type_en::__WHOLE_NUMBER:{
                        int64_t nValue = (*((int64_t*)Value));
                        Value = new int64_t(nValue);
                    }break;
                    Type_en::__POINT_NUMBER:{
                        Sauce::Point64_st nValue = (*((Sauce::Point64_st*)Value));
                        Value = new Sauce::Point64_st(nValue);
                    }break;
                }
            }
            Literal_st(_std::string nValue){
                Value = new _std::string(nValue);
                Type = Type_en::__STRING;
                if(nValue.Compare(new const char*[]{"~","`","`","!","!=","@","#","$","%","^","&","*","(",")","_","-","-=","+","+=","=","{","}"."[","]","'","\"","\\","|","/","?","<","<=",">",">=",",",".","?","?=",nullptr})){
                    Type = Type_en::__OPERATOR;
                }
            }
            Literal_st(int64_t nValue){
                Value = new int64_t(nValue);
                Type == Type_en::__WHOLE_NUMBER;
            }
            Literal_st(long double nValue){
                Value = new long double(nValue);
                Type = Type_en::__DECIMAL_NUMBER;
            }
            Literal_st(Sauce::Point64_st nValue){
                Value = new Sauce::Point64_st(nValue);
            }
            ~Literal_st(){
                switch(Type){
                    Type_en::__NULL:{}break;
                    Type_en::__STRING:{
                        delete ((_std::string*)Value);
                    }break;
                    Type_en::__OPERATOR:{
                        delete ((_std::string*)Value);
                    }break;
                    Type_en::__DECIMAL_NUMBER:{
                        delete ((long double*)Value);
                    }break;
                    Type_en::__WHOLE_NUMBER:{
                        delete ((int64_t*)Value);
                    }break;
                    Type_en::__POINT_NUMBER:{
                        delete ((Sauce::Point64_st*)Value);
                    }break;
                }
            }

        };
    };
};