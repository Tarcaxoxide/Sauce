#pragma once

#include<stddef.h>
#include<stdint.h>

#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace UserLand{
        enum OpCode: uint32_t{
            OP__NULL=0x00000000,
            OP__EXIT=0x00000001,
            OP__ADD=0x00000002,
            OP__SUBTRACT=0x00000003,
            OP__MULTIPLY=0x00000004,
            OP__DIVIDE=0x00000005,
            OP__MODULUS=0x00000006,
            OP__MORE_THAN=0x00000007,
            OP__LESS_THAN=0x00000008,
            OP__EQUALS=0x00000009,
            OP__PUSH=0x0000000A,
            OP__PRINT=0x0000000B,
            OP__IF_JUMP=0x0000000C,
            OP__JUMP=0x0000000D,
            OP__CLONE=0x0000000F,
            OP__SWITCH=0x00000010,
            OP__DATA=0x00000011
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
            V08_E08=0xCC,
            SZ__NULL=0x00
        };
        enum TpCode: uint8_t{
            TP__NULL=0x00,
            TP__INT=0x01,
            TP__BOOL=0x02,
        };

        namespace VirtualStack{
            namespace V64{
                namespace E64{
                    struct VirtualStack_st{
                        int64_t Value;
                        int64_t Extended;
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        int64_t Value;
                        int32_t Extended;
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        int64_t Value;
                        int16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        int64_t Value;
                        int8_t Extended;
                    };
                };
            };
            namespace V32{
                namespace E64{
                    struct VirtualStack_st{
                        int32_t Value;
                        int64_t Extended;
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        int32_t Value;
                        int32_t Extended;
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        int32_t Value;
                        int16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        int32_t Value;
                        int8_t Extended;
                    };
                };
            };
            namespace V16{
                namespace E64{
                    struct VirtualStack_st{
                        int16_t Value;
                        int64_t Extended;
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        int16_t Value;
                        int32_t Extended;
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        int16_t Value;
                        int16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        int16_t Value;
                        int8_t Extended;
                    };
                };
            };
            namespace V8{
                namespace E64{
                    struct VirtualStack_st{
                        int8_t Value;
                        int64_t Extended;
                    };
                };
                namespace E32{
                    struct VirtualStack_st{
                        int8_t Value;
                        int32_t Extended;
                    };
                };
                namespace E16{
                    struct VirtualStack_st{
                        int8_t Value;
                        int16_t Extended;
                    };
                };
                namespace E8{
                    struct VirtualStack_st{
                        int8_t Value=0;
                        int8_t Extended=0;
                    };
                };
            };
        };


        template<class VS_Type>
        struct VirtualStack_st{
            OpCode opcode=OpCode::OP__NULL;
            TpCode Type=TpCode::TP__NULL;
            SzCode szcode=SzCode::SZ__NULL;
            VS_Type Data;
        };


        class VirtualMachine_cl{
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>> _VirtualStack_64_64; //0xFF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>> _VirtualStack_64_32; //0xFE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>> _VirtualStack_64_16; //0XFD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>>  _VirtualStack_64_08; //0xFC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>> _VirtualStack_32_64; //0xEF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>> _VirtualStack_32_32; //0xEE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>> _VirtualStack_32_16; //0XED
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>>  _VirtualStack_32_08; //0xEC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>> _VirtualStack_16_64; //0xDF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>> _VirtualStack_16_32; //0xDE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>> _VirtualStack_16_16; //0XDD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>>  _VirtualStack_16_08; //0xDC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>>  _VirtualStack_08_64; //0xCF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>>  _VirtualStack_08_32; //0xCE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>>  _VirtualStack_08_16; //0XCD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>>   _VirtualStack_08_08; //0xCC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>> _VirtualInstructions_64_64; //0xFF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>> _VirtualInstructions_64_32; //0xFE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>> _VirtualInstructions_64_16; //0XFD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>>  _VirtualInstructions_64_08; //0xFC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>> _VirtualInstructions_32_64; //0xEF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>> _VirtualInstructions_32_32; //0xEE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>> _VirtualInstructions_32_16; //0XED
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>>  _VirtualInstructions_32_08; //0xEC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>> _VirtualInstructions_16_64; //0xDF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>> _VirtualInstructions_16_32; //0xDE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>> _VirtualInstructions_16_16; //0XDD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>>  _VirtualInstructions_16_08; //0xDC
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>>  _VirtualInstructions_08_64; //0xCF
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>>  _VirtualInstructions_08_32; //0xCE
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>>  _VirtualInstructions_08_16; //0XCD
            Sauce::Memory::List_cl<VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>>   _VirtualInstructions_08_08; //0xCC
            size_t InstructionCounter_64_64=0;
            size_t InstructionCounter_64_32=0;
            size_t InstructionCounter_64_16=0;
            size_t InstructionCounter_64_08=0;
            size_t InstructionCounter_32_64=0;
            size_t InstructionCounter_32_32=0;
            size_t InstructionCounter_32_16=0;
            size_t InstructionCounter_32_08=0;
            size_t InstructionCounter_16_64=0;
            size_t InstructionCounter_16_32=0;
            size_t InstructionCounter_16_16=0;
            size_t InstructionCounter_16_08=0;
            size_t InstructionCounter_08_64=0;
            size_t InstructionCounter_08_32=0;
            size_t InstructionCounter_08_16=0;
            size_t InstructionCounter_08_08=0;
            SzCode CurrentSizeCode=SzCode::V08_E08;
            void* CurrentInstruction=nullptr;
            bool hasEnd=false;
            private:
                void AddInstruction_64_64(OpCode opcode,TpCode tpcode,int64_t value=0,int64_t extended=0);
                void AddInstruction_64_32(OpCode opcode,TpCode tpcode,int64_t value=0,int32_t extended=0);
                void AddInstruction_64_16(OpCode opcode,TpCode tpcode,int64_t value=0,int16_t extended=0);
                void AddInstruction_64_08(OpCode opcode,TpCode tpcode,int64_t value=0,int8_t extended=0);
                void AddInstruction_32_64(OpCode opcode,TpCode tpcode,int32_t value=0,int64_t extended=0);
                void AddInstruction_32_32(OpCode opcode,TpCode tpcode,int32_t value=0,int32_t extended=0);
                void AddInstruction_32_16(OpCode opcode,TpCode tpcode,int32_t value=0,int16_t extended=0);
                void AddInstruction_32_08(OpCode opcode,TpCode tpcode,int32_t value=0,int8_t extended=0);
                void AddInstruction_16_64(OpCode opcode,TpCode tpcode,int16_t value=0,int64_t extended=0);
                void AddInstruction_16_32(OpCode opcode,TpCode tpcode,int16_t value=0,int32_t extended=0);
                void AddInstruction_16_16(OpCode opcode,TpCode tpcode,int16_t value=0,int16_t extended=0);
                void AddInstruction_16_08(OpCode opcode,TpCode tpcode,int16_t value=0,int8_t extended=0);
                void AddInstruction_08_64(OpCode opcode,TpCode tpcode,int8_t value=0,int64_t extended=0);
                void AddInstruction_08_32(OpCode opcode,TpCode tpcode,int8_t value=0,int32_t extended=0);
                void AddInstruction_08_16(OpCode opcode,TpCode tpcode,int8_t value=0,int16_t extended=0);
                void AddInstruction_08_08(OpCode opcode,TpCode tpcode,int8_t value=0,int8_t extended=0);
                void AddToVirtualStack_64_64(OpCode opcode,TpCode tpcode,int64_t value=0,int64_t extended=0);
                void AddToVirtualStack_64_32(OpCode opcode,TpCode tpcode,int64_t value=0,int32_t extended=0);
                void AddToVirtualStack_64_16(OpCode opcode,TpCode tpcode,int64_t value=0,int16_t extended=0);
                void AddToVirtualStack_64_08(OpCode opcode,TpCode tpcode,int64_t value=0,int8_t extended=0);
                void AddToVirtualStack_32_64(OpCode opcode,TpCode tpcode,int32_t value=0,int64_t extended=0);
                void AddToVirtualStack_32_32(OpCode opcode,TpCode tpcode,int32_t value=0,int32_t extended=0);
                void AddToVirtualStack_32_16(OpCode opcode,TpCode tpcode,int32_t value=0,int16_t extended=0);
                void AddToVirtualStack_32_08(OpCode opcode,TpCode tpcode,int32_t value=0,int8_t extended=0);
                void AddToVirtualStack_16_64(OpCode opcode,TpCode tpcode,int16_t value=0,int64_t extended=0);
                void AddToVirtualStack_16_32(OpCode opcode,TpCode tpcode,int16_t value=0,int32_t extended=0);
                void AddToVirtualStack_16_16(OpCode opcode,TpCode tpcode,int16_t value=0,int16_t extended=0);
                void AddToVirtualStack_16_08(OpCode opcode,TpCode tpcode,int16_t value=0,int8_t extended=0);
                void AddToVirtualStack_08_64(OpCode opcode,TpCode tpcode,int8_t value=0,int64_t extended=0);
                void AddToVirtualStack_08_32(OpCode opcode,TpCode tpcode,int8_t value=0,int32_t extended=0);
                void AddToVirtualStack_08_16(OpCode opcode,TpCode tpcode,int8_t value=0,int16_t extended=0);
                void AddToVirtualStack_08_08(OpCode opcode,TpCode tpcode,int8_t value=0,int8_t extended=0);
                VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> GetLastFromVirtualStack_64_64();
                VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> GetLastFromVirtualStack_64_32();
                VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> GetLastFromVirtualStack_64_16();
                VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  GetLastFromVirtualStack_64_08();
                VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> GetLastFromVirtualStack_32_64();
                VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> GetLastFromVirtualStack_32_32();
                VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> GetLastFromVirtualStack_32_16();
                VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  GetLastFromVirtualStack_32_08();
                VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> GetLastFromVirtualStack_16_64();
                VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> GetLastFromVirtualStack_16_32();
                VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> GetLastFromVirtualStack_16_16();
                VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  GetLastFromVirtualStack_16_08();
                VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  GetLastFromVirtualStack_08_64();
                VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  GetLastFromVirtualStack_08_32();
                VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  GetLastFromVirtualStack_08_16();
                VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   GetLastFromVirtualStack_08_08();
                VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> GetFirstFromVirtualStack_64_64();
                VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> GetFirstFromVirtualStack_64_32();
                VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> GetFirstFromVirtualStack_64_16();
                VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  GetFirstFromVirtualStack_64_08();
                VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> GetFirstFromVirtualStack_32_64();
                VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> GetFirstFromVirtualStack_32_32();
                VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> GetFirstFromVirtualStack_32_16();
                VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  GetFirstFromVirtualStack_32_08();
                VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> GetFirstFromVirtualStack_16_64();
                VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> GetFirstFromVirtualStack_16_32();
                VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> GetFirstFromVirtualStack_16_16();
                VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  GetFirstFromVirtualStack_16_08();
                VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  GetFirstFromVirtualStack_08_64();
                VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  GetFirstFromVirtualStack_08_32();
                VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  GetFirstFromVirtualStack_08_16();
                VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   GetFirstFromVirtualStack_08_08();
                VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> GetFromVirtualInstructions_64_64(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> GetFromVirtualInstructions_64_32(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> GetFromVirtualInstructions_64_16(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  GetFromVirtualInstructions_64_08(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> GetFromVirtualInstructions_32_64(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> GetFromVirtualInstructions_32_32(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> GetFromVirtualInstructions_32_16(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  GetFromVirtualInstructions_32_08(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> GetFromVirtualInstructions_16_64(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> GetFromVirtualInstructions_16_32(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> GetFromVirtualInstructions_16_16(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  GetFromVirtualInstructions_16_08(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  GetFromVirtualInstructions_08_64(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  GetFromVirtualInstructions_08_32(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  GetFromVirtualInstructions_08_16(size_t ThisInstructionCounter);
                VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   GetFromVirtualInstructions_08_08(size_t ThisInstructionCounter);
            public:
                void GetInstruction();
                bool RunInstruction();
                void Run();
                void AddEnd();
                void RemoveEnd();
                void AddInstruction(SzCode szcode,OpCode opcode,TpCode tpcode,int8_t value=0,int8_t extended=0);
                void AddToVirtualStack(SzCode szcode,OpCode opcode,TpCode tpcode,int8_t value=0,int8_t extended=0);

                void RemoveFromVirtualStack(SzCode szcode);

                void GetValueFromVirtualInstructions(SzCode szcode,int8_t &value,size_t ThisInstructionCounter);
                void GetValueFromVirtualInstructions(SzCode szcode,int16_t &value,size_t ThisInstructionCounter);
                void GetValueFromVirtualInstructions(SzCode szcode,int32_t &value,size_t ThisInstructionCounter);
                void GetValueFromVirtualInstructions(SzCode szcode,int64_t &value,size_t ThisInstructionCounter);
                void GetExtendedFromVirtualInstructions(SzCode szcode,int8_t &extended,size_t ThisInstructionCounter);
                void GetExtendedFromVirtualInstructions(SzCode szcode,int16_t &extended,size_t ThisInstructionCounter);
                void GetExtendedFromVirtualInstructions(SzCode szcode,int32_t &extended,size_t ThisInstructionCounter);
                void GetExtendedFromVirtualInstructions(SzCode szcode,int64_t &extended,size_t ThisInstructionCounter);
                void GetValueFromVirtualStack(SzCode szcode,int8_t &value);
                void GetValueFromVirtualStack(SzCode szcode,int16_t &value);
                void GetValueFromVirtualStack(SzCode szcode,int32_t &value);
                void GetValueFromVirtualStack(SzCode szcode,int64_t &value);
                void GetExtendedFromVirtualStack(SzCode szcode,int8_t &extended);
                void GetExtendedFromVirtualStack(SzCode szcode,int16_t &extended);
                void GetExtendedFromVirtualStack(SzCode szcode,int32_t &extended);
                void GetExtendedFromVirtualStack(SzCode szcode,int64_t &extended);
                void GetTpCodeFromVirtualStack(SzCode szcode,TpCode &tpcode);
                void GetTpCodeFromVirtualInstructions(SzCode szcode,TpCode &tpcode,size_t ThisInstructionCounter);

                void PushToStack(SzCode Instruction_szcode,size_t ThisInstructionCounter);
        };
    };
};

