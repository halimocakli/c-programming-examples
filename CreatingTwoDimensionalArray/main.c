#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

/* Iki boyutlu bir dizi olusturma ve matris olarak yazdirma */
/* Bu programi olurtururken bizim belirleyecegimiz kadar ogrencinin bes adet sinav notunu girecegimizi dusunelim */

void arrayGenerator(int arr[][SIZE], int size);
void printArray(int arr[][SIZE], int size);
int main()
{
	int firstSize;
	int secSize;

	printf("Dizinin birinci boyutunu giriniz: ");
	scanf("%d", &firstSize);

	int arr[firstSize][SIZE];

	arrayGenerator(arr, firstSize);
	printArray(arr, firstSize);

	return 0;
}

void arrayGenerator(int arr[][SIZE], int firstSize)
{
	srand(time(NULL));
	int i, j;

	for (i = 0; i < firstSize; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			arr[i][j] = 1 + rand() % 100;
		}
	}
}

void printArray(int arr[][SIZE], int firstSize)
{
	int i, j;

	printf("\nDizi yazdiriliyor...\n");
	printf("********************\n");

	for (i = 0; i < firstSize; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n\n");

	}
}