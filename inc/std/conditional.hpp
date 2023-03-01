#ifndef __std_conditional
#define __std_conditional
namespace std{
    template<bool B,typename T,typename F>
    struct conditional{
        #if B
            T type;
        #else
            F type;
        #endif
    };
};
#endif