#include "low_level.h"

unsigned char port_byte_in(u16 port) {
	unsigned char result; 
	//"=a" (result) means put al register in result
	//"d" (port) means load edx with port
	__asm__("in %%dx, %%al": "=a" (result) : "d" (port));
	return result; 
}

void port_byte_out(u16 port, u8 data) {
	//"a" (data) means load eax with data
	//"d" (port) means load edx with port
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}

unsigned short port_word_in(u16 port) {
	unsigned short result; 
	__asm__("in %%dx, %%ax": "=a" (result) : "d" (port));
	return result;
}

void port_word_out(u16 port, u16 data) {
	__asm__("out %%ax, %%dx" : :"a" (data), "d" (port));
}