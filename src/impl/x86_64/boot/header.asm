HEADER_Multiboot2 equ 0xE85250D6
HEADER_ProtectedModeI386 equ 0
HEADER_Length equ (header_end-header_start)
HEADER_Checksum equ 0x100000000-(HEADER_Multiboot2+HEADER_ProtectedModeI386+HEADER_Length)

section .multiboot_header

header_start:
    dd HEADER_Multiboot2
    dd HEADER_ProtectedModeI386
    dd HEADER_Length
    dd HEADER_Checksum

    ; EndTag
    dw 0
    dw 0
    dd 8
header_end: