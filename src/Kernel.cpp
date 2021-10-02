#include <Keyboard.hpp>
#include <Terminal.hpp>
#include <Convert.hpp>
#include <Shell.hpp>
#include <Misc.hpp>
#include <Container.hpp>

using namespace Sauce;

void Notify_Kernel_Of_KeyPress(Sauce::Keyboard::KeyboardKey _Key){
    
    Sauce::Shell::KeyPress(_Key);
    
}

void Notify_Kernel_Of_Timer(float rate){
    Sauce::Interrupts::ProgrammableInterruptTimerCounter+=rate;
        
    if(Sauce::Interrupts::ProgrammableInterruptTimerCounter > 0x1000000000000000){
        Sauce::Interrupts::ProgrammableInterruptTimerCounter=0;
    }
}

void Kernel_Main(){
    
    STOP(Nothing);
}
