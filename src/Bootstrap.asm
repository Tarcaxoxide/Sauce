bits 16

Max_Y equ 50
Max_X equ 80

jmp EnterProtectedMode

%include "PrintString.inc"
%include "PrintHex.inc"
%include "gdt.inc"

EnterProtectedMode:
    cli
    call EnableA20
    lgdt [GDT_Descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CodeSeg:StartProtectedMode

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret



bits 32
%include "DetectCPUID.inc"
%include "DetectLongMode.inc"
%include "SimplePaging.inc"

StartProtectedMode:
    mov ax, DataSeg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    xor ecx, ecx
    .Loop:
        mov [0xB8000+ecx], byte ' '
        add ecx, 2
        cmp ecx, (Max_X*Max_Y)
        jne short .Loop
    xor ecx, ecx

    call DetectCPUID
    call DetectLongMode
    call setUpIdentityPaging
    call EditGDT

    jmp CodeSeg:Start64Bit

bits 64
extern _start
Start64Bit:
    mov ax, DataSeg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call _start
jmp $
times 2048-($-$$) db 0