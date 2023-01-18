#include <std/iostream.hpp>
#include <Sauce/Global.hpp>


namespace std{
    std::string cout_st::operator<<(std::string str){
        Sauce::Global::Shell->PutString(str,false);
        return str;
    }
    std::string cout_st::operator<<(const char* cstr){
        std::string str(cstr);
        Sauce::Global::Shell->PutString(str,false);
        return str;
    }
    
};

namespace std{
    const char* endl("AAAAAA");
    cout_st cout;
};