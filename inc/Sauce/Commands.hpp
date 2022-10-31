#pragma once
#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Commands{
        struct Command_st{
            Sauce::Memory::List_cl<Command_st*> SubCommands;
            Sauce::Memory::List_cl<wchar_t> CommandString,ReturnString,HelpString;
            Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>>* Arguments;
            void* ReturnPtr{nullptr};
            size_t ArgumentIndex;
            static Command_st* BaseCommandReference;
            Command_st* (*ExecutableBody)(Command_st* Caller);
            Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Sauce::Memory::List_cl<Command_st*> SubCommands,Sauce::Memory::List_cl<wchar_t> HelpString);
            Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Command_st* (*ExecutableBody)(Command_st* Caller),Sauce::Memory::List_cl<wchar_t> HelpString);
            Command_st(Sauce::Memory::List_cl<wchar_t> CommandString,Sauce::Memory::List_cl<wchar_t> HelpString);
            ~Command_st();
            Command_st* operator()(size_t ArgumentIndex,Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>>* Arguments);
            Command_st* AddSubCommand(Command_st* SubCommands);
        };
    };
};
