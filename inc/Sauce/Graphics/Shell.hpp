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
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
            Sauce::Memory::List_cl<wchar_t> CharBuffer;
            public:
                Shell_cl(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
                void PutChar(Sauce::IO::Debug::Debugger_st* pDebugger,wchar_t chr,bool AddToBuffer=true);
                void PutString(Sauce::IO::Debug::Debugger_st* pDebugger,const wchar_t* str,bool AddToBuffer=true);
                void PutString(Sauce::IO::Debug::Debugger_st* pDebugger,const char* str,bool AddToBuffer=true);
                bool GoDown(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount=1);
                bool GoUp(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount=1);
                bool GoRight(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount=1);
                bool GoLeft(Sauce::IO::Debug::Debugger_st* pDebugger,size_t amount=1);
                void GoFarDown(Sauce::IO::Debug::Debugger_st* pDebugger);
                void GoFarUp(Sauce::IO::Debug::Debugger_st* pDebugger);
                void GoFarRight(Sauce::IO::Debug::Debugger_st* pDebugger);
                void GoFarLeft(Sauce::IO::Debug::Debugger_st* pDebugger);
                void RunCmd(Sauce::IO::Debug::Debugger_st* pDebugger);
                void ShellClear(Sauce::IO::Debug::Debugger_st* pDebugger);
        };
    };
};
