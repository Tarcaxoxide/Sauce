#include<Sauce/Commands.hpp>
#include<Sauce/Global.hpp>

namespace Sauce{
    namespace Commands{
        Command_st* Command_st::BaseCommandReference=nullptr;
        Command_st::Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Sauce::Memory::List_cl<Command_st*> SubCommands,Sauce::Memory::List_cl<wchar_t> HelpString){
            if(BaseCommandReference == nullptr)BaseCommandReference=this;
            ExecutableBody=nullptr;
            this->CommandString=CommandString;
            this->HelpString=HelpString;
        }
        Command_st::Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Command_st* (*ExecutableBody)(Command_st* Caller),Sauce::Memory::List_cl<wchar_t> HelpString){
            if(BaseCommandReference == nullptr)BaseCommandReference=this;
            this->CommandString=CommandString;
            this->ExecutableBody=ExecutableBody;
            this->HelpString=HelpString;
        }
        Command_st::Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Sauce::Memory::List_cl<wchar_t> HelpString){
            if(BaseCommandReference == nullptr)BaseCommandReference=this;
            ExecutableBody=nullptr;
            this->CommandString=CommandString;
            this->HelpString=HelpString;
        }
        Command_st::~Command_st(){
            for(size_t i=0;i<SubCommands.Size();i++){
                delete[] SubCommands[i];
            }
            SubCommands.Clear();
        }
        Command_st* Command_st::operator()(size_t ArgumentIndex,Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>>* Arguments){
            ReturnPtr=(void*)nullptr;
            ReturnString=(wchar_t*)"";
            this->ArgumentIndex=ArgumentIndex;
            this->Arguments=Arguments;
            Sauce::Memory::List_cl<wchar_t> Argument = (*Arguments)[ArgumentIndex];
            if(ExecutableBody != nullptr){
                Command_st* Return = (*ExecutableBody)(this);
                Return->Arguments->Clear();
                return Return;
            }else{
                for(size_t i=0;i<SubCommands.Size();i++){
                    if(SubCommands[i]->CommandString == Argument)return SubCommands[i];
                }
            }
            return nullptr;
        }
        Command_st* Command_st::AddSubCommand(Command_st* nCommand){
            SubCommands.AddLast(nCommand);
            return nCommand;
        }
    };
};