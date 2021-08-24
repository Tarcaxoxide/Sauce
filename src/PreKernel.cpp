#include <Sauce.hpp>

extern void Kernel_Main();

extern "C" void _start(){
    Kernel_Main();
}