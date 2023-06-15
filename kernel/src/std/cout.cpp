#include<std/cout.hpp>
#include<Sauce/Global.hpp>
namespace std{
	cout_st& cout_st::operator<<(std::string str){
		Sauce::Global::Graphics::Shell->PutString(str,false);
		return *this;
	}
	const char* endl("\n\r");
	cout_st cout;
};
