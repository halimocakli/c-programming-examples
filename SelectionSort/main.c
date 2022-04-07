#include <stdio.h>
#define MAX 100

// Selection Sort dizi icinde gezerek en kucuk elemani en basa atma yontemi kullanir
// En kucuk elememani en basa attiktan sonra kontrol etmeye dizinin bir sonraki elemanindan baslar

void SelectionSortAlgorithm(int[], int);
void Swap(int*, int*);
void PrintSortedArray(int[], int);

int main()
{
	int array[MAX];
	int size;
	int i = 0;

	printf("\nInsert the array size that you are going to create: ");
	scanf("%d", &size);
	printf("\n");

	for (i; i < size; ++i)
	{
		printf("Insert the %d. element of the array: ", i + 1);
		scanf("%d", &array[i]);
	}

	printf("\nElements of the array you have defined are printed below...\n");
	PrintSortedArray(array, size);

	SelectionSortAlgorithm(array, size);

	printf("\n\nSorted elements of the array printed below...\n");
	PrintSortedArray(array, size);

	return 0;
}

void SelectionSortAlgorithm(int array[], int size)
{
	int i;
	int j;
	int temp;
	int smallestIndex;

	for (i = 0; i < size; ++i)
	{
		smallestIndex = i;

		for (j = i; j < size; ++j)
		{
			if (array[j] < array[smallestIndex])
			{
				smallestIndex = j;
			}
		}
		Swap(&array[i], &array[smallestIndex]);
	}
}

void Swap(int* aPtr, int* bPtr)
{
	int temp = *aPtr;
	*aPtr = *bPtr;
	*bPtr = temp;
}

void PrintSortedArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", array[i]);
	}
}

