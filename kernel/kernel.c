unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);
int get_screen_offset(int col, int row);
int get_cursor();
void set_cursor(int offset);
int handle_scrolling(int cursor_offset);
void print_at(char* message, int col, int row);
void print(char* message);
void clear_screen();

void main() {
	unsigned char *vidmem = (unsigned char *) 0xb8000;
	int i = 0; 
	for(i = 0; i < 80*25; i++) {
		vidmem[i*2] = ' ';
		vidmem[i*2 + 1] = 0x0f;
	}
	
	vidmem[0] = 'F';
	vidmem[80*25*2-1] = 'L';
	
	for(i = 24*80; i < 80*25; i++) {
		vidmem[i*2] = ' ';
		vidmem[i*2 + 1] = 0x0f;
	}
}