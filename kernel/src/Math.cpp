
#include<Sauce/Math/Functions.hpp>

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
		void make_line(Point64_t pointA,Point64_t pointB,Sauce::Memory::List_cl<Sauce::Math::Point64_t> &Line){
			int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;
		    int point[3];

		    point[0] = pointA.X;
		    point[1] = pointA.Y;
		    point[2] = pointA.Z;
		    dx = pointB.X - pointA.X;
		    dy = pointB.Y - pointA.Y;
		    dz = pointB.Z - pointA.Z;
		    x_inc = (dx < 0) ? -1 : 1;
		    l = make_positive(dx); // make_positive = "abs"
		    y_inc = (dy < 0) ? -1 : 1;
		    m = make_positive(dy); // make_positive = "abs"
		    z_inc = (dz < 0) ? -1 : 1;
		    n = make_positive(dz); // make_positive = "abs"
		    dx2 = l << 1;
		    dy2 = m << 1;
		    dz2 = n << 1;

		    if ((l >= m) && (l >= n)) {
		        err_1 = dy2 - l;
		        err_2 = dz2 - l;
		        for (i = 0; i < l; i++) {
		            //output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
					Line.AddLast({point[0], point[1], point[2]});
		            if (err_1 > 0) {
		                point[1] += y_inc;
		                err_1 -= dx2;
		            }
		            if (err_2 > 0) {
		                point[2] += z_inc;
		                err_2 -= dx2;
		            }
		            err_1 += dy2;
		            err_2 += dz2;
		            point[0] += x_inc;
		        }
		    } else if ((m >= l) && (m >= n)) {
		        err_1 = dx2 - m;
		        err_2 = dz2 - m;
		        for (i = 0; i < m; i++) {
		            //output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
					Line.AddLast({point[0], point[1], point[2]});
		            if (err_1 > 0) {
		                point[0] += x_inc;
		                err_1 -= dy2;
		            }
		            if (err_2 > 0) {
		                point[2] += z_inc;
		                err_2 -= dy2;
		            }
		            err_1 += dx2;
		            err_2 += dz2;
		            point[1] += y_inc;
		        }
		    } else {
		        err_1 = dy2 - n;
		        err_2 = dx2 - n;
		        for (i = 0; i < n; i++) {
		            //output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
					Line.AddLast({point[0], point[1], point[2]});
		            if (err_1 > 0) {
		                point[1] += y_inc;
		                err_1 -= dz2;
		            }
		            if (err_2 > 0) {
		                point[0] += x_inc;
		                err_2 -= dz2;
		            }
		            err_1 += dy2;
		            err_2 += dx2;
		            point[2] += z_inc;
		        }
		    }
		    //output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
			Line.AddLast({point[0], point[1], point[2]});
		}
	};
};
