#include <stdio.h>

int Sum(int);

int main()
{
	int number;
	int result;

	do
	{
		printf("Insert a positive integer: ");
		scanf("%d", &number);

		if (number < 0)
		{
			printf("The number you've insert is not a positive integer. ");
		}
	} while (number < 0);


	result = Sum(number);

	printf("%d is the result. ", result);

	return 0;
}

int Sum(int number)
{
	if (number != 0)
	{
		return number + Sum(number - 1);
	}
	else
	{
		return number;
	}

}