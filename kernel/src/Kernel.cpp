#include<Sauce/Kernel.hpp>

namespace Sauce{
    _Kernel* _Kernel::Self; // pointer to the active kernel to be used by the kernel 
                            //when being updated by the hardware (Example: interrupts)
    _Kernel::_Kernel(DataStructure* DFBL)
        :Term(DFBL){
        Self=this;
        GlobalTerminal=&Term;
        Term.Clear();
        Term.SetCursor(0,0);
        if(Debug)Term.PutString("Kernel Init...\n\r");
        this->DFBL=DFBL;
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();
        Prep_Interrupts();
        if(Debug)Term.PutString("Kernel init finished.\n\r");
    }
    void _Kernel::Prep_GlobalAllocator(){
        if(Debug)Term.PutString("Preping Allocator...\n\r");
        Sauce::Memory::GlobalAllocator = Sauce::Memory::PageFrameAllocator();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::Memory::GlobalAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::Memory::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::Memory::PageTable*)Sauce::Memory::GlobalAllocator.RequestPage();
        Sauce::Memory::memset(PML4,0,0x1000);
        pageTableManager.Initialize(PML4);
    }
    void _Kernel::Prep_VirtualAddresses(){
        if(Debug)Term.PutString("Preping Virtual Addresses...\n\r");
        for(uint64_t t=0;t<Sauce::Memory::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
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
        if(Debug)Term.PutString("Preping GlobalDescriptorTable...\n\r");
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void _Kernel::Prep_Interrupts(){
        if(Debug)Term.PutString("Preping Interrupts...\n\r");
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Memory::GlobalAllocator.RequestPage();

        //
        Sauce::Interrupts::IDTDescriptorEntry* int_PageFault = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + 0xE * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        int_PageFault->SetOffset((uint64_t)Sauce::Interrupts::PageFault_handler);
        int_PageFault->type_attr = IDT_TA_InterruptGate;
        int_PageFault->selector=0x08;
        //
        //
        Sauce::Interrupts::IDTDescriptorEntry* int_DoubleFault = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + 0x8 * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        int_DoubleFault->SetOffset((uint64_t)Sauce::Interrupts::DoubleFault_handler);
        int_DoubleFault->type_attr = IDT_TA_InterruptGate;
        int_DoubleFault->selector=0x08;
        //
        //
        Sauce::Interrupts::IDTDescriptorEntry* int_GeneralProtectionFault = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + 0xD * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        int_GeneralProtectionFault->SetOffset((uint64_t)Sauce::Interrupts::GeneralProtectionFault_handler);
        int_GeneralProtectionFault->type_attr = IDT_TA_InterruptGate;
        int_GeneralProtectionFault->selector=0x08;
        //
        //
        Sauce::Interrupts::IDTDescriptorEntry* int_KeyboardInterrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + 0x21 * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        int_KeyboardInterrupt->SetOffset((uint64_t)Sauce::Interrupts::KeyboardInterrupt_handler);
        int_KeyboardInterrupt->type_attr = IDT_TA_InterruptGate;
        int_KeyboardInterrupt->selector=0x08;
        //
        asm volatile("lidt %0" : : "m" (idtr));
        GlobalTerminal->PutString(" Remaping Pic...\n\r");
        Sauce::Interrupts::RemapPic();

        GlobalTerminal->PutString(" enabling keyboard...\n\r");
        Sauce::outb(PIC1_DATA,0b11111101);
        Sauce::outb(PIC2_DATA,0b11111111);
        asm volatile("sti");
    }
    void _Kernel::Notify_Of_KeyPress(Sauce::Keyboard::KeyboardKey Xkey){
        //if(Xkey.visible && Xkey.Press)GlobalTerminal->PutChar(Xkey.Display);
        if(!Xkey.Press)return;//ignoring key releases for now.
        if(Xkey.visible && Xkey.Press){
            GlobalTerminal->PutChar(Xkey.Display);
            return;
        }
        switch(Xkey.Key){
            case 0x1C:{
                GlobalTerminal->BackSpace();
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

            default:{
                GlobalTerminal->PutChar('[');
                GlobalTerminal->PutString(Sauce::Convert::To_String::From_uint8(Xkey.Key));
                GlobalTerminal->PutChar(']');
            }break;
        }
    }
    void _Kernel::Stop(){
        while(true){
            asm volatile("hlt");
        }
    }
};