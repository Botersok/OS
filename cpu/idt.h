#ifndef IDT_H
#define IDT_H

#include "types.h"

//segment selector
#define KERNEL_CS 0x08


typedef struct {
	u16 low_offset; //handler function address
	u16 sel;
	u8 always0;
	/* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
	u8 flags;
	u16 high_offset;
} __attribute__((packed)) idt_gate_t;

typedef struct {
	u16 limit; 
	u32 base;
}__attribute__((packed)) idt_register_t;

/* A pointer to the array of interrupt handlers.
 * Assembly instruction 'lidt' will read it */
 
#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, u32 handler);
void set_idt();

#endif