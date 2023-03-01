#ifndef __Sauce_Math
#define __Sauce_Math
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Math{
		size_t index(size_t X,size_t Y,size_t MaxX);
		
		long double round(long double number,long double medium=0.5);
		long double maximum(long double number1,long double number2);
		long double minimum(long double number1,long double number2);
		long double average(long double number1,long double number2);
		long double difference(long double number1,long double number2);
		int make_positive(int number);
		int make_negative(int number);
		void make_line(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line);
		void make_line(Sauce::Point64_st point,Sauce::Memory::List_cl<Sauce::Point64_st> &Line,bool reset=false);
		void make_circle(Sauce::Point64_st point,int radius,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle);
		void make_triangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Point64_st pointC,Sauce::Memory::List_cl<Sauce::Point64_st> &Triangle);
		void make_rectangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle);
		size_t random_get(size_t max);
		void random_seed(size_t seed=0);
		inline int abs(int number){return make_positive(number);}
	};
};
#endif