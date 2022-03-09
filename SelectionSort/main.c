#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Selection Sort dizi icinde gezerek en kucuk elemani en basa atma yontemi kullanir
// En kucuk elememani en basa attiktan sonra kontrol etmeye dizinin bir sonraki elemanindan baslar

void selectionSortAlgorithm(int array[], int size)
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

		temp = array[i];
		array[i] = array[smallestIndex];
		array[smallestIndex] = temp;
	}

	printf("\n\nGirdiginiz Dizi Degerleri Siralaniyor...\n");

	for (i = 0; i < size; ++i)
	{
		printf("%d\t", array[i]);
	}
}

int main()
{
	int tamSayiDizisi[MAX];
	int boyut;
	int i = 0;

	printf("Kac Elemanli Bir Dizi Olusturmak Istiyorsunuz: ");
	scanf("%d", &boyut);
	printf("\n");

	for (i; i < boyut; ++i)
	{
		printf("Dizinin %d. Elemanini Giriniz: ", i + 1);
		scanf("%d", &tamSayiDizisi[i]);
	}

	printf("Girdiginiz Dizi Elemanlari Asagidaki Gibidir...\n");

	for (i = 0; i < boyut; ++i)
	{
		printf("%d\t", tamSayiDizisi[i]);
	}

	selectionSortAlgorithm(tamSayiDizisi, boyut);
	return 0;
}
