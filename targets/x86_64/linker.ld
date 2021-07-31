
ENTRY(start)

SECTIONS
{
    . = 1M;
    .boot :
    {
        KEEP(*(.multiboot_header))
    }
    .text :
    {
        *(.text)
    }
    .bss : ALIGH(1024*4)
    {
        *(.Paging)
        *(.Stack)
    }
}
