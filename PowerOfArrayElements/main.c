#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Kullanicidan alinan sayinin ya da rakamin dizi icersinde bulunan sayilarin ya da ramanlarin kati olup olmadigini bulan program */

void arrayGenerator(int arr[], int size);   /* Dizi uretme fonksiyonunun prototipi */
void printArray(int arr[], int size);   /* Dizi yazdirma fonksiyonumuzun prototipi */
void
findPower(int number, int arr[], int size);    /* Girilen eleman ve dizi elemanlari arasinda kuvvet incelemesi yapar */

int main()
{
	int number;
	int size;

	printf("Lutfen dizinizin boyutunu giriniz: ");
	scanf("%d", &size);

	if (size < 0)
	{
		size = -1 * size;
	}

	int arr[size];

	printf("Lutfen bir rakam ya da sayi giriniz: ");
	scanf("%d", &number);

	/* Girilen numaranın pozitif-negatif kontrolu yapiliyor */
	if (number < 0)
	{
		number = -1 * number;
	}

	arrayGenerator(arr, size);  /* Dizi uretec fonksiyonumuza cagri yapiliyor */
	printArray(arr, size);  /* Dizi yazdirma fonksiyonumuza cagri yapiliyor */

	printf("\n");

	findPower(number, arr, size);   /* Kuvvet bulma fonksiyonumuza cagri yapiliyor */

	return 0;
}

void arrayGenerator(int arr[], int size)
{
	int i;
	srand(time(NULL));  /* Sayilarmizi rastgele uretmek icin srand() fonksiyonu kullaniyoruz */

	for (i = 0; i < size; ++i)
	{
		arr[i] = 1 + rand() % 100;
	}
}

void printArray(int arr[], int size)
{
	int i;

	printf("\nDizi yazdiriliyor...\n");
	printf("********************\n");

	for (i = 0; i < size; ++i)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void findPower(int number, int arr[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if (arr[i] % number == 0)
		{
			printf("%d Sayisi %d Sayisinin Katidir...\n", number, arr[i]);
		}
	}
}