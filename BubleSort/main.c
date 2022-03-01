#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Bubble Sort algoritmasi bir dizinin icindeki integer degerleri siralamak icin kullanilir.
// Dizinin eleman sayisinin bir eksigi kadar elemanlar arasinda karsilastirma yapilir.
// Dizi icinde bulunan degerleri ikili ikili karsilastirip ikiliden buyuk olani saga yazar
// Once 5 8 1 3 0 dizisini kontrol edip siraladiktan sonra 5 1 3 0 8 sonucuna ulasir ve ardindan 5 1 3 0 dizisini ayni mantikla kontrol eder

void bubbleSortAlgorithm(int array[], int size)
{
	int i;
	int j;
	int temp;

	for (i = 0; i < size; ++i)
	{
		for (j = 1; j < size - i; ++j)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
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

	bubbleSortAlgorithm(tamSayiDizisi, boyut);
	return 0;
}
