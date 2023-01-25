#include <std/iostream.hpp>
#include <Sauce/Global.hpp>

namespace std _GLIBCXX_VISIBILITY(default){
    cout_st& cout_st::operator<<(std::string str){
        Sauce::Global::Shell->PutString(str,false);
        return *this;
    }
    const char* endl("\n\r");
    cout_st cout;
};

