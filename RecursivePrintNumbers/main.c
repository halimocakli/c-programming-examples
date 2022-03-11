#include <stdio.h>

void Print(int number)
{
	if (number == 0)
	{
		printf("%d", number);

	}
	else
	{
		printf("%d\n", number);
		Print(number - 1);
	}
}

int main()
{
	int number;

	printf("Insert a number: ");
	scanf("%d", &number);

	Print(number);

	return 0;
}
