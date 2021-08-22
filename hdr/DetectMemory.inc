
MemoryRegionCount:db 0
GLOBAL MemoryRegionCount

MemoryMapAddress:dd 0x5000
GLOBAL MemoryMapAddress

DetectMemory:
    mov ax,0
    mov es, ax
    mov di, [MemoryMapAddress] ; location for memory map
    mov edx, 0x534D4150
    xor ebx, ebx

    .repeat:
        mov eax, 0xE820
        mov ecx, 24
        int 0x15
        cmp ebx, 0
        je .Done
        add di, 24
        inc byte [MemoryRegionCount]
        jmp short .repeat
    .Done:
        ret
