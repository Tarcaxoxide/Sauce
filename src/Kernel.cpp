#include <Sauce.hpp>

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack

extern "C" uint64_t _HeadOfheap;

void NotifyKernelOfKeyPress(Sauce::Keyboard::KeyboardKey _Key){
    // theoretically i should just be able to pass this _Key object to userland.
    if(_Key.Press){ // we just have some testing code here I guess; a prototype key handler.
        char D=_Key.Display;
        if(D != NULL && _Key.visible){
            Sauce::Terminal::Character(D);
        }else if(_Key.visible){ // unhandled key.
            Sauce::Terminal::String("0x");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint8(_Key.Key));
        }else{
            switch(_Key.Key){
                case 0x1C:{
                    Sauce::Terminal::BackSpace();
                    }break;
                case 0xD6:{
                    Sauce::Terminal::NewLine();
                    Sauce::Terminal::ReturnCaret();
                    }break;
                case 0xBE:{
                    Sauce::Terminal::RelativeSetCursor(true,0,-1); //up arrow
                    }break;
                case 0xCA:{
                    Sauce::Terminal::RelativeSetCursor(true,1,0); //right arrow
                    }break;
                case 0xC2:{
                    Sauce::Terminal::RelativeSetCursor(true,0,1); //down arrow
                    }break;
                case 0xB6:{
                    Sauce::Terminal::RelativeSetCursor(true,-1,0); //left arrow
                    }break;
            }
        }
        
    }
}

void tests(){
    Sauce::Terminal::Clear();
    Sauce::Terminal::String("Hello From Sauce OS.\n\r");
    Sauce::Memory::MemoryMapEntryMap MemMap = Sauce::Memory::GetMemoryRegions();
    Sauce::Terminal::String("\n\rUsable Memory Region...\n\r");
    for(uint8_t I=0;I<MemMap.MemoryMapEntryCount;I++){
        Sauce::Memory::PrintMemoryMap(MemMap.MemoryMapEntries[I]);
        Sauce::Terminal::String("\n\r");
    }
    Sauce::Terminal::String("\n\rHeap Testing...\n\r");
    Sauce::Memory::InitializeHead(_HeadOfheap,0x100000);
    void* TestMemoryMap1 = Sauce::Memory::malloc(0x20);
    void* TestMemoryMap2 = Sauce::Memory::malloc(0x20);
    void* TestMemoryMap3 = Sauce::Memory::malloc(0x20);
    void* TestMemoryMap4 = Sauce::Memory::malloc(0x10);
    Sauce::Terminal::String("\n\rTestMemoryMap1:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap1));
    Sauce::Terminal::String("\n\rTestMemoryMap2:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap2));
    Sauce::Terminal::String("\n\rTestMemoryMap3:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap3));
    Sauce::Terminal::String("\n\rTestMemoryMap4:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap4));
    
    Sauce::Terminal::String("\n\rfree(TestMemoryMap1)");
    Sauce::Memory::free(TestMemoryMap1);
    Sauce::Terminal::String("\n\rfree(TestMemoryMap2)");
    Sauce::Memory::free(TestMemoryMap2);
    Sauce::Terminal::String("\n\rfree(TestMemoryMap3)");
    Sauce::Memory::free(TestMemoryMap3);
    void* TestMemoryMap5 = Sauce::Memory::malloc(0x60);
    Sauce::Terminal::String("\n\rTestMemoryMap5:");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap5));
    Sauce::Terminal::String("\n\rreallocate TestMemoryMap5 (+0x20):\n\r");
    TestMemoryMap5 = Sauce::Memory::realloc(TestMemoryMap5,0x80);
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)TestMemoryMap5));
    
    Sauce::Terminal::String("\n\rRemaining stack space available...\n\r");
    Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(GetFreeStack()));
    Sauce::Terminal::String("\n\r");
}

void Kernel_Main(){
    tests();
    
    Sauce::Interrupts::InitializeIDT();

    
    while(1){
        asm volatile("hlt");
    }
}
