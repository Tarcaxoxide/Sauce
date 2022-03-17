#include <efi.h>
#include <efilib.h>

EFI_HANDLE _ImageHandle=NULL;
EFI_SYSTEM_TABLE *_SystemTable=NULL;

EFI_FILE* LoadFile(EFI_FILE* Directory,CHAR16* Path){
	Print(L"Loading ");
	Print(Path);
	Print(L": ");
	EFI_FILE* LoadedFile;
	EFI_LOADED_IMAGE_PROTOCOL* LoadedImage;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_STATUS s;
	{
		_SystemTable->BootServices->HandleProtocol(_ImageHandle,&gEfiLoadedImageProtocolGuid,(void**)&LoadedImage);
		_SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle,&gEfiSimpleFileSystemProtocolGuid,(void**)&FileSystem);
		if(Directory == NULL){
			FileSystem->OpenVolume(FileSystem,&Directory);
		}
		s = Directory->Open(Directory,&LoadedFile,Path,EFI_FILE_MODE_READ,EFI_FILE_READ_ONLY);
		if(s != EFI_SUCCESS){
			Print(L"[Failure]\n\r");
			return NULL;
		}
	}
	Print(L"[Success]\n\r");
	return LoadedFile;
}

EFI_STATUS efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	_ImageHandle=ImageHandle;
	_SystemTable=SystemTable;
	InitializeLib(_ImageHandle,_SystemTable);

	Print(L"Blah Blah Blah!\n\r");

	EFI_FILE* Kernel = LoadFile(NULL,L"kernel.elf");

	if(Kernel == NULL){
		//fail
	}

	return EFI_SUCCESS; // Exit the UEFI application
}
