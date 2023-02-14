#include<Sauce/Kernel.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Memory/efiMemory.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageMapIndexer.hpp>
#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Debug/Panic.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/ACPI.hpp>
#include<Sauce/IO/PCI.hpp>
#include<Sauce/Memory/Heap.hpp>
#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/Memory/List.hpp>
#include<Sauce/IO/Debug/Serial.hpp>
#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Graphics/Window.hpp>
#include<Sauce/Graphics/Shell.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/IO/Keyboard.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    int testcount=0;
	Sauce::Point64_st CurrentMouseCursorPosition{0,0,0};
    Sauce::Mouse_st oMouse;
    Sauce::Point64_st oMousePosition;
    Kernel_cl::Kernel_cl(DataStructure* DFBL){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Kernel_cl",_NAMESPACE_,_ALLOW_PRINT_);
        asm volatile("cli");
        this->DFBL=DFBL;
        Sauce::Global::Kernel=this;
        Prep_GlobalAllocator();
        Prep_VirtualAddresses();
        Prep_GDT();
        //setup memory
        Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x512);

        //setting up divisor for timer interrupt and initializing the heap, should happen after virtual address
        //but before setting up the interrupts.
        Sauce::Interrupts::PIT::SetDivisor(65535/6);
        Debugger.Print("The kernel says hi!");
        Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)_KernelEndRef));
        Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)_KernelStartRef));
        
        Prep_Interrupts();
        asm volatile("sti");
        Prep_IO();
        asm volatile("cli");//be default we have interrupts disabled and we enable them when we want to recieve them,
                            //this happens in the main loop when we call 'AcceptingIntterupts'
        Prep_Windows();
        Sauce::IO::outb(PIC1_DATA,0b11111000);
        Sauce::IO::outb(PIC2_DATA,0b11101111);
        Sauce::Math::random_seed(8649245912657);
        // these are for the click detection
        oMouse.Position=&oMousePosition;
        oMouse.CenterButton=false;
        oMouse.RightButton=false;
        oMouse.LeftButton=false;
        Prep_ACPI();
        MainLoop();
    }
    void Kernel_cl::Prep_Windows(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_Windows",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Global::Terminal=new Sauce::Graphics::Basic::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
        Sauce::Global::Screen=new Sauce::Graphics::Basic::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine,{0,0,0},DFBL->FrameBuffer->BaseAddress);
        Sauce::Global::Mouse=new Sauce::Graphics::Mouse_cl({DFBL->FrameBuffer->PixelsPerScanLine/2,DFBL->FrameBuffer->Height/2,0});
        Sauce::Global::Mouse->SetID((char*)"Mouse");
        Sauce::Global::Terminal->SetColor({0x11,0x11,0x11,0x00},{0x11,0x11,0x11,0x00});
        //Sauce::Global::Terminal->SetID((char*)"Terminator");
        Sauce::Global::Terminal->Clear();

        Sauce::Global::Shell=new Sauce::Graphics::Shell_cl({DFBL->FrameBuffer->PixelsPerScanLine-4,DFBL->FrameBuffer->Height-4,0},{2,2,0});
        Sauce::Global::Shell->SetID((char*)"Shell");
        Sauce::Global::Windows.AddLast((Sauce::Graphics::Window_cl*)Sauce::Global::Shell);
    }
    void Kernel_cl::MainLoop(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::MainLoop",_NAMESPACE_,_ALLOW_PRINT_);
        while(true){
            AcceptingInterrupts(100);// are accepting interrupts for X miliseconds, X being the number passed to 'AcceptingInterrupts(X)'.
            DrawUI();// we do all the drawing operations by calling this function, it's effectively 'double buffering'.
        }
    }
    void Kernel_cl::Prep_GlobalAllocator(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_GlobalAllocator",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Global::PageFrameAllocator = Sauce::Memory::Management::PageFrameAllocator_cl();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::Global::PageFrameAllocator.ReadEfiMemoryMap((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::Global::PageFrameAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::Memory::Management::PageTable*)Sauce::Global::PageFrameAllocator.RequestPage();
        Sauce::Memory::memset(PML4,0,0x1000);
        Sauce::Global::PageTableManager = Sauce::Memory::Management::PageTableManager_cl(PML4);
    }
    void Kernel_cl::Prep_VirtualAddresses(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_VirtualAddresses",_NAMESPACE_,_ALLOW_PRINT_);
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
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_GDT",_NAMESPACE_,_ALLOW_PRINT_);
        gdtDescriptor.Size= sizeof(Sauce::GDT::GDT_st)-1;
        gdtDescriptor.Offset= (uint64_t)&Sauce::GDT::DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void Kernel_cl::Add_Interrupt(void* Interrupt_Handler,uint8_t Interrupt_Number,uint8_t type_attr,uint8_t selector){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Add_Interrupt",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Interrupts::IDTDescriptorEntry* Interrupt = (Sauce::Interrupts::IDTDescriptorEntry*)(idtr.Offset + Interrupt_Number * sizeof(Sauce::Interrupts::IDTDescriptorEntry));
        Interrupt->SetOffset((uint64_t)Interrupt_Handler);
        Interrupt->type_attr = type_attr;
        Interrupt->selector=selector;
    }
    void Kernel_cl::Prep_Interrupts(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_Interrupts",_NAMESPACE_,_ALLOW_PRINT_);
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)Sauce::Global::PageFrameAllocator.RequestPage();
        Add_Interrupt((void*)&Sauce::Interrupts::PageFault_handler,0xE,IDT_TA_InterruptGate,0x08);
        Debugger.Print("PageFault_handler");
        Add_Interrupt((void*)&Sauce::Interrupts::DoubleFault_handler,0x8,IDT_TA_InterruptGate,0x08);
        Debugger.Print("DoubleFault_handler");
        Add_Interrupt((void*)&Sauce::Interrupts::GeneralProtectionFault_handler,0xD,IDT_TA_InterruptGate,0x08);
        Debugger.Print("GeneralProtectionFault_handler");
        Add_Interrupt((void*)&Sauce::Interrupts::KeyboardInterrupt_handler,0x21,IDT_TA_InterruptGate,0x08);
        Debugger.Print("KeyboardInterrupt_handler");
        Add_Interrupt((void*)&Sauce::Interrupts::MouseInterrupt_handler,0x2C,IDT_TA_InterruptGate,0x08);
        Debugger.Print("MouseInterrupt_handler");
        Add_Interrupt((void*)&Sauce::Interrupts::PITInterrupt_handler,0x20,IDT_TA_InterruptGate,0x08);
        Debugger.Print("PITInterrupt_handler");
        asm volatile("lidt %0" : : "m" (idtr));
    }
    void Kernel_cl::Prep_IO(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_IO",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::Interrupts::RemapPic();
    }
    void Kernel_cl::Prep_ACPI(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_ACPI",_NAMESPACE_,_ALLOW_PRINT_);
        Sauce::IO::ACPI::SDTHeader* xsdt = (Sauce::IO::ACPI::SDTHeader*)DFBL->rsdp->XSDT_Address;
        Sauce::IO::ACPI::MCFGHeader* mcfg = (Sauce::IO::ACPI::MCFGHeader*)Sauce::IO::ACPI::FindTable(xsdt,(char*)"MCFG");
        Sauce::IO::EnumeratePCI(mcfg);
    }
    void Kernel_cl::oNotify_Of_KeyPress(Sauce::Keyboard_st xKeyboard){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::oNotify_Of_KeyPress",_NAMESPACE_,_ALLOW_PRINT_);
        if(xKeyboard.Press){
            switch(xKeyboard.Key){
                case 0xD6:{
                    /*Sauce::Global::Shell*/Sauce::Global::Windows[0]->PutChar('\n',true);
                    /*Sauce::Global::Shell*/Sauce::Global::Windows[0]->PutChar('\r',true);
                }break;
                case 0x1C:{
                    /*Sauce::Global::Shell*/Sauce::Global::Windows[0]->PutChar('\b',true);
                }break;
                default:{   
                    if(xKeyboard.visible){
                        /*Sauce::Global::Shell*/Sauce::Global::Windows[0]->PutChar(xKeyboard.Display,true);
                    }else{
                       Debugger.Print(Sauce::Utility::Conversion::HexToString(xKeyboard.Key));
                    }
                }break;
            }
        }
    }
    void Kernel_cl::oNotify_Of_Mouse(Sauce::Mouse_st* xMouse){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::oNotify_Of_Mouse",_NAMESPACE_,_ALLOW_PRINT_);
        if(xMouse->Position->Y < 0){xMouse->Position->Y=0;}
        if(xMouse->Position->X < 0){xMouse->Position->X=0;}
        if((xMouse->Position->Y+Sauce::Global::Mouse->Size().Y) > DFBL->FrameBuffer->Height){xMouse->Position->Y=DFBL->FrameBuffer->Height-Sauce::Global::Mouse->Size().Y;}
        if((xMouse->Position->X+Sauce::Global::Mouse->Size().X) > DFBL->FrameBuffer->Width){xMouse->Position->X=DFBL->FrameBuffer->Width-Sauce::Global::Mouse->Size().X;}
        if(CurrentMouseCursorPosition.X != xMouse->Position->X || CurrentMouseCursorPosition.Y != xMouse->Position->Y){
            CurrentMouseCursorPosition = Sauce::Point64_st{xMouse->Position->X,xMouse->Position->Y,xMouse->Position->Z};
            Sauce::Global::Mouse->Move(CurrentMouseCursorPosition);
        }
        if(xMouse->CenterButton && xMouse->CenterButton != oMouse.CenterButton){
            //Press
            oMouse.CenterButton=xMouse->CenterButton;
            *oMouse.Position=*xMouse->Position;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
            }
        }else if(xMouse->CenterButton){
            //Drag
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
            }
        }else if(xMouse->CenterButton != oMouse.CenterButton){
            //Release
            oMouse.CenterButton=xMouse->CenterButton;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
            }
        }
        if(xMouse->RightButton && xMouse->RightButton != oMouse.RightButton){
            //Press
            oMouse.RightButton=xMouse->RightButton;
            *oMouse.Position=*xMouse->Position;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
            }
        }else if(xMouse->RightButton){
            //Drag
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
            }
        }else if(xMouse->RightButton != oMouse.RightButton){
            //Release
            oMouse.RightButton=xMouse->RightButton;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
            }
        }
        if(xMouse->LeftButton && xMouse->LeftButton != oMouse.LeftButton){
            //Press
            oMouse.LeftButton=xMouse->LeftButton;
            *oMouse.Position=*xMouse->Position;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
            }
        }else if(xMouse->LeftButton){
            //Drag
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
            }
        }else if(xMouse->LeftButton != oMouse.LeftButton){
            //Release
            oMouse.LeftButton=xMouse->LeftButton;
            for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
                Sauce::Global::Windows[i]->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
            }
        }
    }
    void Kernel_cl::DrawUI(){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::DrawUI",_NAMESPACE_,_ALLOW_PRINT_);
        for(size_t i=0;i<Sauce::Global::Windows.Size();i++){
            Sauce::Global::Terminal->CopyFrom(Sauce::Global::Windows[i]);
        }
        Sauce::Global::Terminal->CopyFrom(Sauce::Global::Mouse);
        Sauce::Global::Screen->CopyFrom(Sauce::Global::Terminal);
    }
    void Kernel_cl::AcceptingInterrupts(size_t TimeSpan){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::AcceptingInterrupts",_NAMESPACE_,_ALLOW_PRINT_);
        asm volatile("sti");
        Sauce::Interrupts::PIT::Sleep(TimeSpan);
        asm volatile("cli");
    }
    void Kernel_cl::Notify(Sauce::Interrupts::InterruptDataStruct InterruptData){
        Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Notify",_NAMESPACE_,_ALLOW_PRINT_);
        asm volatile("cli");
        switch(InterruptData.TypeCode){
            case Sauce::Interrupts::InterruptTypeCode::ITC__Mouse:{
                Debugger.Print("ITC__Mouse");
                Sauce::IO::HandlePS2Mouse(InterruptData.RawInterruptData);
                Sauce::Global::Kernel->oNotify_Of_Mouse(Sauce::IO::ProcessMousePacket());
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Keyboard:{
                Debugger.Print("ITC__Keyboard");
                Sauce::Global::Kernel->oNotify_Of_KeyPress(Sauce::IO::Code_To_Key(Sauce::IO::Translate_KeyCode(InterruptData.RawInterruptData)));
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__NULL:{
                Debugger.Print("ITC__NULL");
            }break;
            case Sauce::Interrupts::InterruptTypeCode::ITC__Time:{
                Debugger.Print("ITC__Time");
            }break;
        }
    }
};
