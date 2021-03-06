[org 0x7c00]
KERNEL_OFFSET equ 0x1000

	mov bx, 0				; Setting registers to zero
	mov es, bx
	mov ds, bx				
	mov bp, 0x9000			; Set-up the stack
	mov sp, bp				
	
	mov bx, MSG_REAL_MODE
	call print_string
	
	call load_kernel
	
	call switch_to_pm
	
	
	jmp $

%include "boot/gdt.asm"
%include "boot/print_string.asm"
%include "boot/switch_to_pm.asm"
%include "boot/disk_load.asm"
%include "boot/print_string_pm.asm"

[bits 16]
load_kernel: 
	mov bx, MSG_LOADING_KERNEL
	call print_string
	
	mov bx, KERNEL_OFFSET
	mov dh, 15
	mov dl, 0; 0x80
	
	call disk_load
	
	ret

[bits 32]
BEGIN_PM:
	mov ebx, MSG_PROT_MODE
	call print_string_pm
	
	call KERNEL_OFFSET
	
	jmp $

MSG_REAL_MODE:
	db "Started in 16-bit real mode", 0

MSG_LOADING_KERNEL:
	db "Loading kernel...", 0

MSG_PROT_MODE:
	db "Landed in 32-bit protected mode", 0

times 510-($-$$) db 0
dw 0xaa55	