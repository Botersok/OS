[org 0x7c00]

	;set registers to zero
	mov bx, 0
	mov es, bx
	mov ds, bx		
	;set-up the stack
	mov bp, 0x9000
	mov sp, bp
	
	mov ah, 0x0e
	mov al, 'H'
	int 0x10
	jmp $

times 510 - ($-$$) db 0
dw 0xaa55