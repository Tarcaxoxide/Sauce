#pragma once

#include<stddef.h>
#include<stdint.h>

#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace UserLand{
        enum OpCode: uint32_t{
            OP__NULL=0,      // used to basically mean 'no instruction'
            OP__EXIT,        // basically the same as NULL right now but i plan on this doing other things later, like returning to a calling function.
            OP__ADD,         // mathematical add of the last and previews item on the virtual stack  
            OP__SUBTRACT,    // mathematical subtract of the last and previews item on the virtual stack
            OP__MULTIPLY,    // mathematical multiply of the last and previews item on the virtual stack
            OP__DIVIDE,      // mathematical divide of the last and previews item on the virtual stack
            OP__MODULUS,     // mathematical modulus of the last and previews item on the virtual stack
            OP__MORE_THAN,   // mathematical greater than of the last and previews item on the virtual stack 
            OP__LESS_THAN,   // mathematical less than of the last and previews item on the virtual stack
            OP__EQUALS,      // mathematical equals of the last and previews item on the virtual stack
            OP__PUSH,        // push value onto the virtual stack
            OP__PRINT,       // print and remove the last item on the virtual stack
            OP__TAG,         // this is a "tag" for jumping to
            OP__IF_JUMP,     // jump if the previews item is not 0(false)
            OP__JUMP,        // jump
            OP__CLEAR_STACK, // wipes clean the entire stack
            OP__CLONE        // pushes a copy of the last item on the virtual stack onto the virtual stack, useful if you want to print a value but also keep it 2.
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
        const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};

        struct Instruction_st{
            OpCode opcode;
            VirtualStack_st Data{NIL_DATA};
        };

        class VirtualMachine_cl{
            Sauce::Memory::List_cl<VirtualStack_st> _VirtualStack;
            Sauce::Memory::List_cl<VirtualStack_st> _VirtaulStackTags;
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
        };
    };
};

