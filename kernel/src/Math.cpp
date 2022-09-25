
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Math{
		void drawCircle(Sauce::IO::Debug::Debugger_st* pDebugger,int xc, int yc, int x, int y,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"drawCircle",_NAMESPACE_);
			Circle.AddLast({xc+x,yc+y,0});
			Circle.AddLast({xc-x,yc+y,0});
			Circle.AddLast({xc+x,yc-y,0});
			Circle.AddLast({xc-x,yc-y,0});
			Circle.AddLast({xc+y,yc+x,0});
			Circle.AddLast({xc-y,yc+x,0});
			Circle.AddLast({xc+y,yc-x,0});
			Circle.AddLast({xc-y,yc-x,0});
		}
    	size_t index(Sauce::IO::Debug::Debugger_st* pDebugger,size_t X,size_t Y,size_t MaxX){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"index",_NAMESPACE_);
        	return (X + (Y * MaxX));
    	}
		double round(Sauce::IO::Debug::Debugger_st* pDebugger,double number,double medium){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"round",_NAMESPACE_);
			int A1=(int)number;
			double A2=number-A1;
			double A=0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			A=(double)A1;
			if(A2 > medium)A+=1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			return (double)A;
		}
		double maximum(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"maximum",_NAMESPACE_);
			if(number1>number2)return number1;
			if(number2>number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double minimum(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"minimum",_NAMESPACE_);
			if(number1<number2)return number1;
			if(number2<number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double average(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"average",_NAMESPACE_);
			return (number1+number2)/2;
		}
		double difference(Sauce::IO::Debug::Debugger_st* pDebugger,double number1,double number2){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"difference",_NAMESPACE_);
			return Sauce::Math::maximum(&Debugger,number1,number2)/Sauce::Math::minimum(&Debugger,number1,number2);
		}
		int make_positive(Sauce::IO::Debug::Debugger_st* pDebugger,int number){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_positive",_NAMESPACE_);
			if(number < 0)return (number-number-number);
			return number;
		}
		int make_negative(Sauce::IO::Debug::Debugger_st* pDebugger,int number){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_negative",_NAMESPACE_);
			if(number > 0)return (number-number-number);
			return number;
		}
		void make_line(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_line",_NAMESPACE_);
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
		void make_line(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st point,Sauce::Memory::List_cl<Sauce::Point64_st> &Line,bool reset){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_line",_NAMESPACE_);
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
		void make_triangle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Point64_st pointC,Sauce::Memory::List_cl<Sauce::Point64_st> &Triangle){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_triangle",_NAMESPACE_);
			/*
					A
				  .   .
				 .     .
				B.......C
			*/
			make_line(&Debugger,pointB,Triangle,true);
			make_line(&Debugger,pointA,Triangle);
			make_line(&Debugger,pointC,Triangle);
			make_line(&Debugger,pointB,Triangle);
		}
		void make_rectangle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_rectangle",_NAMESPACE_);
			/*
				A...
				.  .
				...B
			*/
			make_line(&Debugger,{pointA.X,pointA.Y,0},Rectangle,true);
			make_line(&Debugger,{pointB.X,pointA.Y,0},Rectangle);
			make_line(&Debugger,{pointB.X,pointB.Y,0},Rectangle);
			make_line(&Debugger,{pointA.X,pointB.Y,0},Rectangle);
			make_line(&Debugger,{pointA.X,pointA.Y,0},Rectangle);
		}
		void make_circle(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st point,int radius,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"make_circle",_NAMESPACE_);
			/*    
				point = the center of the circle.
				radius = the radius of the circle.
			*/
			int x = 0, y = radius;
    		int d = 3 - 2 * radius;
    		drawCircle(&Debugger,point.X, point.Y, x, y,Circle);
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
    		    drawCircle(&Debugger,point.X, point.Y, x, y, Circle);
    		}
		}
		
		size_t next = 1;
		size_t random_get(Sauce::IO::Debug::Debugger_st* pDebugger,size_t max){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"random_get",_NAMESPACE_);
		    next = next * 1103515245 + 12345;
		    return (next/65536) % max;
		}
		void random_seed(Sauce::IO::Debug::Debugger_st* pDebugger,size_t seed){
			Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"random_seed",_NAMESPACE_);
		    next = seed;
		}
	};
};
