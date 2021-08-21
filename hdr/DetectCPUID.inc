%ifndef INC_DetectCPUID
%define INC_DetectCPUID
    DetectCPUID:
        pushfd
        pop eax

        mov ecx, eax
        xor eax, 1 << 21

        push eax
        popfd

        pushfd
        pop eax

        push ecx
        popfd

        xor eax, ecx
        jz NoCPUID
        ret

    NoCPUID:
        hlt
        jmp NoCPUID

%endif