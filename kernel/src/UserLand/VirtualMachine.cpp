#include<Sauce/UserLand/VirtualMachine.hpp>


namespace Sauce{
    namespace UserLand{
        VirtualMachine_cl::VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code){
            for(size_t i=0;i<code.Size();i++){ // prerun stage, get the tags and what not.
                if(code[i].opcode == OP__TAG){
                    _VirtaulStackTags.AddLast(Sauce::UserLand::VirtualStack_st{TP__TAG,code[i].Data.Value,i});
                }
            }
            for(size_t i=0;i<code.Size();i++){ // run stage.
                switch(code[i].opcode){
                    case OP__PUSH:{
                        _VirtualStack.AddLast(code[i].Data);
                    }break;//OP__PUSH
                    case OP__JUMP:{
                        for(size_t a=0;a<_VirtaulStackTags.Size();a++){
                            if(_VirtaulStackTags[a].Value == code[i].Data.Value){
                                i=_VirtaulStackTags[a].eValue;
                                break;
                            }
                        }
                        continue;
                    }break;//OP__JUMP
                    case OP__IF_JUMP:{
                        bool Condition = (bool)_VirtualStack.Last().Value;
                        _VirtualStack.RemoveLast();
                        if(!Condition)continue; // if the condition is false than we skip. if not than we perform.
                        for(size_t a=0;a<_VirtaulStackTags.Size();a++){
                            if(_VirtaulStackTags[a].Value == code[i].Data.Value){
                                i=_VirtaulStackTags[a].eValue;
                                break;
                            }
                        }
                        continue;
                    }break;//OP__IF_JUMP
                    case OP__CLONE:{
                        bool Condition = (bool)_VirtualStack.Last().Value;
                        _VirtualStack.AddLast(_VirtualStack.Last());
                    }break;//OP__CLONE
                    case OP__CLEAR_STACK:{
                        _VirtualStack.Clear();
                    }break;//OP__CLEAR_STACK
                    case OP__ADD:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__SIGNED_INT,(LeftHandValue+RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__UNSIGNED_INT,(LeftHandValue+RightHandValue)});
                            }break;
                        }
                    }break;//OP__ADD
                    case OP__SUBTRACT:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__SIGNED_INT,(LeftHandValue-RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__UNSIGNED_INT,(LeftHandValue-RightHandValue)});
                            }break;
                        }
                    }break;//OP__SUBTRACT
                    case OP__MULTIPLY:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__SIGNED_INT,(LeftHandValue*RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__UNSIGNED_INT,(LeftHandValue*RightHandValue)});
                            }break;
                        }
                    }break;//OP__MULTIPLY
                    case OP__DIVIDE:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__SIGNED_INT,(LeftHandValue/RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__UNSIGNED_INT,(LeftHandValue/RightHandValue)});
                            }break;
                        }
                    }break;//OP__DIVIDE
                    case OP__MODULUS:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__SIGNED_INT,(LeftHandValue%RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__UNSIGNED_INT,(LeftHandValue%RightHandValue)});
                            }break;
                        }
                    }break;//OP__MODULUS
                    case OP__LESS_THAN:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue<RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue<RightHandValue)});
                            }break;
                        }
                    }break;//OP__LESS_THAN
                    case OP__MORE_THAN:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue>RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue>RightHandValue)});
                            }break;
                        }
                    }break;//OP__MORE_THAN
                    case OP__EQUALS:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                int64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue==RightHandValue)});
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t RightHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                uint64_t LeftHandValue = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                _VirtualStack.AddLast({TP__BOOL,(LeftHandValue==RightHandValue)});
                            }break;
                        }
                    }break;//OP__EQUALS
                    case OP__PRINT:{
                        TpCode TargetType = _VirtualStack.Last().Type;
                        switch(TargetType){
                            case TP__SIGNED_INT:{
                                int64_t Value = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(Value));
                            }break;
                            case TP__UNSIGNED_INT:{
                                uint64_t Value = _VirtualStack.Last().Value;
                                _VirtualStack.RemoveLast();
                                Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(Value));
                            }break;
                        }
                    }break;//OP__PRINT
                }//switch(code[i].opcode)
            }//for(size_t i=0;i<code.Size();i++)
        }
        
    };
};