HEADER_Multiboot2 equ 0xE85250D6
HEADER_ProtectedModeI386 equ 0
HEADER_Length equ (header_end-header_start)


section .Multiboot_Header

header_start:
    dd HEADER_MULTIBOOT2
    dd HEADER_ProtectedModeI386
    dd HEADER_Length

    ; EndTag
    dw 0
    dw 0
    dd 8
header_end: