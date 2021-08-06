disk_load:
  push dx
  mov ah, 0x02
  mov al, dh ; Amount of sectors to read

  mov ch, 0 ; C
  mov dh, 0 ; H
  mov cl, 2 ; S

  int 0x13

  jc disk_error
  pop dx
  cmp dh, al
  jne disk_error
  ret

disk_error:
  mov bx, DISK_ERROR_MSG
  call print_string
  jmp $

DISK_ERROR_MSG:
  db "Disk error...", 0
