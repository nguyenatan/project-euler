#include <stdio.h>
#include <math.h>

#define UPPER_LIMIT 999

int is_palindrome(int);
int largest_palindrome(int);

/* Utility functions */
int nat_power(int, int);
int find_lower_limit(int);

int main(void)
{
	int result = largest_palindrome(UPPER_LIMIT);
	
	printf("%d\n", result);
	
	return 0;
}

int is_palindrome(int n)
{
	int temp = n, reversed = 0;
	
	while (temp) {
		reversed = 10*reversed + (temp % 10);
		temp /= 10;
	}
	
	return reversed == n;
}

int largest_palindrome(int upperLimit)
{
	int lowerLimit = find_lower_limit(upperLimit);
	int largestPalindrome = 0;
	int a = upperLimit;
	
	while (a >= lowerLimit) {
		int b = upperLimit;
		int divisible_by;
		
		if (!(a%11))
			divisible_by = 1;
		else
			divisible_by = 11;
		
		while (b >= a) {
			if (a*b <= largestPalindrome)
				break;
			
			if (is_palindrome(a*b))
				largestPalindrome = a*b;
			
			b -= divisible_by;
		}
		
		--a;
	}
	
	return largestPalindrome;
}

int nat_power(int n, int degree)
{
	int power = n;
	
	while (degree-- > 1)
		power *= n;
	
	return power;
}

// If upper limit = 999 then lower limit = 100 (3-digit numbers)
int find_lower_limit(int upperLimit)
{
	int count = log10(upperLimit);
	
	return nat_power(10, count);
}
