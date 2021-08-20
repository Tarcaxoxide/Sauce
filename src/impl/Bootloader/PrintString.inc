
PrintString:
    mov ah, 0x0e
    .Loop:
        cmp [bx], byte 0
        je .Done
        mov al, [bx]
        int 0x10
        inc bx
        jmp .Loop
    .Done:
        ret
