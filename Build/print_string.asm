;The input variable of this function is BX	
[bits 16]
print_string: 
	pusha
	mov ah, 0x0e
	
loop:
	mov al, [bx]
	cmp al, 0
	je end
	int 0x10
	add bx, 1
	jmp loop
	
end:
	popa
	ret