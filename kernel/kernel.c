#include "../drivers/screen.h"
#include "low_level.h"
#include "util.h"

void main() {
	print_char('E', 23, 79, 0x0f);
	char *boodschap = "Boodschap";
	clear_screen();
	print(boodschap);
}