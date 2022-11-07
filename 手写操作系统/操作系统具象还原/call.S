call near near_proc
jmp $

near_proc:
    mov ax,0x1234
    ret
    jn 0x1234