unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);
void print_char(char character, int row, int col, char attribute);
int get_cursor();
int get_screen_offset(int row, int col);
void set_cursor(int cursor_offset);
void print_at(char* message, int row, int col);
void print(char* message);
void clear_screen();

void main() {
	char *boodschap = "Boodschap";
	clear_screen();
	print(boodschap);
}