#include<Sauce/Kernel.hpp>

namespace Sauce{
    Kernel_cl* Kernel_cl::Self=NULL; // pointer to the active kernel to be used by the kernel 
                            //when being updated by the hardware (Example: interrupts)
    Kernel_cl::Kernel_cl(DataStructure* DFBL)
    :kShell(DFBL){
        this->DFBL=DFBL;
        if(Self == NULL)Self=this;
        
        asm volatile("cli");
        //Sauce::IO::GlobalTerminal=&Term;
        
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();

        Sauce::Interrupts::PIT::SetDivisor(65535);
        Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x10);
        
        Prep_Interrupts();

        Prep_IO();// in qemu it wont actually continue past this point until it receives a mouse event.
                  // or at least that's what it looks like because it wont type the finish text till then.
        
        Sauce::IO::outb(PIC1_DATA,0b11111000);
        Sauce::IO::outb(PIC2_DATA,0b11101111);
        
        Sauce::IO::GlobalTerminal->Clear();
        asm volatile("sti");

        Prep_ACPI();
        PreLoop();
        MainLoop();
    }
    void Kernel_cl::PreLoop(){
        /*Testing DynamicArray*/{
            Sauce::Memory::List_cl<char> Test="Hello World!";
            Sauce::IO::GlobalTerminal->PutString(Test.c_str());
        }/*Testing DynamicArray*/
    }
    void Kernel_cl::MainLoop(){
        do{
            Sauce::Interrupts::PIT::Sleep(1000);
            
        }while(true);
    }
    void Kernel_cl::Prep_GlobalAllocator(){
        Sauce::Memory::GlobalAllocator = Sauce::Memory::PageFrameAllocator();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::Memory::GlobalAllocator.ReadEfiMemoryMap((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::Memory::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::Memory::PageTable*)Sauce::Memory::GlobalAllocator.RequestPage();
        Sauce::Memory::memset(PML4,0,0x1000);
        Sauce::Memory::GlobalPageTableManager = Sauce::Memory::PageTableManager(PML4);
    }
    void Kernel_cl::Prep_VirtualAddresses(){
        for(uint64_t t=0;t<Sauce::Memory::GetMemorySize((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            Sauce::Memory::GlobalPageTableManager.MapMemory((void*)t,(void*)t);
        }
        DFBL->fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        DFBL->fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::Memory::GlobalAllocator.LockPages((void*)DFBL->fbBase,DFBL->fbSize/0x1000 +1);
        for(uint64_t t=DFBL->fbBase;t<DFBL->fbBase+DFBL->fbSize;t+=0x1000){
            Sauce::Memory::GlobalPageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
    }
    void Kernel_cl::Prep_GDT(){
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT_st)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void Kernel_cl::Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector){
        Sauce::Interrupts::IDTDescriptorEntry* Interrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + Interrupt_Number * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        Interrupt->SetOffset((uint64_t)Interrupt_Handler);
        Interrupt->type_attr = type_attr;
        Interrupt->selector=selector;
    }
    void Kernel_cl::Prep_Interrupts(){
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Memory::GlobalAllocator.RequestPage();

        Add_Interrupt((void*)&Sauce::Interrupts::PageFault_handler,0xE,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::DoubleFault_handler,0x8,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::GeneralProtectionFault_handler,0xD,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::KeyboardInterrupt_handler,0x21,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::MouseInterrupt_handler,0x2C,IDT_TA_InterruptGate,0x08);
        Add_Interrupt((void*)&Sauce::Interrupts::PITInterrupt_handler,0x20,IDT_TA_InterruptGate,0x08);

        asm volatile("lidt %0" : : "m" (idtr));
    }
    void Kernel_cl::Prep_IO(){
        Sauce::Interrupts::RemapPic();
        Sauce::IO::PS2MouseInitialize();
    }
    void Kernel_cl::Prep_ACPI(){
        Sauce::IO::ACPI::SDTHeader* xsdt = (Sauce::IO::ACPI::SDTHeader*)DFBL->rsdp->XSDT_Address;
        Sauce::IO::ACPI::MCFGHeader* mcfg = (Sauce::IO::ACPI::MCFGHeader*)Sauce::IO::ACPI::FindTable(xsdt,(char*)"MCFG");
        Sauce::IO::EnumeratePCI(mcfg);
    }
    void Kernel_cl::oNotify_Of_KeyPress(Sauce::IO::Keyboard_st xKeyboard){
        InputData.Keyboard.Capital=xKeyboard.Capital;
        InputData.Keyboard.Press=xKeyboard.Press;
        InputData.Keyboard.visible=xKeyboard.visible;
        InputData.Keyboard.Key=xKeyboard.Key;
        InputData.Keyboard.Display=xKeyboard.Display;
        InputData.NewKeyboard=true;
        kShell.Input(InputData);
        InputData.NewKeyboard=false;
    }
    void Kernel_cl::oNotify_Of_Mouse(Sauce::IO::Mouse_st* xMouse){
        if(xMouse->Position->X < 0)xMouse->Position->X=0;//< Don't draw the mouse too far to the right.
        if(xMouse->Position->Y < 0)xMouse->Position->Y=0;//< Don't draw the mouse too high up.
        if(xMouse->Position->X > Sauce::IO::GlobalTerminal->MaxX(Sauce::IO::GlobalTerminal->CharX()))xMouse->Position->X=Sauce::IO::GlobalTerminal->MaxX(Sauce::IO::GlobalTerminal->CharX());//< Don't draw the mouse too far to the left.
        if(xMouse->Position->Y > Sauce::IO::GlobalTerminal->MaxY(Sauce::IO::GlobalTerminal->CharY()))xMouse->Position->Y=Sauce::IO::GlobalTerminal->MaxY(Sauce::IO::GlobalTerminal->CharY());//< Don't draw the mouse too far down.
        
        InputData.Mouse.RightButton=xMouse->RightButton;
        InputData.Mouse.LeftButton=xMouse->LeftButton;
        InputData.Mouse.CenterButton=xMouse->CenterButton;
        InputData.Mouse.Position=*xMouse->Position;
        InputData.Mouse.Good=xMouse->Good;
        InputData.NewMouse=true;
        kShell.Input(InputData);
        InputData.NewMouse=false;

    }
    void Kernel_cl::Notify_Of_KeyPress(Sauce::IO::Keyboard_st xKeyboard){
        Self->oNotify_Of_KeyPress(xKeyboard);
    }
    void Kernel_cl::Notify_Of_Mouse(){
        Self->oNotify_Of_Mouse(Sauce::IO::ProcessMousePacket());
    }
    void Kernel_cl::Stop(bool ClearInterrupts){
        while(true){
            if(ClearInterrupts)asm volatile("cli");
            asm volatile("hlt");
        }
    }
};