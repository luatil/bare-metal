global is_prime

is_prime:
    mov ecx, [esp+4] ; save the argument to is_prime on ecx
    push ebx         ; save the value of ebx on the stack 
    cmp ecx, 2       ; compare the argument to 2
    jl not_prime     ; if the argument is lesser than two, jump to not_prime
    mov ebx, 2       ; else store the value 2 on ebx, this will act as the index for L1
L1:
    mov edx, 1       ; move the value 1 to ebx
    imul edx, ebx    ; multiply edx by the value of ebx
    imul edx, ebx    ; do the same of the last instruction
    cmp ecx, edx     ; check if the argument is bigger than the index squared
    jl it_is_prime   ; if it is jump to it_is_prime
    mov eax, ecx     ; else save on eax the value of ecx, this is done because division occurs on edx:eax
    xor edx, edx     ; zero the value of edx since we are working with 4 bytes values
    div ebx          ; divide 0:eax by the index, the result is saved on eax, and the rest on edx
    cmp edx, 0       ; compare the value of the rest of the division with zero
    je not_prime     ; if the rest of the division is zero, jump to not_prime
    inc ebx          ; else increase the index
    jmp L1           ; and perform the loop again
it_is_prime:
    pop ebx          ; restore the value of ebx
    mov eax, 1       ; if the number is prime, is_prime returns 1
    ret
not_prime:
    pop ebx          ; restore the value of ebx
    mov eax, 0       ; if the number is not prime, is_prime returns 0
    ret
