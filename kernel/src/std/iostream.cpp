#include <std/iostream.hpp>
#include <Sauce/Global.hpp>

namespace std{
    //std::string operator<<(const char* A,const char* B){
    //    return std::string(A,B);
    //}
    std::string operator<<(std::string A,const char* B){
        return std::string(A.Raw(),B);
    }
    std::string operator<<(const char* A,std::string B){
        return std::string(A,B.Raw());
    }
    std::string operator<<(std::string A,std::string B){
        return std::string(A.Raw(),B.Raw());
    }
};

namespace std{
    std::string cout_st::operator<<(std::string str){
        Sauce::Global::Shell->PutString(str,false);
        return str;
    }
};

namespace std{
    const char* endl("AAAAAA");
    cout_st cout;
};