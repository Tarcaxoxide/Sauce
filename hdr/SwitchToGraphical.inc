
%ifndef INC_SwitchToGraphical
%define INC_SwitchToGraphical

IsGraphical:db 0
GLOBAL IsGraphical

SwitchToGraphical:
    mov ax, 0013H
    int 0x10    ; do it
    mov byte [IsGraphical], al
    ret
%endif
