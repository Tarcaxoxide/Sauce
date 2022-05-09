#pragma once

#include<stddef.h>
#include<stdint.h>

#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace UserLand{
        enum OpCode: uint32_t{
            OP__NULL=0,
            OP__EXIT,
            OP__ADD,
            OP__SUBTRACT,
            OP__MULTIPLY,
            OP__DIVIDE,
            OP__MODULUS,
            OP__PUSH,
            OP__PRINT
        };
        enum TpCode: uint32_t{
            TP__NULL=0,
            TP__SIGNED_INT,
            TP__UNSIGNED_INT
        };
        
        struct VirtualStack_st{
            TpCode Type;
            uint64_t Value;
        };
        struct Instruction_st{
            OpCode opcode;
            VirtualStack_st Data;
        };

        class VirtualMachine_cl{
            Sauce::Memory::List_cl<VirtualStack_st> _VirtualStack;
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
        };
    };
};

