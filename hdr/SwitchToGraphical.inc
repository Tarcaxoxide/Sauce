
%ifndef INC_SwitchToGraphical
%define INC_SwitchToGraphical

IsGraphical:db 0
GLOBAL IsGraphical

SwitchToGraphical:
    mov ah,00h ; config is video mode
    mov al, 13h
    int 0x10    ; do it
    mov byte [IsGraphical], al
    ret
%endif
