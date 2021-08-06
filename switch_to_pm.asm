[bits 16]
switch_to_pm:
  cli ; Shut off interrupts, otherwise interrupt vector not there,
      ; interrupts will run wild.
  lgdt [gdt_descriptor] ; Load global descriptor table,
                        ; which defines segments
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax ; The switch

  jmp CODE_SEG:init_pm ; Far jump to flush pipeline.

[bits 32]
init_pm:
  mov ax, DATA_SEG ; Old segments meaningless
  mov ds, ax ; So segments to data selector
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000 ; Update our stack position right
  mov esp, ebp     ; at the top of the free space.

  call BEGIN_PM
