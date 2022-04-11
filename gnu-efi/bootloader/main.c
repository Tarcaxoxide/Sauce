#define Compiling_PureC
#include<efi.h>
#include<efilib.h>
#include<elf.h>
#include<Sauce/Common.h>

EFI_HANDLE _ImageHandle;
EFI_SYSTEM_TABLE *_SystemTable;

EFI_FILE* LoadFile(EFI_FILE* Directory,CHAR16* Path){
	Print(L"Loading ");
	Print(Path);
	Print(L": ");
	EFI_FILE* LoadedFile;
	EFI_LOADED_IMAGE_PROTOCOL* LoadedImage;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	{
		_SystemTable->BootServices->HandleProtocol(_ImageHandle,&gEfiLoadedImageProtocolGuid,(void**)&LoadedImage);
		_SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle,&gEfiSimpleFileSystemProtocolGuid,(void**)&FileSystem);
		if(Directory == NULL){
			FileSystem->OpenVolume(FileSystem,&Directory);
		}
		EFI_STATUS S = Directory->Open(Directory,&LoadedFile,Path,EFI_FILE_MODE_READ,EFI_FILE_READ_ONLY);
		if(S != EFI_SUCCESS){
			Print(L"[Failure]\n\r");
			return NULL;
		}
	}
	Print(L"[Success]\n\r");
	return LoadedFile;
}
FrameBufferStructure FrameBuffer;
FrameBufferStructure* InitializeGOP(){
	EFI_GUID gopGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
	EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
	EFI_STATUS status;

	Print(L"Locate GOP: ");
	status = uefi_call_wrapper(BS->LocateProtocol,3,&gopGuid,NULL,(void**)&gop);
	if(EFI_ERROR(status)){
		Print(L"Failed\n\r");
		return NULL;
	}else{
		Print(L"Located\n\r");
	}
	FrameBuffer.BaseAddress= (void*)gop->Mode->FrameBufferBase;
	FrameBuffer.BufferSize = gop->Mode->FrameBufferSize;
	FrameBuffer.Width = gop->Mode->Info->HorizontalResolution;
	FrameBuffer.Height = gop->Mode->Info->VerticalResolution;
	FrameBuffer.PixelsPerScanLine = gop->Mode->Info->PixelsPerScanLine;
	FrameBuffer.BytesPerPixel=4; //TODO:: Figure this out programmatically;
	return &FrameBuffer;
}
PSF1_FONT* Load_PSF1_FONT(EFI_FILE* Directory,CHAR16* Path){
	EFI_FILE* font = LoadFile(Directory,Path);
	if(font == NULL)return NULL;
	PSF1_HEADER* fontHeader;
	_SystemTable->BootServices->AllocatePool(EfiLoaderData,sizeof(PSF1_HEADER),(void**)&fontHeader);
	UINTN size = sizeof(PSF1_HEADER);
	font->Read(font,&size,fontHeader);
	if(fontHeader->magic[0] != PSF1_MAGIC0 || fontHeader->magic[1] != PSF1_MAGIC1)return NULL;

	UINTN glyphBufferSize = fontHeader->char_size * 256;
	if(fontHeader->mode == 1){
		glyphBufferSize = fontHeader->char_size * 512;
	}
	void* glyphBuffer;
	{
		font->SetPosition(font,sizeof(PSF1_HEADER));
		_SystemTable->BootServices->AllocatePool(EfiLoaderData,glyphBufferSize,(void**)&glyphBuffer);
		font->Read(font,&glyphBufferSize,glyphBuffer);
	}
	PSF1_FONT* finishedFont;
	_SystemTable->BootServices->AllocatePool(EfiLoaderData,sizeof(PSF1_FONT),(void**)&finishedFont);
	finishedFont->psf1_header=fontHeader;
	finishedFont->glyphBuffer = glyphBuffer;
	finishedFont->psf1_header->char_width=8; //TODO:: Figure this out programmatically;
	finishedFont->psf1_header->char_height=16; //TODO:: Figure this out programmatically;
	return finishedFont;
}

int memcmp(const void* aptr,const void* bptr,size_t n){
	const unsigned char *a=aptr, *b=bptr;
	for(size_t i=0;i<n;i++){
		if(a[i] < b[i])return -1;
		else if (a[i] > b[i])return 1;
	}
	return 0;
}

UINTN strncmp(CHAR8* a,CHAR8* b,UINTN length){
	for(UINTN I=0;I<length;I++){
		if(*(a+I) != *(b+I))return 0;
		//if(*a != *b)return 0;
	}
	return 1;
}

