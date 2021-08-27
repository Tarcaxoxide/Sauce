#include "Interrupts.hpp"

// this file contains everything to due with interrupts. all the interrupts will start here and then get passed to the
// appropriate kernel handler which then will decide what to do with the interrupt.
// also contains some conversion code for keycodes and what not.

extern Sauce::Interrupts::IDT64 _idt[256];
// Interrupts
extern uint64_t isr0;
extern uint64_t isr1;

extern "C" void loadIDT();

namespace Sauce{
    namespace Interrupts{
        void MapIDT(size_t index,uint64_t &This_isr){
            _idt[index].offset_low = ((uint16_t)(((uint64_t)&This_isr & 0x000000000000ffff)));
			_idt[index].selector = 0x08;
			_idt[index].ist = 0;
			_idt[index].types_attr = 0x8e;
			_idt[index].offset_mid  = ((uint16_t)(((uint64_t)&This_isr & 0x00000000ffff0000) >> 16));
			_idt[index].offset_high = ((uint32_t)(((uint64_t)&This_isr & 0xffffffff00000000) >> 32));
			_idt[index].zero = 0;
        }
        void InitializeIDT(){
            MapIDT(0,isr0);
            MapIDT(1,isr1);
            //Sauce::IO::outb(0x21,0xfd);
            //Sauce::IO::outb(0xa1,0xff);
            Sauce::IO::RemapPic();
            loadIDT();
        }


        void isr_handler(uint64_t isr_number){
            static float tick=0;
            static uint8_t tock=0;
            static float trigger=1.25252525252525252525;
            static float rate=0.67619068904102403556;
            switch(isr_number){
                case 0:{
                    tick+=rate;
                    if(tick > trigger){
                        tock++;
                        tick-=trigger;
                        if(!(tock%10)){
                            NotifyKernelOfTimer(tick);
                        }
                    }
                }break;
                case 1:{
                    uint8_t input = 0;
                    do {
                      if(Sauce::IO::inb(0x60) != input) {
                        input = Sauce::IO::inb(0x60);
                        if(input > 0) {
                            uint16_t Xinput = Sauce::Keyboard::Translate_KeyCode(input);
                            if(Xinput != NULL){
                                Sauce::Keyboard::KeyboardKey Xkey = Sauce::Keyboard::CodeToKey(Xinput);
                                if(Xkey.Key != NULL)NotifyKernelOfKeyPress(Xkey);
                            }
                        }
                      }
                    } while(input != 0);
                }break;
                default:{
                    Sauce::Terminal::String("Unhandled Interrupt #");
                    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(isr_number));
                    Sauce::Terminal::String("\n\r");
                }break;
            }
            Sauce::IO::outb(0x20,0x20);
            Sauce::IO::outb(0xa0,0x20);
        }
        uint64_t IntHandler(uint64_t Interrupt_Number,uint64_t esp){
            // this is for later when i do task switching. (this will likely not be used for the kernel but only for userland tasks, that is why it is its own function.)
            return esp;
        }
        uint64_t PIT_Counter=0;
    };
};