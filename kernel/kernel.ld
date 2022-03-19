OUTPUT_FORMAT(elf64-x86-64)
ENTRY(_start)

SECTIONS
{
    _KernelStartRef = .;
    .text : ALIGN(0x1000) /* ALIGN to sector*/
    {
        *(.text)
    }
    .data : ALIGN(0x1000) /* ALIGN to sector*/
    {
        *(.data)
    }
    .rodata : ALIGN(0x1000) /* ALIGN to sector*/
    {
        *(.rodata)
    }
    .bss : ALIGN(0x1000) /* ALIGN to sector*/
    {
        *(COMMON)
        *(.bss)
    }
    _KernelEndRef = .;
}
