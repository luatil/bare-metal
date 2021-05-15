global _start

_start:
    mov ebp, 4          ; Move 4 to the ebp registerj
    mov eax, ebp        ; Move the contents of ebp to the eax register
    dec eax             ; Decrement eax by 1
    call fact           
    mov eax, 1          ; Set the sysexit system call on eax register
    int 0x80            ; Perform system call
fact: 
    imul ebp, eax       ; Multiply the contents of ebp register by eax
    dec eax             ; decrement the eax register by one
    cmp eax, 1          ; Compare the eax register to one
    jg fact             ; If eax is greater than one, jump to fact
    mov ebx, ebp        ; Else move the contents from ebp register to ebx 
    ret                 ; Return to after the call to fact
