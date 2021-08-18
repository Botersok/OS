	mov bp, 0x8000				;Setting up the stack, a little above
	mov sp, bp	
	
	mov bx, MSG
	call print_string
	jmp $

%include "print_string.asm"	
	
MSG:
	db "hello", 0

times 510-($-$$) db 0
dw 0xaa55