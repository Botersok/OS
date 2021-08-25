#include "math.h"

void memory_copy(char *source, char *dest, int nbytes) {
	int i = 0;
	for (i = 0; i < nbytes; i++) {
		*(dest + i) = *(source + i);
	}
}

void int_to_ascii(int number, char string[]) {
	int  i = 0;
	int n2, digits, power;
	if (number < 0) {
		number = -number;
		string[i++] = '-';
    } 
	while(number > 0) {
		n2 = number;
		digits = 0;
		while(n2 > 0) {
			n2 /= 10;
			digits++;
		}
		power = digits - 1;
		string[i++] = number/powerOf(10, power) + '0';
		number %= powerOf(10, power);
	}
	string[i] = '\0';
}