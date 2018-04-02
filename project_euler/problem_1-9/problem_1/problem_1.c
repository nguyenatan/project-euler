#include <stdio.h>

#define TARGET 999

int sum_divisible_by(int);

int main(void)
{
	int result = sum_divisible_by(3) + sum_divisible_by(5) - sum_divisible_by(15);
	
	printf("%d\n", result);
	
	return 0;
}

// Formula: 1+2+3+...+p = p*(p+1) / 2
//		3+6+9+...+999 = 3*(1+2+3+...+333)
//
//		5+10+15+...+995 = 5*(1+2+3+...+199)
//			199 = 995/5 but also 999/5 rounded down to the nearest integer.
int sum_divisible_by(int n)
{
	int p = TARGET / n;
	
	return n * (p*(p+1) / 2);
}
