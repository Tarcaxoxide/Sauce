bits 16
[org 0x7c00]
mov bp, $
mov sp,bp

mov [BOOT_DISK], dl

mov bx, String_Bootloader_First_Init
call PrintString

call ReadDisk

jmp PROGRAM_SPACE


jmp $

%include "PrintString.inc"
%include "PrintHex.inc"
%include "ReadDisk.inc"


String_Bootloader_First_Init:db "Hello From Bootloader(First Sector).",0


times 510-($-$$) db 0
dw 0xAA55