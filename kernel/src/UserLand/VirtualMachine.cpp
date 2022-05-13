#include<Sauce/UserLand/VirtualMachine.hpp>
#include<Sauce/Memory/Heap.hpp>


namespace Sauce{
    namespace UserLand{
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint8_t Extended){
            MySzCode=V08_E08;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V8::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint16_t Extended){
            MySzCode=V08_E16;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V8::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint32_t Extended){
            MySzCode=V08_E32;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V8::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint64_t Extended){
            MySzCode=V08_E64;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V8::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint8_t Extended){
            MySzCode=V16_E08;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V16::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint16_t Extended){
            MySzCode=V16_E16;
            MyData = new VirtualStack::V16::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint32_t Extended){
            MySzCode=V16_E32;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V16::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint64_t Extended){
            MySzCode=V16_E64;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V16::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint8_t Extended){
            MySzCode=V32_E08;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V32::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint16_t Extended){
            MySzCode=V32_E16;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V32::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint32_t Extended){
            MySzCode=V32_E32;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V32::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint64_t Extended){
            MySzCode=V32_E64;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V32::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint8_t Extended){
            MySzCode=V64_E08;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V64::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint16_t Extended){
            MySzCode=V64_E16;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V64::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint32_t Extended){
            MySzCode=V64_E32;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V64::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        void Instruction_st::Init(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint64_t Extended){
            MySzCode=V64_E64;
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
            MyData = new VirtualStack::V64::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::~Instruction_st(){
            if(MyData != nullptr){delete[] MyData;MyData=nullptr;}
        }
        OpCode& Instruction_st::Get_OpCode(){
            return MyOpCode;
        }
        SzCode& Instruction_st::Get_SzCode(){
            return MySzCode;
        }
        TpCode& Instruction_st::Get_TpCode(){
            switch(MySzCode){
                case SzCode::V64_E64:return ((VirtualStack::V64::E64::VirtualStack_st*)MyData)->Type;
                case SzCode::V64_E32:return ((VirtualStack::V64::E32::VirtualStack_st*)MyData)->Type;
                case SzCode::V64_E16:return ((VirtualStack::V64::E16::VirtualStack_st*)MyData)->Type;
                case SzCode::V64_E08:return ((VirtualStack::V64::E8::VirtualStack_st*)MyData)->Type; 
                case SzCode::V32_E64:return ((VirtualStack::V32::E64::VirtualStack_st*)MyData)->Type;
                case SzCode::V32_E32:return ((VirtualStack::V32::E32::VirtualStack_st*)MyData)->Type;
                case SzCode::V32_E16:return ((VirtualStack::V32::E16::VirtualStack_st*)MyData)->Type;
                case SzCode::V32_E08:return ((VirtualStack::V32::E8::VirtualStack_st*)MyData)->Type;
                case SzCode::V16_E64:return ((VirtualStack::V16::E64::VirtualStack_st*)MyData)->Type;
                case SzCode::V16_E32:return ((VirtualStack::V16::E32::VirtualStack_st*)MyData)->Type;
                case SzCode::V16_E16:return ((VirtualStack::V16::E16::VirtualStack_st*)MyData)->Type;
                case SzCode::V16_E08:return ((VirtualStack::V16::E8::VirtualStack_st*)MyData)->Type; 
                case SzCode::V08_E64:return ((VirtualStack::V8::E64::VirtualStack_st*)MyData)->Type;
                case SzCode::V08_E32:return ((VirtualStack::V8::E32::VirtualStack_st*)MyData)->Type;
                case SzCode::V08_E16:return ((VirtualStack::V8::E16::VirtualStack_st*)MyData)->Type;
                case SzCode::V08_E08:return ((VirtualStack::V8::E8::VirtualStack_st*)MyData)->Type; 
            }
        }
        int8_t& Instruction_st::V8(){
            switch(MySzCode){
                case SzCode::V08_E64:return ((VirtualStack::V8::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E32:return ((VirtualStack::V8::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E16:return ((VirtualStack::V8::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E08:return ((VirtualStack::V8::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        int16_t& Instruction_st::V16(){
            switch(MySzCode){
                case SzCode::V16_E64:return ((VirtualStack::V16::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E32:return ((VirtualStack::V16::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E16:return ((VirtualStack::V16::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E08:return ((VirtualStack::V16::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        int32_t& Instruction_st::V32(){
            switch(MySzCode){
                case SzCode::V32_E64:return ((VirtualStack::V32::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E32:return ((VirtualStack::V32::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E16:return ((VirtualStack::V32::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E08:return ((VirtualStack::V32::E8::VirtualStack_st*)MyData)->Value;
            }
        }
        int64_t& Instruction_st::V64(){
            switch(MySzCode){
                case SzCode::V64_E64:return ((VirtualStack::V64::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E32:return ((VirtualStack::V64::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E16:return ((VirtualStack::V64::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E08:return ((VirtualStack::V64::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        uint8_t& Instruction_st::E8(){
            switch(MySzCode){
                case SzCode::V64_E08:return ((VirtualStack::V64::E8::VirtualStack_st*)MyData)->Extended; 
                case SzCode::V32_E08:return ((VirtualStack::V32::E8::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E08:return ((VirtualStack::V16::E8::VirtualStack_st*)MyData)->Extended; 
                case SzCode::V08_E08:return ((VirtualStack::V8::E8::VirtualStack_st*)MyData)->Extended; 
            }
        }
        uint16_t& Instruction_st::E16(){
            switch(MySzCode){
                case SzCode::V64_E16:return ((VirtualStack::V64::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V32_E16:return ((VirtualStack::V32::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E16:return ((VirtualStack::V16::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V08_E16:return ((VirtualStack::V8::E16::VirtualStack_st*)MyData)->Extended;
            }
        }
        uint32_t& Instruction_st::E32(){
            switch(MySzCode){
                case SzCode::V64_E32:return ((VirtualStack::V64::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V32_E32:return ((VirtualStack::V32::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E32:return ((VirtualStack::V16::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V08_E32:return ((VirtualStack::V8::E32::VirtualStack_st*)MyData)->Extended;
            }
        }
        uint64_t& Instruction_st::E64(){
            switch(MySzCode){
                case SzCode::V64_E64:return ((VirtualStack::V64::E64::VirtualStack_st*)MyData)->Extended;
                case SzCode::V32_E64:return ((VirtualStack::V32::E64::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E64:return ((VirtualStack::V16::E64::VirtualStack_st*)MyData)->Extended;
                case SzCode::V08_E64:return ((VirtualStack::V8::E64::VirtualStack_st*)MyData)->Extended;
            }
        }

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
        void VirtualMachine_cl::Clear(){
            _VirtualStack_64_64.Clear();
            _VirtualStack_64_32.Clear();
            _VirtualStack_64_16.Clear();
            _VirtualStack_64_08.Clear();
            _VirtualStack_32_64.Clear();
            _VirtualStack_32_32.Clear();
            _VirtualStack_32_16.Clear();
            _VirtualStack_32_08.Clear();
            _VirtualStack_16_64.Clear();
            _VirtualStack_16_32.Clear();
            _VirtualStack_16_16.Clear();
            _VirtualStack_16_08.Clear();
            _VirtualStack_08_64.Clear();
            _VirtualStack_08_32.Clear();
            _VirtualStack_08_16.Clear();
            _VirtualStack_08_08.Clear();
        }
        void VirtualMachine_cl::AddFirst_64_64(Instruction_st &TheInstruction){
            _VirtualStack_64_64.AddFirst( *((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_64_32(Instruction_st &TheInstruction){
            _VirtualStack_64_32.AddFirst( *((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_64_16(Instruction_st &TheInstruction){
            _VirtualStack_64_16.AddFirst( *((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_64_08(Instruction_st &TheInstruction){
            _VirtualStack_64_08.AddFirst( *((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_32_64(Instruction_st &TheInstruction){
            _VirtualStack_32_64.AddFirst( *((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_32_32(Instruction_st &TheInstruction){
            _VirtualStack_32_32.AddFirst( *((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_32_16(Instruction_st &TheInstruction){
            _VirtualStack_32_16.AddFirst( *((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_32_08(Instruction_st &TheInstruction){
            _VirtualStack_32_08.AddFirst( *((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_16_64(Instruction_st &TheInstruction){
            _VirtualStack_16_64.AddFirst( *((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_16_32(Instruction_st &TheInstruction){
            _VirtualStack_16_32.AddFirst( *((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_16_16(Instruction_st &TheInstruction){
            _VirtualStack_16_16.AddFirst( *((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_16_08(Instruction_st &TheInstruction){
            _VirtualStack_16_08.AddFirst( *((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_08_64(Instruction_st &TheInstruction){
            _VirtualStack_08_64.AddFirst( *((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_08_32(Instruction_st &TheInstruction){
            _VirtualStack_08_32.AddFirst( *((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_08_16(Instruction_st &TheInstruction){
            _VirtualStack_08_16.AddFirst( *((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddFirst_08_08(Instruction_st &TheInstruction){
            _VirtualStack_08_08.AddFirst( *((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_64_64(Instruction_st &TheInstruction){
            _VirtualStack_64_64.AddLast( *((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_64_32(Instruction_st &TheInstruction){
            _VirtualStack_64_32.AddLast( *((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_64_16(Instruction_st &TheInstruction){
            _VirtualStack_64_16.AddLast( *((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_64_08(Instruction_st &TheInstruction){
            _VirtualStack_64_08.AddLast( *((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_32_64(Instruction_st &TheInstruction){
            _VirtualStack_32_64.AddLast( *((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_32_32(Instruction_st &TheInstruction){
            _VirtualStack_32_32.AddLast( *((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_32_16(Instruction_st &TheInstruction){
            _VirtualStack_32_16.AddLast( *((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_32_08(Instruction_st &TheInstruction){
            _VirtualStack_32_08.AddLast( *((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_16_64(Instruction_st &TheInstruction){
            _VirtualStack_16_64.AddLast( *((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_16_32(Instruction_st &TheInstruction){
            _VirtualStack_16_32.AddLast( *((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_16_16(Instruction_st &TheInstruction){
            _VirtualStack_16_16.AddLast( *((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_16_08(Instruction_st &TheInstruction){
            _VirtualStack_16_08.AddLast( *((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_08_64(Instruction_st &TheInstruction){
            _VirtualStack_08_64.AddLast( *((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_08_32(Instruction_st &TheInstruction){
            _VirtualStack_08_32.AddLast( *((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_08_16(Instruction_st &TheInstruction){
            _VirtualStack_08_16.AddLast( *((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData) );
        }
        void VirtualMachine_cl::AddLast_08_08(Instruction_st &TheInstruction){
            _VirtualStack_08_08.AddLast( *((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData) );
        }
        
        void VirtualMachine_cl::GetFirst_64_64(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_64.First().Type;
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_64.First().Value;
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_64_32(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_32.First().Type;
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_32.First().Value;
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_64_16(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_16.First().Type;
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_16.First().Value;
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_64_08(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_08.First().Type;
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_08.First().Value;
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_08.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_32_64(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_64.First().Type;
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_64.First().Value;
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_32_32(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_32.First().Type;
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_32.First().Value;
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_32_16(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_16.First().Type;
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_16.First().Value;
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_32_08(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_08.First().Type;
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_08.First().Value;
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_08.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_16_64(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_64.First().Type;
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_64.First().Value;
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_16_32(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_32.First().Type;
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_32.First().Value;
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_16_16(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_16.First().Type;
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_16.First().Value;
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_16_08(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_08.First().Type;
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_08.First().Value;
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_08.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_08_64(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_64.First().Type;
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_64.First().Value;
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_08_32(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_32.First().Type;
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_32.First().Value;
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_08_16(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_16.First().Type;
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_16.First().Value;
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst_08_08(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_08.First().Type;
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_08.First().Value;
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_08.First().Extended;
        }

        void VirtualMachine_cl::GetLast_64_64(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_64.Last().Type;
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_64.Last().Value;
            ((VirtualStack::V64::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_64_32(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_32.Last().Type;
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_32.Last().Value;
            ((VirtualStack::V64::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_64_16(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_16.Last().Type;
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_16.Last().Value;
            ((VirtualStack::V64::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_64_08(Instruction_st &TheInstruction){
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_64_08.Last().Type;
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_64_08.Last().Value;
            ((VirtualStack::V64::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_64_08.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_32_64(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_64.Last().Type;
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_64.Last().Value;
            ((VirtualStack::V32::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_32_32(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_32.Last().Type;
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_32.Last().Value;
            ((VirtualStack::V32::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_32_16(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_16.Last().Type;
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_16.Last().Value;
            ((VirtualStack::V32::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_32_08(Instruction_st &TheInstruction){
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_32_08.Last().Type;
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_32_08.Last().Value;
            ((VirtualStack::V32::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_32_08.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_16_64(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_64.Last().Type;
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_64.Last().Value;
            ((VirtualStack::V16::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_16_32(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_32.Last().Type;
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_32.Last().Value;
            ((VirtualStack::V16::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_16_16(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_16.Last().Type;
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_16.Last().Value;
            ((VirtualStack::V16::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_16_08(Instruction_st &TheInstruction){
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_16_08.Last().Type;
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_16_08.Last().Value;
            ((VirtualStack::V16::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_16_08.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_08_64(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_64.Last().Type;
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_64.Last().Value;
            ((VirtualStack::V8::E64::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_08_32(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_32.Last().Type;
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_32.Last().Value;
            ((VirtualStack::V8::E32::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_08_16(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_16.Last().Type;
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_16.Last().Value;
            ((VirtualStack::V8::E16::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast_08_08(Instruction_st &TheInstruction){
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Type=_VirtualStack_08_08.Last().Type;
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Value=_VirtualStack_08_08.Last().Value;
            ((VirtualStack::V8::E8::VirtualStack_st*)TheInstruction.MyData)->Extended=_VirtualStack_08_08.Last().Extended;
        }
        
        
        void VirtualMachine_cl::AddFirst(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{AddFirst_64_64(TheInstruction);}break;
                case SzCode::V64_E32:{AddFirst_64_32(TheInstruction);}break;
                case SzCode::V64_E16:{AddFirst_64_16(TheInstruction);}break;
                case SzCode::V64_E08:{AddFirst_64_08(TheInstruction);}break;
                case SzCode::V32_E64:{AddFirst_32_64(TheInstruction);}break;
                case SzCode::V32_E32:{AddFirst_32_32(TheInstruction);}break;
                case SzCode::V32_E16:{AddFirst_32_16(TheInstruction);}break;
                case SzCode::V32_E08:{AddFirst_32_08(TheInstruction);}break;
                case SzCode::V16_E64:{AddFirst_16_64(TheInstruction);}break;
                case SzCode::V16_E32:{AddFirst_16_32(TheInstruction);}break;
                case SzCode::V16_E16:{AddFirst_16_16(TheInstruction);}break;
                case SzCode::V16_E08:{AddFirst_16_08(TheInstruction);}break;
                case SzCode::V08_E64:{AddFirst_08_64(TheInstruction);}break;
                case SzCode::V08_E32:{AddFirst_08_32(TheInstruction);}break;
                case SzCode::V08_E16:{AddFirst_08_16(TheInstruction);}break;
                case SzCode::V08_E08:{AddFirst_08_08(TheInstruction);}break;
            }
        }
        void VirtualMachine_cl::AddLast(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{AddLast_64_64(TheInstruction);}break;
                case SzCode::V64_E32:{AddLast_64_32(TheInstruction);}break;
                case SzCode::V64_E16:{AddLast_64_16(TheInstruction);}break;
                case SzCode::V64_E08:{AddLast_64_08(TheInstruction);}break;
                case SzCode::V32_E64:{AddLast_32_64(TheInstruction);}break;
                case SzCode::V32_E32:{AddLast_32_32(TheInstruction);}break;
                case SzCode::V32_E16:{AddLast_32_16(TheInstruction);}break;
                case SzCode::V32_E08:{AddLast_32_08(TheInstruction);}break;
                case SzCode::V16_E64:{AddLast_16_64(TheInstruction);}break;
                case SzCode::V16_E32:{AddLast_16_32(TheInstruction);}break;
                case SzCode::V16_E16:{AddLast_16_16(TheInstruction);}break;
                case SzCode::V16_E08:{AddLast_16_08(TheInstruction);}break;
                case SzCode::V08_E64:{AddLast_08_64(TheInstruction);}break;
                case SzCode::V08_E32:{AddLast_08_32(TheInstruction);}break;
                case SzCode::V08_E16:{AddLast_08_16(TheInstruction);}break;
                case SzCode::V08_E08:{AddLast_08_08(TheInstruction);}break;
            }
        }
        void VirtualMachine_cl::RemoveFirst(SzCode TheSizecode){
            switch(TheSizecode){
                case SzCode::V64_E64:{_VirtualStack_64_64.RemoveFirst();}break;
                case SzCode::V64_E32:{_VirtualStack_64_32.RemoveFirst();}break;
                case SzCode::V64_E16:{_VirtualStack_64_16.RemoveFirst();}break;
                case SzCode::V64_E08:{_VirtualStack_64_08.RemoveFirst();}break;
                case SzCode::V32_E64:{_VirtualStack_32_64.RemoveFirst();}break;
                case SzCode::V32_E32:{_VirtualStack_32_32.RemoveFirst();}break;
                case SzCode::V32_E16:{_VirtualStack_32_16.RemoveFirst();}break;
                case SzCode::V32_E08:{_VirtualStack_32_08.RemoveFirst();}break;
                case SzCode::V16_E64:{_VirtualStack_16_64.RemoveFirst();}break;
                case SzCode::V16_E32:{_VirtualStack_16_32.RemoveFirst();}break;
                case SzCode::V16_E16:{_VirtualStack_16_16.RemoveFirst();}break;
                case SzCode::V16_E08:{_VirtualStack_16_08.RemoveFirst();}break;
                case SzCode::V08_E64:{_VirtualStack_08_64.RemoveFirst();}break;
                case SzCode::V08_E32:{_VirtualStack_08_32.RemoveFirst();}break;
                case SzCode::V08_E16:{_VirtualStack_08_16.RemoveFirst();}break;
                case SzCode::V08_E08:{_VirtualStack_08_08.RemoveFirst();}break;
            }
        }
        void VirtualMachine_cl::RemoveLast(SzCode TheSizecode){
            switch(TheSizecode){
                case SzCode::V64_E64:{_VirtualStack_64_64.RemoveLast();}break;
                case SzCode::V64_E32:{_VirtualStack_64_32.RemoveLast();}break;
                case SzCode::V64_E16:{_VirtualStack_64_16.RemoveLast();}break;
                case SzCode::V64_E08:{_VirtualStack_64_08.RemoveLast();}break;
                case SzCode::V32_E64:{_VirtualStack_32_64.RemoveLast();}break;
                case SzCode::V32_E32:{_VirtualStack_32_32.RemoveLast();}break;
                case SzCode::V32_E16:{_VirtualStack_32_16.RemoveLast();}break;
                case SzCode::V32_E08:{_VirtualStack_32_08.RemoveLast();}break;
                case SzCode::V16_E64:{_VirtualStack_16_64.RemoveLast();}break;
                case SzCode::V16_E32:{_VirtualStack_16_32.RemoveLast();}break;
                case SzCode::V16_E16:{_VirtualStack_16_16.RemoveLast();}break;
                case SzCode::V16_E08:{_VirtualStack_16_08.RemoveLast();}break;
                case SzCode::V08_E64:{_VirtualStack_08_64.RemoveLast();}break;
                case SzCode::V08_E32:{_VirtualStack_08_32.RemoveLast();}break;
                case SzCode::V08_E16:{_VirtualStack_08_16.RemoveLast();}break;
                case SzCode::V08_E08:{_VirtualStack_08_08.RemoveLast();}break;
            }
        }

        void VirtualMachine_cl::GetLast(Instruction_st &TheInstruction){
         switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{GetLast_64_64(TheInstruction);}break;
                case SzCode::V64_E32:{GetLast_64_32(TheInstruction);}break;
                case SzCode::V64_E16:{GetLast_64_16(TheInstruction);}break;
                case SzCode::V64_E08:{GetLast_64_08(TheInstruction);}break;
                case SzCode::V32_E64:{GetLast_32_64(TheInstruction);}break;
                case SzCode::V32_E32:{GetLast_32_32(TheInstruction);}break;
                case SzCode::V32_E16:{GetLast_32_16(TheInstruction);}break;
                case SzCode::V32_E08:{GetLast_32_08(TheInstruction);}break;
                case SzCode::V16_E64:{GetLast_16_64(TheInstruction);}break;
                case SzCode::V16_E32:{GetLast_16_32(TheInstruction);}break;
                case SzCode::V16_E16:{GetLast_16_16(TheInstruction);}break;
                case SzCode::V16_E08:{GetLast_16_08(TheInstruction);}break;
                case SzCode::V08_E64:{GetLast_08_64(TheInstruction);}break;
                case SzCode::V08_E32:{GetLast_08_32(TheInstruction);}break;
                case SzCode::V08_E16:{GetLast_08_16(TheInstruction);}break;
                case SzCode::V08_E08:{GetLast_08_08(TheInstruction);}break;
            }
        }
        void VirtualMachine_cl::GetFirst(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{GetFirst_64_64(TheInstruction);}break;
                case SzCode::V64_E32:{GetFirst_64_32(TheInstruction);}break;
                case SzCode::V64_E16:{GetFirst_64_16(TheInstruction);}break;
                case SzCode::V64_E08:{GetFirst_64_08(TheInstruction);}break;
                case SzCode::V32_E64:{GetFirst_32_64(TheInstruction);}break;
                case SzCode::V32_E32:{GetFirst_32_32(TheInstruction);}break;
                case SzCode::V32_E16:{GetFirst_32_16(TheInstruction);}break;
                case SzCode::V32_E08:{GetFirst_32_08(TheInstruction);}break;
                case SzCode::V16_E64:{GetFirst_16_64(TheInstruction);}break;
                case SzCode::V16_E32:{GetFirst_16_32(TheInstruction);}break;
                case SzCode::V16_E16:{GetFirst_16_16(TheInstruction);}break;
                case SzCode::V16_E08:{GetFirst_16_08(TheInstruction);}break;
                case SzCode::V08_E64:{GetFirst_08_64(TheInstruction);}break;
                case SzCode::V08_E32:{GetFirst_08_32(TheInstruction);}break;
                case SzCode::V08_E16:{GetFirst_08_16(TheInstruction);}break;
                case SzCode::V08_E08:{GetFirst_08_08(TheInstruction);}break;
            }
        }

        void VirtualMachine_cl::Clone(SzCode FromStack,SzCode ToStack){
            switch(FromStack){
                case SzCode::V64_E64:{
                    int64_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast_64_64(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    int64_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast_64_32(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    int64_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast_64_16(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    int64_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast_64_08(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    int32_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast_32_64(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    int32_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast_32_32(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    int32_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast_32_16(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    int32_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast_32_08(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    int16_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast_16_64(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    int16_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast_16_32(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    int16_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast_16_16(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    int16_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast_16_08(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    int8_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast_08_64(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    int8_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast_08_32(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    int8_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast_08_16(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    int8_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast_08_08(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_64_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_64_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_64_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_64_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_32_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_32_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_32_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_32_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_16_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_16_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_16_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_16_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast_08_64(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast_08_32(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast_08_16(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast_08_08(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
            }
        }
        void VirtualMachine_cl::Print(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V64()));
                }break;
                case SzCode::V64_E32:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V64()));
                }break;
                case SzCode::V64_E16:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V64()));
                }break;
                case SzCode::V64_E08:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V64()));
                }break;
                case SzCode::V32_E64:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V32()));
                }break;
                case SzCode::V32_E32:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V32()));
                }break;
                case SzCode::V32_E16:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V32()));
                }break;
                case SzCode::V32_E08:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V32()));
                }break;
                case SzCode::V16_E64:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V16()));
                }break;
                case SzCode::V16_E32:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V16()));
                }break;
                case SzCode::V16_E16:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V16()));
                }break;
                case SzCode::V16_E08:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V16()));
                }break;
                case SzCode::V08_E64:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V8()));
                }break;
                case SzCode::V08_E32:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V8()));
                }break;
                case SzCode::V08_E16:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V8()));
                }break;
                case SzCode::V08_E08:{
                    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(TheInstruction.V8()));
                }break;
            }
        }
        void VirtualMachine_cl::MathematicalAdd(Instruction_st &aStack,Instruction_st &bStack){
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()+=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()+=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()+=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()+=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()+=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()+=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()+=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()+=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()+=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()+=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()+=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()+=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()+=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()+=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()+=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()+=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()+=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalSubtract(Instruction_st &aStack,Instruction_st &bStack){
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()-=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()-=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()-=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()-=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()-=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()-=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()-=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()-=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()-=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()-=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()-=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()-=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()-=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()-=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()-=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()-=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()-=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalMultiply(Instruction_st &aStack,Instruction_st &bStack){
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()*=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()*=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()*=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()*=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()*=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()*=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()*=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()*=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()*=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()*=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()*=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()*=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()*=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()*=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()*=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()*=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()*=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalDivide(Instruction_st &aStack,Instruction_st &bStack){
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()/=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()/=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()/=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()/=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()/=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()/=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()/=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()/=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()/=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()/=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()/=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()/=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()/=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()/=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()/=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()/=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()/=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalModulus(Instruction_st &aStack,Instruction_st &bStack){
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()%=(int64_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()%=(int64_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()%=(int64_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()%=(int64_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()%=(int32_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()%=(int32_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()%=(int32_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()%=(int32_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()%=(int16_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()%=(int16_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()%=(int16_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()%=(int16_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()%=(int8_t)bStack.V64();
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()%=(int8_t)bStack.V32();
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()%=(int8_t)bStack.V16();
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()%=(int8_t)bStack.V8();
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalMore(Instruction_st &aStack,Instruction_st &bStack){
            aStack.Get_TpCode()=TpCode::TP__BOOL;
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()>(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()>(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()>(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()>(int8_t)bStack.V8());
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalLess(Instruction_st &aStack,Instruction_st &bStack){
            aStack.Get_TpCode()=TpCode::TP__BOOL;
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()<(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()<(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()<(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()<(int8_t)bStack.V8());
                        }break;
                    }
                }break;
            }
        }

        void VirtualMachine_cl::MathematicalSame(Instruction_st &aStack,Instruction_st &bStack){
            aStack.Get_TpCode()=TpCode::TP__BOOL;
            switch(aStack.Get_SzCode()){
                case SzCode::V64_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V64()=(int64_t)(bool)(aStack.V64()==(int64_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()%=bStack.V8();
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V32()=(int32_t)(bool)(aStack.V32()==(int32_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V16()=(int16_t)(bool)(aStack.V16()==(int16_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    switch(bStack.Get_SzCode()){
                        case SzCode::V64_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V64_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V64());
                        }break;
                        case SzCode::V32_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V32_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V32());
                        }break;
                        case SzCode::V16_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V16_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V16());
                        }break;
                        case SzCode::V08_E64:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E32:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E16:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                        case SzCode::V08_E08:{
                            aStack.V8()=(int8_t)(bool)(aStack.V8()==(int8_t)bStack.V8());
                        }break;
                    }
                }break;
            }
        }

        VirtualMachine_cl::VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code){
            for(size_t InstructionCounter=0;InstructionCounter<code.Size();InstructionCounter++){
                
                switch(code[InstructionCounter].Get_OpCode()){
                    case OpCode::OP__NULL:{}break;
                    case OpCode::OP__EXIT:{}break;
                    case OpCode::OP__ADD:{
                        Instruction_st FromStack;
                        Instruction_st ToStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalAdd(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__SUBTRACT:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalSubtract(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MULTIPLY:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalMultiply(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__DIVIDE:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalDivide(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MODULUS:{
                        Instruction_st FromStack;
                        Instruction_st ToStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalModulus(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MORE_THAN:{
                        Instruction_st FromStack;
                        Instruction_st ToStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalMore(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__LESS_THAN:{
                        Instruction_st FromStack;
                        Instruction_st ToStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalLess(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__EQUALS:{
                        Instruction_st FromStack;
                        Instruction_st ToStack;
                        FromStack.MySzCode = (SzCode)code[InstructionCounter].V8();
                        ToStack.MySzCode = (SzCode)code[InstructionCounter].E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalSame(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__PUSH:{
                        AddLast(code[InstructionCounter]);
                    }break;
                    case OpCode::OP__PRINT:{
                        SzCode TargetSz=(SzCode)code[InstructionCounter].V8();
                        Instruction_st TargetInstruct;
                        switch(TargetSz){
                            case SzCode::V64_E64:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int64_t)0,(uint64_t)0);}break;
                            case SzCode::V64_E32:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int64_t)0,(uint32_t)0);}break;
                            case SzCode::V64_E16:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int64_t)0,(uint16_t)0);}break;
                            case SzCode::V64_E08:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int64_t)0,(uint8_t)0); }break; 
                            case SzCode::V32_E64:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int32_t)0,(uint64_t)0);}break;
                            case SzCode::V32_E32:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int32_t)0,(uint32_t)0);}break;
                            case SzCode::V32_E16:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int32_t)0,(uint16_t)0);}break;
                            case SzCode::V32_E08:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int32_t)0,(uint8_t)0); }break;
                            case SzCode::V16_E64:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int16_t)0,(uint64_t)0);}break;
                            case SzCode::V16_E32:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int16_t)0,(uint32_t)0);}break;
                            case SzCode::V16_E16:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int16_t)0,(uint16_t)0);}break;
                            case SzCode::V16_E08:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int16_t)0,(uint8_t)0); }break;
                            case SzCode::V08_E64:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int8_t)0,(uint64_t)0);}break;
                            case SzCode::V08_E32:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int8_t)0,(uint32_t)0);}break;
                            case SzCode::V08_E16:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int8_t)0,(uint16_t)0);}break;
                            case SzCode::V08_E08:{TargetInstruct.Init(OpCode::OP__PRINT,TpCode::TP__NULL,(int8_t)0,(uint8_t)0); }break;
                        }
                        GetLast(TargetInstruct);
                        RemoveLast(TargetInstruct.Get_SzCode());
                        Print(TargetInstruct);
                    }break;
                    case OpCode::OP__IF_JUMP:{}break;
                    case OpCode::OP__JUMP:{}break;
                    case OpCode::OP__CLEAR_STACK:{}break;
                    case OpCode::OP__CLONE:{
                        uint8_t FromStack = code[InstructionCounter].V8();
                        uint8_t ToStack = code[InstructionCounter].E8();
                        Clone((SzCode)FromStack,(SzCode)ToStack);
                    }break;
                }
            }
        }
    };
};