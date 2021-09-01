#include "../drivers/screen.h"
#include "util.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void main() {
	clear_screen();
	char *boodschap = "Boodschap\n";
	char int_string[255];
	int number = -123;
	int_to_ascii(number, int_string);
	print_char('B', 24, 78, 0x0f);
	print(int_string);
	print(boodschap);
	isr_install();
	char *strings[2] = {
		"bood", 
		"schap"
	};
	print(strings[0]);
	print(strings[1]);
	__asm__ __volatile__("int $2");
	__asm__ __volatile__("int $3");
}