
global start

section .text
bits 32
start:
    ; print 'OK'
    mov dword[0xB8000], 0x2f4b2f4f
    jmp _Stop
_Stop:
    hlt
    jmp _Stop