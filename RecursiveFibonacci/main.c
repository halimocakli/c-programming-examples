#include <stdio.h>

unsigned long long int Fibonacci(unsigned int n);

int main(void)
{
	unsigned int number;

	printf("%s", "Bir Tamsayi Giriniz: ");
	scanf("%u", &number);

	unsigned long long int result = Fibonacci(number);

	printf("Fibonacci(%u) = %llu\n", number, result);
}

unsigned long long int Fibonacci(unsigned int n)
{
	if (0 == n || 1 == n)
	{
		return n;
	}

	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
