#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Bir dizideki max ve min degerleri bulan program */

void arrayGenerator(int arr[], int size)    /* Dizi uretme fonksiyonu*/
{
	int i;
	srand(time(NULL));

	for (i = 0; i < size; ++i)
	{
		arr[i] = 1 + rand() % 100;
	}
}

void printArray(int arr[], int size)    /* Dizi yazdirma fonksiyonu */
{
	int i;

	printf("\nDizi yazdiriliyor...\n");
	printf("********************\n");

	for (i = 0; i < size; ++i)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

int arrayMaxFinding(int arr[], int size)    /* Dizinin max elemanini bulma fonksiyonu */
{
	int i = 0;
	int max = arr[i];

	for (i = 0; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int arrayMinFinding(int arr[], int size)    /* Dizinin min elemanin bulan fonksiyon */
{
	int i = 0;
	int min;

	min = arr[i];

	for (i = 0; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int main()
{
	int size;
	int max;
	int min;

	printf("Dizi boyutunu giriniz: ");
	scanf("%d", &size);

	int arr[size];

	arrayGenerator(arr, size);
	printArray(arr, size);

	max = arrayMaxFinding(arr, size);
	min = arrayMinFinding(arr, size);

	printf("\nDizinin Max Elemani = %d\nDizinin Min Elemani = %d", max, min);

	return 0;
}