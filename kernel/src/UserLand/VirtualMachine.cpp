#include<Sauce/UserLand/VirtualMachine.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>


namespace Sauce{
    namespace UserLand{
        void VirtualMachine_cl::GetInstruction(){
            Sauce::IO::Debug::COM1_Console.Write("[VirtualMachine_cl::GetInstruction]\0");
            switch(CurrentSizeCode){
                case SzCode::V64_E64:{CurrentInstruction=(void*)&_VirtualInstructions_64_64[InstructionCounter_64_64];}break;
                case SzCode::V64_E32:{CurrentInstruction=(void*)&_VirtualInstructions_64_32[InstructionCounter_64_32];}break;
                case SzCode::V64_E16:{CurrentInstruction=(void*)&_VirtualInstructions_64_16[InstructionCounter_64_16];}break;
                case SzCode::V64_E08:{CurrentInstruction=(void*)&_VirtualInstructions_64_08[InstructionCounter_64_08];}break;
                case SzCode::V32_E64:{CurrentInstruction=(void*)&_VirtualInstructions_32_64[InstructionCounter_32_64];}break;
                case SzCode::V32_E32:{CurrentInstruction=(void*)&_VirtualInstructions_32_32[InstructionCounter_32_32];}break;
                case SzCode::V32_E16:{CurrentInstruction=(void*)&_VirtualInstructions_32_16[InstructionCounter_32_16];}break;
                case SzCode::V32_E08:{CurrentInstruction=(void*)&_VirtualInstructions_32_08[InstructionCounter_32_08];}break;
                case SzCode::V16_E64:{CurrentInstruction=(void*)&_VirtualInstructions_16_64[InstructionCounter_16_64];}break;
                case SzCode::V16_E32:{CurrentInstruction=(void*)&_VirtualInstructions_16_32[InstructionCounter_16_32];}break;
                case SzCode::V16_E16:{CurrentInstruction=(void*)&_VirtualInstructions_16_16[InstructionCounter_16_16];}break;
                case SzCode::V16_E08:{CurrentInstruction=(void*)&_VirtualInstructions_16_08[InstructionCounter_16_08];}break;
                case SzCode::V08_E64:{CurrentInstruction=(void*)&_VirtualInstructions_08_64[InstructionCounter_08_64];}break;
                case SzCode::V08_E32:{CurrentInstruction=(void*)&_VirtualInstructions_08_32[InstructionCounter_08_32];}break;
                case SzCode::V08_E16:{CurrentInstruction=(void*)&_VirtualInstructions_08_16[InstructionCounter_08_16];}break;
                case SzCode::V08_E08:{CurrentInstruction=(void*)&_VirtualInstructions_08_08[InstructionCounter_08_08];}break;
               case SzCode::SZ__NULL:{CurrentInstruction=nullptr;}break;
            }
        }
        bool VirtualMachine_cl::RunInstruction(){
            Sauce::IO::Debug::COM1_Console.Write("[VirtualMachine_cl::RunInstruction]\0");
            switch(CurrentSizeCode){
                case SzCode::V64_E64:{VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__ADD)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__SUBTRACT)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__MULTIPLY)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__DIVIDE)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__MODULUS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__MORE_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__LESS_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__EQUALS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_64_64);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__PRINT)\n\0");
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint64_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__IF_JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_64_64+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_64_64+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__CLONE)\n\0");
                            int64_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_64_64);
                            int64_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_64_64);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__SWITCH)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_64);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E64::OP__CHANGE_TYPE)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_64);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_64_64(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_64_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_64_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_64_64++;
                }break;
                case SzCode::V64_E32:{VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__ADD)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__SUBTRACT)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__MULTIPLY)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__DIVIDE)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__MODULUS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__MORE_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__LESS_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__EQUALS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_64_32);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__PRINT)\n\0");
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint64_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__IF_JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_64_32+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_64_32+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__CLONE)\n\0");
                            int64_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_64_32);
                            int32_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_64_32);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__SWITCH)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_32);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E32::OP__CHANGE_TYPE)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_32);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_64_32(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_64_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_64_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_64_32++;
                }break;
                case SzCode::V64_E16:{VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__ADD)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__SUBTRACT)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__MULTIPLY)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__DIVIDE)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__MODULUS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__MORE_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__LESS_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__EQUALS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_64_16);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__PRINT)\n\0");
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint64_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__IF_JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_64_16+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_64_16+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__CLONE)\n\0");
                            int64_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_64_16);
                            int16_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_64_16);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__SWITCH)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_16);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E16::OP__CHANGE_TYPE)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_16);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_64_16(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_64_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_64_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_64_16++;
                }break;
                case SzCode::V64_E08:{VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__ADD)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__SUBTRACT)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__MULTIPLY)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__DIVIDE)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__MODULUS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__MORE_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__LESS_THAN)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__EQUALS)\n\0");
                            int64_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_64_08);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__PRINT)\n\0");
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint64_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__IF_JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int64_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_64_08+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__JUMP)\n\0");
                            int64_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_64_08+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__CLONE)\n\0");
                            int64_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_64_08);
                            int8_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_64_08);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__SWITCH)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_08);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V64_E8::OP__CHANGE_TYPE)\n\0");
                            int64_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_64_08);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int64_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_64_08(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_64_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_64_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_64_08++;
                }break;
                case SzCode::V32_E64:{VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__ADD)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__SUBTRACT)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__MULTIPLY)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__DIVIDE)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__MODULUS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__MORE_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__LESS_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__EQUALS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_32_64);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__PRINT)\n\0");
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint32_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__IF_JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_32_64+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_32_64+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__CLONE)\n\0");
                            int32_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_32_64);
                            int64_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_32_64);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__SWITCH)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_64);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E64::OP__CHANGE_TYPE)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_64);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_32_64(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_32_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_32_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_32_64++;
                }break;
                case SzCode::V32_E32:{VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__ADD)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__SUBTRACT)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__MULTIPLY)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__DIVIDE)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__MODULUS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__MORE_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__LESS_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__EQUALS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_32_32);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__PRINT)\n\0");
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint32_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__IF_JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_32_32+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_32_32+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__CLONE)\n\0");
                            int32_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_32_32);
                            int32_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_32_32);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__SWITCH)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_32);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E32::OP__CHANGE_TYPE)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_32);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_32_32(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_32_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_32_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_32_32++;
                }break;
                case SzCode::V32_E16:{VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__ADD)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__SUBTRACT)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__MULTIPLY)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__DIVIDE)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__MODULUS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__MORE_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__LESS_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__EQUALS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_32_16);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__PRINT)\n\0");
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint32_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__IF_JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_32_16+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_32_16+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__CLONE)\n\0");
                            int32_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_32_16);
                            int16_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_32_16);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__SWITCH)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_16);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E16::OP__CHANGE_TYPE)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_16);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_32_16(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_32_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_32_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_32_16++;
                }break;
                case SzCode::V32_E08:{VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__ADD)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__SUBTRACT)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__MULTIPLY)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__DIVIDE)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__MODULUS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__MORE_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__LESS_THAN)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__EQUALS)\n\0");
                            int32_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_32_08);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__PRINT)\n\0");
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint32_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__IF_JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int32_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_32_08+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__JUMP)\n\0");
                            int32_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_32_08+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__CLONE)\n\0");
                            int32_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_32_08);
                            int8_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_32_08);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__SWITCH)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_08);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V32_E8::OP__CHANGE_TYPE)\n\0");
                            int32_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_32_08);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int32_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_32_08(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_32_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_32_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_32_08++;
                }break;
                case SzCode::V16_E64:{VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__ADD)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__SUBTRACT)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__MULTIPLY)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__DIVIDE)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__MODULUS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__MORE_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__LESS_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__EQUALS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_16_64);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__PRINT)\n\0");
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint16_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__IF_JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_16_64+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_16_64+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__CLONE)\n\0");
                            int16_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_16_64);
                            int64_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_16_64);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__SWITCH)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_64);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E64::OP__CHANGE_TYPE)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_64);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_16_64(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_16_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_16_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_16_64++;
                }break;
                case SzCode::V16_E32:{VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__ADD)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__SUBTRACT)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__MULTIPLY)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__DIVIDE)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__MODULUS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__MORE_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__LESS_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__EQUALS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_16_32);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__PRINT)\n\0");
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint16_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__IF_JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_16_32+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_16_32+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__CLONE)\n\0");
                            int16_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_16_32);
                            int32_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_16_32);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__SWITCH)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_32);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E32::OP__CHANGE_TYPE)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_32);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_16_32(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_16_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_16_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_16_32++;
                }break;
                case SzCode::V16_E16:{VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__ADD)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__SUBTRACT)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__MULTIPLY)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__DIVIDE)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__MODULUS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__MORE_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__LESS_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__EQUALS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_16_16);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__PRINT)\n\0");
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint16_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__IF_JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_16_16+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_16_16+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__CLONE)\n\0");
                            int16_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_16_16);
                            int16_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_16_16);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__SWITCH)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_16);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E16::OP__CHANGE_TYPE)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_16);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_16_16(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_16_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_16_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_16_16++;
                }break;
                case SzCode::V16_E08:{VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__ADD)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__SUBTRACT)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__MULTIPLY)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__DIVIDE)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__MODULUS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__MORE_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__LESS_THAN)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__EQUALS)\n\0");
                            int16_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_16_08);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__PRINT)\n\0");
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint16_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__IF_JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int16_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_16_08+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__JUMP)\n\0");
                            int16_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_16_08+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__CLONE)\n\0");
                            int16_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_16_08);
                            int8_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_16_08);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__SWITCH)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_08);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V16_E8::OP__CHANGE_TYPE)\n\0");
                            int16_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_16_08);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int16_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_16_08(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_16_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_16_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_16_08++;
                }break;
                case SzCode::V08_E64:{VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__ADD)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__SUBTRACT)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__MULTIPLY)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__DIVIDE)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__MODULUS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__MORE_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__LESS_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__EQUALS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_08_64);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__PRINT)\n\0");
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint8_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__IF_JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_08_64+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_08_64+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__CLONE)\n\0");
                            int8_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_08_64);
                            int64_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_08_64);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__SWITCH)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_64);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E64::OP__CHANGE_TYPE)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_64);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int64_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_08_64(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_08_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_08_64(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_08_64++;
                }break;
                case SzCode::V08_E32:{VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__ADD)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__SUBTRACT)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__MULTIPLY)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__DIVIDE)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__MODULUS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__MORE_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__LESS_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__EQUALS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_08_32);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__PRINT)\n\0");
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint8_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__IF_JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_08_32+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_08_32+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__CLONE)\n\0");
                            int8_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_08_32);
                            int32_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_08_32);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__SWITCH)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_32);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E32::OP__CHANGE_TYPE)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_32);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int32_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_08_32(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_08_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_08_32(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_08_32++;
                }break;
                case SzCode::V08_E16:{VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__ADD)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__SUBTRACT)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__MULTIPLY)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__DIVIDE)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__MODULUS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__MORE_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__LESS_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__EQUALS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_08_16);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__PRINT)\n\0");
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint8_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__IF_JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_08_16+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_08_16+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__CLONE)\n\0");
                            int8_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_08_16);
                            int16_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_08_16);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__SWITCH)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_16);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E16::OP__CHANGE_TYPE)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_16);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int16_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_08_16(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_08_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_08_16(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_08_16++;
                }break;
                case SzCode::V08_E08:{VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>* ThisInstruction = (VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>*)CurrentInstruction;
                    switch(ThisInstruction->opcode){
                        case OpCode::OP__NULL:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__NULL)\n\0");
                            return false;
                        }break;
                        case OpCode::OP__EXIT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__EXIT)\n\0");
                        }break;
                        case OpCode::OP__ADD:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__ADD)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue+ThisValue_LastValue));
                        }break;
                        case OpCode::OP__SUBTRACT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__SUBTRACT)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue-ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MULTIPLY:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__MULTIPLY)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue*ThisValue_LastValue));
                        }break;
                        case OpCode::OP__DIVIDE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__DIVIDE)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue/ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MODULUS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__MODULUS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,ThisTpCode,(ThisValue_FirstValue%ThisValue_LastValue));
                        }break;
                        case OpCode::OP__MORE_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__MORE_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue>ThisValue_LastValue));
                        }break;
                        case OpCode::OP__LESS_THAN:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__LESS_THAN)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue<ThisValue_LastValue));
                        }break;
                        case OpCode::OP__EQUALS:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__EQUALS)\n\0");
                            int8_t ThisValue_LastValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_LastValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValue_FirstValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue_FirstValue);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack(CurrentSizeCode,OpCode::OP__DATA,TpCode::TP__BOOL,(ThisValue_FirstValue==ThisValue_LastValue));
                        }break;
                        case OpCode::OP__PUSH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__PUSH)\n\0");
                            PushToStack(CurrentSizeCode,InstructionCounter_08_08);
                        }break;
                        case OpCode::OP__PRINT:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__PRINT)\n\0");
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(CurrentSizeCode,ThisTpCode);
                            switch(ThisTpCode){
                                case TpCode::TP__INT:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(ThisValue));}break;
                                case TpCode::TP__CHAR:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__KEYBOARD:{Sauce::IO::GlobalTerminal->PutChar((char)ThisValue);}break;
                                case TpCode::TP__HEX:{Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint8_t)ThisValue));}break;
                            }
                            RemoveFromVirtualStack(CurrentSizeCode);
                        }break;
                        case OpCode::OP__IF_JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__IF_JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            int8_t ThisValueBase;GetValueFromVirtualStack(CurrentSizeCode,ThisValueBase);RemoveFromVirtualStack(CurrentSizeCode);
                            bool ThisValue=(bool)ThisValueBase;
                            if(ThisValue)InstructionCounter_08_08+=JumpTarget;
                        }break;
                        case OpCode::OP__JUMP:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__JUMP)\n\0");
                            int8_t JumpTarget;GetValueFromVirtualStack(CurrentSizeCode,JumpTarget);RemoveFromVirtualStack(CurrentSizeCode);
                            InstructionCounter_08_08+=JumpTarget;
                        }break;
                        case OpCode::OP__CLONE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__CLONE)\n\0");
                            int8_t FromStackTargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,FromStackTargetBase,InstructionCounter_08_08);
                            int8_t ToStackTargetBase;GetExtendedFromVirtualInstructions(CurrentSizeCode,ToStackTargetBase,InstructionCounter_08_08);
                            SzCode FromStackTarget=(SzCode)(int8_t)FromStackTargetBase;
                            SzCode ToStackTarget=(SzCode)(int8_t)ToStackTargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(FromStackTarget,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(FromStackTarget,ThisExtended);
                            TpCode ThisTpCode;GetTpCodeFromVirtualStack(FromStackTarget,ThisTpCode);
                            switch(ToStackTarget){
                                case SzCode::V64_E64:{AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V64_E32:{AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V64_E16:{AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V64_E08:{AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,(int64_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V32_E64:{AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V32_E32:{AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V32_E16:{AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V32_E08:{AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,(int32_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V16_E64:{AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V16_E32:{AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V16_E16:{AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V16_E08:{AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,(int16_t)ThisValue,(int8_t)ThisExtended);}break;
                                case SzCode::V08_E64:{AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int64_t)ThisExtended);}break;
                                case SzCode::V08_E32:{AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int32_t)ThisExtended);}break;
                                case SzCode::V08_E16:{AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int16_t)ThisExtended);}break;
                                case SzCode::V08_E08:{AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,(int8_t)ThisValue,(int8_t)ThisExtended);}break;
                            }
                        }break;
                        case OpCode::OP__SWITCH:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__SWITCH)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_08);
                            SzCode Target=(SzCode)(int8_t)TargetBase;
                            CurrentSizeCode=Target;
                        }break;
                        case OpCode::OP__CHANGE_TYPE:{
                            Sauce::IO::Debug::COM1_Console.Write("\t(V8_E8::OP__CHANGE_TYPE)\n\0");
                            int8_t TargetBase;GetValueFromVirtualInstructions(CurrentSizeCode,TargetBase,InstructionCounter_08_08);
                            TpCode Target=(TpCode)(int8_t)TargetBase;
                            int8_t ThisValue;GetValueFromVirtualStack(CurrentSizeCode,ThisValue);
                            int8_t ThisExtended;GetExtendedFromVirtualStack(CurrentSizeCode,ThisExtended);
                            RemoveFromVirtualStack(CurrentSizeCode);
                            AddToVirtualStack_08_08(OpCode::OP__DATA,Target,ThisValue,ThisExtended);
                        }break;
                        case OpCode::OP__GET_KEYBOARD:{
                            int8_t _Key,_Data;
                            if(GetKeyboard(_Key,_Data)){
                                AddToVirtualStack_08_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD,_Key,_Data);
                            }else{
                                AddToVirtualStack_08_08(OpCode::OP__DATA,TpCode::TP__KEYBOARD);
                            }
                        }break;
                    }//switch(ThisInstruction->opcode)
                    InstructionCounter_08_08++;
                }break;
               case SzCode::SZ__NULL:{return false;}break;
            }//switch(CurrentSizeCode)
            return true;
        }//bool VirtualMachine_cl::RunInstruction()
        void VirtualMachine_cl::Run(){
            AddEnd();
            do{
                GetInstruction();
            }while(RunInstruction());
            RemoveEnd();
        }
        void VirtualMachine_cl::AddInstruction_64_64(OpCode opcode,TpCode tpcode,int64_t value,int64_t extended){_VirtualInstructions_64_64.AddLast((VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>{opcode,tpcode,SzCode::V64_E64,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_64_32(OpCode opcode,TpCode tpcode,int64_t value,int32_t extended){_VirtualInstructions_64_32.AddLast((VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>{opcode,tpcode,SzCode::V64_E32,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_64_16(OpCode opcode,TpCode tpcode,int64_t value,int16_t extended){_VirtualInstructions_64_16.AddLast((VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>{opcode,tpcode,SzCode::V64_E16,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_64_08(OpCode opcode,TpCode tpcode,int64_t value,int8_t extended) {_VirtualInstructions_64_08.AddLast( (VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>{opcode,tpcode,SzCode::V64_E08,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_32_64(OpCode opcode,TpCode tpcode,int32_t value,int64_t extended){_VirtualInstructions_32_64.AddLast((VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>{opcode,tpcode,SzCode::V32_E64,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_32_32(OpCode opcode,TpCode tpcode,int32_t value,int32_t extended){_VirtualInstructions_32_32.AddLast((VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>{opcode,tpcode,SzCode::V32_E32,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_32_16(OpCode opcode,TpCode tpcode,int32_t value,int16_t extended){_VirtualInstructions_32_16.AddLast((VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>{opcode,tpcode,SzCode::V32_E16,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_32_08(OpCode opcode,TpCode tpcode,int32_t value,int8_t extended) {_VirtualInstructions_32_08.AddLast( (VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>{opcode,tpcode,SzCode::V32_E08,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_16_64(OpCode opcode,TpCode tpcode,int16_t value,int64_t extended){_VirtualInstructions_16_64.AddLast((VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>{opcode,tpcode,SzCode::V16_E64,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_16_32(OpCode opcode,TpCode tpcode,int16_t value,int32_t extended){_VirtualInstructions_16_32.AddLast((VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>{opcode,tpcode,SzCode::V16_E32,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_16_16(OpCode opcode,TpCode tpcode,int16_t value,int16_t extended){_VirtualInstructions_16_16.AddLast((VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>{opcode,tpcode,SzCode::V16_E16,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_16_08(OpCode opcode,TpCode tpcode,int16_t value,int8_t extended) {_VirtualInstructions_16_08.AddLast( (VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>{opcode,tpcode,SzCode::V16_E08,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_08_64(OpCode opcode,TpCode tpcode,int8_t value,int64_t extended) {_VirtualInstructions_08_64.AddLast( (VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>{opcode,tpcode,SzCode::V08_E64,{value,extended}}));} 
        void VirtualMachine_cl::AddInstruction_08_32(OpCode opcode,TpCode tpcode,int8_t value,int32_t extended) {_VirtualInstructions_08_32.AddLast( (VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>{opcode,tpcode,SzCode::V08_E32,{value,extended}}));} 
        void VirtualMachine_cl::AddInstruction_08_16(OpCode opcode,TpCode tpcode,int8_t value,int16_t extended) {_VirtualInstructions_08_16.AddLast( (VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>{opcode,tpcode,SzCode::V08_E16,{value,extended}}));}
        void VirtualMachine_cl::AddInstruction_08_08(OpCode opcode,TpCode tpcode,int8_t value,int8_t extended)  {_VirtualInstructions_08_08.AddLast(  (VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>{opcode,tpcode,SzCode::V08_E08,{value,extended}}));} 
        void VirtualMachine_cl::AddInstruction(SzCode szcode,OpCode opcode,TpCode tpcode,int8_t value,int8_t extended){
            switch(szcode){
                case SzCode::V64_E64:{AddInstruction_64_64(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E32:{AddInstruction_64_32(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E16:{AddInstruction_64_16(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E08:{AddInstruction_64_08(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E64:{AddInstruction_32_64(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E32:{AddInstruction_32_32(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E16:{AddInstruction_32_16(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E08:{AddInstruction_32_08(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E64:{AddInstruction_16_64(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E32:{AddInstruction_16_32(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E16:{AddInstruction_16_16(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E08:{AddInstruction_16_08(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E64:{AddInstruction_08_64(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E32:{AddInstruction_08_32(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E16:{AddInstruction_08_16(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E08:{AddInstruction_08_08(opcode,tpcode,value,extended);}break;
               case SzCode::SZ__NULL:{CurrentInstruction=nullptr;}break;
            }
        }

        void VirtualMachine_cl::AddToVirtualStack_64_64(OpCode opcode,TpCode tpcode,int64_t value,int64_t extended){_VirtualStack_64_64.AddLast((VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>{opcode,tpcode,SzCode::V64_E64,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_64_32(OpCode opcode,TpCode tpcode,int64_t value,int32_t extended){_VirtualStack_64_32.AddLast((VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>{opcode,tpcode,SzCode::V64_E32,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_64_16(OpCode opcode,TpCode tpcode,int64_t value,int16_t extended){_VirtualStack_64_16.AddLast((VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>{opcode,tpcode,SzCode::V64_E16,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_64_08(OpCode opcode,TpCode tpcode,int64_t value,int8_t extended) {_VirtualStack_64_08.AddLast( (VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>{opcode,tpcode,SzCode::V64_E08,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_32_64(OpCode opcode,TpCode tpcode,int32_t value,int64_t extended){_VirtualStack_32_64.AddLast((VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>{opcode,tpcode,SzCode::V32_E64,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_32_32(OpCode opcode,TpCode tpcode,int32_t value,int32_t extended){_VirtualStack_32_32.AddLast((VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>{opcode,tpcode,SzCode::V32_E32,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_32_16(OpCode opcode,TpCode tpcode,int32_t value,int16_t extended){_VirtualStack_32_16.AddLast((VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>{opcode,tpcode,SzCode::V32_E16,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_32_08(OpCode opcode,TpCode tpcode,int32_t value,int8_t extended) {_VirtualStack_32_08.AddLast( (VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>{opcode,tpcode,SzCode::V32_E08,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_16_64(OpCode opcode,TpCode tpcode,int16_t value,int64_t extended){_VirtualStack_16_64.AddLast((VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>{opcode,tpcode,SzCode::V16_E64,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_16_32(OpCode opcode,TpCode tpcode,int16_t value,int32_t extended){_VirtualStack_16_32.AddLast((VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>{opcode,tpcode,SzCode::V16_E32,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_16_16(OpCode opcode,TpCode tpcode,int16_t value,int16_t extended){_VirtualStack_16_16.AddLast((VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>{opcode,tpcode,SzCode::V16_E16,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_16_08(OpCode opcode,TpCode tpcode,int16_t value,int8_t extended) {_VirtualStack_16_08.AddLast( (VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>{opcode,tpcode,SzCode::V16_E08,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_08_64(OpCode opcode,TpCode tpcode,int8_t value,int64_t extended) {_VirtualStack_08_64.AddLast( (VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>{opcode,tpcode,SzCode::V08_E64,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_08_32(OpCode opcode,TpCode tpcode,int8_t value,int32_t extended) {_VirtualStack_08_32.AddLast( (VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>{opcode,tpcode,SzCode::V08_E32,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_08_16(OpCode opcode,TpCode tpcode,int8_t value,int16_t extended) {_VirtualStack_08_16.AddLast( (VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>{opcode,tpcode,SzCode::V08_E16,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack_08_08(OpCode opcode,TpCode tpcode,int8_t value,int8_t extended)  {_VirtualStack_08_08.AddLast(  (VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>{opcode,tpcode,SzCode::V08_E08,{value,extended}}));}
        void VirtualMachine_cl::AddToVirtualStack(SzCode szcode,OpCode opcode,TpCode tpcode,int8_t value,int8_t extended){
            switch(szcode){
                case SzCode::V64_E64:{AddToVirtualStack_64_64(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E32:{AddToVirtualStack_64_32(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E16:{AddToVirtualStack_64_16(opcode,tpcode,value,extended);}break;
                case SzCode::V64_E08:{AddToVirtualStack_64_08(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E64:{AddToVirtualStack_32_64(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E32:{AddToVirtualStack_32_32(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E16:{AddToVirtualStack_32_16(opcode,tpcode,value,extended);}break;
                case SzCode::V32_E08:{AddToVirtualStack_32_08(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E64:{AddToVirtualStack_16_64(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E32:{AddToVirtualStack_16_32(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E16:{AddToVirtualStack_16_16(opcode,tpcode,value,extended);}break;
                case SzCode::V16_E08:{AddToVirtualStack_16_08(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E64:{AddToVirtualStack_08_64(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E32:{AddToVirtualStack_08_32(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E16:{AddToVirtualStack_08_16(opcode,tpcode,value,extended);}break;
                case SzCode::V08_E08:{AddToVirtualStack_08_08(opcode,tpcode,value,extended);}break;
               case SzCode::SZ__NULL:{CurrentInstruction=nullptr;}break;
            }
        }

        VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_64_64(){return _VirtualStack_64_64.Last();}
        VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_64_32(){return _VirtualStack_64_32.Last();}
        VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_64_16(){return _VirtualStack_64_16.Last();}
        VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_64_08(){return _VirtualStack_64_08.Last();}
        VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_32_64(){return _VirtualStack_32_64.Last();}
        VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_32_32(){return _VirtualStack_32_32.Last();}
        VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_32_16(){return _VirtualStack_32_16.Last();}
        VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_32_08(){return _VirtualStack_32_08.Last();}
        VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_16_64(){return _VirtualStack_16_64.Last();}
        VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_16_32(){return _VirtualStack_16_32.Last();}
        VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> VirtualMachine_cl::GetLastFromVirtualStack_16_16(){return _VirtualStack_16_16.Last();}
        VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_16_08(){return _VirtualStack_16_08.Last();}
        VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_08_64(){return _VirtualStack_08_64.Last();}
        VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_08_32(){return _VirtualStack_08_32.Last();}
        VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  VirtualMachine_cl::GetLastFromVirtualStack_08_16(){return _VirtualStack_08_16.Last();}
        VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   VirtualMachine_cl::GetLastFromVirtualStack_08_08(){return _VirtualStack_08_08.Last();}
        VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_64_64(){return _VirtualStack_64_64.First();}
        VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_64_32(){return _VirtualStack_64_32.First();}
        VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_64_16(){return _VirtualStack_64_16.First();}
        VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_64_08(){return _VirtualStack_64_08.First();}
        VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_32_64(){return _VirtualStack_32_64.First();}
        VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_32_32(){return _VirtualStack_32_32.First();}
        VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_32_16(){return _VirtualStack_32_16.First();}
        VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_32_08(){return _VirtualStack_32_08.First();}
        VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_16_64(){return _VirtualStack_16_64.First();}
        VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_16_32(){return _VirtualStack_16_32.First();}
        VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> VirtualMachine_cl::GetFirstFromVirtualStack_16_16(){return _VirtualStack_16_16.First();}
        VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_16_08(){return _VirtualStack_16_08.First();}
        VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_08_64(){return _VirtualStack_08_64.First();}
        VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_08_32(){return _VirtualStack_08_32.First();}
        VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  VirtualMachine_cl::GetFirstFromVirtualStack_08_16(){return _VirtualStack_08_16.First();}
        VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   VirtualMachine_cl::GetFirstFromVirtualStack_08_08(){return _VirtualStack_08_08.First();}
        
        VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_64_64(size_t ThisInstructionCounter){return _VirtualInstructions_64_64[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_64_32(size_t ThisInstructionCounter){return _VirtualInstructions_64_32[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_64_16(size_t ThisInstructionCounter){return _VirtualInstructions_64_16[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_64_08(size_t ThisInstructionCounter){return _VirtualInstructions_64_08[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_32_64(size_t ThisInstructionCounter){return _VirtualInstructions_32_64[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_32_32(size_t ThisInstructionCounter){return _VirtualInstructions_32_32[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_32_16(size_t ThisInstructionCounter){return _VirtualInstructions_32_16[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_32_08(size_t ThisInstructionCounter){return _VirtualInstructions_32_08[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_16_64(size_t ThisInstructionCounter){return _VirtualInstructions_16_64[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_16_32(size_t ThisInstructionCounter){return _VirtualInstructions_16_32[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st> VirtualMachine_cl::GetFromVirtualInstructions_16_16(size_t ThisInstructionCounter){return _VirtualInstructions_16_16[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_16_08(size_t ThisInstructionCounter){return _VirtualInstructions_16_08[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_08_64(size_t ThisInstructionCounter){return _VirtualInstructions_08_64[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_08_32(size_t ThisInstructionCounter){return _VirtualInstructions_08_32[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>  VirtualMachine_cl::GetFromVirtualInstructions_08_16(size_t ThisInstructionCounter){return _VirtualInstructions_08_16[ThisInstructionCounter];}
        VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>   VirtualMachine_cl::GetFromVirtualInstructions_08_08(size_t ThisInstructionCounter){return _VirtualInstructions_08_08[ThisInstructionCounter];}


        void VirtualMachine_cl::AddEnd(){
            if(!hasEnd){_VirtualInstructions_64_64.AddLast((VirtualStack_st<VirtualStack::V64::E64::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_64_32.AddLast((VirtualStack_st<VirtualStack::V64::E32::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_64_16.AddLast((VirtualStack_st<VirtualStack::V64::E16::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_64_08.AddLast( (VirtualStack_st<VirtualStack::V64::E8::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_32_64.AddLast((VirtualStack_st<VirtualStack::V32::E64::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_32_32.AddLast((VirtualStack_st<VirtualStack::V32::E32::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_32_16.AddLast((VirtualStack_st<VirtualStack::V32::E16::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_32_08.AddLast( (VirtualStack_st<VirtualStack::V32::E8::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_16_64.AddLast((VirtualStack_st<VirtualStack::V16::E64::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_16_32.AddLast((VirtualStack_st<VirtualStack::V16::E32::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_16_16.AddLast((VirtualStack_st<VirtualStack::V16::E16::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_16_08.AddLast( (VirtualStack_st<VirtualStack::V16::E8::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_08_64.AddLast( (VirtualStack_st<VirtualStack::V8::E64::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_08_32.AddLast( (VirtualStack_st<VirtualStack::V8::E32::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_08_16.AddLast( (VirtualStack_st<VirtualStack::V8::E16::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            if(!hasEnd){_VirtualInstructions_08_08.AddLast(  (VirtualStack_st<VirtualStack::V8::E8::VirtualStack_st>{OpCode::OP__NULL,TpCode::TP__NULL,SzCode::SZ__NULL,{0,0}}));}
            hasEnd=true;
        }
        void VirtualMachine_cl::RemoveEnd(){
            if(hasEnd){_VirtualInstructions_64_64.RemoveLast();}
            if(hasEnd){_VirtualInstructions_64_32.RemoveLast();}
            if(hasEnd){_VirtualInstructions_64_16.RemoveLast();}
            if(hasEnd){_VirtualInstructions_64_08.RemoveLast();}
            if(hasEnd){_VirtualInstructions_32_64.RemoveLast();}
            if(hasEnd){_VirtualInstructions_32_32.RemoveLast();}
            if(hasEnd){_VirtualInstructions_32_16.RemoveLast();}
            if(hasEnd){_VirtualInstructions_32_08.RemoveLast();}
            if(hasEnd){_VirtualInstructions_16_64.RemoveLast();}
            if(hasEnd){_VirtualInstructions_16_32.RemoveLast();}
            if(hasEnd){_VirtualInstructions_16_16.RemoveLast();}
            if(hasEnd){_VirtualInstructions_16_08.RemoveLast();}
            if(hasEnd){_VirtualInstructions_08_64.RemoveLast();}
            if(hasEnd){_VirtualInstructions_08_32.RemoveLast();}
            if(hasEnd){_VirtualInstructions_08_16.RemoveLast();}
            if(hasEnd){_VirtualInstructions_08_08.RemoveLast();}
            hasEnd=false;
        }

        void VirtualMachine_cl::GetValueFromVirtualInstructions(SzCode szcode,int8_t &value,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{value=(int8_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E32:{value=(int8_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E16:{value=(int8_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E08:{value=(int8_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E64:{value=(int8_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E32:{value=(int8_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E16:{value=(int8_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E08:{value=(int8_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E64:{value=(int8_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E32:{value=(int8_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E16:{value=(int8_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E08:{value=(int8_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E64:{value=(int8_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E32:{value=(int8_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E16:{value=(int8_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E08:{value=(int8_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualInstructions(SzCode szcode,int16_t &value,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{value=(int16_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E32:{value=(int16_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E16:{value=(int16_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E08:{value=(int16_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E64:{value=(int16_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E32:{value=(int16_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E16:{value=(int16_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E08:{value=(int16_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E64:{value=(int16_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E32:{value=(int16_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E16:{value=(int16_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E08:{value=(int16_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E64:{value=(int16_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E32:{value=(int16_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E16:{value=(int16_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E08:{value=(int16_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualInstructions(SzCode szcode,int32_t &value,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{value=(int32_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E32:{value=(int32_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E16:{value=(int32_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E08:{value=(int32_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E64:{value=(int32_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E32:{value=(int32_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E16:{value=(int32_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E08:{value=(int32_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E64:{value=(int32_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E32:{value=(int32_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E16:{value=(int32_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E08:{value=(int32_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E64:{value=(int32_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E32:{value=(int32_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E16:{value=(int32_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E08:{value=(int32_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualInstructions(SzCode szcode,int64_t &value,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{value=(int64_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E32:{value=(int64_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E16:{value=(int64_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V64_E08:{value=(int64_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E64:{value=(int64_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E32:{value=(int64_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E16:{value=(int64_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V32_E08:{value=(int64_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E64:{value=(int64_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E32:{value=(int64_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E16:{value=(int64_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V16_E08:{value=(int64_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E64:{value=(int64_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E32:{value=(int64_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E16:{value=(int64_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Value;}break;
                case SzCode::V08_E08:{value=(int64_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualInstructions(SzCode szcode,int8_t &extended,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int8_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int8_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int8_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int8_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int8_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int8_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int8_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int8_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int8_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int8_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int8_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int8_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int8_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int8_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int8_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int8_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualInstructions(SzCode szcode,int16_t &extended,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int16_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int16_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int16_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int16_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int16_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int16_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int16_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int16_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int16_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int16_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int16_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int16_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int16_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int16_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int16_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int16_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualInstructions(SzCode szcode,int32_t &extended,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int32_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int32_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int32_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int32_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int32_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int32_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int32_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int32_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int32_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int32_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int32_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int32_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int32_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int32_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int32_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int32_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualInstructions(SzCode szcode,int64_t &extended,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int64_t)GetFromVirtualInstructions_64_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int64_t)GetFromVirtualInstructions_64_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int64_t)GetFromVirtualInstructions_64_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int64_t)GetFromVirtualInstructions_64_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int64_t)GetFromVirtualInstructions_32_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int64_t)GetFromVirtualInstructions_32_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int64_t)GetFromVirtualInstructions_32_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int64_t)GetFromVirtualInstructions_32_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int64_t)GetFromVirtualInstructions_16_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int64_t)GetFromVirtualInstructions_16_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int64_t)GetFromVirtualInstructions_16_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int64_t)GetFromVirtualInstructions_16_08(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int64_t)GetFromVirtualInstructions_08_64(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int64_t)GetFromVirtualInstructions_08_32(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int64_t)GetFromVirtualInstructions_08_16(ThisInstructionCounter).Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int64_t)GetFromVirtualInstructions_08_08(ThisInstructionCounter).Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualStack(SzCode szcode,int8_t &value){
            switch(szcode){
                case SzCode::V64_E64:{value=(int8_t)GetLastFromVirtualStack_64_64().Data.Value;}break;
                case SzCode::V64_E32:{value=(int8_t)GetLastFromVirtualStack_64_32().Data.Value;}break;
                case SzCode::V64_E16:{value=(int8_t)GetLastFromVirtualStack_64_16().Data.Value;}break;
                case SzCode::V64_E08:{value=(int8_t)GetLastFromVirtualStack_64_08().Data.Value;}break;
                case SzCode::V32_E64:{value=(int8_t)GetLastFromVirtualStack_32_64().Data.Value;}break;
                case SzCode::V32_E32:{value=(int8_t)GetLastFromVirtualStack_32_32().Data.Value;}break;
                case SzCode::V32_E16:{value=(int8_t)GetLastFromVirtualStack_32_16().Data.Value;}break;
                case SzCode::V32_E08:{value=(int8_t)GetLastFromVirtualStack_32_08().Data.Value;}break;
                case SzCode::V16_E64:{value=(int8_t)GetLastFromVirtualStack_16_64().Data.Value;}break;
                case SzCode::V16_E32:{value=(int8_t)GetLastFromVirtualStack_16_32().Data.Value;}break;
                case SzCode::V16_E16:{value=(int8_t)GetLastFromVirtualStack_16_16().Data.Value;}break;
                case SzCode::V16_E08:{value=(int8_t)GetLastFromVirtualStack_16_08().Data.Value;}break;
                case SzCode::V08_E64:{value=(int8_t)GetLastFromVirtualStack_08_64().Data.Value;}break;
                case SzCode::V08_E32:{value=(int8_t)GetLastFromVirtualStack_08_32().Data.Value;}break;
                case SzCode::V08_E16:{value=(int8_t)GetLastFromVirtualStack_08_16().Data.Value;}break;
                case SzCode::V08_E08:{value=(int8_t)GetLastFromVirtualStack_08_08().Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualStack(SzCode szcode,int16_t &value){
            switch(szcode){
                case SzCode::V64_E64:{value=(int16_t)GetLastFromVirtualStack_64_64().Data.Value;}break;
                case SzCode::V64_E32:{value=(int16_t)GetLastFromVirtualStack_64_32().Data.Value;}break;
                case SzCode::V64_E16:{value=(int16_t)GetLastFromVirtualStack_64_16().Data.Value;}break;
                case SzCode::V64_E08:{value=(int16_t)GetLastFromVirtualStack_64_08().Data.Value;}break;
                case SzCode::V32_E64:{value=(int16_t)GetLastFromVirtualStack_32_64().Data.Value;}break;
                case SzCode::V32_E32:{value=(int16_t)GetLastFromVirtualStack_32_32().Data.Value;}break;
                case SzCode::V32_E16:{value=(int16_t)GetLastFromVirtualStack_32_16().Data.Value;}break;
                case SzCode::V32_E08:{value=(int16_t)GetLastFromVirtualStack_32_08().Data.Value;}break;
                case SzCode::V16_E64:{value=(int16_t)GetLastFromVirtualStack_16_64().Data.Value;}break;
                case SzCode::V16_E32:{value=(int16_t)GetLastFromVirtualStack_16_32().Data.Value;}break;
                case SzCode::V16_E16:{value=(int16_t)GetLastFromVirtualStack_16_16().Data.Value;}break;
                case SzCode::V16_E08:{value=(int16_t)GetLastFromVirtualStack_16_08().Data.Value;}break;
                case SzCode::V08_E64:{value=(int16_t)GetLastFromVirtualStack_08_64().Data.Value;}break;
                case SzCode::V08_E32:{value=(int16_t)GetLastFromVirtualStack_08_32().Data.Value;}break;
                case SzCode::V08_E16:{value=(int16_t)GetLastFromVirtualStack_08_16().Data.Value;}break;
                case SzCode::V08_E08:{value=(int16_t)GetLastFromVirtualStack_08_08().Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualStack(SzCode szcode,int32_t &value){
            switch(szcode){
                case SzCode::V64_E64:{value=(int32_t)GetLastFromVirtualStack_64_64().Data.Value;}break;
                case SzCode::V64_E32:{value=(int32_t)GetLastFromVirtualStack_64_32().Data.Value;}break;
                case SzCode::V64_E16:{value=(int32_t)GetLastFromVirtualStack_64_16().Data.Value;}break;
                case SzCode::V64_E08:{value=(int32_t)GetLastFromVirtualStack_64_08().Data.Value;}break;
                case SzCode::V32_E64:{value=(int32_t)GetLastFromVirtualStack_32_64().Data.Value;}break;
                case SzCode::V32_E32:{value=(int32_t)GetLastFromVirtualStack_32_32().Data.Value;}break;
                case SzCode::V32_E16:{value=(int32_t)GetLastFromVirtualStack_32_16().Data.Value;}break;
                case SzCode::V32_E08:{value=(int32_t)GetLastFromVirtualStack_32_08().Data.Value;}break;
                case SzCode::V16_E64:{value=(int32_t)GetLastFromVirtualStack_16_64().Data.Value;}break;
                case SzCode::V16_E32:{value=(int32_t)GetLastFromVirtualStack_16_32().Data.Value;}break;
                case SzCode::V16_E16:{value=(int32_t)GetLastFromVirtualStack_16_16().Data.Value;}break;
                case SzCode::V16_E08:{value=(int32_t)GetLastFromVirtualStack_16_08().Data.Value;}break;
                case SzCode::V08_E64:{value=(int32_t)GetLastFromVirtualStack_08_64().Data.Value;}break;
                case SzCode::V08_E32:{value=(int32_t)GetLastFromVirtualStack_08_32().Data.Value;}break;
                case SzCode::V08_E16:{value=(int32_t)GetLastFromVirtualStack_08_16().Data.Value;}break;
                case SzCode::V08_E08:{value=(int32_t)GetLastFromVirtualStack_08_08().Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetValueFromVirtualStack(SzCode szcode,int64_t &value){
            switch(szcode){
                case SzCode::V64_E64:{value=(int64_t)GetLastFromVirtualStack_64_64().Data.Value;}break;
                case SzCode::V64_E32:{value=(int64_t)GetLastFromVirtualStack_64_32().Data.Value;}break;
                case SzCode::V64_E16:{value=(int64_t)GetLastFromVirtualStack_64_16().Data.Value;}break;
                case SzCode::V64_E08:{value=(int64_t)GetLastFromVirtualStack_64_08().Data.Value;}break;
                case SzCode::V32_E64:{value=(int64_t)GetLastFromVirtualStack_32_64().Data.Value;}break;
                case SzCode::V32_E32:{value=(int64_t)GetLastFromVirtualStack_32_32().Data.Value;}break;
                case SzCode::V32_E16:{value=(int64_t)GetLastFromVirtualStack_32_16().Data.Value;}break;
                case SzCode::V32_E08:{value=(int64_t)GetLastFromVirtualStack_32_08().Data.Value;}break;
                case SzCode::V16_E64:{value=(int64_t)GetLastFromVirtualStack_16_64().Data.Value;}break;
                case SzCode::V16_E32:{value=(int64_t)GetLastFromVirtualStack_16_32().Data.Value;}break;
                case SzCode::V16_E16:{value=(int64_t)GetLastFromVirtualStack_16_16().Data.Value;}break;
                case SzCode::V16_E08:{value=(int64_t)GetLastFromVirtualStack_16_08().Data.Value;}break;
                case SzCode::V08_E64:{value=(int64_t)GetLastFromVirtualStack_08_64().Data.Value;}break;
                case SzCode::V08_E32:{value=(int64_t)GetLastFromVirtualStack_08_32().Data.Value;}break;
                case SzCode::V08_E16:{value=(int64_t)GetLastFromVirtualStack_08_16().Data.Value;}break;
                case SzCode::V08_E08:{value=(int64_t)GetLastFromVirtualStack_08_08().Data.Value;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualStack(SzCode szcode,int8_t &extended){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int8_t)GetLastFromVirtualStack_64_64().Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int8_t)GetLastFromVirtualStack_64_32().Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int8_t)GetLastFromVirtualStack_64_16().Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int8_t)GetLastFromVirtualStack_64_08().Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int8_t)GetLastFromVirtualStack_32_64().Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int8_t)GetLastFromVirtualStack_32_32().Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int8_t)GetLastFromVirtualStack_32_16().Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int8_t)GetLastFromVirtualStack_32_08().Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int8_t)GetLastFromVirtualStack_16_64().Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int8_t)GetLastFromVirtualStack_16_32().Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int8_t)GetLastFromVirtualStack_16_16().Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int8_t)GetLastFromVirtualStack_16_08().Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int8_t)GetLastFromVirtualStack_08_64().Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int8_t)GetLastFromVirtualStack_08_32().Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int8_t)GetLastFromVirtualStack_08_16().Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int8_t)GetLastFromVirtualStack_08_08().Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualStack(SzCode szcode,int16_t &extended){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int16_t)GetLastFromVirtualStack_64_64().Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int16_t)GetLastFromVirtualStack_64_32().Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int16_t)GetLastFromVirtualStack_64_16().Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int16_t)GetLastFromVirtualStack_64_08().Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int16_t)GetLastFromVirtualStack_32_64().Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int16_t)GetLastFromVirtualStack_32_32().Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int16_t)GetLastFromVirtualStack_32_16().Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int16_t)GetLastFromVirtualStack_32_08().Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int16_t)GetLastFromVirtualStack_16_64().Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int16_t)GetLastFromVirtualStack_16_32().Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int16_t)GetLastFromVirtualStack_16_16().Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int16_t)GetLastFromVirtualStack_16_08().Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int16_t)GetLastFromVirtualStack_08_64().Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int16_t)GetLastFromVirtualStack_08_32().Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int16_t)GetLastFromVirtualStack_08_16().Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int16_t)GetLastFromVirtualStack_08_08().Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualStack(SzCode szcode,int32_t &extended){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int32_t)GetLastFromVirtualStack_64_64().Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int32_t)GetLastFromVirtualStack_64_32().Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int32_t)GetLastFromVirtualStack_64_16().Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int32_t)GetLastFromVirtualStack_64_08().Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int32_t)GetLastFromVirtualStack_32_64().Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int32_t)GetLastFromVirtualStack_32_32().Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int32_t)GetLastFromVirtualStack_32_16().Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int32_t)GetLastFromVirtualStack_32_08().Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int32_t)GetLastFromVirtualStack_16_64().Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int32_t)GetLastFromVirtualStack_16_32().Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int32_t)GetLastFromVirtualStack_16_16().Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int32_t)GetLastFromVirtualStack_16_08().Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int32_t)GetLastFromVirtualStack_08_64().Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int32_t)GetLastFromVirtualStack_08_32().Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int32_t)GetLastFromVirtualStack_08_16().Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int32_t)GetLastFromVirtualStack_08_08().Data.Extended;}break;
            }
        }
        void VirtualMachine_cl::GetExtendedFromVirtualStack(SzCode szcode,int64_t &extended){
            switch(szcode){
                case SzCode::V64_E64:{extended=(int64_t)GetLastFromVirtualStack_64_64().Data.Extended;}break;
                case SzCode::V64_E32:{extended=(int64_t)GetLastFromVirtualStack_64_32().Data.Extended;}break;
                case SzCode::V64_E16:{extended=(int64_t)GetLastFromVirtualStack_64_16().Data.Extended;}break;
                case SzCode::V64_E08:{extended=(int64_t)GetLastFromVirtualStack_64_08().Data.Extended;}break;
                case SzCode::V32_E64:{extended=(int64_t)GetLastFromVirtualStack_32_64().Data.Extended;}break;
                case SzCode::V32_E32:{extended=(int64_t)GetLastFromVirtualStack_32_32().Data.Extended;}break;
                case SzCode::V32_E16:{extended=(int64_t)GetLastFromVirtualStack_32_16().Data.Extended;}break;
                case SzCode::V32_E08:{extended=(int64_t)GetLastFromVirtualStack_32_08().Data.Extended;}break;
                case SzCode::V16_E64:{extended=(int64_t)GetLastFromVirtualStack_16_64().Data.Extended;}break;
                case SzCode::V16_E32:{extended=(int64_t)GetLastFromVirtualStack_16_32().Data.Extended;}break;
                case SzCode::V16_E16:{extended=(int64_t)GetLastFromVirtualStack_16_16().Data.Extended;}break;
                case SzCode::V16_E08:{extended=(int64_t)GetLastFromVirtualStack_16_08().Data.Extended;}break;
                case SzCode::V08_E64:{extended=(int64_t)GetLastFromVirtualStack_08_64().Data.Extended;}break;
                case SzCode::V08_E32:{extended=(int64_t)GetLastFromVirtualStack_08_32().Data.Extended;}break;
                case SzCode::V08_E16:{extended=(int64_t)GetLastFromVirtualStack_08_16().Data.Extended;}break;
                case SzCode::V08_E08:{extended=(int64_t)GetLastFromVirtualStack_08_08().Data.Extended;}break;
            }
        }

        void VirtualMachine_cl::GetTpCodeFromVirtualStack(SzCode szcode,TpCode &tpcode){
            switch(szcode){
                case SzCode::V64_E64:{tpcode=GetLastFromVirtualStack_64_64().Type;}break;
                case SzCode::V64_E32:{tpcode=GetLastFromVirtualStack_64_32().Type;}break;
                case SzCode::V64_E16:{tpcode=GetLastFromVirtualStack_64_16().Type;}break;
                case SzCode::V64_E08:{tpcode=GetLastFromVirtualStack_64_08().Type;}break;
                case SzCode::V32_E64:{tpcode=GetLastFromVirtualStack_32_64().Type;}break;
                case SzCode::V32_E32:{tpcode=GetLastFromVirtualStack_32_32().Type;}break;
                case SzCode::V32_E16:{tpcode=GetLastFromVirtualStack_32_16().Type;}break;
                case SzCode::V32_E08:{tpcode=GetLastFromVirtualStack_32_08().Type;}break;
                case SzCode::V16_E64:{tpcode=GetLastFromVirtualStack_16_64().Type;}break;
                case SzCode::V16_E32:{tpcode=GetLastFromVirtualStack_16_32().Type;}break;
                case SzCode::V16_E16:{tpcode=GetLastFromVirtualStack_16_16().Type;}break;
                case SzCode::V16_E08:{tpcode=GetLastFromVirtualStack_16_08().Type;}break;
                case SzCode::V08_E64:{tpcode=GetLastFromVirtualStack_08_64().Type;}break;
                case SzCode::V08_E32:{tpcode=GetLastFromVirtualStack_08_32().Type;}break;
                case SzCode::V08_E16:{tpcode=GetLastFromVirtualStack_08_16().Type;}break;
                case SzCode::V08_E08:{tpcode=GetLastFromVirtualStack_08_08().Type;}break;
            }
        }
        void VirtualMachine_cl::GetTpCodeFromVirtualInstructions(SzCode szcode,TpCode &tpcode,size_t ThisInstructionCounter){
            switch(szcode){
                case SzCode::V64_E64:{tpcode=GetFromVirtualInstructions_64_64(ThisInstructionCounter).Type;}break;
                case SzCode::V64_E32:{tpcode=GetFromVirtualInstructions_64_32(ThisInstructionCounter).Type;}break;
                case SzCode::V64_E16:{tpcode=GetFromVirtualInstructions_64_16(ThisInstructionCounter).Type;}break;
                case SzCode::V64_E08:{tpcode=GetFromVirtualInstructions_64_08(ThisInstructionCounter).Type;}break;
                case SzCode::V32_E64:{tpcode=GetFromVirtualInstructions_32_64(ThisInstructionCounter).Type;}break;
                case SzCode::V32_E32:{tpcode=GetFromVirtualInstructions_32_32(ThisInstructionCounter).Type;}break;
                case SzCode::V32_E16:{tpcode=GetFromVirtualInstructions_32_16(ThisInstructionCounter).Type;}break;
                case SzCode::V32_E08:{tpcode=GetFromVirtualInstructions_32_08(ThisInstructionCounter).Type;}break;
                case SzCode::V16_E64:{tpcode=GetFromVirtualInstructions_16_64(ThisInstructionCounter).Type;}break;
                case SzCode::V16_E32:{tpcode=GetFromVirtualInstructions_16_32(ThisInstructionCounter).Type;}break;
                case SzCode::V16_E16:{tpcode=GetFromVirtualInstructions_16_16(ThisInstructionCounter).Type;}break;
                case SzCode::V16_E08:{tpcode=GetFromVirtualInstructions_16_08(ThisInstructionCounter).Type;}break;
                case SzCode::V08_E64:{tpcode=GetFromVirtualInstructions_08_64(ThisInstructionCounter).Type;}break;
                case SzCode::V08_E32:{tpcode=GetFromVirtualInstructions_08_32(ThisInstructionCounter).Type;}break;
                case SzCode::V08_E16:{tpcode=GetFromVirtualInstructions_08_16(ThisInstructionCounter).Type;}break;
                case SzCode::V08_E08:{tpcode=GetFromVirtualInstructions_08_08(ThisInstructionCounter).Type;}break;
            }
        }
        void  VirtualMachine_cl::PushToStack(SzCode Instruction_szcode,size_t ThisInstructionCounter){
            switch(Instruction_szcode){
                case SzCode::V64_E64:{int64_t ThisValue;int64_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_64_64(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V64_E32:{int64_t ThisValue;int32_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_64_32(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V64_E16:{int64_t ThisValue;int16_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_64_16(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V64_E08:{int64_t ThisValue;int8_t ThisExtended; TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_64_08(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V32_E64:{int32_t ThisValue;int64_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_32_64(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V32_E32:{int32_t ThisValue;int32_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_32_32(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V32_E16:{int32_t ThisValue;int16_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_32_16(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V32_E08:{int32_t ThisValue;int8_t ThisExtended; TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_32_08(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V16_E64:{int16_t ThisValue;int64_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_16_64(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V16_E32:{int16_t ThisValue;int32_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_16_32(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V16_E16:{int16_t ThisValue;int16_t ThisExtended;TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_16_16(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V16_E08:{int16_t ThisValue;int8_t ThisExtended; TpCode ThisTpCode;GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_16_08(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V08_E64:{int8_t ThisValue;int64_t ThisExtended;TpCode ThisTpCode; GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_08_64(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V08_E32:{int8_t ThisValue;int32_t ThisExtended;TpCode ThisTpCode; GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_08_32(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V08_E16:{int8_t ThisValue;int16_t ThisExtended;TpCode ThisTpCode; GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_08_16(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
                case SzCode::V08_E08:{int8_t ThisValue;int8_t ThisExtended; TpCode ThisTpCode; GetTpCodeFromVirtualInstructions(Instruction_szcode,ThisTpCode,ThisInstructionCounter);GetValueFromVirtualInstructions(Instruction_szcode,ThisValue,ThisInstructionCounter);GetExtendedFromVirtualInstructions(Instruction_szcode,ThisExtended,ThisInstructionCounter);AddToVirtualStack_08_08(OpCode::OP__DATA,ThisTpCode,ThisValue,ThisExtended);}break;
            }
        }
        void VirtualMachine_cl::RemoveFromVirtualStack(SzCode szcode){
            switch(szcode){
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
        bool VirtualMachine_cl::GetKeyboard(int8_t &value,int8_t &extended){
            if(_Virtual_Keyboard.Size() < 1)return false;
            value = _Virtual_Keyboard.Last().Data.Value;
            extended = _Virtual_Keyboard.Last().Data.Extended;
            _Virtual_Keyboard.RemoveLast();
            return true;
        }
        void VirtualMachine_cl::AddKeyboard(int8_t value,int8_t extended){
            _Virtual_Keyboard.AddFirst({OpCode::OP__DATA,TpCode::TP__KEYBOARD,SzCode::V08_E08,{value,extended}});
        }
    };
};