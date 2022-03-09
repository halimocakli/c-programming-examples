#include <stdio.h>

int Sum(int);

int main()
{
	int number;
	int result;

	printf("Insert the number: ");
	scanf("%d", &number);

	result = Sum(number);

	printf("Result is %d", result);
	return 0;
}

int Sum(int number)
{
	if (number != 0)
	{
		return (number % 10 + Sum(number / 10));
	}
	else
	{
		return 0;
	}
}
