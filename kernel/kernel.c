#include "../drivers/screen.h"
#include "low_level.h"
#include "util.h"

void main() {
	clear_screen();
	char *boodschap = "Boodschap";
	print_char('E', 23, 79, 0x0f);
	print(boodschap);
}