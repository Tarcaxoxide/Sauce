#ifndef __Sauce_Math
#define __Sauce_Math
#include<std/list.hpp>
#include<std/string.hpp>
#include<Sauce/Graphics/Frame.hpp>
namespace Sauce{
	namespace Math{
		static const long double PI=3.14159265358979323846264338327950288419716939937510;
		static const long double E=0.5772156649015328606065120900824024310421593359399;
		static const long double ROOT2=1.4142135623730950488016887242096980785696718753769;
		static const long double ROOT3=1.7320508075688772935274463415058723669428052538103;
		static const long double GOLDEN_RATIO=1.2020569031595942853997381615114499907649862923404;
		static const long double K=2.6854520010653064453097148354817956938203822939944;
		static const long double A=1.2824271291006226368753425688697917277676889273250;
		static const long double MINIMAL_LONG_DOUBLE=0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
		
		double inverse_square_root(double number);
		double square_root(double number);
		long double power(long double number,int64_t of);
		long double square(long double number);
		size_t index(size_t X,size_t Y,size_t MaxX);
		long double round(long double number,long double medium=0.5);
		long double maximum(long double number1,long double number2);
		long double minimum(long double number1,long double number2);
		long double average(long double number1,long double number2);
		long double difference(long double number1,long double number2);
		long double degrees_to_radians(long double degree);
		long double radians_to_degrees(long double radian);
		int make_positive(int number);
		int make_negative(int number);
		size_t random_get(size_t max);
		void random_seed(size_t seed=0);
		inline int abs(int number){return make_positive(number);}
		long double circular_adjust(long double value,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double circular_add(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double circular_subtract(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double circular_multiply(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double circular_divide(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double circular_shortest_difference(long double leftHandSide,long double rightHandSide,long double circumferenceMinimal=0,long double circumferenceMaximal=360);
		long double pythagoras_hypotenuse(long double a,long double b);
		long double pythagoras_side(long double a,long double c);
		long double normalize(std::list<long double> values);
		long double denormalize(std::list<long double> values,long double factor);
		long double sine_degree(long double angle);
		long double cosine_degree(long double angle);
		long double sine_radian(long double angle);
		long double cosine_radian(long double angle);
		//Memory Math
		size_t kb_to_b(size_t kb);
		size_t mb_to_b(size_t mb);
		size_t gb_to_b(size_t gb);
		size_t tb_to_b(size_t tb);
		size_t b_to_kb(size_t b);
		size_t b_to_mb(size_t b);
		size_t b_to_gb(size_t b);
		size_t b_to_tb(size_t b);
		//Graphical math
		Sauce::Graphics::Basic::Frame_st draw_line(long double length,long double angle,GOP_PixelStructure foregroundColor={0xFF,0xFF,0xFF,0xFF},GOP_PixelStructure backgroundColor={0x00,0x00,0x00,0x00});
		Sauce::Graphics::Basic::Frame_st draw_circle(long double radius,GOP_PixelStructure foregroundColor={0xFF,0xFF,0xFF,0xFF},GOP_PixelStructure backgroundColor={0x00,0x00,0x00,0x00});
	};
};
#endif