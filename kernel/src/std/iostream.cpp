#include <std/iostream.hpp>
#include <Sauce/Global.hpp>

namespace std _GLIBCXX_VISIBILITY(default){
    std::string cout_st::operator<<(std::string str){
        Sauce::Global::Shell->PutString(str,false);
        return str;
    }
    const char* endl("\n\r");
    cout_st cout;
};

