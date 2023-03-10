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
#include<std/to_string.hpp>

extern "C" int64_t _start(DataStructure* DFBL);

namespace Sauce{

	//Input Statics
		Sauce::Point64_st CurrentMouseCursorPosition{0,0,0};
		Sauce::Mouse_st oMouse;
		Sauce::Point64_st oMousePosition;
		Sauce::Mouse_st iMouse;
		Sauce::Point64_st iMousePosition;
		bool KeyboardAsMouseMode=false;
		bool KeyboardCtrl=false;
		bool KeyboardAlt=false;
		bool KeyboardDel=false;
		bool KeyboardIns=false;
		bool KeyboardEnd=false;
		bool KeyboardHome=false;
		bool KeyboardPageDown=false;
		bool KeyboardPageUp=false;
		bool KeyboardPause=false;
		bool KeyboardBreak=false;

	Kernel_cl::Kernel_cl(DataStructure* DFBL){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Kernel_cl",_NAMESPACE_,_ALLOW_PRINT_);
		asm volatile("cli");
		this->DFBL=DFBL;
		Sauce::Global::Kernel=this;
		Prep_GlobalAllocator();
		Prep_VirtualAddresses();
		Prep_GDT();
		//Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x512);
		Sauce::Memory::InitalizeHeap((void*)Sauce::Math::mb_to_b(512),1);
		Sauce::Interrupts::PIT::SetDivisor(65535/6);
		Debugger.Print("The kernel says hi!");
		Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)_KernelEndRef));
		Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)_KernelStartRef));
		Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)this));
		Debugger.Print(Sauce::Utility::Conversion::HexToString((uint64_t)DFBL->TestNumber));
		Prep_Interrupts();
		asm volatile("sti");
		Prep_IO();
		asm volatile("cli");
		Prep_Windows();
		Sauce::IO::outb(PIC1_DATA,0b11111000);
		Sauce::IO::outb(PIC2_DATA,0b11101111);
		Sauce::Math::random_seed(8649245912657);
		// these are for the click detection
		oMouse.Position=&oMousePosition;
		iMouse.Position=&iMousePosition;
		oMouse.CenterButton=false;
		oMouse.RightButton=false;
		oMouse.LeftButton=false;
		iMouse.CenterButton=false;
		iMouse.RightButton=false;
		iMouse.LeftButton=false;
		Prep_ACPI();
		Prep_Filesystem();
		MainLoop();
	}
	void Kernel_cl::Prep_Windows(){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_Windows",_NAMESPACE_,_ALLOW_PRINT_);
		//Construct
		Sauce::Global::Graphics::Terminal=new Sauce::Graphics::Basic::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
		Sauce::Global::Graphics::Screen=new Sauce::Graphics::Basic::Terminal_cl((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine,{0,0,0},DFBL->FrameBuffer->BaseAddress);
		Sauce::Global::Graphics::Mouse=new Sauce::Graphics::Mouse_cl({DFBL->FrameBuffer->PixelsPerScanLine/2,DFBL->FrameBuffer->Height/2,0});
		Sauce::Global::Graphics::Shell=new Sauce::Graphics::Shell_cl({DFBL->FrameBuffer->PixelsPerScanLine,DFBL->FrameBuffer->Height,0},{0,0,0});
		//Set IDs
		Sauce::Global::Graphics::Mouse->SetID((char*)"Mouse");
		Sauce::Global::Graphics::Shell->SetID((char*)"Shell");
		//set Colors
		Sauce::Global::Graphics::Screen->SetColor({0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00});
		Sauce::Global::Graphics::Terminal->SetColor({0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00});
		Sauce::Global::Graphics::Mouse->SetColor({0xFF,0xFF,0xFF,0xF0},{0x00,0x00,0x00,0x00});
		Sauce::Global::Graphics::Shell->SetColor({0x00,0xFF,0x00,0xF0},{0x00,0x00,0x00,0x00});
		//border sets
		Sauce::Global::Graphics::Screen->BorderSet({0xFF,0x00,0xFF,0x00});
		Sauce::Global::Graphics::Terminal->BorderSet({0xFF,0x00,0xFF,0x00});
		Sauce::Global::Graphics::Shell->BorderSet({0xFF,0x00,0xFF,0x00});
		//Add the appropriate items to the appropriate lists
		Sauce::Global::Graphics::Windows.AddLast((Sauce::Graphics::Window_cl*)Sauce::Global::Graphics::Shell);
		//Clear
		Sauce::Global::Graphics::Screen->Clear();
		Sauce::Global::Graphics::Terminal->Clear();
		Sauce::Global::Graphics::Shell->ShellClear(true);

	}
	void Kernel_cl::MainLoop(){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::MainLoop",_NAMESPACE_,_ALLOW_PRINT_);
		asm volatile("sti");
		while(true){
			Sauce::Global::Hardware::RTC.Update();
			DrawUI();
		}
	}
	void Kernel_cl::Prep_GlobalAllocator(){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_GlobalAllocator",_NAMESPACE_,_ALLOW_PRINT_);
		Sauce::Global::Memory::PageFrameAllocator = Sauce::Memory::Management::PageFrameAllocator_cl();
		mMapEntries = DFBL->mMapSize/DFBL->mDescriptorSize;
		Sauce::Global::Memory::PageFrameAllocator.ReadEfiMemoryMap((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,DFBL->mMapSize,DFBL->mDescriptorSize);
		kernelSize = ((uint64_t)&_KernelEndRef)-((uint64_t)&_KernelStartRef);
		kernelPages = (uint64_t)kernelSize/4096 +1;
		Sauce::Global::Memory::PageFrameAllocator.LockPages(&_KernelStartRef,kernelPages);
		PML4 = (Sauce::Memory::Management::PageTable*)Sauce::Global::Memory::PageFrameAllocator.RequestPage();
		Sauce::Memory::memset(PML4,0,0x1000);
		Sauce::Global::Memory::PageTableManager = Sauce::Memory::Management::PageTableManager_cl(PML4);
	}
	void Kernel_cl::Prep_VirtualAddresses(){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_VirtualAddresses",_NAMESPACE_,_ALLOW_PRINT_);
		for(uint64_t t=0;t<Sauce::Memory::GetMemorySize((Sauce::Memory::EFI_MEMORY_DESCRIPTOR*)DFBL->mMap,mMapEntries,DFBL->mDescriptorSize);t+=0x1000){
			Sauce::Global::Memory::PageTableManager.MapMemory((void*)t,(void*)t);
		}
		DFBL->fbBase = (uint64_t)DFBL->FrameBuffer->BaseAddress;
		DFBL->fbSize = (uint64_t)DFBL->FrameBuffer->BufferSize + 0x1000;
		Sauce::Global::Memory::PageFrameAllocator.LockPages((void*)DFBL->fbBase,DFBL->fbSize/0x1000 +1);
		for(uint64_t t=DFBL->fbBase;t<DFBL->fbBase+DFBL->fbSize;t+=0x1000){
			Sauce::Global::Memory::PageTableManager.MapMemory((void*)t,(void*)t);
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
		idtr.Offset= (uint64_t)Sauce::Global::Memory::PageFrameAllocator.RequestPage();
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
		Sauce::IO::PCI::EnumeratePCI(mcfg);
	}
	void Kernel_cl::Prep_Filesystem(){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Prep_Filesystem",_NAMESPACE_,_ALLOW_PRINT_);
		Sauce::Global::Filesystem::RootDirectory.AddDirectory("FictitiousDirectory1");
		Sauce::Global::Filesystem::RootDirectory.AddDirectory("FictitiousDirectory2");
		Sauce::Global::Filesystem::RootDirectory.AddFile("FictitiousFile1");
		Sauce::Global::Filesystem::RootDirectory.AddFile("FictitiousFile2");
	}
	void Kernel_cl::oNotify_Of_KeyPress(Sauce::Keyboard_st xKeyboard){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::oNotify_Of_KeyPress",_NAMESPACE_,true);
		if(!KeyboardAsMouseMode){
			switch(xKeyboard.Key){
				case 0xF8:/*KeyboardAsMouseMode Toggle, aka scroll lock*/{
					if(!xKeyboard.Press)return;
					KeyboardAsMouseMode=!KeyboardAsMouseMode;
					Sauce::Global::Graphics::Mouse->SetColor({0x00,0xFF,0xFF,0xF0},{0x00,0x00,0x00,0x00});
					Sauce::Global::Graphics::Mouse->ReDraw();
				}break;
				case 0xD6:{
					if(!xKeyboard.Press)return;
					/*Sauce::Global::Graphics::Shell*/Sauce::Global::Graphics::Windows[0]->PutChar('\n',true);
					/*Sauce::Global::Graphics::Shell*/Sauce::Global::Graphics::Windows[0]->PutChar('\r',true);
				}break;
				case 0x1C:{
					if(!xKeyboard.Press)return;
					/*Sauce::Global::Graphics::Shell*/Sauce::Global::Graphics::Windows[0]->PutChar('\b',true);
				}break;
				case 0x7E:/*ctrl*/{
					if(xKeyboard.Press){KeyboardCtrl=true;}else{KeyboardCtrl=false;}
				}break;
				case 0x7A:/*alt*/{
					if(xKeyboard.Press){KeyboardAlt=true;}else{KeyboardAlt=false;}
				}break;
				case 0xCE:/*del*/{
					if(xKeyboard.Press){KeyboardDel=true;}else{KeyboardDel=false;}
				}break;
				case 0xC4:/*ins*/{
					if(xKeyboard.Press){KeyboardIns=true;}else{KeyboardIns=false;}
				}break;
				case 0xB8:/*end*/{
					if(xKeyboard.Press){KeyboardEnd=true;}else{KeyboardEnd=false;}
				}break;
				case 0xB4:/*home*/{
					if(xKeyboard.Press){KeyboardHome=true;}else{KeyboardHome=false;}
				}break;
				case 0xCC:/*page down*/{
					if(xKeyboard.Press){KeyboardPageDown=true;}else{KeyboardPageDown=false;}
				}break;
				case 0xC8:/*page up*/{
					if(xKeyboard.Press){KeyboardPageUp=true;}else{KeyboardPageUp=false;}
				}break;
				case 0xB2:/*pause/break, also triggers 0x7E?*/{
					if(xKeyboard.Press){KeyboardBreak=true;}else{KeyboardBreak=false;}
				}
				default:{
					if(!xKeyboard.Press)return;
					if(xKeyboard.visible){
						/*Sauce::Global::Graphics::Shell*/Sauce::Global::Graphics::Windows[0]->PutChar(xKeyboard.Display,true);
					}else{
					   Debugger.Print(Sauce::Utility::Conversion::HexToString(xKeyboard.Key));
					}
				}break;
			}
			
		}else{
			switch(xKeyboard.Key){
				case 0xF8:/*KeyboardAsMouseMode Toggle, aka scroll lock*/{
					if(!xKeyboard.Press)return;
					KeyboardAsMouseMode=!KeyboardAsMouseMode;
					Sauce::Global::Graphics::Mouse->SetColor({0xFF,0xFF,0xFF,0xF0},{0x00,0x00,0x00,0x00});
					Sauce::Global::Graphics::Mouse->ReDraw();
				}break;
				case 0xB6:/*left*/{
					if(!xKeyboard.Press)return;
					if(KeyboardCtrl && !KeyboardAlt && !KeyboardDel && !KeyboardIns && !KeyboardEnd && !KeyboardHome && !KeyboardPageDown && !KeyboardPageUp && !KeyboardPause && !KeyboardBreak){
						Sauce::Global::Graphics::Mouse->CycleDirectionCounterClockwise();
						Sauce::Global::Graphics::Mouse->ReDraw();
						return;
					}
					if(xKeyboard.Capital){
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X-1,CurrentMouseCursorPosition.Y,CurrentMouseCursorPosition.Z};
					}else{
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X-10,CurrentMouseCursorPosition.Y,CurrentMouseCursorPosition.Z};
					}
					//BorderCheck
					if(CurrentMouseCursorPosition.Y < 0){CurrentMouseCursorPosition.Y=0;}
					if(CurrentMouseCursorPosition.X < 0){CurrentMouseCursorPosition.X=0;}
					if((CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;}
					if((CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;}
					//move
					Sauce::Global::Graphics::Mouse->Move(CurrentMouseCursorPosition);
					//faux click detection
					if(iMouse.CenterButton && iMouse.CenterButton != oMouse.CenterButton){
						//Press
						oMouse.CenterButton=iMouse.CenterButton;
						*oMouse.Position=*iMouse.Position;
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.CenterButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.CenterButton != oMouse.CenterButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
						oMouse.CenterButton=iMouse.CenterButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.RightButton && iMouse.RightButton != oMouse.RightButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.RightButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.RightButton != oMouse.RightButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.LeftButton && iMouse.LeftButton != oMouse.LeftButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.LeftButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.LeftButton != oMouse.LeftButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
				}break;
				case 0xCA:/*right*/{
					if(!xKeyboard.Press)return;
					if(KeyboardCtrl && !KeyboardAlt && !KeyboardDel && !KeyboardIns && !KeyboardEnd && !KeyboardHome && !KeyboardPageDown && !KeyboardPageUp && !KeyboardPause && !KeyboardBreak){
						Sauce::Global::Graphics::Mouse->CycleDirectionClockwise();
						Sauce::Global::Graphics::Mouse->ReDraw();
						return;
					}
					if(xKeyboard.Capital){
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X+1,CurrentMouseCursorPosition.Y,CurrentMouseCursorPosition.Z};
					}else{
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X+10,CurrentMouseCursorPosition.Y,CurrentMouseCursorPosition.Z};
					}
					//BorderCheck
					if(CurrentMouseCursorPosition.Y < 0){CurrentMouseCursorPosition.Y=0;}
					if(CurrentMouseCursorPosition.X < 0){CurrentMouseCursorPosition.X=0;}
					if((CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;}
					if((CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;}
					//move
					Sauce::Global::Graphics::Mouse->Move(CurrentMouseCursorPosition);
					//faux click detection
					if(iMouse.CenterButton && iMouse.CenterButton != oMouse.CenterButton){
						//Press
						oMouse.CenterButton=iMouse.CenterButton;
						*oMouse.Position=*iMouse.Position;
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.CenterButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.CenterButton != oMouse.CenterButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
						oMouse.CenterButton=iMouse.CenterButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.RightButton && iMouse.RightButton != oMouse.RightButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.RightButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.RightButton != oMouse.RightButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.LeftButton && iMouse.LeftButton != oMouse.LeftButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.LeftButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.LeftButton != oMouse.LeftButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
				}break;
				case 0xBE:/*up*/{
					if(!xKeyboard.Press)return;
					if(KeyboardCtrl && !KeyboardAlt && !KeyboardDel && !KeyboardIns && !KeyboardEnd && !KeyboardHome && !KeyboardPageDown && !KeyboardPageUp && !KeyboardPause && !KeyboardBreak){
						Sauce::Global::Graphics::Mouse->DirectionalSensitivity++;
						return;
					}
					if(xKeyboard.Capital){
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X,CurrentMouseCursorPosition.Y-1,CurrentMouseCursorPosition.Z};
					}else{
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X,CurrentMouseCursorPosition.Y-10,CurrentMouseCursorPosition.Z};
					}
					//BorderCheck
					if(CurrentMouseCursorPosition.Y < 0){CurrentMouseCursorPosition.Y=0;}
					if(CurrentMouseCursorPosition.X < 0){CurrentMouseCursorPosition.X=0;}
					if((CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;}
					if((CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;}
					//move
					Sauce::Global::Graphics::Mouse->Move(CurrentMouseCursorPosition);
					//faux click detection
					if(iMouse.CenterButton && iMouse.CenterButton != oMouse.CenterButton){
						//Press
						oMouse.CenterButton=iMouse.CenterButton;
						*oMouse.Position=*iMouse.Position;
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.CenterButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.CenterButton != oMouse.CenterButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
						oMouse.CenterButton=iMouse.CenterButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.RightButton && iMouse.RightButton != oMouse.RightButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.RightButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.RightButton != oMouse.RightButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.LeftButton && iMouse.LeftButton != oMouse.LeftButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.LeftButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.LeftButton != oMouse.LeftButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
				}break;
				case 0xC2:/*down*/{
					if(!xKeyboard.Press)return;
					if(KeyboardCtrl && !KeyboardAlt && !KeyboardDel && !KeyboardIns && !KeyboardEnd && !KeyboardHome && !KeyboardPageDown && !KeyboardPageUp && !KeyboardPause && !KeyboardBreak){
						Sauce::Global::Graphics::Mouse->DirectionalSensitivity=Sauce::Global::Graphics::Mouse->DirectionalSensitivity>0?Sauce::Global::Graphics::Mouse->DirectionalSensitivity-1:0;
						return;
					}
					if(xKeyboard.Capital){
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X,CurrentMouseCursorPosition.Y+1,CurrentMouseCursorPosition.Z};
					}else{
						CurrentMouseCursorPosition = Sauce::Point64_st{CurrentMouseCursorPosition.X,CurrentMouseCursorPosition.Y+10,CurrentMouseCursorPosition.Z};
					}
					//BorderCheck
					if(CurrentMouseCursorPosition.Y < 0){CurrentMouseCursorPosition.Y=0;}
					if(CurrentMouseCursorPosition.X < 0){CurrentMouseCursorPosition.X=0;}
					if((CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;}
					if((CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;}
					//move
					Sauce::Global::Graphics::Mouse->Move(CurrentMouseCursorPosition);
					//faux click detection
					if(iMouse.CenterButton && iMouse.CenterButton != oMouse.CenterButton){
						//Press
						oMouse.CenterButton=iMouse.CenterButton;
						*oMouse.Position=*iMouse.Position;
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.CenterButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.CenterButton != oMouse.CenterButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
						oMouse.CenterButton=iMouse.CenterButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.RightButton && iMouse.RightButton != oMouse.RightButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.RightButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.RightButton != oMouse.RightButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
						oMouse.RightButton=iMouse.RightButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
					if(iMouse.LeftButton && iMouse.LeftButton != oMouse.LeftButton){
						//Press
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						*oMouse.Position=*iMouse.Position;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Down(Sauce::Global::Graphics::Mouse->Focus());
						}
					}else if(iMouse.LeftButton){
						//Drag
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(CurrentMouseCursorPosition,*oMouse.Position);
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
						}
					}else if(iMouse.LeftButton != oMouse.LeftButton){
						//Release
						Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
						oMouse.LeftButton=iMouse.LeftButton;
						for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
							Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Up(Sauce::Global::Graphics::Mouse->Focus());
						}
					}
				}break;
				case 0x20:/*left click*/{
					if(xKeyboard.Press){iMouse.LeftButton=true;}else{iMouse.LeftButton=false;}
				}break;
				case 0x22:/*middle click*/{
					if(xKeyboard.Press){iMouse.CenterButton=true;}else{iMouse.CenterButton=false;}
				}break;
				case 0x24:/*right click*/{
					if(xKeyboard.Press){iMouse.RightButton=true;}else{iMouse.RightButton=false;}
				}break;
				case 0x7E:/*ctrl*/{
					if(xKeyboard.Press){KeyboardCtrl=true;}else{KeyboardCtrl=false;}
				}break;
				case 0x7A:/*alt*/{
					if(xKeyboard.Press){KeyboardAlt=true;}else{KeyboardAlt=false;}
				}break;
				case 0xCE:/*del*/{
					if(xKeyboard.Press){KeyboardDel=true;}else{KeyboardDel=false;}
				}break;
				case 0xC4:/*ins*/{
					if(xKeyboard.Press){KeyboardIns=true;}else{KeyboardIns=false;}
				}break;
				case 0xB8:/*end*/{
					if(xKeyboard.Press){KeyboardEnd=true;}else{KeyboardEnd=false;}
				}break;
				case 0xB4:/*home*/{
					if(xKeyboard.Press){KeyboardHome=true;}else{KeyboardHome=false;}
				}break;
				case 0xCC:/*page down*/{
					if(xKeyboard.Press){KeyboardPageDown=true;}else{KeyboardPageDown=false;}
				}break;
				case 0xC8:/*page up*/{
					if(xKeyboard.Press){KeyboardPageUp=true;}else{KeyboardPageUp=false;}
				}break;
				case 0xB2:/*pause/break, also triggers 0x7E?*/{
					if(xKeyboard.Press){KeyboardBreak=true;}else{KeyboardBreak=false;}
				}
				default:{
					if(!xKeyboard.Press)return;
					Debugger.Print(Sauce::Utility::Conversion::HexToString(xKeyboard.Key));
				}break;
			}
		}
	}
	void Kernel_cl::oNotify_Of_Mouse(Sauce::Mouse_st* xMouse){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::oNotify_Of_Mouse",_NAMESPACE_,_ALLOW_PRINT_);
		if(KeyboardAsMouseMode)return;//if we are in keyboard as mouse mode ignore the real mouse.
		if(CurrentMouseCursorPosition.X != xMouse->Position->X || CurrentMouseCursorPosition.Y != xMouse->Position->Y){
			CurrentMouseCursorPosition = Sauce::Point64_st{xMouse->Position->X,xMouse->Position->Y,xMouse->Position->Z};
			//BorderCheck
			if(CurrentMouseCursorPosition.Y < 0){CurrentMouseCursorPosition.Y=0;}
			if(CurrentMouseCursorPosition.X < 0){CurrentMouseCursorPosition.X=0;}
			if((CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;}
			if((CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;}
			//move
			Sauce::Global::Graphics::Mouse->Move(CurrentMouseCursorPosition);
		}
		static int safety=8;//discards the first 8 events, they are likely noise.
		if(safety){
			safety--;
			return;
		}
		if(xMouse->CenterButton && xMouse->CenterButton != oMouse.CenterButton){
			//Press
			oMouse.CenterButton=xMouse->CenterButton;
			*oMouse.Position=*xMouse->Position;
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(CurrentMouseCursorPosition);
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Down(Sauce::Global::Graphics::Mouse->Focus());
			}
		}else if(xMouse->CenterButton){
			//Drag
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(CurrentMouseCursorPosition,*oMouse.Position);
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
			}
		}else if(xMouse->CenterButton != oMouse.CenterButton){
			//Release
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(CurrentMouseCursorPosition);
			oMouse.CenterButton=xMouse->CenterButton;
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Center_Up(Sauce::Global::Graphics::Mouse->Focus());
			}
		}
		if(xMouse->RightButton && xMouse->RightButton != oMouse.RightButton){
			//Press
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(CurrentMouseCursorPosition);
			oMouse.RightButton=xMouse->RightButton;
			*oMouse.Position=*xMouse->Position;
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Down(Sauce::Global::Graphics::Mouse->Focus());
			}
		}else if(xMouse->RightButton){
			//Drag
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(CurrentMouseCursorPosition,*oMouse.Position);
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
			}
		}else if(xMouse->RightButton != oMouse.RightButton){
			//Release
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(CurrentMouseCursorPosition);
			oMouse.RightButton=xMouse->RightButton;
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Right_Up(Sauce::Global::Graphics::Mouse->Focus());
			}
		}
		if(xMouse->LeftButton && xMouse->LeftButton != oMouse.LeftButton){
			//Press
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(CurrentMouseCursorPosition);
			oMouse.LeftButton=xMouse->LeftButton;
			*oMouse.Position=*xMouse->Position;
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Down(Sauce::Global::Graphics::Mouse->Focus());
			}
		}else if(xMouse->LeftButton){
			//Drag
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(CurrentMouseCursorPosition,*oMouse.Position);
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Drag(Sauce::Global::Graphics::Mouse->Focus(),*oMouse.Position);
			}
		}else if(xMouse->LeftButton != oMouse.LeftButton){
			//Release
			Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(CurrentMouseCursorPosition);
			oMouse.LeftButton=xMouse->LeftButton;
			for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
				Sauce::Global::Graphics::Windows[i]->Notify_Of_Mouse_Left_Up(Sauce::Global::Graphics::Mouse->Focus());
			}
		}
	}
	void Kernel_cl::InterruptsOff(){
		asm volatile("cli");
	}
	void Kernel_cl::InterruptsOn(){
		asm volatile("sti");
	}
	void Kernel_cl::DrawUI(){
		InterruptsOff();
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::DrawUI",_NAMESPACE_,_ALLOW_PRINT_);
		for(size_t i=0;i<Sauce::Global::Graphics::Windows.Size();i++){
			Sauce::Global::Graphics::Terminal->CopyFrom(Sauce::Global::Graphics::Windows[i]);
		}
		Sauce::Global::Graphics::Terminal->DrawFrom(Sauce::Global::Graphics::Mouse);
		Sauce::Global::Graphics::Screen->CopyFrom(Sauce::Global::Graphics::Terminal);
		InterruptsOn();
	}
	void Kernel_cl::Notify(Sauce::Interrupts::InterruptDataStruct InterruptData){
		Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kernel_cl::Notify",_NAMESPACE_,_ALLOW_PRINT_);
		Sauce::Global::Kernel->InterruptsOff();
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
				Debugger.Print(std::to_string(Sauce::Interrupts::PIT::GetTimeSinceBoot()));
			}break;
			case Sauce::Interrupts::InterruptTypeCode::ITC__DoubleFault:{
				Debugger.Print(std::string("ip:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ip));
				Debugger.Print(std::string("cs:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.cs));
				Debugger.Print(std::string("flags:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.flags));
				Debugger.Print(std::string("sp:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.sp));
				Debugger.Print(std::string("ss:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ss));
				Sauce::IO::Panic("Double Fault Detected!");
			}break;
			case Sauce::Interrupts::InterruptTypeCode::ITC__GeneralProtectionFault:{
				Debugger.Print(std::string("ip:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ip));
				Debugger.Print(std::string("cs:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.cs));
				Debugger.Print(std::string("flags:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.flags));
				Debugger.Print(std::string("sp:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.sp));
				Debugger.Print(std::string("ss:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ss));
				Sauce::IO::Panic("General Protection Fault Detected!");
			}break;
			case Sauce::Interrupts::InterruptTypeCode::ITC__PageFault:{
				Debugger.Print(std::string("ip:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ip));
				Debugger.Print(std::string("cs:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.cs));
				Debugger.Print(std::string("flags:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.flags));
				Debugger.Print(std::string("sp:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.sp));
				Debugger.Print(std::string("ss:")+Sauce::Utility::Conversion::HexToString(InterruptData.Frame.ss));
				Sauce::IO::Panic("Page Fault Detected!");
			}break;
		}
		Sauce::Global::Kernel->InterruptsOn();
	}
};
