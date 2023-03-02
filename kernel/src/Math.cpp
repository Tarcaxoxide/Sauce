
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<std/iostream.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Interrupts/PIT.hpp>

namespace Sauce{
	namespace Math{
		#define SQRT_MAGIC_F 0x5fe6eb50c7b537a9 
		double sqrt(double number,int steps){
			double y = number;
		  	double x2 = y * 0.5f;
		  	union{
				double x;
				int i;
		  	} u;
		  	u.x = y;
		  	u.i = SQRT_MAGIC_F - (u.i >> 1);  // gives initial guess y0
			while(steps--)u.x = u.x * (1.5 - (x2 * u.x * u.x));

			return u.x;// Newton step, repeating increases accuracy 
		}
		void drawCircle(int xc, int yc, int x, int y,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"drawCircle",_NAMESPACE_,_ALLOW_PRINT_);
			Circle.AddLast({xc+x,yc+y,0});
			Circle.AddLast({xc-x,yc+y,0});
			Circle.AddLast({xc+x,yc-y,0});
			Circle.AddLast({xc-x,yc-y,0});
			Circle.AddLast({xc+y,yc+x,0});
			Circle.AddLast({xc-y,yc+x,0});
			Circle.AddLast({xc+y,yc-x,0});
			Circle.AddLast({xc-y,yc-x,0});
		}
		size_t index(size_t X,size_t Y,size_t MaxX){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"index",_NAMESPACE_,_ALLOW_PRINT_);
			return (X + (Y * MaxX));
		}
		long double round(long double number,long double medium){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"round",_NAMESPACE_,_ALLOW_PRINT_);
			int A1=(int)number;
			long double A2=number-A1;
			long double A=0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			A=(long double)A1;
			if(A2 > medium)A+=1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			return (long double)A;
		}
		long double maximum(long double number1,long double number2){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"maximum",_NAMESPACE_,_ALLOW_PRINT_);
			if(number1>number2)return number1;
			if(number2>number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		long double minimum(long double number1,long double number2){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"minimum",_NAMESPACE_,_ALLOW_PRINT_);
			if(number1<number2)return number1;
			if(number2<number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		long double average(long double number1,long double number2){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"average",_NAMESPACE_,_ALLOW_PRINT_);
			return (number1+number2)/2;
		}
		long double difference(long double number1,long double number2){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"difference",_NAMESPACE_,_ALLOW_PRINT_);
			return Sauce::Math::maximum(number1,number2)/Sauce::Math::minimum(number1,number2);
		}
		int make_positive(int number){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_positive",_NAMESPACE_,_ALLOW_PRINT_);
			if(number < 0)return -number;
			return number;
		}
		int make_negative(int number){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_negative",_NAMESPACE_,_ALLOW_PRINT_);
			if(number > 0)return -number;
			return number;
		}
		void make_line(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_line",_NAMESPACE_,_ALLOW_PRINT_);
			/*
				A......B
			*/
			Sauce::Point64_st Current=pointA;
			while( Current.X != pointB.X || Current.Y != pointB.Y || Current.Z != pointB.Z){
				if(Current.X > pointB.X)Current.X--;
				if(Current.X < pointB.X)Current.X++;
				if(Current.Y > pointB.Y)Current.Y--;
				if(Current.Y < pointB.Y)Current.Y++;
				if(Current.Z > pointB.Z)Current.Z--;
				if(Current.Z < pointB.Z)Current.Z++;
				Line.AddLast(Current);
			}
		}
		void make_line(Sauce::Point64_st point,Sauce::Memory::List_cl<Sauce::Point64_st> &Line,bool reset){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_line",_NAMESPACE_,_ALLOW_PRINT_);
			/*
				A......B
			*/
			static Sauce::Point64_st Current{0,0,0};

			if(reset)Current=point;

			while( Current.X != point.X || Current.Y != point.Y || Current.Z != point.Z){
				if(Current.X > point.X)Current.X--;
				if(Current.X < point.X)Current.X++;
				if(Current.Y > point.Y)Current.Y--;
				if(Current.Y < point.Y)Current.Y++;
				if(Current.Z > point.Z)Current.Z--;
				if(Current.Z < point.Z)Current.Z++;
				Line.AddLast(Current);
			}
		}
		void make_triangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Point64_st pointC,Sauce::Memory::List_cl<Sauce::Point64_st> &Triangle){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_triangle",_NAMESPACE_,_ALLOW_PRINT_);
			/*
					A
				  .   .
				 .	 .
				B.......C
			*/
			make_line(pointB,Triangle,true);
			make_line(pointA,Triangle);
			make_line(pointC,Triangle);
			make_line(pointB,Triangle);
		}
		void make_rectangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_rectangle",_NAMESPACE_,_ALLOW_PRINT_);
			/*
				A...
				.  .
				...B
			*/
			make_line({pointA.X,pointA.Y,0},Rectangle,true);
			make_line({pointB.X,pointA.Y,0},Rectangle);
			make_line({pointB.X,pointB.Y,0},Rectangle);
			make_line({pointA.X,pointB.Y,0},Rectangle);
			make_line({pointA.X,pointA.Y,0},Rectangle);
		}
		void make_circle(Sauce::Point64_st point,int radius,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"make_circle",_NAMESPACE_,_ALLOW_PRINT_);
			/*	
				point = the center of the circle.
				radius = the radius of the circle.
			*/
			int x = 0, y = radius;
			int d = 3 - 2 * radius;
			drawCircle(point.X, point.Y, x, y,Circle);
			while (y >= x)
			{
				// for each pixel we will
				// draw all eight pixels
				x++;
				// check for decision parameter
				// and correspondingly
				// update d, x, y
				if (d > 0)
				{
					y--;
					d = d + 4 * (x - y) + 10;
				}
				else
					d = d + 4 * x + 6;
				drawCircle(point.X, point.Y, x, y, Circle);
			}
		}
		size_t next = 1;
		size_t random_get(size_t max){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"random_get",_NAMESPACE_,_ALLOW_PRINT_);
			next = next * 1103515245 + 12345;
			return (next/65536) % max;
		}
		void random_seed(size_t seed){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"random_seed",_NAMESPACE_,_ALLOW_PRINT_);

			next = (seed?seed:(Sauce::Interrupts::PIT::GetTimeSinceBoot()*10000));
		}
	};
};
