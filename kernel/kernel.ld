OUTPUT_FORMAT(elf64-x86-64)
ENTRY(_start)

SECTIONS
{
    .text : ALIGN(0x512) /* ALIGN to sector*/
    {
        *(.text)
    }
    .data : ALIGN(0x512) /* ALIGN to sector*/
    {
        *(.data)
    }
    .rodata : ALIGN(0x512) /* ALIGN to sector*/
    {
        *(.rodata)
    }
    .bss : ALIGN(0x512) /* ALIGN to sector*/
    {
        *(COMMON)
        *(.bss)
    }
}
