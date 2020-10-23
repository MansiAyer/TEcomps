.model small
.stack 100
.data
n1 dw 0004
n2 dw 0002
hcf dw ?
lcm dw ?

.code
mov ax,@data
mov ds,ax
mov ax,n1
mov bx,n2
call gcdiv

proc gcdiv
        WHIL:mov dx,0
        mov cx,bx
        div bx
        mov bx,dx
        mov ax,cx
        cmp bx,0
        JNE WHIL
        mov hcf,ax
        mov cx,ax
endp gcdiv
call lcmul
proc lcmul
         mov ax,n1
         mov bx,n2
         mul bx
         div cx
         mov lcm,ax
endp lcmul

mov ah,4ch
int 21h
end
