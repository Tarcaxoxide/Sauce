//#include <stdint.h>
//#include <stddef.h>
//#include <KeyboardMaps.hpp>
#include <IO.hpp>
#include <Interrupts.hpp>
//#include <Keyboard.hpp>
#include <Terminal.hpp>
//#include <Convert.hpp>
#include <Memory.hpp>
//#include <Graphics.hpp>
//#include <Utils.hpp>
//#include <Shell.hpp>
//#include <Misc.hpp>

extern void Kernel_Main();

extern uint64_t* _HeapTail;
extern uint64_t* _HeapHead;
extern void* _Stack_Bottom;
extern void* _Stack_Top;

extern "C" void _start(){
    Sauce::IO::init_serial();
    Sauce::Interrupts::Initialize_Interrupt_Descriptor_Table();
    Sauce::Memory::InitializeHeap(0x100000,0x100000);
    Sauce::Terminal::String("\n\r _Stack_Bottom:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)_Stack_Bottom));
    Sauce::Terminal::String("\n\r _Stack_Top   :");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)_Stack_Top));
    Sauce::Terminal::String("\n\r GetFreeHeap():");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Sauce::Memory::GetFreeHeap()));
    Sauce::Terminal::String(" \n\r");
    Kernel_Main();
}