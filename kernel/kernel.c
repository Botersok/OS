#include "../drivers/screen.h"
#include "low_level.h"
#include "util.h"

void main() {
	clear_screen();
	char *boodschap = "Boodschap";
	char int_string[255];
	int number = -123;
	int_to_ascii(number, int_string);
	print_char('B', 24, 78, 0x0f);
	print(int_string);
	print(boodschap);
}