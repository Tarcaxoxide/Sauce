extern _idt
extern isr1_handler

%macro PUSHALL 0
    push rax
    push rcx
    push rdx
    push r8
    push r9
    push r10
    push r11
%endmacro

%macro POPALL 0
    push r11
    push r10
    push r9
    push r8
    push rdx
    push rcx
    push rax
%endmacro


idtDescriptor:
    dw 4095
    dq _idt

isr1:
    PUSHALL
    call isr1_handler
    POPALL
    iretq
    GLOBAL isr1

loadIDT:
    lidt[idtDescriptor]
    sti
    ret
    GLOBAL loadIDT