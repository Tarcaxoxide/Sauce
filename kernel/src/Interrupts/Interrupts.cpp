#include<Sauce/Interrupts/Interrupts.hpp>
#include<Sauce/Kernel.hpp>

namespace Sauce{
    namespace Interrupts{
        __attribute__((interrupt)) void PageFault_handler(struct interrupt_frame* frame){
            Panic("Page Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void DoubleFault_handler(struct interrupt_frame* frame){
            Panic("Double Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void GeneralProtectionFault_handler(struct interrupt_frame* frame){
            Panic("General Protection Fault Detected!\n\r");
        }
        __attribute__((interrupt)) void KeyboardInterrupt_handler(struct interrupt_frame* frame){
            uint8_t input = 0;
                    do {
                      if(Sauce::inb(0x60) != input) {
                        input = Sauce::inb(0x60);
                        if(input > 0) {
                            uint16_t Xinput = Sauce::Keyboard::Translate_KeyCode(input);
                            if(Xinput != NULL){
                                Sauce::Keyboard::KeyboardKey Xkey = Sauce::Keyboard::Code_To_Key(Xinput);
                                if(Xkey.Key != NULL)_Kernel::Notify_Of_KeyPress(Xkey);
                            }
                        }
                      }
                    } while(input != 0);
            PIC1_Done();
        }
        void PIC1_Done(){
            outb(PIC1_COMMAND,PIC_EOI);
        }
        void PIC2_Done(){
            outb(PIC2_COMMAND,PIC_EOI);
            outb(PIC1_COMMAND,PIC_EOI);
        }
        void RemapPic(){
            uint8_t a1, a2;
            
            a1 = inb_w(PIC1_DATA);
            a2 = inb_w(PIC2_DATA);
            
            outb_w(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
            outb_w(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

            outb_w(PIC1_DATA,0x20);
            outb_w(PIC2_DATA,0x28);

            outb_w(PIC1_DATA, 4);
            outb_w(PIC2_DATA, 2);

            outb_w(PIC1_DATA, ICW4_8086);
            outb_w(PIC2_DATA, ICW4_8086);

            outb_w(PIC1_DATA,a1);
            outb_w(PIC2_DATA,a2);
        }
    };
};