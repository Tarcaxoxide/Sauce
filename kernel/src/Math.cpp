
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Console.hpp>

void drawCircle(int xc, int yc, int x, int y,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle)
{
	Sauce::IO::Debug::Print_Call("drawCircle",Sauce::IO::Debug::MATH);
	Circle.AddLast({xc+x,yc+y,0});
	Circle.AddLast({xc-x,yc+y,0});
	Circle.AddLast({xc+x,yc-y,0});
	Circle.AddLast({xc-x,yc-y,0});
	Circle.AddLast({xc+y,yc+x,0});
	Circle.AddLast({xc-y,yc+x,0});
	Circle.AddLast({xc+y,yc-x,0});
	Circle.AddLast({xc-y,yc-x,0});
}

namespace Sauce{
    namespace Math{
    	size_t index(size_t X,size_t Y,size_t MaxX){
			Sauce::IO::Debug::Print_Call("index",Sauce::IO::Debug::MATH);
        	return (X + (Y * MaxX));
    	}
		double round(double number,double medium){
			Sauce::IO::Debug::Print_Call("round",Sauce::IO::Debug::MATH);
			int A1=(int)number;
			double A2=number-A1;
			double A=0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			A=(double)A1;
			if(A2 > medium)A+=1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			return (double)A;
		}
		double maximum(double number1,double number2){
			Sauce::IO::Debug::Print_Call("maximum",Sauce::IO::Debug::MATH);
			if(number1>number2)return number1;
			if(number2>number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double minimum(double number1,double number2){
			Sauce::IO::Debug::Print_Call("minimum",Sauce::IO::Debug::MATH);
			if(number1<number2)return number1;
			if(number2<number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double average(double number1,double number2){
			Sauce::IO::Debug::Print_Call("average",Sauce::IO::Debug::MATH);
			return (number1+number2)/2;
		}
		double difference(double number1,double number2){
			Sauce::IO::Debug::Print_Call("difference",Sauce::IO::Debug::MATH);
			return Sauce::Math::maximum(number1,number2)/Sauce::Math::minimum(number1,number2);
		}
		int make_positive(int number){
			Sauce::IO::Debug::Print_Call("make_positive",Sauce::IO::Debug::MATH);
			if(number < 0)return (number-number-number);
			return number;
		}
		int make_negative(int number){
			Sauce::IO::Debug::Print_Call("make_negative",Sauce::IO::Debug::MATH);
			if(number > 0)return (number-number-number);
			return number;
		}
		void make_line(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line){
			Sauce::IO::Debug::Print_Call("make_line",Sauce::IO::Debug::MATH);
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
			Sauce::IO::Debug::Print_Call("make_line",Sauce::IO::Debug::MATH);
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
			Sauce::IO::Debug::Print_Call("make_triangle",Sauce::IO::Debug::MATH);
			/*
					A
				  .   .
				 .     .
				B.......C
			*/
			make_line(pointB,Triangle,true);
			make_line(pointA,Triangle);
			make_line(pointC,Triangle);
			make_line(pointB,Triangle);
		}
		void make_rectangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle){
			Sauce::IO::Debug::Print_Call("make_rectangle",Sauce::IO::Debug::MATH);
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
			Sauce::IO::Debug::Print_Call("make_circle",Sauce::IO::Debug::MATH);
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
			Sauce::IO::Debug::Print_Call("random_get",Sauce::IO::Debug::MATH);
		    next = next * 1103515245 + 12345;
		    return (next/65536) % max;
		}
		void random_seed(size_t seed){
			Sauce::IO::Debug::Print_Call("random_seed",Sauce::IO::Debug::MATH);
		    next = seed;
		}
	};
};
