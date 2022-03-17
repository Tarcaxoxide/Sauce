#include <efi.h>
#include <efilib.h>
#include <elf.h>
#include <Sauce/Common.h>

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


int memcmp(const void* aptr,const void* bptr,size_t n){
	const unsigned char *a=aptr, *b=bptr;
	for(size_t i=0;i<n;i++){
		if(a[i] < b[i])return -1;
		else if (a[i] > b[i])return 1;
	}
	return 0;
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
			}
	}

	return EFI_SUCCESS; // Exit the UEFI application
}
