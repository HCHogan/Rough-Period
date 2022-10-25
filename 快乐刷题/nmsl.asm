assume cs:nmsl
nmsl segment
    mov ax,1
    mov cs,ffffh
  s:add ax,ax
    loop s
    mov ax,4c00h
    int 21h
nmsl ends
end