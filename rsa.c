#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b) {
	if(a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}
	
unsigned long long mod_pow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

int main(int argc, char *argv[]) {


	//TO DO
	//error handling
	
	int p = atoi(argv[4]), q = atoi(argv[5]); //prime
	int N = p * q;
	int phi = (p - 1) * (q - 1);
	int e = atoi(argv[2]); //coprime with phi
	int d = atoi(argv[3]);

	int num;
	scanf("%d", &num);
	if(!strcmp("enc", argv[1])) { //encrypt
		printf("%llu", mod_pow(num, e, N));	
	} else if (!strcmp("dec", argv[1])) { //decrypt
		printf("%llu", mod_pow(num, d, N));
	} else {
		printf("First argument must be \'enc\' or \'dec\'"); 
	}

	//for (int i = 2; i < phi; ++i) { 
	//	//calculate e
	//	if(i % 2 != 0 && gcd(i, N) == 1 && gcd(i, phi) == 1) {
	//		e = i;
	//		break;
	//	}
	//}
	
	return 0;
}
