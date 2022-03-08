#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Once Ikinci eleman kontrol edilir, birinciden kucukse sola atilir.
// Ardindan ucuncu eleman kontrol edilir, birinci ve ikinciden kucukse en basa atilir.

void insertionSortAlgorithm(int array[], int size)
{
	int i;
	int arrayMember;
	int previusArrayMember;

	for (i = 1; i < size; ++i)
	{
		arrayMember = array[i];
		previusArrayMember = i - 1;

		while (previusArrayMember >= 0 && array[previusArrayMember] > arrayMember)
		{
			array[previusArrayMember + 1] = array[previusArrayMember];
			previusArrayMember--;
		}

		array[previusArrayMember + 1] = arrayMember;
	}

	printf("\n\nGirdiginiz Dizi Degerleri Siralaniyor...\n");

	for (i = 0; i < size; ++i)
	{
		printf("%d\t", array[i]);
	}
}

void insertionSortAlgorithm_2(int array[], int size)
{
	int add;
	int i;
	int j;
	int k;

	for (i = 0; i < size; ++i)
	{
		add = array[i];

		for (k = i - 1; k >= 0 && add <= array[k]; --k)
		{
			array[k + 1] = array[k];
		}
		array[k + 1] = add;
	}

	printf("\nGirdiginiz Dizi Degerleri Siralaniyor...\n");

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

	printf("\nGirdiginiz Dizi Elemanlari Asagidaki Gibidir...\n");

	for (i = 0; i < boyut; ++i)
	{
		printf("%d\t", tamSayiDizisi[i]);
	}

	insertionSortAlgorithm(tamSayiDizisi, boyut);
	printf("\n");
	insertionSortAlgorithm_2(tamSayiDizisi, boyut);

	return 0;
}