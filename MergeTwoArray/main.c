#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Rastgele sayilardan olusturduğumuz iki diziyi birbirine kopyalama */

/* Dizilerimizi birlestirecek olan fonksiyon prototipi olurutuluyor */
void arrayMerge(int firstArr[], int secondArr[], int firstSize, int secSize);

int main()
{
	int first_size;
	int second_size;
	int i;

	srand(time(NULL));

	printf("1.Dizinizin boyutunu giriniz:");
	scanf("%d", &first_size);
	printf("2.Dizinizin boyutunu giriniz:");
	scanf("%d", &second_size);

	/* Girilen boyutlarin pozitif/negatif olma durumlari kontrol ediliyor */
	if (first_size < 0)
	{
		first_size = -1 * first_size;
	}

	if (second_size < 0)
	{
		second_size = -1 * second_size;
	}

	printf("\n");

	int firstArr[first_size];
	int secondArr[second_size];

	/* Ilk dizimizi 0-100 araligindaki rastgele sayilardan olusturuyoruz */
	for (i = 0; i < first_size; ++i)
	{
		firstArr[i] = 1 + rand() % 100;
	}

	printf("Birinci dizi elemanlari yazdirliyor...\n");
	printf("**************************************\n");

	/* Ilk dizimizi yazdiralim */
	for (i = 0; i < first_size; ++i)
	{
		printf("firsArr[%d] = %d\n", i, firstArr[i]);
	}

	/* Ikinci dizimizi 0-100 araliginda rastgele sayilardan olusturuyoruz */
	for (i = 0; i < second_size; ++i)
	{
		secondArr[i] = 1 + rand() % 100;
	}

	printf("\nIkinci dizi elemanlari yazdirliyor\n");
	printf("**********************************\n");

	/* Ikinci dizimizi yazdiralim */
	for (i = 0; i < second_size; ++i)
	{
		printf("secondArr[%d] = %d\n", i, secondArr[i]);
	}

	/* Dizilerimizi birlestirecek olan arrayMerge fonksiyonuna çagri yapiliyor*/
	arrayMerge(firstArr, secondArr, first_size, second_size);

	return 0;
}

void arrayMerge(int firstArr[], int secondArr[], int firstSize, int secSize)
{
	int i;
	int newArrSize =
			firstSize + secSize;   /* Yeni dizimizin boyuyu diger iki dizinin boyutlarinin toplamina esit olacak */
	int newArr[newArrSize];
	int sizeOfSubtraction;

	/*Diziler birlestiriliyor*/
	if (firstSize > secSize)
	{
		sizeOfSubtraction = firstSize - secSize;

		for (i = 0; i < firstSize; ++i)
		{
			newArr[i] = firstArr[i];
		}

		for (i = firstSize; i < newArrSize; ++i)
		{
			newArr[i] = secondArr[i - firstSize];
		}
	}

	else
	{
		sizeOfSubtraction = secSize - firstSize;

		for (i = 0; i < firstSize; ++i)
		{
			newArr[i] = firstArr[i];
		}

		for (i = firstSize; i < newArrSize; ++i)
		{
			newArr[i] = secondArr[i - firstSize];
		}
	}

	printf("\nYeni Dizimiz Yazdiriliyor...\n");
	printf("****************************\n");

	for (i = 0; i < newArrSize; ++i)
	{
		printf("newArr[%d] = %d\n", i, newArr[i]);
	}
}