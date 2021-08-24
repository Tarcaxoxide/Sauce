bits 16

jmp EnterProtectedMode

%include "PrintString.inc"
%include "PrintHex.inc"
%include "gdt.inc"
%include "DetectMemory.inc"

EnterProtectedMode:
    cli
    call DetectMemory
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
    
    ;Clear the screen.
    xor ecx, ecx
    .Loop:
        mov [0xB8000+ecx], byte ' '
        add ecx, 2
        cmp ecx, (80*50)
        jne short .Loop
    xor ecx, ecx

    call DetectCPUID
    call DetectLongMode
    call setUpIdentityPaging
    call EditGDT

    jmp CodeSeg:Start64Bit

bits 64
extern _start
extern _Stack_Top
extern _Stack_Bottom

GetFreeStack:
    ;push eax 
    mov eax, esp
    sub eax, _Stack_Bottom
    ret
GLOBAL GetFreeStack

GetMaxStack:
    ;push eax
    mov eax, _Stack_Top
    sub eax, _Stack_Bottom
    ret
GLOBAL GetMaxStack

Start64Bit:
    mov ax, DataSeg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, _Stack_Top
    mov esp,ebp
    call _start
jmp $

times 2048-($-$$) db 0
