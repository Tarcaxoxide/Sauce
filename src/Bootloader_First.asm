bits 16
[org 0x7c00]
mov bp, $
mov sp,bp

mov [BOOT_DISK], dl

call ReadDisk

jmp PROGRAM_SPACE


jmp $

%include "PrintString.inc"
%include "PrintHex.inc"
%include "ReadDisk.inc"

times 510-($-$$) db 0
dw 0xAA55