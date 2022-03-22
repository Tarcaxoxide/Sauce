#include<Sauce/Kernel.hpp>

namespace Sauce{
    _Kernel* _Kernel::Self; // pointer to the active kernel to be used by the kernel 
                            //when being updated by the hardware (Example: interrupts)
    _Kernel::_Kernel(DataStructure* DFBL)
        :Term(DFBL){
        this->DFBL=DFBL;
        Self=this;
        asm volatile("cli");
        Sauce::IO::GlobalTerminal=&Term;
        Term.Clear();
        
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();
        Prep_Interrupts();
        Term.Clear();
        Prep_IO();// in qemu it wont actually continue past this point until it receives a mouse event.
                  // or at least that's what it looks like because it wont type the finish text till then.
        Sauce::IO::outb(PIC1_DATA,0b11111001);
        Sauce::IO::outb(PIC2_DATA,0b11101111);
        Term.Clear();
        asm volatile("sti");
    }
    void _Kernel::Prep_GlobalAllocator(){
        Sauce::Memory::GlobalAllocator = Sauce::Memory::PageFrameAllocator();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::Memory::GlobalAllocator.ReadEfiMemoryMap((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::Memory::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::Memory::PageTable*)Sauce::Memory::GlobalAllocator.RequestPage();
        Sauce::Memory::memset(PML4,0,0x1000);
        pageTableManager.Initialize(PML4);
    }
    void _Kernel::Prep_VirtualAddresses(){
        for(uint64_t t=0;t<Sauce::Memory::GetMemorySize((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::Memory::GlobalAllocator.LockPages((void*)fbBase,fbSize/0x1000 +1);
        for(uint64_t t=fbBase;t<fbBase+fbSize;t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
    }
    void _Kernel::Prep_GDT(){
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void _Kernel::Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector){
        Sauce::Interrupts::IDTDescriptorEntry* Interrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + Interrupt_Number * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        Interrupt->SetOffset((uint64_t)Interrupt_Handler);
        Interrupt->type_attr = type_attr;
        Interrupt->selector=selector;
    }
    void _Kernel::Prep_Interrupts(){
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Memory::GlobalAllocator.RequestPage();

        Add_Interrupt((void*)&Sauce::Interrupts::PageFault_handler,0xE,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::DoubleFault_handler,0x8,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::GeneralProtectionFault_handler,0xD,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::KeyboardInterrupt_handler,0x21,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::MouseInterrupt_handler,0x2C,IDT_TA_InterruptGate,0x08);

        asm volatile("lidt %0" : : "m" (idtr));
    }
    void _Kernel::Prep_IO(){
        Sauce::Interrupts::RemapPic();
        Sauce::IO::PS2MouseInitialize();
    }
    void _Kernel::Notify_Of_KeyPress(Sauce::IO::KeyboardKey Xkey){
        if(!Xkey.Press)return;//ignoring key releases for now.
        if(Xkey.visible && Xkey.Press){
            Sauce::IO::GlobalTerminal->PutChar(Xkey.Display);
            return;
        }
        switch(Xkey.Key){
            case 0x1C:{
                Sauce::IO::GlobalTerminal->BackSpace();
            }break;

            case 0x56:{/*Left Shift*/}break;
            case 0x70:{/*Right Shift*/}break;
            case 0x3A:{/*caps lock*/}break;
            case 0xD6:{/*enter*/}break;
            case 0xF8:{/*scr lk*/}break;
            case 0x7E:{/*pause break*/}break;
            case 0xC4:{/*ins*/}break;
            case 0xB4:{/*home*/}break;
            case 0xC8:{/*page up*/}break;
            case 0xCE:{/*del*/}break;
            case 0xB8:{/*end*/}break;
            case 0xCC:{/*page down*/}break;
            case 0xDA:{Sauce::IO::GlobalTerminal->Clear();}break;
            case 0x7A:{/*alt*/}break;

            default:{
                Sauce::IO::GlobalTerminal->PutChar('[');
                Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::To_String::From_uint8(Xkey.Key));
                Sauce::IO::GlobalTerminal->PutChar(']');
            }break;
        }
    }
    void _Kernel::Notify_Of_Mouse(Sauce::IO::MouseData Xmouse){
        Sauce::IO::GlobalTerminal->Mouse(Xmouse.Position);
        if(Xmouse.LeftButton){
            Sauce::IO::GlobalTerminal->PutString("!Click!");
        }
    }
    void _Kernel::Stop(){
        while(true){
            asm volatile("hlt");
        }
    }
};