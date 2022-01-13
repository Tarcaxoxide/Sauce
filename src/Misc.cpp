#include <Misc.hpp>


void* operator new[](size_t size){
    return Sauce::Memory::alloc(size);
}
void operator delete[](void* pointer){
    Sauce::Memory::free(pointer);
}
void operator delete[](void* pointer, size_t Some_Size_I_Guess){
    Sauce::Memory::free(pointer);
}

namespace Sauce{
    void STOP(ERROR_CODES code){
        Sauce::Terminal::String("\n\r [");
        Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(code));
	Sauce::Terminal::String("] System halted");
	if(code != Nothing){
		Sauce::Terminal::String(" and stopped interrupts ");
	}
	if(code == Nothing)Sauce::Terminal::String("(Ok)");
	if(code == Index_too_big)Sauce::Terminal::String("(Index too big)");
	if(code == Shape_mismatch)Sauce::Terminal::String("(Shape mismatch)");
	if(code == Out_of_memory)Sauce::Terminal::String("(Out of memory)");
	if(code == Combined_segment_with_null)Sauce::Terminal::String("(Combined segment with null)");
	if(code == Alignment_unspecified)Sauce::Terminal::String("(Alignment unspecified)");
	if(code == Size_unspecified)Sauce::Terminal::String("(Size unspecified)");
	if(code == User_Executed)Sauce::Terminal::String("(User Executed)");

        while(true){
            Sauce::Terminal::String(".\n\r");
	    if(code != Nothing)asm volatile("cli");
	    asm volatile("hlt"); // halt the cpu.
        }
    }
    void REBOOT(){
        // TODO: add reboot assembly function to actually do the reboot.
    }
};
