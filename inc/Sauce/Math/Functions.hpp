#pragma once
#include<Sauce/Math/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
	namespace Math{
		size_t index(size_t X,size_t Y,size_t MaxX);
		double round(double number,double medium=0.5);
		double maximum(double number1,double number2);
		double minimum(double number1,double number2);
		double average(double number1,double number2);
		int make_positive(int number);
		int make_negative(int number);
		void make_line(Point64_t pointA,Point64_t PointB,Sauce::Memory::List_cl<Sauce::Math::Point64_t> &Line);
		inline int abs(int number){return make_positive(number);}
	};
};
