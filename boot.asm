[org 0x7c00]

  mov bp, 0x9000 ; Set the stack
  mov sp, bp

  mov bx, MSG_REAL_MODE
  call print_string

  call switch_to_pm ; We never return from here

  jmp $

%include "print_string.asm"
%include "gdt.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"


[bits 32]
BEGIN_PM:
  mov ebx, MSG_PROT_MODE
  call print_string_pm

  jmp $

; Global variables
MSG_REAL_MODE db "Started in 16-bit mode", 0
MSG_PROT_MODE db "In 32-bit mode", 0

; Boot sector padding

times 510-($-$$) db 0
dw 0xaa55
