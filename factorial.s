global _start

_start:
    mov ebp, 4
    mov eax, ebp
    dec eax
    call fact
    mov eax, 1
    int 0x80
fact: 
    imul ebp, eax
    dec eax
    cmp eax, 1
    jg fact
    mov ebx, ebp
    ret
