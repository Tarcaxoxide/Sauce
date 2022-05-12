#include<Sauce/UserLand/VirtualMachine.hpp>


namespace Sauce{
    namespace UserLand{
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint8_t Extended){
            MySzCode=V08_E08;
            MyData = new VirtualStack::V8::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint16_t Extended){
            MySzCode=V08_E16;
            MyData = new VirtualStack::V8::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint32_t Extended){
            MySzCode=V08_E32;
            MyData = new VirtualStack::V8::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint8_t Value,uint64_t Extended){
            MySzCode=V08_E64;
            MyData = new VirtualStack::V8::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint8_t Extended){
            MySzCode=V16_E08;
            MyData = new VirtualStack::V16::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint16_t Extended){
            MySzCode=V16_E16;
            MyData = new VirtualStack::V16::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint32_t Extended){
            MySzCode=V16_E32;
            MyData = new VirtualStack::V16::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint16_t Value,uint64_t Extended){
            MySzCode=V16_E64;
            MyData = new VirtualStack::V16::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint8_t Extended){
            MySzCode=V32_E08;
            MyData = new VirtualStack::V32::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint16_t Extended){
            MySzCode=V32_E16;
            MyData = new VirtualStack::V32::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint32_t Extended){
            MySzCode=V32_E32;
            MyData = new VirtualStack::V32::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint32_t Value,uint64_t Extended){
            MySzCode=V32_E64;
            MyData = new VirtualStack::V32::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint8_t Extended){
            MySzCode=V64_E08;
            MyData = new VirtualStack::V64::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint16_t Extended){
            MySzCode=V64_E16;
            MyData = new VirtualStack::V64::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint32_t Extended){
            MySzCode=V64_E32;
            MyData = new VirtualStack::V64::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,uint64_t Value,uint64_t Extended){
            MySzCode=V64_E64;
            MyData = new VirtualStack::V64::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::~Instruction_st(){
            delete[] MyData;
        }
        OpCode Instruction_st::Get_OpCode(){
            return MyOpCode;
        }
        SzCode Instruction_st::Get_SzCode(){
            return MySzCode;
        }
        uint8_t Instruction_st::V8(){}
        uint16_t Instruction_st::V16(){}
        uint32_t Instruction_st::V32(){}
        uint64_t Instruction_st::V64(){}
        uint8_t Instruction_st::E8(){}
        uint16_t Instruction_st::E16(){}
        uint32_t Instruction_st::E32(){}
        uint64_t Instruction_st::E64(){}

        void* VirtualMachine_cl::GetSizedStack(SzCode SizeCode){
            switch(SizeCode){
                case SzCode::V64_E64:return (void*)&_VirtualStack_64_64;
                case SzCode::V64_E32:return (void*)&_VirtualStack_64_32;
                case SzCode::V64_E16:return (void*)&_VirtualStack_64_16;
                case SzCode::V64_E08:return (void*)&_VirtualStack_64_08;
                case SzCode::V32_E64:return (void*)&_VirtualStack_32_64;
                case SzCode::V32_E32:return (void*)&_VirtualStack_32_32;
                case SzCode::V32_E16:return (void*)&_VirtualStack_32_16;
                case SzCode::V32_E08:return (void*)&_VirtualStack_32_08;
                case SzCode::V16_E64:return (void*)&_VirtualStack_16_64;
                case SzCode::V16_E32:return (void*)&_VirtualStack_16_32;
                case SzCode::V16_E16:return (void*)&_VirtualStack_16_16;
                case SzCode::V16_E08:return (void*)&_VirtualStack_16_08;
                case SzCode::V08_E64:return (void*)&_VirtualStack_08_64;
                case SzCode::V08_E32:return (void*)&_VirtualStack_08_32;
                case SzCode::V08_E16:return (void*)&_VirtualStack_08_16;
                case SzCode::V08_E08:return (void*)&_VirtualStack_08_08;
            }

            return (void*)nullptr;
        }
        VirtualMachine_cl::VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code){
            for(size_t InstructionCounter=0;InstructionCounter<code.Size();InstructionCounter++){}
            
        }
    };
};