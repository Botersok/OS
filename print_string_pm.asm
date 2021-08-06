[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print_string_pm:
  pusha
  mov edx, VIDEO_MEMORY     ; EDX to the start of the video memory

print_string_pm_loop:
  mov al, [ebx]             ; ebx is set to the address of the char
  mov ah, [WHITE_ON_BLACK]  ; that needs to be printed

  cmp al, 0
  je done

  mov [edx], ax             ; Store the character and the style
                            ; to the current video address
  add ebx, 1                ; String is stored here
  add edx, 2                ; character cell of the video memory

  jmp print_string_pm_loop


done:
  popa
  ret
