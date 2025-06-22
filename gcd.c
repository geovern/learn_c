#include <stdio.h>
#include <stdlib.h> // for atoi

int gcd(int a, int b) {
	if(a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	
	int num1 = atoi(argv[1]); // ASCII to INT
	int num2 = atoi(argv[2]);

	printf("gcd(%s, %s) = %d", argv[1], argv[2], gcd(num1, num2));
	
	return 0;
}
