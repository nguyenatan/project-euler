#include <stdio.h>
#include <math.h>

// First 10 primes
int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int smallest_number_db(int);

/* Utility functions */
int nat_power(int, int);

int main(void)
{
	int result = smallest_number_db(20);
	
	printf("%d\n", result);
	
	return 0;
}

// Return smallest positive number that is evenly divisible
// by all of the numbers from 1 to upperLimit.
int smallest_number_db(int upperLimit)
{
	int smallestNumber = 1;
	int a[10];
	int check = 1;
	int limit = sqrt(upperLimit);
	
	int i = 0;
	while (p[i] <= upperLimit) {
		a[i] = 1;
		
		if (check) {
			if (p[i] <= limit)
				a[i] = floor( log(upperLimit) / log(p[i]) );
			else
				check = 0;
		}
		
		smallestNumber *= nat_power(p[i], a[i]);
		
		++i;
	}
	
	return smallestNumber;
}

int nat_power(int n, int degree)
{
	int power = n;
	
	while (degree-- > 1)
		power *= n;
		
	return power;
}
