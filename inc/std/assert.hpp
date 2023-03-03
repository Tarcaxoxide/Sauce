#ifndef __std_assert
#define __std_assert
#include<Sauce/IO/Panic.hpp>
#include<std/string.hpp>
namespace std{
	void assertFail(const char *msg, const char *file, int line){
		std::string _msg(msg);
		_msg+=", ";
		_msg+=file;
		_msg+=":";
		_msg+=std::to_string(line);
		Panic(_msg);
	}
	void assert(bool result,const char *msg, const char *file, int line){
		if(!result)assertFail(msg,file,line);
	}
};

#define assert(EX) (void)((EX) || (std::assertFail (#EX, __FILE__, __LINE__),0))

#endif