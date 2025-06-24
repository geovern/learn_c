#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if(a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int main(int argc, char *argv[]) {


	int p = atoi(argv[1]), q = atoi(argv[2]); //prime
	int N = p * q;
	int phi = (p - 1) * (q - 1);
	int e; //coprime with phi
	int d;

	printf("Phi: %d\n", phi);

	for (int i = 2; i < phi; ++i) {
		//calculate e
		if(i % 2 != 0 && gcd(i, N) == 1 && gcd(i, phi) == 1) {
			e = i;
			break;
		}
	}
	printf("e: %d\n", e);
	

	return 0;
}
