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
        Sauce::GlobalAllocator = Sauce::PageFrameAllocator();
        mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
        Sauce::GlobalAllocator.ReadEfiMemoryMap(DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
        kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
        kernelPages = (uint64_t)kernelSize/4096 +1;
        Sauce::GlobalAllocator.LockPages(&_KernelStartRef,kernelPages);
        PML4 = (Sauce::PageTable*)Sauce::GlobalAllocator.RequestPage();
        Sauce::memset(PML4,0,0x1000);
        pageTableManager.Initialize(PML4);
    }
    void _Kernel::Prep_VirtualAddresses(){
        if(Debug)Term.PutString("Preping Virtual Addresses...\n\r");
        for(uint64_t t=0;t<Sauce::GetMemorySize(DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
        fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
        Sauce::GlobalAllocator.LockPages((void*)fbBase,fbSize/0x1000 +1);
        for(uint64_t t=fbBase;t<fbBase+fbSize;t+=0x1000){
            pageTableManager.MapMemory((void*)t,(void*)t);
        }
        asm volatile("mov %0, %%cr3" : : "r" (PML4));
    }
    void _Kernel::Prep_GDT(){
        if(Debug)Term.PutString("Preping GlobalDescriptorTable...\n\r");
        gdtDescriptor.Size=sizeof(GDT)-1;
        gdtDescriptor.Offset= (uint64_t)&DefaultGDT;
        LoadGDT(&gdtDescriptor);
    }
    void _Kernel::Prep_Interrupts(){
        if(Debug)Term.PutString("Preping Interrupts...\n\r");
        idtr.Limit = 0x0FFF;
        idtr.Offset= (uint64_t)GlobalAllocator.RequestPage();

        //
        IDTDescriptorEntry* int_PageFault = (IDTDescriptorEntry*)(idtr.Offset + 0xE * sizeof(IDTDescriptorEntry));
        int_PageFault->SetOffset((uint64_t)PageFault_handler);
        int_PageFault->type_attr = IDT_TA_InterruptGate;
        int_PageFault->selector=0x08;
        //
        //
        IDTDescriptorEntry* int_DoubleFault = (IDTDescriptorEntry*)(idtr.Offset + 0x8 * sizeof(IDTDescriptorEntry));
        int_DoubleFault->SetOffset((uint64_t)DoubleFault_handler);
        int_DoubleFault->type_attr = IDT_TA_InterruptGate;
        int_DoubleFault->selector=0x08;
        //
        //
        IDTDescriptorEntry* int_GeneralProtectionFault = (IDTDescriptorEntry*)(idtr.Offset + 0xD * sizeof(IDTDescriptorEntry));
        int_GeneralProtectionFault->SetOffset((uint64_t)GeneralProtectionFault_handler);
        int_GeneralProtectionFault->type_attr = IDT_TA_InterruptGate;
        int_GeneralProtectionFault->selector=0x08;
        //

        
        asm("lidt %0" : : "m" (idtr));
    }
    void _Kernel::Stop(){
        while(true){
            asm volatile("cli;hlt");
        }
    }
};