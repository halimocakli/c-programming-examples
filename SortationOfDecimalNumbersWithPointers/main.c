#include <math.h>
#include <stdio.h>

void Decomposition(double, char*, int*, double*);

int main()
{
	double number;
	double decimal;
	char numbSign;
	int complete;

	printf("Insert the decimal number: ");
	scanf("%lf", &number);

	Decomposition(number, &numbSign, &complete, &decimal);
	printf("Analysis of %lf...\n", number);
	printf("------------------\n");
	printf("The sign is: %c\n", numbSign);
	printf("Integer part of the number is: %d\n", complete);
	printf("Decimal part of the number is: %lf\n", decimal);

	return 0;
}

void Decomposition(double numb, char* signPtr, int* completePtr, double* decimalPtr)
{
	double positiveValue;

	if (numb > 0)
	{
		*signPtr = '+';
	}
	else
	{
		*signPtr = '-';
	}

	positiveValue = fabs(numb);
	*completePtr = floor(positiveValue);
	*decimalPtr = positiveValue - *completePtr;
}
