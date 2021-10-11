%ifndef INC_ReadDisk
%define INC_ReadDisk
    ;PROGRAM_SPACE equ 0x7e00
    PROGRAM_SPACE equ (0x7c00+(512*2));
    BOOT_DISK: db 0
    ReadDisk:
        mov ah, 0x02
        mov bx, PROGRAM_SPACE
        mov al, 115
        mov dl, [BOOT_DISK]
        mov ch, 0x00
        mov dh, 0x00
        mov cl, 0x02
        int 0x13
        jc DiskError
        ret
    DiskError:
        mov dx, [BOOT_DISK]
        call PrintHex
        mov bx,String_DiskError
        call PrintString
        jmp $

    String_DiskError:db " :: Failed to read disk.",0
%endif
