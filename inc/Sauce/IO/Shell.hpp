#pragma once
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Common.h>
#include<Sauce/Math.hpp>
#include<Sauce/IO/InputData.hpp>
#include<Sauce/IO/Terminal.hpp>


namespace Sauce{
    namespace Shell{
        class Kshell{
            Kshell* Self=nullptr;
            DataStructure* DFBL=nullptr;
            Sauce::IO::Terminal Term;
            public:
                Kshell(DataStructure* DFBL); 
                void Input(Sauce::IO::InputData_st Data);
        };
    };
};