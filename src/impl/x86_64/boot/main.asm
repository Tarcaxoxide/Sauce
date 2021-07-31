
global start
extern long_mode_start

section .text
bits 32
start:
    mov esp, stack_top
    call check_multiboot
    call check_cpuid
    call check_long_mode

    call setup_page_tables
    call enable_paging
    lgdt [gdt64.pointer]
    jmp gdt64.code_seqment:long_mode_start
    jmp _Stop


check_multiboot:
    cmp eax, 0x36D76289
    jne .no_multiboot
    ret
    .no_multiboot:
        mov al, "M"
        jmp error


check_cpuid:
    pushfd
    pop eax
    mov ecx, eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax
    push ecx
    popfd
    cmp eax,ecx
    je .no_cpuid
    .no_cpuid:
        mov al, "C"
        jmp error

check_long_mode:
    mov eax, 0x80000000
    cpuid
    cmp eax, 0x80000001
    jb .no_long_mode
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz .no_long_mode
    ret

    .no_long_mode:
        mov al, "L"
        jmp error


setup_page_tables:
    mov eax, page_table_l3
    or eax,0b11 ; present, writable
    mov [page_table_l4], eax

    mov eax, page_table_l2
    or eax,0b11 ; present, writable
    mov [page_table_l3], eax

    .loop:
        mov eax, 0x200000 ; 2MiB
        mul ecx
        or eax, 0b10000011
        mov [page_table_l2 + ecx * 8], eax

        mov ecx, 0 ; counter
        inc ecx ; increment counter
        cmp, ecx, 512 ; check if whole table is mapped
        jne .loop ; not done
        ret

enable_paging:
    ; pass page table location to cpu
    mov eax, page_table_l4
    mov cr3, eax
    ; enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ;enable long mode
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr
    
    ; enable paging
    mov eax,cr0
    or eax, 1 << 31
    mov cr0,eax
    ret

error:
    mov dword[0xB8000], 0x4F524F45
    mov dword[0xB8004], 0x4F3a4F52
    mov dword[0xB8008], 0x4F204F20
    mov byte[0xB8000A], al
    jmp _Stop


_Stop:
    hlt
    jmp _Stop


section .Paging
page_table_l4:
    resb 1024*4
page_table_l3:
    resb 1024*4
page_table_l2:
    resb 1024*4

section .Stack
stack_bottom:
    resb 1024*16
stack_top:

section .rodata
gdt64:
    dq 0
    .code_seqment: equ $ - gdt64
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53)
    .pointer:
        dw $ - gdt64 - 1
        dq gdt64