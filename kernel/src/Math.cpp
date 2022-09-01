
#include<Sauce/Math/Functions.hpp>



void drawCircle(int xc, int yc, int x, int y,Sauce::Memory::List_cl<Sauce::Math::Point64_t> &Circle)
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
		void make_line(Sauce::Math::Point64_t pointA,Sauce::Math::Point64_t pointB,Sauce::Memory::List_cl<Sauce::Math::Point64_t> &Line){
			
			
			Sauce::Math::Point64_t point_smaller,point_bigger;

			if(pointA.X > pointB.X){point_smaller=pointB;point_bigger=pointA;}else{point_smaller=pointA;point_bigger=pointB;}
			
			int m_new = 2 * (point_bigger.Y - point_smaller.Y);
   			int slope_error_new = m_new - (point_bigger.X - point_smaller.X);
   			
			if(point_smaller.X != point_bigger.X){
				for (int x = point_smaller.X, y = point_smaller.Y; x <= point_bigger.X; x++)
   				{
				   Line.AddLast({x,y,0});
   				   slope_error_new += m_new;
   				   if (slope_error_new >= 0)
   				   {
   				      y++;
   				      slope_error_new  -= 2 * (point_bigger.X - point_smaller.X);
   				   }
   				}
			}else{
				if(pointA.Y > pointB.Y){point_smaller=pointB;point_bigger=pointA;}else{point_smaller=pointA;point_bigger=pointB;}
				for (int y = point_smaller.Y; y <= point_bigger.Y; y++)
   				{
				   Line.AddLast({point_bigger.X,y,0});
   				}
			}
		}
		void make_circle(Sauce::Math::Point64_t point,int radius,Sauce::Memory::List_cl<Sauce::Math::Point64_t> &Circle){
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
