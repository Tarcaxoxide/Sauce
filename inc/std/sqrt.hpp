#ifndef __std_sqrt
#define __std_sqrt
#include<Sauce/Math.hpp>
namespace std{
	double sqrt(double number,int steps=2){
		return Sauce::Math::sqrt(number,steps);
	}
};
float sqrt(float number){
	return (float)std::sqrt(number,1);
}
#endif