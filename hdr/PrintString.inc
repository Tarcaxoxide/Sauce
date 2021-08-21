%ifndef INC_PrintString
%define INC_PrintString
    PrintString:
        pusha
        mov ah, 0x0e
        .Loop:
            cmp [bx], byte 0
            je short .Done
            mov al, byte [bx]
            int 0x10
            inc bx
            jmp short .Loop
        .Done:
            popa
            ret
%endif