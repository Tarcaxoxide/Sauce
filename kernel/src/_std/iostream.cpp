#include <_std/iostream.hpp>
#include <Sauce/Global.hpp>

namespace _std /*_GLIBCXX_VISIBILITY(default)*/{
    //I don't know what this does yet but i'm going to put it here for later.
    cout_st& cout_st::operator<<(_std::string str){
        Sauce::Global::Shell->PutString(str,false);
        return *this;
    }
    const char* endl("\n\r");
    cout_st cout;
};

