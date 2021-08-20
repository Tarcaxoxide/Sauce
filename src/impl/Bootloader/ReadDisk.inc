PROGRAM_SPACE equ 0x7e00

ReadDisk:
    mov ah, 0x02
    mov bx, PROGRAM_SPACE
    mov al, 44
    mov dl, [BOOT_DISK]
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13
    jc DiskReadError
    ret


DiskReadError:
    mov bx, String_DiskReadError
    call PrintString
    .HLT:
        hlt
        jmp short .HLT

BOOT_DISK: db 0

String_DiskReadError:db "Failed to read disk!",0