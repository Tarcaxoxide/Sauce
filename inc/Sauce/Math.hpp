#ifndef __Sauce_Math
#define __Sauce_Math
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Math{
		double sqrt(double number,int steps=2);
		size_t index(size_t X,size_t Y,size_t MaxX);
		long double round(long double number,long double medium=0.5);
		long double maximum(long double number1,long double number2);
		long double minimum(long double number1,long double number2);
		long double average(long double number1,long double number2);
		long double difference(long double number1,long double number2);
		int make_positive(int number);
		int make_negative(int number);
		size_t random_get(size_t max);
		void random_seed(size_t seed=0);
		inline int abs(int number){return make_positive(number);}
	};
};
#endif