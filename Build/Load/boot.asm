[org 0x7c00]

	mov bx, 0
	mov es, bx
	mov ds, bx
	mov bp, 0x8000				;Setting up the stack, a little above
	mov sp, bp					;the boot sector
	
	mov bx, 0x9000
	mov dh, 2
	mov dl, 0x80
	
	call disk_load
	
	mov bx, 0x9000
	call print_string
	
	mov bx, 0x9000 + 512
	call print_string
	
	jmp $

%include "print_string.asm"
%include "disk_load.asm"

times 510-($-$$) db 0
dw 0xaa55

times 256 db 'L', 0
times 128 db 'WIN', 0