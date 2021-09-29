#include <Sauce.hpp>

extern void Kernel_Main();

extern "C" void _start(){
    Sauce::IO::init_serial();
    Sauce::Interrupts::Initialize_Interrupt_Descriptor_Table();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    Kernel_Main();
}