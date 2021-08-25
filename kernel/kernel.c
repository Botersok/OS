#include "../drivers/screen.h"
#include "low_level.h"
#include "util.h"

void main() {
	clear_screen();
	char *boodschap = "Boodschap";
	char int_string[255];
	int_to_ascii(6, int_string);
	print_at(int_string, 24, 79);
	print(boodschap);
}