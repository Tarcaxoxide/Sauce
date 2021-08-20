[org 0x7e00]
;extern SYS_START_POINT
db 'h'

mov bx,ExtendedSpaceTestString
call PrintString


jmp $

ExtendedSpaceTestString: db "Hello Extended",0
%include "PrintString.inc"

times (44*512)-($-$$) db 0