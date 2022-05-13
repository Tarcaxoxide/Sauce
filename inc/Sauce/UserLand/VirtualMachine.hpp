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
            OP__IF_JUMP,
            OP__JUMP,
            OP__CLEAR_STACK,
            OP__CLONE
        };
        enum SzCode:uint8_t{
            V64_E64=0xFF,
            V64_E32=0xFE,
            V64_E16=0XFD,
            V64_E08=0xFC,
            V32_E64=0xEF,
            V32_E32=0xEE,
            V32_E16=0XED,
            V32_E08=0xEC,
            V16_E64=0xDF,
            V16_E32=0xDE,
            V16_E16=0XDD,
            V16_E08=0xDC,
            V08_E64=0xCF,
            V08_E32=0xCE,
            V08_E16=0XCD,
            V08_E08=0xCC
        };
        enum TpCode: uint8_t{
            TP__NULL=0,
            TP__SIGNED_INT,
            TP__UNSIGNED_INT,
            TP__BOOL,
        };

        namespace VirtualStack{
            namespace V64{
                namespace E64{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint64_t Value;
                        uint64_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V64_E64;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint64_t Value;
                        uint32_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V64_E32;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint64_t Value;
                        uint16_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V64_E16;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint64_t Value;
                        uint8_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V64_E08;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
            };
            namespace V32{
                namespace E64{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint32_t Value;
                        uint64_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V32_E64;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint32_t Value;
                        uint32_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V32_E32;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint32_t Value;
                        uint16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint32_t Value;
                        uint8_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V32_E08;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
            };
            namespace V16{
                namespace E64{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint16_t Value;
                        uint64_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V16_E64;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint16_t Value;
                        uint32_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V16_E32;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint16_t Value;
                        uint16_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V16_E16;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint16_t Value;
                        uint8_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V16_E08;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
            };
            namespace V8{
                namespace E64{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint8_t Value;
                        uint64_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V08_E64;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint8_t Value;
                        uint32_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V08_E32;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint8_t Value;
                        uint16_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V08_E16;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        TpCode Type;
                        uint8_t Value;
                        uint8_t Extended;
                    };
                    const VirtualStack_st NIL_DATA{Sauce::UserLand::TP__NULL,0,0};
                    struct Instruction_st{
                        OpCode opcode;
                        const SzCode szcode=V08_E08;
                        VirtualStack_st Data{NIL_DATA};
                    };
                };
            };
        };


        struct Instruction_st{
           void* MyData=nullptr;

            OpCode MyOpCode;
            SzCode MySzCode;
            
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint8_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint16_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint32_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint64_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint8_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint16_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint32_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint64_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint8_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint16_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint32_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint64_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint8_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint16_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint32_t Extended);
            Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint64_t Extended);
            ~Instruction_st();
            OpCode Get_OpCode();
            SzCode Get_SzCode();
            TpCode Get_TpCode();
            uint8_t& V8();
            uint16_t& V16();
            uint32_t& V32();
            uint64_t& V64();
            uint8_t& E8();
            uint16_t& E16();
            uint32_t& E32();
            uint64_t& E64();
        };




        class VirtualMachine_cl{
            Sauce::Memory::List_cl<VirtualStack::V64::E64::VirtualStack_st> _VirtualStack_64_64; //0xFF
            Sauce::Memory::List_cl<VirtualStack::V64::E32::VirtualStack_st> _VirtualStack_64_32; //0xFE
            Sauce::Memory::List_cl<VirtualStack::V64::E16::VirtualStack_st> _VirtualStack_64_16; //0XFD
            Sauce::Memory::List_cl<VirtualStack::V64::E8::VirtualStack_st>  _VirtualStack_64_08; //0xFC
            Sauce::Memory::List_cl<VirtualStack::V32::E64::VirtualStack_st> _VirtualStack_32_64; //0xEF
            Sauce::Memory::List_cl<VirtualStack::V32::E32::VirtualStack_st> _VirtualStack_32_32; //0xEE
            Sauce::Memory::List_cl<VirtualStack::V32::E16::VirtualStack_st> _VirtualStack_32_16; //0XED
            Sauce::Memory::List_cl<VirtualStack::V32::E8::VirtualStack_st>  _VirtualStack_32_08; //0xEC
            Sauce::Memory::List_cl<VirtualStack::V16::E64::VirtualStack_st> _VirtualStack_16_64; //0xDF
            Sauce::Memory::List_cl<VirtualStack::V16::E32::VirtualStack_st> _VirtualStack_16_32; //0xDE
            Sauce::Memory::List_cl<VirtualStack::V16::E16::VirtualStack_st> _VirtualStack_16_16; //0XDD
            Sauce::Memory::List_cl<VirtualStack::V16::E8::VirtualStack_st>  _VirtualStack_16_08; //0xDC
            Sauce::Memory::List_cl<VirtualStack::V8::E64::VirtualStack_st>  _VirtualStack_08_64; //0xCF
            Sauce::Memory::List_cl<VirtualStack::V8::E32::VirtualStack_st>  _VirtualStack_08_32; //0xCE
            Sauce::Memory::List_cl<VirtualStack::V8::E16::VirtualStack_st>  _VirtualStack_08_16; //0XCD
            Sauce::Memory::List_cl<VirtualStack::V8::E8::VirtualStack_st>   _VirtualStack_08_08; //0xCC
            private:
                void* GetSizedStack(SzCode SizeCode);
                void Clear();
                void AddFirst(TpCode TheType,uint64_t TheValue,uint64_t TheExtended);
                void AddFirst(TpCode TheType,uint64_t TheValue,uint32_t TheExtended);
                void AddFirst(TpCode TheType,uint64_t TheValue,uint16_t TheExtended);
                void AddFirst(TpCode TheType,uint64_t TheValue,uint8_t TheExtended);
                void AddFirst(TpCode TheType,uint32_t TheValue,uint64_t TheExtended);
                void AddFirst(TpCode TheType,uint32_t TheValue,uint32_t TheExtended);
                void AddFirst(TpCode TheType,uint32_t TheValue,uint16_t TheExtended);
                void AddFirst(TpCode TheType,uint32_t TheValue,uint8_t TheExtended);
                void AddFirst(TpCode TheType,uint16_t TheValue,uint64_t TheExtended);
                void AddFirst(TpCode TheType,uint16_t TheValue,uint32_t TheExtended);
                void AddFirst(TpCode TheType,uint16_t TheValue,uint16_t TheExtended);
                void AddFirst(TpCode TheType,uint16_t TheValue,uint8_t TheExtended);
                void AddFirst(TpCode TheType,uint8_t TheValue,uint64_t TheExtended);
                void AddFirst(TpCode TheType,uint8_t TheValue,uint32_t TheExtended);
                void AddFirst(TpCode TheType,uint8_t TheValue,uint16_t TheExtended);
                void AddFirst(TpCode TheType,uint8_t TheValue,uint8_t TheExtended);
                void AddLast(TpCode TheType,uint64_t TheValue,uint64_t TheExtended);
                void AddLast(TpCode TheType,uint64_t TheValue,uint32_t TheExtended);
                void AddLast(TpCode TheType,uint64_t TheValue,uint16_t TheExtended);
                void AddLast(TpCode TheType,uint64_t TheValue,uint8_t TheExtended);
                void AddLast(TpCode TheType,uint32_t TheValue,uint64_t TheExtended);
                void AddLast(TpCode TheType,uint32_t TheValue,uint32_t TheExtended);
                void AddLast(TpCode TheType,uint32_t TheValue,uint16_t TheExtended);
                void AddLast(TpCode TheType,uint32_t TheValue,uint8_t TheExtended);
                void AddLast(TpCode TheType,uint16_t TheValue,uint64_t TheExtended);
                void AddLast(TpCode TheType,uint16_t TheValue,uint32_t TheExtended);
                void AddLast(TpCode TheType,uint16_t TheValue,uint16_t TheExtended);
                void AddLast(TpCode TheType,uint16_t TheValue,uint8_t TheExtended);
                void AddLast(TpCode TheType,uint8_t TheValue,uint64_t TheExtended);
                void AddLast(TpCode TheType,uint8_t TheValue,uint32_t TheExtended);
                void AddLast(TpCode TheType,uint8_t TheValue,uint16_t TheExtended);
                void AddLast(TpCode TheType,uint8_t TheValue,uint8_t TheExtended);
                void AddLast(Instruction_st &TheInstruction);
                void AddFirst(Instruction_st &TheInstruction);
                void RemoveFirst(SzCode TheSizecode);
                void RemoveLast(SzCode TheSizecode);
                void GetFirst(TpCode &TheType,uint64_t &TheValue,uint64_t &TheExtended);
                void GetFirst(TpCode &TheType,uint64_t &TheValue,uint32_t &TheExtended);
                void GetFirst(TpCode &TheType,uint64_t &TheValue,uint16_t &TheExtended);
                void GetFirst(TpCode &TheType,uint64_t &TheValue,uint8_t &TheExtended);
                void GetFirst(TpCode &TheType,uint32_t &TheValue,uint64_t &TheExtended);
                void GetFirst(TpCode &TheType,uint32_t &TheValue,uint32_t &TheExtended);
                void GetFirst(TpCode &TheType,uint32_t &TheValue,uint16_t &TheExtended);
                void GetFirst(TpCode &TheType,uint32_t &TheValue,uint8_t &TheExtended);
                void GetFirst(TpCode &TheType,uint16_t &TheValue,uint64_t &TheExtended);
                void GetFirst(TpCode &TheType,uint16_t &TheValue,uint32_t &TheExtended);
                void GetFirst(TpCode &TheType,uint16_t &TheValue,uint16_t &TheExtended);
                void GetFirst(TpCode &TheType,uint16_t &TheValue,uint8_t &TheExtended);
                void GetFirst(TpCode &TheType,uint8_t &TheValue,uint64_t &TheExtended);
                void GetFirst(TpCode &TheType,uint8_t &TheValue,uint32_t &TheExtended);
                void GetFirst(TpCode &TheType,uint8_t &TheValue,uint16_t &TheExtended);
                void GetFirst(TpCode &TheType,uint8_t &TheValue,uint8_t &TheExtended);
                void GetLast(TpCode &TheType,uint64_t &TheValue,uint64_t &TheExtended);
                void GetLast(TpCode &TheType,uint64_t &TheValue,uint32_t &TheExtended);
                void GetLast(TpCode &TheType,uint64_t &TheValue,uint16_t &TheExtended);
                void GetLast(TpCode &TheType,uint64_t &TheValue,uint8_t &TheExtended);
                void GetLast(TpCode &TheType,uint32_t &TheValue,uint64_t &TheExtended);
                void GetLast(TpCode &TheType,uint32_t &TheValue,uint32_t &TheExtended);
                void GetLast(TpCode &TheType,uint32_t &TheValue,uint16_t &TheExtended);
                void GetLast(TpCode &TheType,uint32_t &TheValue,uint8_t &TheExtended);
                void GetLast(TpCode &TheType,uint16_t &TheValue,uint64_t &TheExtended);
                void GetLast(TpCode &TheType,uint16_t &TheValue,uint32_t &TheExtended);
                void GetLast(TpCode &TheType,uint16_t &TheValue,uint16_t &TheExtended);
                void GetLast(TpCode &TheType,uint16_t &TheValue,uint8_t &TheExtended);
                void GetLast(TpCode &TheType,uint8_t &TheValue,uint64_t &TheExtended);
                void GetLast(TpCode &TheType,uint8_t &TheValue,uint32_t &TheExtended);
                void GetLast(TpCode &TheType,uint8_t &TheValue,uint16_t &TheExtended);
                void GetLast(TpCode &TheType,uint8_t &TheValue,uint8_t &TheExtended);
                void GetLast(Instruction_st &TheInstruction);
                void GetFirst(Instruction_st &TheInstruction);
                void Clone(SzCode FromStack,SzCode ToStack);
                void MathematicalAdd(Instruction_st &aStack,Instruction_st &bStack);
                void Print(Instruction_st &TheInstruction);
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
        };
    };
};

/*
(OpCode [32]bits)(SzCode [8]bits)(Data (Type [8]bits) (Value [8,16,32,64]bits) (Extended [8,16,32,64]bits))

Example: push (32bit value 16bit extended) unsigned int;

ExampleCode.AddLast({OpCode::OP__PUSH,SzCode::V32_E16,{TpCode::TP__UNSIGNED_INT,0x12345678,0x1458}})

*/