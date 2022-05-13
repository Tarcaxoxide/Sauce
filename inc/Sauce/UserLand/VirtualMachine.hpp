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
            TP__INT,
            TP__BOOL,
        };

        namespace VirtualStack{
            namespace V64{
                namespace E64{
                    struct VirtualStack_st{
                        TpCode Type;
                        int64_t Value;
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
                        int64_t Value;
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
                        int64_t Value;
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
                        int64_t Value;
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
                        int32_t Value;
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
                        int32_t Value;
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
                        int32_t Value;
                        uint16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        TpCode Type;
                        int32_t Value;
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
                        int16_t Value;
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
                        int16_t Value;
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
                        int16_t Value;
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
                        int16_t Value;
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
                        int8_t Value;
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
                        int8_t Value;
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
                        int8_t Value;
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
                        int8_t Value;
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
            
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint8_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint16_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint32_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint64_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint8_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint16_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint32_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint64_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint8_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint16_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint32_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint64_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint8_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint16_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint32_t Extended);
            void Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint64_t Extended);
            Instruction_st(){}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int8_t _Value,uint8_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int8_t _Value,uint16_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int8_t _Value,uint32_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int8_t _Value,uint64_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int16_t _Value,uint8_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int16_t _Value,uint16_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int16_t _Value,uint32_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int16_t _Value,uint64_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int32_t _Value,uint8_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int32_t _Value,uint16_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int32_t _Value,uint32_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int32_t _Value,uint64_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int64_t _Value,uint8_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int64_t _Value,uint16_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int64_t _Value,uint32_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(OpCode _MyOpCode,TpCode _MyTypeCode,int64_t _Value,uint64_t _Extended){Init(_MyOpCode,_MyTypeCode,_Value,_Extended);}
            Instruction_st(void* Data){MyData=Data;}


            ~Instruction_st();
            OpCode& Get_OpCode();
            SzCode& Get_SzCode();
            TpCode& Get_TpCode();
            int8_t& V8();
            int16_t& V16();
            int32_t& V32();
            int64_t& V64();
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
                void AddFirst_64_64(Instruction_st &TheInstruction);
                void AddFirst_64_32(Instruction_st &TheInstruction);
                void AddFirst_64_16(Instruction_st &TheInstruction);
                void AddFirst_64_08(Instruction_st &TheInstruction);
                void AddFirst_32_64(Instruction_st &TheInstruction);
                void AddFirst_32_32(Instruction_st &TheInstruction);
                void AddFirst_32_16(Instruction_st &TheInstruction);
                void AddFirst_32_08(Instruction_st &TheInstruction);
                void AddFirst_16_64(Instruction_st &TheInstruction);
                void AddFirst_16_32(Instruction_st &TheInstruction);
                void AddFirst_16_16(Instruction_st &TheInstruction);
                void AddFirst_16_08(Instruction_st &TheInstruction);
                void AddFirst_08_64(Instruction_st &TheInstruction);
                void AddFirst_08_32(Instruction_st &TheInstruction);
                void AddFirst_08_16(Instruction_st &TheInstruction);
                void AddFirst_08_08(Instruction_st &TheInstruction);
                 void AddLast_64_64(Instruction_st &TheInstruction);
                 void AddLast_64_32(Instruction_st &TheInstruction);
                 void AddLast_64_16(Instruction_st &TheInstruction);
                 void AddLast_64_08(Instruction_st &TheInstruction);
                 void AddLast_32_64(Instruction_st &TheInstruction);
                 void AddLast_32_32(Instruction_st &TheInstruction);
                 void AddLast_32_16(Instruction_st &TheInstruction);
                 void AddLast_32_08(Instruction_st &TheInstruction);
                 void AddLast_16_64(Instruction_st &TheInstruction);
                 void AddLast_16_32(Instruction_st &TheInstruction);
                 void AddLast_16_16(Instruction_st &TheInstruction);
                 void AddLast_16_08(Instruction_st &TheInstruction);
                 void AddLast_08_64(Instruction_st &TheInstruction);
                 void AddLast_08_32(Instruction_st &TheInstruction);
                 void AddLast_08_16(Instruction_st &TheInstruction);
                 void AddLast_08_08(Instruction_st &TheInstruction);
                void AddLast(Instruction_st &TheInstruction);
                void AddFirst(Instruction_st &TheInstruction);
                void RemoveFirst(SzCode TheSizecode);
                void RemoveLast(SzCode TheSizecode);
                void GetFirst_64_64(Instruction_st &TheInstruction);
                void GetFirst_64_32(Instruction_st &TheInstruction);
                void GetFirst_64_16(Instruction_st &TheInstruction);
                void GetFirst_64_08(Instruction_st &TheInstruction);
                void GetFirst_32_64(Instruction_st &TheInstruction);
                void GetFirst_32_32(Instruction_st &TheInstruction);
                void GetFirst_32_16(Instruction_st &TheInstruction);
                void GetFirst_32_08(Instruction_st &TheInstruction);
                void GetFirst_16_64(Instruction_st &TheInstruction);
                void GetFirst_16_32(Instruction_st &TheInstruction);
                void GetFirst_16_16(Instruction_st &TheInstruction);
                void GetFirst_16_08(Instruction_st &TheInstruction);
                void GetFirst_08_64(Instruction_st &TheInstruction);
                void GetFirst_08_32(Instruction_st &TheInstruction);
                void GetFirst_08_16(Instruction_st &TheInstruction);
                void GetFirst_08_08(Instruction_st &TheInstruction);
                 void GetLast_64_64(Instruction_st &TheInstruction);
                 void GetLast_64_32(Instruction_st &TheInstruction);
                 void GetLast_64_16(Instruction_st &TheInstruction);
                 void GetLast_64_08(Instruction_st &TheInstruction);
                 void GetLast_32_64(Instruction_st &TheInstruction);
                 void GetLast_32_32(Instruction_st &TheInstruction);
                 void GetLast_32_16(Instruction_st &TheInstruction);
                 void GetLast_32_08(Instruction_st &TheInstruction);
                 void GetLast_16_64(Instruction_st &TheInstruction);
                 void GetLast_16_32(Instruction_st &TheInstruction);
                 void GetLast_16_16(Instruction_st &TheInstruction);
                 void GetLast_16_08(Instruction_st &TheInstruction);
                 void GetLast_08_64(Instruction_st &TheInstruction);
                 void GetLast_08_32(Instruction_st &TheInstruction);
                 void GetLast_08_16(Instruction_st &TheInstruction);
                 void GetLast_08_08(Instruction_st &TheInstruction);
                void GetLast(Instruction_st &TheInstruction);
                void GetFirst(Instruction_st &TheInstruction);
                void Clone(SzCode FromStack,SzCode ToStack);
                void MathematicalAdd(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalSubtract(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalMultiply(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalDivide(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalModulus(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalMore(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalLess(Instruction_st &aStack,Instruction_st &bStack);
                void MathematicalSame(Instruction_st &aStack,Instruction_st &bStack);
                void Print(Instruction_st &TheInstruction);
            public:
            VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);
        };
    };
};

