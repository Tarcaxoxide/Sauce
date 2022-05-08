#pragma once

#include<stddef.h>
#include<stdint.h>

#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace UserLand{
        enum OpCode: uint64_t{
            OP__NULL=0,
            OP__EXIT,
            OP__ADD_INT,
            OP__PUSH_INT,
            OP__PRINT_INT
        };
        struct Data_st{
            union{
                uint64_t u64Data;
                uint32_t u32Data[2];
                uint16_t u16Data[4];
                uint8_t u8Data[8];
            };
        };
        struct Instruction_st{
            OpCode opcode;
            Data_st Data;
        };
        class VirtualMachine_cl{
            Sauce::Memory::List_cl<Data_st> _VirtualStack;
            Sauce::Memory::List_cl<Instruction_st> _code;
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
            void Run();
        };
    };
};