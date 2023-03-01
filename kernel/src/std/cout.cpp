#include<std/cout.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace std{
    cout_st& cout_st::operator<<(std::string str){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"cout_st::operator<<",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Global::Shell->PutString(str,false);
        return *this;
    }
    const char* endl("\n\r");
    cout_st cout;
};

