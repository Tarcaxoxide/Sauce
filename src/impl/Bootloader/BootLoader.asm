[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp,bp

call ReadDisk

mov al,[PROGRAM_SPACE]
mov ah, 0x0e
int 0x10

jmp [PROGRAM_SPACE+1]

jmp $

%include "ReadDisk.inc"
%include "PrintString.inc"

String_Test: db "Hello Bootloader!",0


times 510-($-$$) db 0
dw 0xAA55