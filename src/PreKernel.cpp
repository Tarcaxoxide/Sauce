//#include <stdint.h>
//#include <stddef.h>
//#include <KeyboardMaps.hpp>
#include <IO.hpp>
#include <Interrupts.hpp>
//#include <Keyboard.hpp>
//#include <Terminal.hpp>
//#include <Convert.hpp>
#include <Memory.hpp>
//#include <Graphics.hpp>
//#include <Utils.hpp>
//#include <Shell.hpp>
//#include <Misc.hpp>

extern void Kernel_Main();

extern "C" void _start(){
    Sauce::IO::init_serial();
    Sauce::Interrupts::Initialize_Interrupt_Descriptor_Table();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    Kernel_Main();
}