data segment
a dw 0009h
b dw 0054h
c dw ?
data ends
 
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0000h
mov bx,0000h
mov ax,a
mov bx,b
mul bx
mov c,ax
int 3
code ends
end start
