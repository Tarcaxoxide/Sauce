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
            OP__MORE_THAN,
            OP__LESS_THAN,
            OP__EQUALS,
            OP__PUSH,
            OP__PRINT,
            OP__TAG,
            OP__IF_JUMP,
            OP__JUMP,
            OP__CLEAR_STACK
        };
        enum TpCode: uint32_t{
            TP__NULL=0,
            TP__SIGNED_INT,
            TP__UNSIGNED_INT,
            TP__BOOL,
            TP__TAG
        };
        struct VirtualStack_st{
            TpCode Type;
            union {
                uint64_t Value;
                unsigned char CValue[8];
            };
            union {
                uint64_t eValue;
                unsigned char eCValue[8];
            };
        };
        struct Instruction_st{
            OpCode opcode;
            VirtualStack_st Data;
        };

        class VirtualMachine_cl{
            Sauce::Memory::List_cl<VirtualStack_st> _VirtualStack;
            Sauce::Memory::List_cl<VirtualStack_st> _VirtaulStackTags;
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
        };
    };
};

