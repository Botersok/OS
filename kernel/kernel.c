#include "../drivers/screen.h"
#include "low_level.h"
#include "util.h"

void main() {
	clear_screen();
	char *boodschap = "Boodschap";
	char int_string[255];
	int_to_ascii(-123, int_string);
	print_char('B', 24, 78, 0x0f);
	print_at(int_string, -1, -1);
	print(boodschap);
}