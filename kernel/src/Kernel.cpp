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
#include<Sauce/Graphics/Shell/Shell.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Mouse.hpp>
#include<Sauce/IO/Keyboard.hpp>
#include<std/to_string.hpp>
#include<Sauce/Filesystem/FAT32.hpp>

extern "C" int64_t _start(DataStructure* DFBL);

namespace Sauce{
	//Input Statics
	namespace Input_Data{
		enum KeyboardMode_en{
			KeyboardMode_Default=0,
			KeyboardMode_AsMouse
		};
		Sauce::Point64_st CurrentMouseCursorPosition{0,0,0};
		Sauce::Mouse_st oMouse;
		Sauce::Point64_st oMousePosition;
		Sauce::Mouse_st iMouse;
		Sauce::Point64_st iMousePosition;
		Sauce::Memory::List_cl<Sauce::Keyboard_st> KeyboardBuffer;
		KeyboardMode_en KeyboardMode;
	};
	namespace Core{
		Kernel_cl::Kernel_cl(DataStructure* DFBL){
			asm volatile("cli");
			this->DFBL=DFBL;
			Sauce::Global::Kernel=this;
			Prep_GlobalAllocator();
			Prep_VirtualAddresses();
			Prep_GDT();
			//Sauce::Memory::InitalizeHeap((void*)0x0000100000000000,0x512);
			Sauce::Memory::InitalizeHeap((void*)Sauce::Math::gb_to_b(1),1);
			Sauce::Interrupts::PIT::SetDivisor(65535/6);
			Prep_Interrupts();
			asm volatile("sti");
			Prep_IO();
			asm volatile("cli");
			Prep_Windows();
			Sauce::IO::outb(PIC1_DATA,0b11111000);
			Sauce::IO::outb(PIC2_DATA,0b11101111);
			Sauce::Math::random_seed(8649245912657);
			// these are for the click detection
			Sauce::Input_Data::oMouse.Position=&Sauce::Input_Data::oMousePosition;
			Sauce::Input_Data::iMouse.Position=&Sauce::Input_Data::iMousePosition;
			Sauce::Input_Data::oMouse.CenterButton=false;
			Sauce::Input_Data::oMouse.RightButton=false;
			Sauce::Input_Data::oMouse.LeftButton=false;
			Sauce::Input_Data::iMouse.CenterButton=false;
			Sauce::Input_Data::iMouse.RightButton=false;
			Sauce::Input_Data::iMouse.LeftButton=false;
			Prep_ACPI();
			Prep_Filesystem();
			MainLoop();
		}
		void Kernel_cl::Prep_Windows(){
			//Construct
			Sauce::Global::Graphics::Screen=new Sauce::Graphics::Basic::Frame_st((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine,DFBL->FrameBuffer->BaseAddress);
			Sauce::Global::Graphics::ScreenBuffer=new Sauce::Graphics::Basic::Frame_st((size_t)(DFBL->FrameBuffer->Height*DFBL->FrameBuffer->Width),(size_t)DFBL->FrameBuffer->PixelsPerScanLine);
			Sauce::Global::Graphics::Mouse=new Sauce::Graphics::Mouse_cl({DFBL->FrameBuffer->PixelsPerScanLine/2,DFBL->FrameBuffer->Height/2,0});
			Sauce::Global::Graphics::Shell=new Sauce::Graphics::Shell::Shell_cl({DFBL->FrameBuffer->PixelsPerScanLine,DFBL->FrameBuffer->Height,0});
			//set Colors
			Sauce::Global::Graphics::Mouse->SetColor({0xFF,0xFF,0xFF,0xF0},{0x00,0x00,0x00,0x00});
			Sauce::Global::Graphics::Shell->SetColor({0x00,0xFF,0x00,0xF0},{0x00,0x00,0x00,0x00});
			//Clear
			Sauce::Global::Graphics::Shell->ShellClear(true);
		}
		void Kernel_cl::MainLoop(){
			asm volatile("sti");
			while(true){
				Sauce::Global::Hardware::RTC.Update();
				DrawUI();
			}
		}
		void Kernel_cl::Prep_GlobalAllocator(){
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
			idtr.Offset= (uint64_t)Sauce::Global::Memory::PageFrameAllocator.RequestPage();
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
		}
		void Kernel_cl::Prep_ACPI(){
			Sauce::IO::ACPI::SDTHeader* xsdt = (Sauce::IO::ACPI::SDTHeader*)DFBL->rsdp->XSDT_Address;
			Sauce::IO::ACPI::MCFGHeader* mcfg = (Sauce::IO::ACPI::MCFGHeader*)Sauce::IO::ACPI::FindTable(xsdt,(char*)"MCFG");
			Sauce::IO::PCI::EnumeratePCI(mcfg);
		}
		void Kernel_cl::Prep_Filesystem(){
			Sauce::Filesystem::FAT32::FAT32_cl PrimaryDrive_PrimaryPartition(0,0);
		}
		void Kernel_cl::oNotify_Of_KeyPress(Sauce::Keyboard_st xKeyboard){
			Sauce::Input_Data::KeyboardBuffer.AddLast(xKeyboard);
		}
		void Kernel_cl::oNotify_Of_Mouse(Sauce::Mouse_st* xMouse){
			if(Sauce::Input_Data::KeyboardMode != Sauce::Input_Data::KeyboardMode_en::KeyboardMode_Default)return;//if we are in keyboard as mouse mode ignore the real mouse.
			if(Sauce::Input_Data::CurrentMouseCursorPosition.X != xMouse->Position->X || Sauce::Input_Data::CurrentMouseCursorPosition.Y != xMouse->Position->Y){
				Sauce::Input_Data::CurrentMouseCursorPosition = Sauce::Point64_st{xMouse->Position->X,xMouse->Position->Y,xMouse->Position->Z};
				//BorderCheck
				if(Sauce::Input_Data::CurrentMouseCursorPosition.Y < 0){Sauce::Input_Data::CurrentMouseCursorPosition.Y=0;xMouse->Position->Y=Sauce::Input_Data::CurrentMouseCursorPosition.Y;}
				if(Sauce::Input_Data::CurrentMouseCursorPosition.X < 0){Sauce::Input_Data::CurrentMouseCursorPosition.X=0;xMouse->Position->X=Sauce::Input_Data::CurrentMouseCursorPosition.X;}
				if((Sauce::Input_Data::CurrentMouseCursorPosition.Y+Sauce::Global::Graphics::Mouse->Size().Y) > DFBL->FrameBuffer->Height-1){Sauce::Input_Data::CurrentMouseCursorPosition.Y=(DFBL->FrameBuffer->Height-Sauce::Global::Graphics::Mouse->Size().Y)-1;xMouse->Position->Y=Sauce::Input_Data::CurrentMouseCursorPosition.Y;}
				if((Sauce::Input_Data::CurrentMouseCursorPosition.X+Sauce::Global::Graphics::Mouse->Size().X) > DFBL->FrameBuffer->Width-1){Sauce::Input_Data::CurrentMouseCursorPosition.X=(DFBL->FrameBuffer->Width-Sauce::Global::Graphics::Mouse->Size().X)-1;xMouse->Position->X=Sauce::Input_Data::CurrentMouseCursorPosition.X;}
				//move
				Sauce::Global::Graphics::Mouse->Move(Sauce::Input_Data::CurrentMouseCursorPosition);
			}
			static int safety=8;//discards the first 8 events, they are likely noise.
			if(safety){
				safety--;
				return;
			}
			if(xMouse->CenterButton && xMouse->CenterButton != Sauce::Input_Data::oMouse.CenterButton){
				//Press
				Sauce::Input_Data::oMouse.CenterButton=xMouse->CenterButton;
				*Sauce::Input_Data::oMouse.Position=*xMouse->Position;
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Down(Sauce::Input_Data::CurrentMouseCursorPosition);
			}else if(xMouse->CenterButton){
				//Drag
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Drag(Sauce::Input_Data::CurrentMouseCursorPosition,*Sauce::Input_Data::oMouse.Position);
			}else if(xMouse->CenterButton != Sauce::Input_Data::oMouse.CenterButton){
				//Release
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Center_Up(Sauce::Input_Data::CurrentMouseCursorPosition);
				Sauce::Input_Data::oMouse.CenterButton=xMouse->CenterButton;
			}
			if(xMouse->RightButton && xMouse->RightButton != Sauce::Input_Data::oMouse.RightButton){
				//Press
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Down(Sauce::Input_Data::CurrentMouseCursorPosition);
				Sauce::Input_Data::oMouse.RightButton=xMouse->RightButton;
				*Sauce::Input_Data::oMouse.Position=*xMouse->Position;
			}else if(xMouse->RightButton){
				//Drag
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Drag(Sauce::Input_Data::CurrentMouseCursorPosition,*Sauce::Input_Data::oMouse.Position);
			}else if(xMouse->RightButton != Sauce::Input_Data::oMouse.RightButton){
				//Release
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Right_Up(Sauce::Input_Data::CurrentMouseCursorPosition);
				Sauce::Input_Data::oMouse.RightButton=xMouse->RightButton;
			}
			if(xMouse->LeftButton && xMouse->LeftButton != Sauce::Input_Data::oMouse.LeftButton){
				//Press
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Down(Sauce::Input_Data::CurrentMouseCursorPosition);
				Sauce::Input_Data::oMouse.LeftButton=xMouse->LeftButton;
				*Sauce::Input_Data::oMouse.Position=*xMouse->Position;
			}else if(xMouse->LeftButton){
				//Drag
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Drag(Sauce::Input_Data::CurrentMouseCursorPosition,*Sauce::Input_Data::oMouse.Position);
			}else if(xMouse->LeftButton != Sauce::Input_Data::oMouse.LeftButton){
				//Release
				Sauce::Global::Graphics::Mouse->Notify_Of_Mouse_Left_Up(Sauce::Input_Data::CurrentMouseCursorPosition);
				Sauce::Input_Data::oMouse.LeftButton=xMouse->LeftButton;
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
			Sauce::Global::Graphics::ScreenBuffer->Clear();
			Sauce::Global::Graphics::ScreenBuffer->DrawFrom(Sauce::Global::Graphics::Shell->Frame);
			Sauce::Global::Graphics::ScreenBuffer->DrawFrom(Sauce::Global::Graphics::Mouse->Frame);
			Sauce::Global::Graphics::Screen->CopyFrom(*Sauce::Global::Graphics::ScreenBuffer);
			InterruptsOn();
		}
		void* Kernel_cl::Notify(const Sauce::Interrupts::InterruptDataStruct& InterruptData){
			Sauce::Global::Kernel->InterruptsOff();
			switch(InterruptData.TypeCode){
				case Sauce::Interrupts::InterruptTypeCode::ITC__Mouse:{
					Sauce::IO::HandlePS2Mouse(InterruptData.RawInterruptData);
					Sauce::Global::Kernel->oNotify_Of_Mouse(Sauce::IO::ProcessMousePacket());
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Keyboard:{
					Sauce::Global::Kernel->oNotify_Of_KeyPress(Sauce::IO::Code_To_Key(Sauce::IO::Translate_KeyCode(InterruptData.RawInterruptData)));
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__NULL:{
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Time:{
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__DoubleFault:{
					Sauce::IO::Panic("Double Fault Detected!");
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__GeneralProtectionFault:{
					Sauce::IO::Panic("General Protection Fault Detected!");
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__PageFault:{
					Sauce::IO::Panic("Page Fault Detected!");
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_Memory_B:{
					if(InterruptData.ExtraData==0x00)return Sauce::Memory::malloc(InterruptData.RawInterruptData);
					return Sauce::Memory::malloc(InterruptData.RawInterruptData*InterruptData.ExtraData);
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_Memory_KB:{
					if(InterruptData.ExtraData==0x00)return Sauce::Memory::malloc(Sauce::Math::kb_to_b(InterruptData.RawInterruptData));
					return Sauce::Memory::malloc(Sauce::Math::kb_to_b(InterruptData.RawInterruptData)*InterruptData.ExtraData);
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_Memory_MB:{
					if(InterruptData.ExtraData==0x00)return Sauce::Memory::malloc(Sauce::Math::mb_to_b(InterruptData.RawInterruptData));
					return Sauce::Memory::malloc(Sauce::Math::mb_to_b(InterruptData.RawInterruptData)*InterruptData.ExtraData);
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_Memory_GB:{
					if(InterruptData.ExtraData==0x00)return Sauce::Memory::malloc(Sauce::Math::gb_to_b(InterruptData.RawInterruptData));
					return Sauce::Memory::malloc(Sauce::Math::gb_to_b(InterruptData.RawInterruptData)*InterruptData.ExtraData);
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_Memory_TB:{
					if(InterruptData.ExtraData==0x00)return Sauce::Memory::malloc(Sauce::Math::tb_to_b(InterruptData.RawInterruptData));
					return Sauce::Memory::malloc(Sauce::Math::tb_to_b(InterruptData.RawInterruptData)*InterruptData.ExtraData);
				}break;
				case Sauce::Interrupts::InterruptTypeCode::ITC__Request_KeyboardKey:{
					void* KeyPress = Sauce::Memory::malloc(sizeof(Sauce::Keyboard_st));
					*((Sauce::Keyboard_st*)KeyPress)=Sauce::Input_Data::KeyboardBuffer.First();
					Sauce::Input_Data::KeyboardBuffer.RemoveFirst();
					//Potential memory leak? (fix in std::cin? this just has to be generic here because this function does many things.)
					return KeyPress;
				};
			}
			Sauce::Global::Kernel->InterruptsOn();
			return nullptr;
		}
	};
};