EFI_STATUS efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	_ImageHandle=ImageHandle;
	_SystemTable=SystemTable;
	InitializeLib(_ImageHandle,_SystemTable);

	EFI_FILE* Kernel = LoadFile(NULL,L"kernel.elf");
	if(Kernel != NULL){
		Elf64_Ehdr Kernel_header;
		UINTN FileInfoSize;
		EFI_FILE_INFO* FileInfo;
		Kernel->GetInfo(Kernel,&gEfiFileInfoGuid,&FileInfoSize,NULL);
		_SystemTable->BootServices->AllocatePool(EfiLoaderData,FileInfoSize,(void**)&FileInfo);
		Kernel->GetInfo(Kernel,&gEfiFileInfoGuid,&FileInfoSize,(void**)&FileInfo);

		UINTN size = sizeof(Kernel_header);
		Print(L"Kernel header format: ");

		Kernel->Read(Kernel,&size,&Kernel_header);
		if(	memcmp(&Kernel_header.e_ident[EI_MAG0],ELFMAG,SELFMAG) != 0){
			Print(L"Invalid Magic %d\r\n",memcmp(&Kernel_header.e_ident[EI_MAG0],ELFMAG,SELFMAG));
		}
		else if(Kernel_header.e_ident[EI_CLASS] != ELFCLASS64){
			Print(L"Invalid Class\r\n");
		}
		else if(Kernel_header.e_ident[EI_DATA] != ELFDATA2LSB){
			Print(L"Invalid Data\r\n");
		}
		else if(Kernel_header.e_type != ET_EXEC){
			Print(L"Invalid Type\r\n");
		}
		else if(Kernel_header.e_machine != EM_X86_64){
			Print(L"Invalid Machine\r\n");
		}
		else if(Kernel_header.e_version != EV_CURRENT){
			Print(L"Invalid Version\r\n");
		}
		else {
				Print(L"Valid\r\n");
				Print(L"Kernel Setup: ");
				Elf64_Phdr* phdrs;
				Kernel->SetPosition(Kernel,Kernel_header.e_phoff);
				UINTN size = Kernel_header.e_phnum * Kernel_header.e_phentsize;
				_SystemTable->BootServices->AllocatePool(EfiLoaderData,size,(void**)&phdrs);
				Kernel->Read(Kernel,&size,phdrs);
				int64_t cccc=0;
				Print(L"S%d\n\r",cccc++);
				for(
					Elf64_Phdr* phdr = phdrs;
					(char*)phdr < (char*)phdrs+Kernel_header.e_phnum*Kernel_header.e_phentsize;
					phdr= (Elf64_Phdr*)((char*)phdr+Kernel_header.e_phentsize)
				){
					Print(L"S%d\n\r",cccc++);
					switch(phdr->p_type){
						case PT_LOAD:{
							int pages = (phdr->p_memsz + 0x1000 - 1) / 0x1000;
							Elf64_Addr segment = phdr->p_paddr;
							_SystemTable->BootServices->AllocatePages(AllocateAddress,EfiLoaderData,pages,&segment);
							Kernel->SetPosition(Kernel,phdr->p_offset);
							UINTN size = phdr->p_filesz;
							Kernel->Read(Kernel,&size,(void*)segment);
						}break;
					}
					Print(L"phdr->p_type == %x\n\r",phdr->p_type);
					Print(L"target p_type == %x\n\r",PT_LOAD);
				}
				Print(L" Done\n\r");
				//__asm__ volatile("cli");
				//__asm__ volatile("hlt");
				DataStructure nDFBL;
				int64_t (*KernelStart)(DataStructure* DFBL) = ((__attribute__((sysv_abi)) int64_t (*)(DataStructure* DFBL) ) Kernel_header.e_entry);
				nDFBL.TestNumber=0x0123456789ABCDEF;
				nDFBL.FrameBuffer=InitializeGOP();
				nDFBL.Font=Load_PSF1_FONT(NULL,L"zap-light16.psf");
				if(nDFBL.Font == NULL){
					Print(L"Font is not valid or found!\n\r");
				}else{
					Print(L"\n\r\
						Base: 0x%x\n\r\
						Size: 0x%x\n\r\
						Width: %d\n\r\
						Height: %d\n\r\
						Font Char Size: %d\n\r\
						\n\r",
						nDFBL.FrameBuffer->BaseAddress,
						nDFBL.FrameBuffer->BufferSize,
						nDFBL.FrameBuffer->Width,
						nDFBL.FrameBuffer->Height,
						nDFBL.FrameBuffer->PixelsPerScanLine,
						nDFBL.Font->psf1_header->char_size);
					
					EFI_MEMORY_DESCRIPTOR* Map = NULL;
					UINTN MapSize,MapKey;
					UINTN DescriptorSize;
					UINT32 DescriptorVersion;
					{
						_SystemTable->BootServices->GetMemoryMap(&MapSize,Map,&MapKey,&DescriptorSize,&DescriptorVersion);
						_SystemTable->BootServices->AllocatePool(EfiLoaderData,MapSize,(void**)&Map);
						_SystemTable->BootServices->GetMemoryMap(&MapSize,Map,&MapKey,&DescriptorSize,&DescriptorVersion);

					}
					EFI_CONFIGURATION_TABLE* configTable = _SystemTable->ConfigurationTable;
					void* rsdp =NULL;
					EFI_GUID Acpi2TableGuid = ACPI_20_TABLE_GUID;
					for(UINTN index = 0;index < _SystemTable->NumberOfTableEntries;index++){
						if(CompareGuid(&configTable[index].VendorGuid,&Acpi2TableGuid)){
							if(strncmp((CHAR8*)"RSD PTR ",(CHAR8*)configTable->VendorTable,8)){
								rsdp = (void*)configTable->VendorTable;
								//break;
							}
						}
						configTable++;
					}
					nDFBL.rsdp = rsdp;
					nDFBL.mMap=Map;
					nDFBL.mMapSize = MapSize;
					nDFBL.mDescriptorSize=DescriptorSize;
					Print(L"Starting Kernel now!\n\r");
					_SystemTable->BootServices->ExitBootServices(_ImageHandle,MapKey);
					int64_t return_code=KernelStart(&nDFBL);
					Print(L"Kernel Exit:0x%x\n\r    OK code:0x12345678\n\r",return_code);
					}
		}
	}

	return EFI_SUCCESS; // Exit the UEFI application
}
