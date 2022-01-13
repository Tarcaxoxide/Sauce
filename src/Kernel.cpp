#include <Keyboard.hpp>
#include <Terminal.hpp>
#include <Convert.hpp>
#include <Shell.hpp>
#include <Misc.hpp>
#include <Container.hpp>

using namespace Sauce;


void Notify_Kernel_Of_KeyPress(Sauce::Keyboard::KeyboardKey _Key){
    
    Shell::KeyPress(_Key);
    
}

void Notify_Kernel_Of_Timer(float rate){
    Interrupts::ProgrammableInterruptTimerCounter+=rate;
        
    if(Interrupts::ProgrammableInterruptTimerCounter > 0x1000000000000000){
        Interrupts::ProgrammableInterruptTimerCounter=0;
    }
}

void Kernel_Main(){
    Memory::PrintMemoryMap_All();

    STOP(Nothing);
}
