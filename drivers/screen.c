#include "screen.h"
#include "../kernel/low_level.h"
#include "../kernel/util.h"

void print_char(char character, int row, int col, char attribute) {
	unsigned char *video_memory = (unsigned char *) VIDEO_ADDRESS;
	int offset = 0; 
	
	//attribute
	if(!attribute) {
		attribute = WHITE_ON_BLACK;
	}
	
	//offset
	if(row >= 0 && col >= 0) {
		offset = get_screen_offset(row, col);
	} else {
		offset = get_cursor();
	}
	
	//printing
	if(character == '\n') {
		int rows = offset / (MAX_COLS * 2);
		offset = get_screen_offset(rows, 79);
	} else {
		video_memory += offset;
		*video_memory = character;
		video_memory += 1;
		*video_memory = attribute;
	}
	
	//moving cursor to next character
	offset += 2;
	
	//handle scrolling
	if(offset >= MAX_COLS*MAX_ROWS*2) {
		int i;
		for(i = 1; i<MAX_ROWS; i++) {
			memory_copy((char *)(get_screen_offset(i, 0) + VIDEO_ADDRESS), 
						(char *)(get_screen_offset(i - 1, 0) + VIDEO_ADDRESS), 
						MAX_COLS*2);
		}
		//blank last line
		char *lastline = (char *)(get_screen_offset(MAX_ROWS - 1, 0) + VIDEO_ADDRESS);
		for(i = 0; i < MAX_COLS*2; i++) {
			*(lastline + i) = 0;
		}
		offset = get_screen_offset(24, 0);
	}
	
	set_cursor(offset);
}

int get_cursor() {
	int offset = 0; 
	//set reg screen data to high byte
	port_byte_out(REG_SCREEN_CTRL, 14);
	offset = port_byte_in(REG_SCREEN_DATA) << 8;
	//set reg screen data to low byte
	port_byte_out(REG_SCREEN_CTRL, 15);
	offset += port_byte_in(REG_SCREEN_DATA);
	return offset * 2;
}

int get_screen_offset(int row, int col) {
	return (row * MAX_COLS + col) * 2;
}

void set_cursor(int cursor_offset) {
	cursor_offset /= 2;
	
	port_byte_out(REG_SCREEN_CTRL, 14);
	port_byte_out(REG_SCREEN_DATA, (unsigned char)(cursor_offset >> 8));
	port_byte_out(REG_SCREEN_CTRL, 15);
	//don't get this line
	port_byte_out(REG_SCREEN_DATA, (unsigned char)(cursor_offset & 0xff));
}

void print_at(char* message, int row, int col) {
	if(row >= 0 && col >= 0) {
		set_cursor(get_screen_offset(row, col));
	}
	while(*message != 0) {
		print_char(*message, row, col, WHITE_ON_BLACK);
		message += 1;
	}
}

void print(char* message) {
	print_at(message, -1, -1);
}

void clear_screen() {
	int col = 0; 
	int row = 0;
	
	for (row=0; row<MAX_ROWS; row++) {
        for (col=0; col<MAX_COLS; col++) {
			print_char(' ', row, col, WHITE_ON_BLACK);
        }
    }
	
	set_cursor(0);
}