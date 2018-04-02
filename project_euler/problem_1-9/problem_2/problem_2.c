#include <stdio.h>

#define LIMIT 4000000

unsigned int n1 = 1, n2 = 1, n3 = 2;

unsigned int sum_even_Fibonacci(unsigned int);

int main(void)
{
	unsigned int result = sum_even_Fibonacci(LIMIT);
	
	printf("%u\n", result);
	
	return 0;
}

unsigned int sum_even_Fibonacci(unsigned int limit)
{
	unsigned int sum = 0;
	
	while (n3 < limit) {
		sum += n3;
		n1 = n2 + n3;
		n2 = n3 + n1;
		n3 = n1 + n2;
	}
	
	return sum;
}
