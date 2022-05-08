#include<Sauce/UserLand/VirtualMachine.hpp>


namespace Sauce{
    namespace UserLand{
        VirtualMachine_cl::VirtualMachine_cl(Sauce::Memory::List_cl<Instruction_st> code);{
            for(size_t i=0;i<code.Size();i++){
                _code.AddLast(code[i]);
            }
        }
        void VirtualMachine_cl::Run(){
            size_t CurrentInstruction=1;
            while(_code[CurrentInstruction].opcode != Op__NULL){
                switch(_code[CurrentInstruction].opcode){
                    case OP__EXIT:{
                        CurrentInstruction=0; // set the current instruction counter to a known null instruction at 0.
                    }break;
                    case OP__ADD_INT:{
                        uint64_t RightSideNumber = _VirtualStack.Last();
                        _VirtualStack.RemoveLast();
                        uint64_t LeftSideNumber = _VirtualStack.Last();
                        _VirtualStack.RemoveLast();
                        _VirtualStack.AddLast(LeftSideNumber+RightSideNumber);
                        CurrentInstruction++;
                    }break;
                    case OP__PUSH_INT:{
                        _VirtualStack.AddLast(_code[CurrentInstruction].Data);
                        CurrentInstruction++;
                    }break;
                    case OP__PRINT_INT:{
                        uint64_t number = _VirtualStack.Last();
                        _VirtualStack.RemoveLast();
                        Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::ToString(number));
                        Sauce::IO::GlobalTerminal->PutString("\n\r");
                        CurrentInstruction++;
                    }break;
                }
            }
        }
    };
};