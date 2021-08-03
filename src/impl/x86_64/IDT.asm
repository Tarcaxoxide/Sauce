extern _idt


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


%macro isr 1
    extern isr%1_handler
    isr%1:
        PUSHALL
        call isr%1_handler
        POPALL
        iretq
    GLOBAL isr%1
%endmacro

idtDescriptor:
    dw 4095
    dq _idt

;isr1:
;    PUSHALL
;    call isr1_handler
;    POPALL
;    iretq
;    GLOBAL isr1

isr 1

loadIDT:
    lidt[idtDescriptor]
    sti
    ret
    GLOBAL loadIDT