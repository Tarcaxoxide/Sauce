%ifndef INC_DetectLongMode
%define INC_DetectLongMode
    DetectLongMode:
            mov eax, 0x80000001
            cpuid
            test edx, 1 << 29
            jz NoLongMode
        ret
    
    NoLongMode:
        hlt
        jmp NoLongMode
%endif