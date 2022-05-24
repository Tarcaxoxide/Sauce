#include<Sauce/Kernel.hpp>
#include<Sauce/Convert/To_String.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/efiMemory.h>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/ACPI/ACPI.hpp>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/UserLand/VirtualMachine.hpp>
#include<Sauce/IO/Debug/Serial.hpp>
#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Graphics/Font.hpp>


namespace Sauce{
    Kernel_cl* Kernel_cl::Self=NULL; // pointer to the active kernel to be used by the kernel 
                            //when being updated by the hardware (Example: interrupts)
    Kernel_cl::Kernel_cl(DataStructure* DFBL){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Kernel_cl]\n\0");
        this->DFBL=DFBL;
        if(Self == NULL)Self=this;
        asm volatile("cli");

        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();

        Sauce::Interrupts::PIT::SetDivisor(65535);
        Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x10);
        
        Prep_Interrupts();

        Prep_IO();// in qemu it wont actually continue past this point until it receives a mouse event.
                  // or at least that's what it looks like because it wont type the finish text till then.
        
        Sauce::Graphics::GlobalTerminal=new Sauce::Graphics::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);


        Sauce::IO::outb(PIC1_DATA,0b11111000);
        Sauce::IO::outb(PIC2_DATA,0b11101111);
        Sauce::Graphics::GlobalTerminal->Clear();

        asm volatile("sti");
        

        Prep_ACPI();
        PreLoop();
        MainLoop();
    }
    void Kernel_cl::PreLoop(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::PreLoop]\n\0");
        
        /*testing terminal*/{
            for(size_t i=0;i<DFBL->FrameBuffer->PixelsPerScanLine-5;i+=5){
                Sauce::Graphics::GlobalTerminal->RowFill(i,{0x40,0x00,0x00,0XFF});
            }
            for(size_t i=0;i<DFBL->FrameBuffer->Height-5;i+=5){
                Sauce::Graphics::GlobalTerminal->ColumnFill(i,{0x00,0x40,0x00,0XFF});
            }

            Sauce::Graphics::Shell_cl TestWindow({1800,900,0},{60,40,0});

            TestWindow.PutChar(L'\"');
            TestWindow.PutChar(L'\'');
            TestWindow.PutChar(L' ');
            TestWindow.PutChar(L'!');
            TestWindow.PutChar(L'#');
            TestWindow.PutChar(L'$');
            TestWindow.PutChar(L'%');
            TestWindow.PutChar(L'&');
            TestWindow.PutChar(L'(');
            TestWindow.PutChar(L')');
            TestWindow.PutChar(L'*');
            TestWindow.PutChar(L'+');
            TestWindow.PutChar(L',');
            TestWindow.PutChar(L'-');
            TestWindow.PutChar(L'.');
            TestWindow.PutChar(L'/');
            TestWindow.PutChar(L'0');
            TestWindow.PutChar(L'1');
            TestWindow.PutChar(L'2');
            TestWindow.PutChar(L'3');
            TestWindow.PutChar(L'4');
            TestWindow.PutChar(L'5');
            TestWindow.PutChar(L'6');
            TestWindow.PutChar(L'7');
            TestWindow.PutChar(L'8');
            TestWindow.PutChar(L'9');
            TestWindow.PutChar(L':');
            TestWindow.PutChar(L';');
            TestWindow.PutChar(L'<');
            TestWindow.PutChar(L'=');
            TestWindow.PutChar(L'>');
            TestWindow.PutChar(L'?');
            TestWindow.PutChar(L'@');
            TestWindow.PutChar(L'A');
            TestWindow.PutChar(L'B');
            TestWindow.PutChar(L'C');
            TestWindow.PutChar(L'D');
            TestWindow.PutChar(L'E');
            TestWindow.PutChar(L'F');
            TestWindow.PutChar(L'G');
            TestWindow.PutChar(L'H');
            TestWindow.PutChar(L'I');
            TestWindow.PutChar(L'J');
            TestWindow.PutChar(L'K');
            TestWindow.PutChar(L'L');
            TestWindow.PutChar(L'M');
            TestWindow.PutChar(L'N');
            TestWindow.PutChar(L'O');
            TestWindow.PutChar(L'P');
            TestWindow.PutChar(L'Q');
            TestWindow.PutChar(L'R');
            TestWindow.PutChar(L'T');
            TestWindow.PutChar(L'U');
            TestWindow.PutChar(L'V');
            TestWindow.PutChar(L'W');
            TestWindow.PutChar(L'X');
            TestWindow.PutChar(L'Y');
            TestWindow.PutChar(L'Z');
            TestWindow.PutChar(L'[');
            TestWindow.PutChar(L'\\');
            TestWindow.PutChar(L']');
            TestWindow.PutChar(L'^');
            TestWindow.PutChar(L'_');
            TestWindow.PutChar(L'`');
            TestWindow.PutChar(L'a');
            TestWindow.PutChar(L'b');
            TestWindow.PutChar(L'c');
            TestWindow.PutChar(L'd');
            TestWindow.PutChar(L'e');
            TestWindow.PutChar(L'f');
            TestWindow.PutChar(L'g');
            TestWindow.PutChar(L'h');
            TestWindow.PutChar(L'i');
            TestWindow.PutChar(L'j');
            TestWindow.PutChar(L'k');
            TestWindow.PutChar(L'l');
            TestWindow.PutChar(L'm');
            TestWindow.PutChar(L'n');
            TestWindow.PutChar(L'o');
            TestWindow.PutChar(L'p');
            TestWindow.PutChar(L'q');
            TestWindow.PutChar(L'r');
            TestWindow.PutChar(L's');
            TestWindow.PutChar(L't');
            TestWindow.PutChar(L'u');
            TestWindow.PutChar(L'v');
            TestWindow.PutChar(L'w');
            TestWindow.PutChar(L'x');
            TestWindow.PutChar(L'y');
            TestWindow.PutChar(L'z');
            TestWindow.PutChar(L'{');
            TestWindow.PutChar(L'|');
            TestWindow.PutChar(L'}');
            TestWindow.PutChar(L'~');
            TestWindow.PutChar(L'€');

            Sauce::Graphics::GlobalTerminal->CopyFrom(&TestWindow);

            Sauce::Graphics::GlobalTerminal->CopyTo(DFBL->FrameBuffer->BaseAddress,(size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
        };
    }
    void Kernel_cl::MainLoop(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::MainLoop]\n\0");
        do{
            asm volatile("cli");
            asm volatile("sti");
        }while(true);
    }
    void Kernel_cl::Prep_GlobalAllocator(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_GlobalAllocator]\n\0");
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
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_VirtualAddresses]\n\0");
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
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_GDT]\n\0");
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT_st)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void Kernel_cl::Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Add_Interrupt]\0");
        Sauce::Interrupts::IDTDescriptorEntry* Interrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + Interrupt_Number * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        Interrupt->SetOffset((uint64_t)Interrupt_Handler);
        Interrupt->type_attr = type_attr;
        Interrupt->selector=selector;
    }
    void Kernel_cl::Prep_Interrupts(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_Interrupts]\n\0");
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Memory::GlobalAllocator.RequestPage();

        Add_Interrupt((void*)&Sauce::Interrupts::PageFault_handler,0xE,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(PageFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::DoubleFault_handler,0x8,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(DoubleFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::GeneralProtectionFault_handler,0xD,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(GeneralProtectionFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::KeyboardInterrupt_handler,0x21,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(KeyboardInterrupt_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::MouseInterrupt_handler,0x2C,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(MouseInterrupt_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::PITInterrupt_handler,0x20,IDT_TA_InterruptGate,0x08);
        Sauce::IO::Debug::COM1_Console.Write((char*)"->(PITInterrupt_handler)\n\0");

        asm volatile("lidt %0" : : "m" (idtr));
    }
    void Kernel_cl::Prep_IO(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_IO]\n\0");
        Sauce::Interrupts::RemapPic();
        /*Not Handled By Terminal Anymore, Please Implement in Shell*///Sauce::IO::PS2MouseInitialize({Sauce::IO::GlobalTerminal->CharX()*5,Sauce::IO::GlobalTerminal->CharY()*5,0});
    }
    void Kernel_cl::Prep_ACPI(){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_ACPI]\n\0");
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
        /*Broke it XD please re-implement*///kShell.Input(InputData);
        InputData.NewKeyboard=false;
    }
    void Kernel_cl::oNotify_Of_Mouse(Sauce::IO::Mouse_st* xMouse){
        if(xMouse->Position->X < 0)xMouse->Position->X=0;//< Don't draw the mouse too far to the right.
        if(xMouse->Position->Y < 0)xMouse->Position->Y=0;//< Don't draw the mouse too high up.
        /*Not Handled By Terminal Anymore, Please Implement in Shell*///if(xMouse->Position->X > Sauce::IO::GlobalTerminal->MaxX(Sauce::IO::GlobalTerminal->CharX()))xMouse->Position->X=Sauce::IO::GlobalTerminal->MaxX(Sauce::IO::GlobalTerminal->CharX());//< Don't draw the mouse too far to the left.
        /*Not Handled By Terminal Anymore, Please Implement in Shell*///if(xMouse->Position->Y > Sauce::IO::GlobalTerminal->MaxY(Sauce::IO::GlobalTerminal->CharY()))xMouse->Position->Y=Sauce::IO::GlobalTerminal->MaxY(Sauce::IO::GlobalTerminal->CharY());//< Don't draw the mouse too far down.
        InputData.Mouse.RightButton=xMouse->RightButton;
        InputData.Mouse.LeftButton=xMouse->LeftButton;
        InputData.Mouse.CenterButton=xMouse->CenterButton;
        InputData.Mouse.Position=*xMouse->Position;
        InputData.Mouse.Good=xMouse->Good;
        InputData.NewMouse=true;
        /*Broke it XD please re-implement*///kShell.Input(InputData);
        InputData.NewMouse=false;

    }
    void Kernel_cl::Notify(Sauce::Interrupts::InterruptDataStruct InterruptData){
        switch(InterruptData.TypeCode){
            case Sauce::Interrupts::InterruptTypeCode::ITC__Mouse:{
                Sauce::IO::HandlePS2Mouse(InterruptData.RawInterruptData);
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Keyboard:{
                    Self->oNotify_Of_KeyPress(Sauce::IO::Code_To_Key(Sauce::IO::Translate_KeyCode(InterruptData.RawInterruptData)));
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__NULL:{
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Time:{
                Self->oNotify_Of_Mouse(Sauce::IO::ProcessMousePacket());
            }break;
        }
    }
    void Kernel_cl::Stop(bool ClearInterrupts){
        Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Stop]\n\0");
        while(true){
            if(ClearInterrupts)asm volatile("cli");
            asm volatile("hlt");
        }
    }
};