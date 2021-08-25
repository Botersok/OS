void memory_copy(char *source, char *dest, int nbytes) {
	int i = 0;
	for (i = 0; i < nbytes; i++) {
		*(dest + i) = *(source + i);
	}
}

void int_to_ascii(int n, char string[]) {
	int i, sign;
	if ((sign=n) < 0) {
		n = -n;
	}
	
	do {
		string[i++] =  n % 10 + '0';
	} while ((n/=10) > 0);
	
	if (sign < 0) {
		string[i++] = '-';
	}
	string[i] = '\0';
}
