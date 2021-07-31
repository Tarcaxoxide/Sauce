global long_mode_start
section .text
bits 64

long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    ; print 'OK'
    mov dword[0xB8000], 0x2F4B2F4F