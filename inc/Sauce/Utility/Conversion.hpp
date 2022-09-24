#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Utility{
		//Hex 0x0123456789ABC
		char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value,bool ClearBefore=true);
		char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t value,bool ClearBefore=true);
		char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint32_t value,bool ClearBefore=true);
		char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t value,bool ClearBefore=true);
		//Numeric 1234567890
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int8_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int16_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int32_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int64_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint32_t value,bool ClearBefore=true);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t value,bool ClearBefore=true);
		//Decimal 0.0
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,float value,uint16_t decimalPlaces=4);
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,double value,uint16_t decimalPlaces=4);
    };
};
