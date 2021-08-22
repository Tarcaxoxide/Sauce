
ENTRY(_start)

SECTIONS
{
    . = 0x7e00;
    .boot :
    {
        KEEP(*(.multiboot_header))
    }
    .text :
    {
        *(.text)
    }
    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        _idt = .;
        . = . + 0x1000;
    }
    .data :
    {
        *(.data)
    }
    .rodata :
    {
        *(.rodata)
    }
    .bss :
    {
        *(COMMON)
        *(.bss)
    }
    .StackSpace BLOCK(0x2000) : ALIGN(0x1000)
    {
        _Stack_Bottom = .;
        . = . + 0x2000;
        _Stack_Top = .;
    }
}
