global _start

extern main

_start:
    xor ebp, ebp         ; zero ebp register 
    pop esi              ; save argc to esi
    mov ecx, esp         ; save argv to ecx
    and esp, 0xfffffff0  ; align the stack 
    push ecx             ; push argv on the stack
    push esi             ; push argv on the stack 
    call main            ; call main function
    mov eax, 1           ; set eax to 1, the sys_exit code
    mov ebx, 1           ; set ebx to 1
    int 0x80             ; perform interrup

	
