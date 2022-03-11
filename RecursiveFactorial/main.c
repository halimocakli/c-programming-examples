#include <stdio.h>

unsigned long long int Factorial(unsigned int);

int main()
{
	unsigned int i;

	for (i = 0; i <= 21; ++i)
	{
		printf("%u! = %llu\n", i, Factorial(i));
	}
}

unsigned long long int Factorial(unsigned int number)
{
	if (number <= 1)
	{
		return 1;
	}
	else
	{
		return (number * Factorial(number - 1));
	}
}
