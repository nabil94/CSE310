.model small

.stack 100h

.data

ret DW ?
a2 DW ?
a2 DW ?
x3 DW ?
a3 DW ?
t1 DW ?
t2 DW ?
a3 DW ?
t3 DW ?
b3 DW ?
t4 DW ?
x3 DW ?
a4 DW ?
b4 DW ?
a4 DW ?
a4 DW ?
b4 DW ?
t5 DW ?
t6 DW ?
t7 DW ?
main proc
	mov ax, 1
	mov a4, ax
	mov ax, 2
	mov b4, ax
mov ax, a
	mov t5, ax
	mov ax, b
	mov t6, ax
	call g
	mov t7, ret
	mov ax, t7
	mov a4, ax
	mov ax, a
	call decimal_out
	mov ret, ax

	mov ah,4ch
	int 21h
main endp

g proc 
	mov ax, a
	mov t1, ax
	call f
	mov t2, ret
	mov ax, t2
	add ax, a3
	mov t3 , ax
	mov ax, t3
	add ax, b3
	mov t4 , ax
	mov ax, t4
	mov x3, ax
	mov ret, ax
g endp

f proc 
		mov ax, 2
	mov bx , a2
	mul bx
	mov t0, ax
	mov ret, ax
	mov ax, 9
	mov a2, ax
f endp



decimal_out endp

	push ax
	push bx
	push cx
	push dx
	or ax,ax
 	jge enddif
	push ax
	mov dl,'-'
	mov ah,2
	int 21h
	pop ax
	neg ax
enddif:
	xor cx,cx
	mov bx,10d
repeat:
	xor dx,dx
	div bx
	 push dx
	inc cx
	or ax,ax
	jne repeat
	mov ah,2
print_loop:
	pop dx
	or dl,30h
	int 21h
	loop print_loop
	pop dx
	pop cx
	pop bx
	pop ax
	ret

decimal_out endp

