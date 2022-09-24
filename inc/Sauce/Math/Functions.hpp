#pragma once
#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Math{
		size_t index(Sauce::IO::Debug::Debugger_st* pDebugger,size_t X,size_t Y,size_t MaxX);
		
		double round(Sauce::IO::Debug::Debugger_st* pDebugger,double number,double medium=0.5);
		double maximum(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2);
		double minimum(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2);
		double average(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2);
		double difference(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2);

		int make_positive(Sauce::IO::Debug::Debugger_st* pDebugger,int number);
		int make_negative(Sauce::IO::Debug::Debugger_st* pDebugger,int number);
		void make_line(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line);
		void make_line(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st point,Sauce::Memory::List_cl<Sauce::Point64_st> &Line,bool reset=false);
		void make_circle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st point,int radius,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle);
		void make_triangle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Point64_st pointC,Sauce::Memory::List_cl<Sauce::Point64_st> &Triangle);
		void make_rectangle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle);
		size_t random_get(Sauce::IO::Debug::Debugger_st* pDebugger,size_t max);
		void random_seed(Sauce::IO::Debug::Debugger_st* pDebugger,size_t seed);
		inline int abs(Sauce::IO::Debug::Debugger_st* pDebugger,int number){return make_positive(pDebugger,number);}
	};
};
