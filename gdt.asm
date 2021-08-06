gdt_start:

gdt_null:
  dd 0x0
  dd 0x0

gdt_code:
  dw 0xffff     ; limit
  dw 0x0        ; base
  db 0x0        ; base
  db 10011010b  ; flags
  db 11001111b  ; more flags, last four are
  db 0x0        ; are the second part of the limit

gdt_data:
  dw 0xffff    ; Limit
  dw 0x0       ; Base
  db 0x0       ; Base
  db 10010010b ; 1st flags , type flags
  db 11001111b ; 2nd flags , Limit ( bits 16 -19)
  db 0x0       ; Base

gdt_end:


gdt_descriptor:
  dw gdt_end - gdt_start - 1 ; size always one less
  dd gdt_start

; These variables are what the segment registers have to contain
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
