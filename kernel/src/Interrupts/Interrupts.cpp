#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>

namespace Sauce{
    namespace Interrupts{
        __attribute__((interrupt)) void PageFault_handler(interrupt_frame* frame){
            Sauce::IO::Panic("Page Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void DoubleFault_handler(interrupt_frame* frame){
            Sauce::IO::Panic("Double Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void GeneralProtectionFault_handler(interrupt_frame* frame){
            Sauce::IO::Panic("General Protection Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void KeyboardInterrupt_handler(interrupt_frame* frame){
            uint8_t input = 0;
            do {
              if(Sauce::IO::inb(0x60) != input) {
                input = Sauce::IO::inb(0x60);
                if(input > 0) {
                    uint16_t Xinput = Sauce::IO::Translate_KeyCode(input);
                    if(Xinput != 0){
                        Sauce::IO::KeyboardKey_st Xkey = Sauce::IO::Code_To_Key(Xinput);
                        if(Xkey.Key != 0)Kernel_cl::Notify_Of_KeyPress(Xkey);
                    }
                }
              }
            } while(input != 0);
            PIC1_Done();
        }
        __attribute__((interrupt)) void MouseInterrupt_handler(interrupt_frame* frame){
            uint8_t mouseData = Sauce::IO::inb(0x60);
            Sauce::IO::HandlePS2Mouse(mouseData);
            PIC2_Done();
        }
        void PIC1_Done(){
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
        }
        void PIC2_Done(){
            Sauce::IO::outb(PIC2_COMMAND,PIC_EOI);
            Sauce::IO::outb(PIC1_COMMAND,PIC_EOI);
        }
        void RemapPic(){
            uint8_t a1, a2;
            
            a1 = Sauce::IO::inb_w(PIC1_DATA);
            a2 = Sauce::IO::inb_w(PIC2_DATA);
            
            Sauce::IO::outb_w(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
            Sauce::IO::outb_w(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

            Sauce::IO::outb_w(PIC1_DATA,0x20);
            Sauce::IO::outb_w(PIC2_DATA,0x28);

            Sauce::IO::outb_w(PIC1_DATA, 4);
            Sauce::IO::outb_w(PIC2_DATA, 2);

            Sauce::IO::outb_w(PIC1_DATA, ICW4_8086);
            Sauce::IO::outb_w(PIC2_DATA, ICW4_8086);

            Sauce::IO::outb_w(PIC1_DATA,a1);
            Sauce::IO::outb_w(PIC2_DATA,a2);
        }
    };
};