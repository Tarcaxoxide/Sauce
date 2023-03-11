
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
		int64_t circular_add(int64_t leftHandSide,int64_t rightHandSide,int64_t circumferenceMinimal,int64_t circumferenceMaximal){
			int64_t result = leftHandSide+rightHandSide;
			int64_t range = circumferenceMaximal-circumferenceMinimal;
			while(result>=circumferenceMaximal)result-=range;
			while(result<circumferenceMinimal)result+=range;
			return result;
		}
		int64_t circular_subtract(int64_t leftHandSide,int64_t rightHandSide,int64_t circumferenceMinimal,int64_t circumferenceMaximal){
			int64_t result = leftHandSide-rightHandSide;
			int64_t range = circumferenceMaximal-circumferenceMinimal;
			while(result>=circumferenceMaximal)result-=range;
			while(result<circumferenceMinimal)result+=range;
			return result;
		}
		int64_t circular_multiply(int64_t leftHandSide,int64_t rightHandSide,int64_t circumferenceMinimal,int64_t circumferenceMaximal){
			int64_t result = leftHandSide*rightHandSide;
			int64_t range = circumferenceMaximal-circumferenceMinimal;
			while(result>=circumferenceMaximal)result-=range;
			while(result<circumferenceMinimal)result+=range;
			return result;
		}
		int64_t circular_divide(int64_t leftHandSide,int64_t rightHandSide,int64_t circumferenceMinimal,int64_t circumferenceMaximal){
			int64_t result = leftHandSide/rightHandSide;
			int64_t range = circumferenceMaximal-circumferenceMinimal;
			while(result>=circumferenceMaximal)result-=range;
			while(result<circumferenceMinimal)result+=range;
			return result;
		}
		int64_t circular_shortest_difference(int64_t leftHandSide,int64_t rightHandSide,int64_t circumferenceMinimal,int64_t circumferenceMaximal){
			int64_t counter_clockwise = circular_subtract(rightHandSide,leftHandSide,circumferenceMinimal,circumferenceMaximal);
			int64_t clockwise = circular_subtract(leftHandSide,rightHandSide,circumferenceMinimal,circumferenceMaximal);
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
	};
};
