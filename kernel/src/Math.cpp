
#include<Sauce/Math/Functions.hpp>



void drawCircle(int xc, int yc, int x, int y,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle)
{
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
        	return (X + (Y * MaxX));
    	}
		double round(double number,double medium){
			int A1=(int)number;
			double A2=number-A1;
			double A=0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			A=(double)A1;
			if(A2 > medium)A+=1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
			return (double)A;
		}
		double maximum(double number1,double number2){
			if(number1>number2)return number1;
			if(number2>number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double minimum(double number1,double number2){
			if(number1<number2)return number1;
			if(number2<number1)return number2;
			return number1;// their equal so it doesn't matter.
		}
		double average(double number1,double number2){
			return (number1+number2)/2;
		}
		int make_positive(int number){
			if(number < 0)return (number-number-number);
			return number;
		}
		int make_negative(int number){
			if(number > 0)return (number-number-number);
			return number;
		}
		void make_line(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Line){
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
		void make_triangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Point64_st pointC,Sauce::Memory::List_cl<Sauce::Point64_st> &Triangle){
			/*
					A
				  .   .
				 .     .
				B.......C
			*/
			make_line(pointB,pointA,Triangle);
			make_line(pointA,pointC,Triangle);
			make_line(pointC,pointB,Triangle);
		}
		void make_rectangle(Sauce::Point64_st pointA,Sauce::Point64_st pointB,Sauce::Memory::List_cl<Sauce::Point64_st> &Rectangle){
			/*
				A...
				.  .
				...B
			*/
			make_line({pointA.X,pointA.Y,0},{pointB.X,pointA.Y,0},Rectangle);
			make_line({pointB.X,pointA.Y,0},{pointB.X,pointB.Y,0},Rectangle);
			make_line({pointB.X,pointB.Y,0},{pointA.X,pointB.Y,0},Rectangle);
			make_line({pointA.X,pointB.Y,0},{pointA.X,pointA.Y,0},Rectangle);
		}
		void make_circle(Sauce::Point64_st point,int radius,Sauce::Memory::List_cl<Sauce::Point64_st> &Circle){
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
	};
};
