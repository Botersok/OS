int powerOf(int base, int exponent) {
	int result = 1;
	if (exponent >= 1) {
		for(int i = 0; i < exponent; i++) {
			result *= base;
		}
		return result;
	} else if(exponent == 0) {
		return 1;
	} else {
		for(int i = 0; i < -exponent; i++) {
			result *= (1/base);
		}
		return result;
	}
}