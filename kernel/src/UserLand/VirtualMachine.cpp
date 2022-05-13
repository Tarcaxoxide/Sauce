#include<Sauce/UserLand/VirtualMachine.hpp>


namespace Sauce{
    namespace UserLand{
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint8_t Extended){
            MySzCode=V08_E08;
            MyData = new VirtualStack::V8::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint16_t Extended){
            MySzCode=V08_E16;
            MyData = new VirtualStack::V8::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint32_t Extended){
            MySzCode=V08_E32;
            MyData = new VirtualStack::V8::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int8_t Value,uint64_t Extended){
            MySzCode=V08_E64;
            MyData = new VirtualStack::V8::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint8_t Extended){
            MySzCode=V16_E08;
            MyData = new VirtualStack::V16::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint16_t Extended){
            MySzCode=V16_E16;
            MyData = new VirtualStack::V16::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint32_t Extended){
            MySzCode=V16_E32;
            MyData = new VirtualStack::V16::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int16_t Value,uint64_t Extended){
            MySzCode=V16_E64;
            MyData = new VirtualStack::V16::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint8_t Extended){
            MySzCode=V32_E08;
            MyData = new VirtualStack::V32::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint16_t Extended){
            MySzCode=V32_E16;
            MyData = new VirtualStack::V32::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint32_t Extended){
            MySzCode=V32_E32;
            MyData = new VirtualStack::V32::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int32_t Value,uint64_t Extended){
            MySzCode=V32_E64;
            MyData = new VirtualStack::V32::E64::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint8_t Extended){
            MySzCode=V64_E08;
            MyData = new VirtualStack::V64::E8::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint16_t Extended){
            MySzCode=V64_E16;
            MyData = new VirtualStack::V64::E16::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint32_t Extended){
            MySzCode=V64_E32;
            MyData = new VirtualStack::V64::E32::VirtualStack_st{MyTypeCode,Value,Extended};
        }
        Instruction_st::Instruction_st(OpCode MyOpCode,TpCode MyTypeCode,int64_t Value,uint64_t Extended){
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
        TpCode Instruction_st::Get_TpCode(){
            switch(SizeCode){
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
            switch(SizeCode){
                case SzCode::V08_E64:return ((VirtualStack::V8::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E32:return ((VirtualStack::V8::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E16:return ((VirtualStack::V8::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V08_E08:return ((VirtualStack::V8::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        int16_t& Instruction_st::V16(){
            switch(SizeCode){
                case SzCode::V16_E64:return ((VirtualStack::V16::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E32:return ((VirtualStack::V16::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E16:return ((VirtualStack::V16::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V16_E08:return ((VirtualStack::V16::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        int32_t& Instruction_st::V32(){
            switch(SizeCode){
                case SzCode::V32_E64:return ((VirtualStack::V32::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E32:return ((VirtualStack::V32::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E16:return ((VirtualStack::V32::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V32_E08:return ((VirtualStack::V32::E8::VirtualStack_st*)MyData)->Value;
            }
        }
        int64_t& Instruction_st::V64(){
            switch(SizeCode){
                case SzCode::V64_E64:return ((VirtualStack::V64::E64::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E32:return ((VirtualStack::V64::E32::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E16:return ((VirtualStack::V64::E16::VirtualStack_st*)MyData)->Value;
                case SzCode::V64_E08:return ((VirtualStack::V64::E8::VirtualStack_st*)MyData)->Value; 
            }
        }
        uint8_t& Instruction_st::E8(){
            switch(SizeCode){
                case SzCode::V64_E08:return ((VirtualStack::V64::E8::VirtualStack_st*)MyData)->Extended; 
                case SzCode::V32_E08:return ((VirtualStack::V32::E8::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E08:return ((VirtualStack::V16::E8::VirtualStack_st*)MyData)->Extended; 
                case SzCode::V08_E08:return ((VirtualStack::V8::E8::VirtualStack_st*)MyData)->Extended; 
            }
        }
        uint16_t& Instruction_st::E16(){
            switch(SizeCode){
                case SzCode::V64_E16:return ((VirtualStack::V64::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V32_E16:return ((VirtualStack::V32::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E16:return ((VirtualStack::V16::E16::VirtualStack_st*)MyData)->Extended;
                case SzCode::V08_E16:return ((VirtualStack::V8::E16::VirtualStack_st*)MyData)->Extended;
            }
        }
        uint32_t& Instruction_st::E32(){
            switch(SizeCode){
                case SzCode::V64_E32:return ((VirtualStack::V64::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V32_E32:return ((VirtualStack::V32::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V16_E32:return ((VirtualStack::V16::E32::VirtualStack_st*)MyData)->Extended;
                case SzCode::V08_E32:return ((VirtualStack::V8::E32::VirtualStack_st*)MyData)->Extended;
            }
        }
        uint64_t& Instruction_st::E64(){
            switch(SizeCode){
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
        void VirtualMachine_cl::AddFirst(TpCode TheType,int64_t TheValue,uint64_t TheExtended){
            _VirtualStack_64_64.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int64_t TheValue,uint32_t TheExtended){
            _VirtualStack_64_32.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int64_t TheValue,uint16_t TheExtended){
            _VirtualStack_64_16.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int64_t TheValue,uint8_t TheExtended){
            _VirtualStack_64_08.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int32_t TheValue,uint64_t TheExtended){
            _VirtualStack_32_64.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int32_t TheValue,uint32_t TheExtended){
            _VirtualStack_32_32.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int32_t TheValue,uint16_t TheExtended){
            _VirtualStack_32_16.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int32_t TheValue,uint8_t TheExtended){
            _VirtualStack_32_08.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int16_t TheValue,uint64_t TheExtended){
            _VirtualStack_16_64.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int16_t TheValue,uint32_t TheExtended){
            _VirtualStack_16_32.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int16_t TheValue,uint16_t TheExtended){
            _VirtualStack_16_16.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int16_t TheValue,uint8_t TheExtended){
            _VirtualStack_16_08.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int8_t TheValue,uint64_t TheExtended){
            _VirtualStack_08_64.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int8_t TheValue,uint32_t TheExtended){
            _VirtualStack_08_32.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int8_t TheValue,uint16_t TheExtended){
            _VirtualStack_08_16.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddFirst(TpCode TheType,int8_t TheValue,uint8_t TheExtended){
            _VirtualStack_08_08.AddFirst({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int64_t TheValue,uint64_t TheExtended){
            _VirtualStack_64_64.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int64_t TheValue,uint32_t TheExtended){
            _VirtualStack_64_32.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int64_t TheValue,uint16_t TheExtended){
            _VirtualStack_64_16.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int64_t TheValue,uint8_t TheExtended){
            _VirtualStack_64_08.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int32_t TheValue,uint64_t TheExtended){
            _VirtualStack_32_64.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int32_t TheValue,uint32_t TheExtended){
            _VirtualStack_32_32.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int32_t TheValue,uint16_t TheExtended){
            _VirtualStack_32_16.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int32_t TheValue,uint8_t TheExtended){
            _VirtualStack_32_08.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int16_t TheValue,uint64_t TheExtended){
            _VirtualStack_16_64.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int16_t TheValue,uint32_t TheExtended){
            _VirtualStack_16_32.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int16_t TheValue,uint16_t TheExtended){
            _VirtualStack_16_16.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int16_t TheValue,uint8_t TheExtended){
            _VirtualStack_16_08.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int8_t TheValue,uint64_t TheExtended){
            _VirtualStack_08_64.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int8_t TheValue,uint32_t TheExtended){
            _VirtualStack_08_32.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int8_t TheValue,uint16_t TheExtended){
            _VirtualStack_08_16.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::AddLast(TpCode TheType,int8_t TheValue,uint8_t TheExtended){
            _VirtualStack_08_08.AddLast({TheType,TheValue,TheExtended});
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int64_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_64_64.First().Type;
            TheValue=_VirtualStack_64_64.First().Value;
            TheExtended=_VirtualStack_64_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int64_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_64_32.First().Type;
            TheValue=_VirtualStack_64_32.First().Value;
            TheExtended=_VirtualStack_64_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int64_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_64_16.First().Type;
            TheValue=_VirtualStack_64_16.First().Value;
            TheExtended=_VirtualStack_64_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int64_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_64_08.First().Type;
            TheValue=_VirtualStack_64_08.First().Value;
            TheExtended=_VirtualStack_64_08.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int16_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_16_64.First().Type;
            TheValue=_VirtualStack_16_64.First().Value;
            TheExtended=_VirtualStack_16_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int16_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_16_32.First().Type;
            TheValue=_VirtualStack_16_32.First().Value;
            TheExtended=_VirtualStack_16_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int16_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_16_16.First().Type;
            TheValue=_VirtualStack_16_16.First().Value;
            TheExtended=_VirtualStack_16_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int16_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_16_08.First().Type;
            TheValue=_VirtualStack_16_08.First().Value;
            TheExtended=_VirtualStack_16_08.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int8_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_08_64.First().Type;
            TheValue=_VirtualStack_08_64.First().Value;
            TheExtended=_VirtualStack_08_64.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int8_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_08_32.First().Type;
            TheValue=_VirtualStack_08_32.First().Value;
            TheExtended=_VirtualStack_08_32.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int8_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_08_16.First().Type;
            TheValue=_VirtualStack_08_16.First().Value;
            TheExtended=_VirtualStack_08_16.First().Extended;
        }
        void VirtualMachine_cl::GetFirst(TpCode &TheType,int8_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_08_08.First().Type;
            TheValue=_VirtualStack_08_08.First().Value;
            TheExtended=_VirtualStack_08_08.First().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int64_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_64_64.Last().Type;
            TheValue=_VirtualStack_64_64.Last().Value;
            TheExtended=_VirtualStack_64_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int64_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_64_32.Last().Type;
            TheValue=_VirtualStack_64_32.Last().Value;
            TheExtended=_VirtualStack_64_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int64_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_64_16.Last().Type;
            TheValue=_VirtualStack_64_16.Last().Value;
            TheExtended=_VirtualStack_64_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int64_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_64_08.First().Type;
            TheValue=_VirtualStack_64_08.First().Value;
            TheExtended=_VirtualStack_64_08.First().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int16_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_16_64.Last().Type;
            TheValue=_VirtualStack_16_64.Last().Value;
            TheExtended=_VirtualStack_16_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int16_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_16_32.Last().Type;
            TheValue=_VirtualStack_16_32.Last().Value;
            TheExtended=_VirtualStack_16_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int16_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_16_16.Last().Type;
            TheValue=_VirtualStack_16_16.Last().Value;
            TheExtended=_VirtualStack_16_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int16_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_16_08.Last().Type;
            TheValue=_VirtualStack_16_08.Last().Value;
            TheExtended=_VirtualStack_16_08.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,uint8_t &TheValue,uint64_t &TheExtended){
            TheType=_VirtualStack_08_64.Last().Type;
            TheValue=_VirtualStack_08_64.Last().Value;
            TheExtended=_VirtualStack_08_64.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int8_t &TheValue,uint32_t &TheExtended){
            TheType=_VirtualStack_08_32.Last().Type;
            TheValue=_VirtualStack_08_32.Last().Value;
            TheExtended=_VirtualStack_08_32.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int8_t &TheValue,uint16_t &TheExtended){
            TheType=_VirtualStack_08_16.Last().Type;
            TheValue=_VirtualStack_08_16.Last().Value;
            TheExtended=_VirtualStack_08_16.Last().Extended;
        }
        void VirtualMachine_cl::GetLast(TpCode &TheType,int8_t &TheValue,uint8_t &TheExtended){
            TheType=_VirtualStack_08_08.Last().Type;
            TheValue=_VirtualStack_08_08.Last().Value;
            TheExtended=_VirtualStack_08_08.Last().Extended;
        }
        
        void VirtualMachine_cl::AddFirst(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E64());}break;
                case SzCode::V64_E32:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E32());}break;
                case SzCode::V64_E16:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E16());}break;
                case SzCode::V64_E08:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E8()); }break;
                case SzCode::V32_E64:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E64());}break;
                case SzCode::V32_E32:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E32());}break;
                case SzCode::V32_E16:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E16());}break;
                case SzCode::V32_E08:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E8()); }break;
                case SzCode::V16_E64:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E64());}break;
                case SzCode::V16_E32:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E32());}break;
                case SzCode::V16_E16:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E16());}break;
                case SzCode::V16_E08:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E8()); }break;
                case SzCode::V08_E64:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E64());}break;
                case SzCode::V08_E32:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E32());}break;
                case SzCode::V08_E16:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E16());}break;
                case SzCode::V08_E08:{AddFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E8()); }break;
            }
        }
        void VirtualMachine_cl::AddLast(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E64());}break;
                case SzCode::V64_E32:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E32());}break;
                case SzCode::V64_E16:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E16());}break;
                case SzCode::V64_E08:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E8()); }break;
                case SzCode::V32_E64:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E64());}break;
                case SzCode::V32_E32:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E32());}break;
                case SzCode::V32_E16:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E16());}break;
                case SzCode::V32_E08:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E8()); }break;
                case SzCode::V16_E64:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E64());}break;
                case SzCode::V16_E32:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E32());}break;
                case SzCode::V16_E16:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E16());}break;
                case SzCode::V16_E08:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E8()); }break;
                case SzCode::V08_E64:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E64());}break;
                case SzCode::V08_E32:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E32());}break;
                case SzCode::V08_E16:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E16());}break;
                case SzCode::V08_E08:{AddLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E8()); }break;
            }
        }
        void VirtualMachine_cl::RemoveFirst(SzCode TheSizecode){
            switch(TheInstruction.Get_SzCode()){
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
            switch(TheInstruction.Get_SzCode()){
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
                case SzCode::V64_E64:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E64());}break;
                case SzCode::V64_E32:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E32());}break;
                case SzCode::V64_E16:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E16());}break;
                case SzCode::V64_E08:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E8()); }break;
                case SzCode::V32_E64:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E64());}break;
                case SzCode::V32_E32:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E32());}break;
                case SzCode::V32_E16:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E16());}break;
                case SzCode::V32_E08:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E8()); }break;
                case SzCode::V16_E64:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E64());}break;
                case SzCode::V16_E32:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E32());}break;
                case SzCode::V16_E16:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E16());}break;
                case SzCode::V16_E08:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E8()); }break;
                case SzCode::V08_E64:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E64());}break;
                case SzCode::V08_E32:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E32());}break;
                case SzCode::V08_E16:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E16());}break;
                case SzCode::V08_E08:{GetLast(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E8()); }break;
            }
        }
        void VirtualMachine_cl::GetFirst(Instruction_st &TheInstruction){
            switch(TheInstruction.Get_SzCode()){
                case SzCode::V64_E64:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E64());}break;
                case SzCode::V64_E32:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E32());}break;
                case SzCode::V64_E16:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E16());}break;
                case SzCode::V64_E08:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V64(),TheInstruction.E8()); }break;
                case SzCode::V32_E64:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E64());}break;
                case SzCode::V32_E32:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E32());}break;
                case SzCode::V32_E16:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E16());}break;
                case SzCode::V32_E08:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V32(),TheInstruction.E8()); }break;
                case SzCode::V16_E64:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E64());}break;
                case SzCode::V16_E32:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E32());}break;
                case SzCode::V16_E16:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E16());}break;
                case SzCode::V16_E08:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V16(),TheInstruction.E8()); }break;
                case SzCode::V08_E64:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E64());}break;
                case SzCode::V08_E32:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E32());}break;
                case SzCode::V08_E16:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E16());}break;
                case SzCode::V08_E08:{GetFirst(TheInstruction.Get_TpCode(),TheInstruction.V8(),TheInstruction.E8()); }break;
            }
        }

        void VirtualMachine_cl::Clone(SzCode FromStack,SzCode ToStack){
            switch(FromStack){
                case SzCode::V64_E64:{
                    int64_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            int32_t TheNewValue=(int32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            int16_t TheNewValue=(int16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            int8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            int8_t TheNewValue=(int8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E32:{
                    int64_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E16:{
                    int64_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V64_E08:{
                    int64_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E64:{
                    uint32_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E32:{
                    uint32_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E16:{
                    uint32_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V32_E08:{
                    uint32_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E64:{
                    uint16_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E32:{
                    uint16_t TheValue;
                    uint32_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E16:{
                    uint16_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V16_E08:{
                    uint16_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E64:{
                    uint16_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E32:{
                    uint8_t TheValue;
                    uint64_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E16:{
                    uint8_t TheValue;
                    uint16_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                    }
                }break;
                case SzCode::V08_E08:{
                    uint8_t TheValue;
                    uint8_t TheExtended;
                    TpCode TheType;
                    GetLast(TheType,TheValue,TheExtended);
                    switch(ToStack){
                        case SzCode::V64_E64:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E32:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E16:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V64_E08:{
                            int64_t TheNewValue=(int64_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E64:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E32:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E16:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V32_E08:{
                            uint32_t TheNewValue=(uint32_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E64:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E32:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E16:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V16_E08:{
                            uint16_t TheNewValue=(uint16_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E64:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint64_t TheNewExtended=(uint64_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E32:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint32_t TheNewExtended=(uint32_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E16:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint16_t TheNewExtended=(uint16_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
                        }break;
                        case SzCode::V08_E08:{
                            uint8_t TheNewValue=(uint8_t)TheValue;
                            uint8_t TheNewExtended=(uint8_t)TheExtended;
                            AddLast(TheType,TheNewValue,TheNewExtended);
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
                Instruction_st CurrentInstruction=code[InstructionCounter];

                switch(CurrentInstruction.Get_OpCode()){
                    case OpCode::OP__NULL:{}break;
                    case OpCode::OP__EXIT:{}break;
                    case OpCode::OP__ADD:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalAdd(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__SUBTRACT:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalSubtract(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MULTIPLY:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalMultiply(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__DIVIDE:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalDivide(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MODULUS:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalModulus(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__MORE_THAN:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalMore(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__LESS_THAN:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalLess(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__EQUALS:{
                        Instruction_st FromStack;
                        FromStack.MySzCode = (SzCode)CurrentInstruction.V8();
                        Instruction_st ToStack;
                        ToStack.MySzCode = (SzCode)CurrentInstruction.E8();
                        GetLast(FromStack);
                        RemoveLast(FromStack.Get_SzCode());
                        GetLast(ToStack);
                        RemoveLast(ToStack.Get_SzCode());
                        MathematicalSame(FromStack,ToStack);
                        AddLast(FromStack);
                    }break;
                    case OpCode::OP__PUSH:{
                        AddLast(CurrentInstruction);
                    }break;
                    case OpCode::OP__PRINT:{
                        GetLast(CurrentInstruction);
                        Print(CurrentInstruction);
                        RemoveLast(CurrentInstruction.Get_SzCode());
                    }break;
                    case OpCode::OP__IF_JUMP:{}break;
                    case OpCode::OP__JUMP:{}break;
                    case OpCode::OP__CLEAR_STACK:{}break;
                    case OpCode::OP__CLONE:{
                        uint8_t FromStack = CurrentInstruction.V8();
                        uint8_t ToStack = CurrentInstruction.E8();
                        Clone((SzCode)FromStack,(SzCode)ToStack);
                    }break;
                }
            }
        }
    };
};