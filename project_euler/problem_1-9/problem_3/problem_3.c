#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t largest_prime_factor(uint64_t);

int main(void)
{
	uint64_t n = 600851475143;
	
	uint64_t result = largest_prime_factor(n);
	
	printf("%llu\n", result);
	
	return 0;
}

uint64_t largest_prime_factor(uint64_t n)
{
	uint64_t lastFactor = 1;
	
	if (!(n%2)) {
		lastFactor = 2;
		n /= 2;
		
		while (!(n%2))
			n /= 2;
	}
	
	uint64_t factor = 3;
	uint64_t maxFactor = sqrt(n);
	
	while (n > 1 && factor < maxFactor) {
		if (!(n%factor)) {
			lastFactor = factor;
			n /= factor;
		}
		
		while (!(n%factor))
			n /= factor;
		
		maxFactor = sqrt(n);
		factor += 2;
	}
	
	if (n == 1)
		return lastFactor;
	
	return n;
}
