global print_asm

print_asm:
	push ebx            ; save ebx register value on stack
	mov ebx, 1          ; describe the stdout value for the system call
	mov ecx, [esp+12]   ; save second function argument, the string pointer, to ecx
	mov edx, [esp+8]    ; save the first argument to edx, the length of the string
	mov eax, 4          ; set sys_write call
	int 0x80            ; perform interruption
	pop ebx             ; restore ebx value
	mov eax, 1          ; set 1 return value for eax 
	ret                 ; return 
