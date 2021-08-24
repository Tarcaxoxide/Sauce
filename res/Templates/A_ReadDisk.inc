%ifndef INC_ReadDisk
%define INC_ReadDisk
    ;PROGRAM_SPACE equ 0x7e00
    PROGRAM_SPACE equ (0x7c00+(512*2));
    BOOT_DISK: db 0
    ReadDisk:
        mov ah, 0x02
        mov bx, PROGRAM_SPACE
