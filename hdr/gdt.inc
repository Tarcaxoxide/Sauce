%ifndef INC_GDT
%define INC_GDT
    GDT_NullDesc:
        dd 0
        dd 0
    GDT_CodeDesc:
        dw 0xFFFF
        dw 0x0000
        db 0x00
        db 10011010b
        db 11001111b
        db 0x00
    GDT_DataDesc:
        dw 0xFFFF
        dw 0x0000
        db 0x00
        db 10010010b
        db 11001111b
        db 0x00
    GDT_EndDesc:

    GDT_Descriptor:
        gdt_size:
            dw GDT_EndDesc - GDT_NullDesc - 1
            dq GDT_NullDesc
    
    CodeSeg equ GDT_CodeDesc - GDT_NullDesc
    DataSeg equ GDT_DataDesc - GDT_NullDesc

    bits 32
    EditGDT:
        mov [GDT_CodeDesc+6], byte 10101111b
        mov [GDT_DataDesc+6], byte 10101111b
        ret
    bits 16
%endif
