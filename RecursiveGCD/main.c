#include <stdio.h>

int GCD(int, int);

int main()
{
	int x;
	int y;
	int result;

	do
	{
		printf("Insert first number: ");
		scanf("%d", &x);

		printf("Insert second number: ");
		scanf("%d", &y);

		if (x <= y)
			printf("The first number can't be smaller than the second one to calculate GCD.\n");

	} while (x <= y);

	result = GCD(x, y);

	printf("\nGCD{%d, %d} = %d", x, y, result);

	return 0;
}

int GCD(int x, int y)
{
	if (y != 0)
	{
		return GCD(y, x % y);
	}
	else
	{
		return x;
	}
}