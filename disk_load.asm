;input variables : bx for where to load to in memory, 
; dh for amount of sectors to read and dl for disk
[bits 16]
disk_load:

	push dx 			; Number of sectors is stored in here
	mov ah, 0x02
	mov al, dh 			; amount of sectors to read
	mov ch, 0 			; cylinder
	mov dh, 0 			; head
	mov cl, 2 			; sector
	
	
	int 0x13
	
	jc disk_error
	
	pop dx
	cmp al, dh
	jne disk_error
	ret
	
disk_error:
	mov bx, DISK_ERROR_MSG
	call print_string
	jmp $

DISK_ERROR_MSG: 
	db "Disk read error", 0