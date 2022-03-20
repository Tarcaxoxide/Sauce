#include<Sauce/Kernel.hpp>

namespace Sauce{
    _Kernel::_Kernel(DataStructure* DFBL)
        :Term(DFBL){
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
    void _Kernel::Stop(){
        while(true){
            asm volatile("hlt");
        }
    }
};