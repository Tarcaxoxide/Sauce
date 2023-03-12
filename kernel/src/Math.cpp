
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<std/iostream.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/Interrupts/PIT.hpp>

namespace Sauce{
	namespace Math{
		double square_root (double number){
			if(number==2)return (double)ROOT2;
			if(number==3)return (double)ROOT3;
			bool negative=false;
			if(number<0){number=-number;negative=true;}
			double res;
			asm volatile("fsqrt" : "=t" (res) : "0" (number));
			if(negative)res=-res;
			return res;
		}
		double inverse_square_root(double number){
			return 1/square_root(number);
		}
		long double power(long double number,int64_t of){
			int64_t counter=of>=0?of:-of;
			bool negative=!(of>=0);
			long double Result=number;
			for(;counter;counter--){
				Result*=number;
			}
			return negative?-Result:Result;
		}
		long double square(long double number){
			return power(number,1);
		}
		size_t index(size_t X,size_t Y,size_t MaxX){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"index",_NAMESPACE_,_ALLOW_PRINT_);
			return (X + (Y * MaxX));
		}
		long double round(long double number,long double medium){
			Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"round",_NAMESPACE_,_ALLOW_PRINT_);
			int A1=(int)number;
			long double A2=number-A1;
			long double A=MINIMAL_LONG_DOUBLE;
			A=(long double)A1;
			if(A2 > medium)A+=(1.0+MINIMAL_LONG_DOUBLE);
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
			//I can't remember why i'm doing division here and not substraction.
		}
		long double degrees_to_radians(long double degree){
			return degree*(PI/180);
		}
		long double radians_to_degrees(long double radian){
			return radian*(180/PI);
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
		long double circular_adjust(long double value,long double circumferenceMinimal,long double circumferenceMaximal){
			long double range = circumferenceMaximal-circumferenceMinimal;
			while(value>=circumferenceMaximal)value-=range;
			while(value<circumferenceMinimal)value+=range;
			return value;
		}
		long double circular_add(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal,long double circumferenceMaximal){
			long double result = leftHandSide+rightHandSide;
			result=circular_adjust(result,circumferenceMinimal,circumferenceMaximal);
			return result;
		}
		long double circular_subtract(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal,long double circumferenceMaximal){
			long double result = leftHandSide-rightHandSide;
			result=circular_adjust(result,circumferenceMinimal,circumferenceMaximal);
			return result;
		}
		long double circular_multiply(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal,long double circumferenceMaximal){
			long double result = leftHandSide*rightHandSide;
			result=circular_adjust(result,circumferenceMinimal,circumferenceMaximal);
			return result;
		}
		long double circular_divide(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal,long double circumferenceMaximal){
			long double result = leftHandSide/rightHandSide;
			result=circular_adjust(result,circumferenceMinimal,circumferenceMaximal);
			return result;
		}
		long double circular_shortest_difference(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal,long double circumferenceMaximal){
			long double counter_clockwise = circular_subtract(rightHandSide,leftHandSide,circumferenceMinimal,circumferenceMaximal);
			long double clockwise = circular_subtract(leftHandSide,rightHandSide,circumferenceMinimal,circumferenceMaximal);
			return counter_clockwise>clockwise?clockwise:-counter_clockwise;
		}
		long double pythagoras_hypotenuse(long double a,long double b){
			return square_root(square(a)+square(b));
		}
		long double pythagoras_side(long double a,long double c){
			return square_root(square(c)-square(a));
		}
		long double normalize(std::list<long double> values){
			//I wonder if this will work *shrugs*
			long double maxValue=MINIMAL_LONG_DOUBLE;
			for(size_t i=0;i<values.Size();i++)maxValue=maximum(values[i],maxValue);
			for(size_t i=0;i<values.Size();i++)values[i]/=maxValue;
			return maxValue;
		}
		long double denormalize(std::list<long double> values,long double factor){
			long double maxValue=MINIMAL_LONG_DOUBLE;
			for(size_t i=0;i<values.Size();i++)values[i]*=factor;
			for(size_t i=0;i<values.Size();i++)maxValue=maximum(values[i],maxValue);
			return maxValue;
		}
		long double sine_degree(long double angle){
			return circular_add(360.0,angle);
		}
		long double cosine_degree(long double angle){
			return circular_subtract(360.0,angle);//?
		}
		long double sine_radian(long double angle){
			angle=radians_to_degrees(angle);
			angle=sine_degree(angle);
			angle=degrees_to_radians(angle);
			return angle;
		}
		long double cosine_radian(long double angle){
			angle=radians_to_degrees(angle);
			angle=cosine_degree(angle);
			angle=degrees_to_radians(angle);
			return angle;
		}
		//Memory Math
		size_t kb_to_b(size_t kb){
			return kb*1024;
		}
		size_t mb_to_b(size_t mb){
			return kb_to_b(mb*1024);
		}
		size_t gb_to_b(size_t gb){
			return mb_to_b(gb*1024);
		}
		size_t tb_to_b(size_t tb){
			return gb_to_b(tb*1024);
		}
		size_t b_to_kb(size_t b){
			return b/1024;
		}
		size_t b_to_mb(size_t b){
			return b_to_kb(b/1024);
		}
		size_t b_to_gb(size_t b){
			return b_to_mb(b/1024);
		}
		size_t b_to_tb(size_t b){
			return b_to_gb(b/1024);
		}
		//Graphical math
		Sauce::Graphics::Basic::Frame_st draw_line(long double length,long double angle,GOP_PixelStructure foregroundColor,GOP_PixelStructure backgroundColor){
			Sauce::Point64_st startingPoint{0,0,0};
			angle=circular_adjust(angle*4,0.0,359.0);
			Sauce::Point64_st endingPoint{(int64_t)(degrees_to_radians(cosine_degree(angle))*length),(int64_t)(degrees_to_radians(sine_degree(angle))*length),0};
			Sauce::Graphics::Basic::Frame_st Result(make_positive(endingPoint.X)*make_positive(endingPoint.Y),make_positive(endingPoint.X));
			Result.SetColor(foregroundColor,backgroundColor);
			Result.Clear();
			//Draw the line
			Result.PutPixel(startingPoint);
			Result.PutPixel(endingPoint);
			const long double max = maximum(maximum(startingPoint.X,endingPoint.X),maximum(startingPoint.Y,endingPoint.Y));
			long double x=maximum(startingPoint.X,endingPoint.X)/max;
			long double y=maximum(startingPoint.Y,endingPoint.Y)/max;
			long double x0=0,y0=0;
			for (long double n=0.0; n < max; n+=1.0){
				Result.PutPixel({(int64_t)x0,(int64_t)y0,0});
    		    x0 += x; y0 += y;
    		}
			
			return Result;
		}
	};
};
