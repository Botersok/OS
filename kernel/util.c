#include "math.h"

void memory_copy(char *source, char *dest, int nbytes) {
	int i = 0;
	for (i = 0; i < nbytes; i++) {
		*(dest + i) = *(source + i);
	}
}

void int_to_ascii(int n, char string[]) {
	int i = 0;
	int digits, n2, power;
	string[0] = 'K';
	if (n < 0) {
		n = -n;
		string[i++] = '-';
	}
	
	do {
		digits = 0;
		n2 = n;
		
		while(n2 > 0) {
			n2 /= 10;
			digits++;
		}
		power = digits - 1;
		string[i++] = (n / powerOf(10, power)) + '0';
		
	} while ((n%powerOf(10, power)) > 0);
	string[i] = '\0';
}
