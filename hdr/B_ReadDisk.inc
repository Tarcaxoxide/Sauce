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
