
ENTRY(_start)

SECTIONS
{
    . = (0x7c00+(512*2));
    .text : ALIGN(0x512) /* ALIGN to sector*/
    {
        *(.text)
    }
    .idt BLOCK(0x1024) : ALIGN(0x512) /* ALIGN to sector*/
    {
        _idt = .;
        . = . + 0x1024;
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
    .StackSpace BLOCK(0x512*4) : ALIGN(0x512) /* ALIGN to sector*/
    {
        _Stack_Bottom = .; /* Symbol for calculating how much space I have left. */
        . = . + (0x512*4);  /* the stack grows in /\ that direction ?right? */
        _Stack_Top = .; /* Symbol for setting the stack pointer and base to the start of the stack space. */
    }
    .HeapSpace BLOCK(0x100000): ALIGN(0x512)
    {
        _HeadOfheap = .;
        . = 0x1000000;
        _TailOfHeap = .;
    }
}
