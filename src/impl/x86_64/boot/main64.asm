global long_mode_start
extern Kernel_Main

section .text
bits 64

long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call ActivateSSE
    call Kernel_Main
    hlt


ActivateSSE:
    mov rax,cr0
    and ax,0b11111101
    or ax,0b00000001
    mov cr0,rax

    mov rax, cr4
    or ax,0b1100000000
    mov cr4,rax
    
    ret