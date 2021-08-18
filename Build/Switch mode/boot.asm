[org 0x7c00]
	mov dx, 0
	mov ds, dx
	mov bp, 0x8000				;Setting up the stack, a little above
	mov sp, bp					;the boot sector
	
	mov bx, MSG_REAL_MODE
	call print_string
	
	call switch_to_pm
	
	jmp $

%include "gdt.asm"
%include "print_string.asm"
%include "switch_to_pm.asm"
%include "print_string_pm.asm"

[bits 32]
BEGIN_PM:
	mov ebx, MSG_PROT_MODE
	call print_string_pm
	
	jmp $

MSG_REAL_MODE:
	db "Started in 16-bit real mode", 0
	
MSG_PROT_MODE:
	db "Landed in 32-bit protected mode", 0

times 510-($-$$) db 0
dw 0xaa55