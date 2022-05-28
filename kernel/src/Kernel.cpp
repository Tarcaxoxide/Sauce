#include<Sauce/Kernel.hpp>
#include<Sauce/Utilities/Conversion.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/efiMemory.h>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/ACPI.hpp>
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
#include<Sauce/Global/Global.hpp>

namespace Sauce{
    Kernel_cl* Kernel_cl::Self=NULL; // pointer to the active kernel to be used by the kernel 
                            //when being updated by the hardware (Example: interrupts)
    bool ReadyToDraw=true;
    Kernel_cl::Kernel_cl(DataStructure* DFBL){
        asm volatile("cli");
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Kernel_cl]\n\0");
        this->DFBL=DFBL;
        if(Self == NULL)Self=this;
        
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();
        
        Sauce::Interrupts::PIT::SetDivisor(65535);
        Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x10);

        Prep_Interrupts();
        asm volatile("sti");
        Prep_IO();
        asm volatile("cli");
        Sauce::Global::Terminal=new Sauce::Graphics::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
        Sauce::Global::Shell=new Sauce::Graphics::Shell_cl({DFBL->FrameBuffer->PixelsPerScanLine,DFBL->FrameBuffer->Height,0},{0,0,0});
        Sauce::Global::Mouse=new Sauce::Graphics::Mouse_cl({50,50,0});
        Sauce::IO::outb(PIC1_DATA,0b11111000);
        Sauce::IO::outb(PIC2_DATA,0b11101111);
        Sauce::Global::Terminal->Clear();
        Prep_ACPI();
        PreLoop();
        MainLoop();
    }
    void Kernel_cl::PreLoop(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::PreLoop]\n\0");
        Sauce::Global::Shell->SetColor({0x00,0xFA,0xFA,0xFF});
    }
    void Kernel_cl::MainLoop(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::MainLoop]\n\0");
        while(true){
            asm volatile("sti");Sauce::Interrupts::PIT::Sleep(500);asm volatile("cli");
            DrawUI();
        }
    }
    void Kernel_cl::Prep_GlobalAllocator(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_GlobalAllocator]\n\0");
        Sauce::Global::PageFrameAllocator = Sauce::Memory::PageFrameAllocator_cl();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::Global::PageFrameAllocator.ReadEfiMemoryMap((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::Global::PageFrameAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::Memory::PageTable*)Sauce::Global::PageFrameAllocator.RequestPage();
        Sauce::Memory::memset(PML4,0,0x1000);
        Sauce::Global::PageTableManager = Sauce::Memory::PageTableManager_cl(PML4);
    }
    void Kernel_cl::Prep_VirtualAddresses(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_VirtualAddresses]\n\0");
        for(uint64_t t=0;t<Sauce::Memory::GetMemorySize((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            Sauce::Global::PageTableManager.MapMemory((void*)t,(void*)t);
        }
        DFBL->fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        DFBL->fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::Global::PageFrameAllocator.LockPages((void*)DFBL->fbBase,DFBL->fbSize/0x1000 +1);
        for(uint64_t t=DFBL->fbBase;t<DFBL->fbBase+DFBL->fbSize;t+=0x1000){
            Sauce::Global::PageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
    }
    void Kernel_cl::Prep_GDT(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_GDT]\n\0");
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT_st)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void Kernel_cl::Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Add_Interrupt]\n\0");
        Sauce::Interrupts::IDTDescriptorEntry* Interrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + Interrupt_Number * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        Interrupt->SetOffset((uint64_t)Interrupt_Handler);
        Interrupt->type_attr = type_attr;
        Interrupt->selector=selector;
    }
    void Kernel_cl::Prep_Interrupts(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_Interrupts]\n\0");
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Global::PageFrameAllocator.RequestPage();

        Add_Interrupt((void*)&Sauce::Interrupts::PageFault_handler,0xE,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(PageFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::DoubleFault_handler,0x8,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(DoubleFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::GeneralProtectionFault_handler,0xD,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(GeneralProtectionFault_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::KeyboardInterrupt_handler,0x21,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(KeyboardInterrupt_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::MouseInterrupt_handler,0x2C,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(MouseInterrupt_handler)\n\0");
        Add_Interrupt((void*)&Sauce::Interrupts::PITInterrupt_handler,0x20,IDT_TA_InterruptGate,0x08);
        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(PITInterrupt_handler)\n\0");

        asm volatile("lidt %0" : : "m" (idtr));
    }
    void Kernel_cl::Prep_IO(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_IO]\n\0");
        Sauce::Interrupts::RemapPic();
    }
    void Kernel_cl::Prep_ACPI(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Prep_ACPI]\n\0");
        Sauce::IO::ACPI::SDTHeader* xsdt = (Sauce::IO::ACPI::SDTHeader*)DFBL->rsdp->XSDT_Address;
        Sauce::IO::ACPI::MCFGHeader* mcfg = (Sauce::IO::ACPI::MCFGHeader*)Sauce::IO::ACPI::FindTable(xsdt,(char*)"MCFG");
        Sauce::IO::EnumeratePCI(mcfg);
    }
    void Kernel_cl::oNotify_Of_KeyPress(Sauce::IO::Keyboard_st xKeyboard){
        ReadyToDraw=false;
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::oNotify_Of_KeyPress]\n\0");
        if(xKeyboard.Press){
            switch(xKeyboard.Key){
                case 0xD6:{
                    Sauce::Global::Shell->PutChar('\n');
                    Sauce::Global::Shell->PutChar('\r');
                }break;
                case 0x1C:{
                    Sauce::Global::Shell->PutChar('\b');
                }break;
                default:{   
                    if(xKeyboard.visible){
                        Sauce::Global::Shell->PutChar(xKeyboard.Display);
                    }else{
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(\0");
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString(xKeyboard.Key));
                        if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                    }
                }break;
            }
        }
    }
    int testcount=0;
    Point64_t CurrentMouseCursorPosition{0,0,0};
    void Kernel_cl::oNotify_Of_Mouse(Sauce::IO::Mouse_st* xMouse){
        ReadyToDraw=false;
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::oNotify_Of_Mouse]\n\0");
        
        if(CurrentMouseCursorPosition.X != xMouse->Position->X || CurrentMouseCursorPosition.Y != xMouse->Position->Y){
            CurrentMouseCursorPosition = Point64_t{xMouse->Position->X,xMouse->Position->Y,xMouse->Position->Z};
            Sauce::Global::Mouse->Move(CurrentMouseCursorPosition);
        }
    }
    void Kernel_cl::DrawUI(){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::DrawUI]\n\0");
        if(!ReadyToDraw){
            ReadyToDraw=true;
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            return;
        }
        
        Sauce::Global::Terminal->CopyFrom(Sauce::Global::Shell);
        Sauce::Global::Terminal->CopyFrom(Sauce::Global::Mouse);
        Sauce::Global::Terminal->CopyTo(DFBL->FrameBuffer->BaseAddress,(size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
        if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
    }
    void Kernel_cl::Notify(Sauce::Interrupts::InterruptDataStruct InterruptData){
        asm volatile("cli");
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Notify]\n\0");
        switch(InterruptData.TypeCode){
            case Sauce::Interrupts::InterruptTypeCode::ITC__Mouse:{
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(Mouse)\n\0");
                Sauce::IO::HandlePS2Mouse(InterruptData.RawInterruptData);
                Self->oNotify_Of_Mouse(Sauce::IO::ProcessMousePacket());
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Keyboard:{
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(Keyboard)\n\0");
                Self->oNotify_Of_KeyPress(Sauce::IO::Code_To_Key(Sauce::IO::Translate_KeyCode(InterruptData.RawInterruptData)));
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__NULL:{
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(NULL)\n\0");
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Time:{
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(Time)\n\0");
            }break;
        }
        if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::KERNEL && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        asm volatile("sti");
    }
    void Kernel_cl::Stop(bool ClearInterrupts){
        if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"[Kernel_cl::Stop]\n\0");
        while(true){
            if(ClearInterrupts)asm volatile("cli");
            asm volatile("hlt");
        }
        if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::KERNEL)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
    }
};