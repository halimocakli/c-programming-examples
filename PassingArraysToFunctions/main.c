#include<stdio.h>
#define SIZE 5

/* Dizilerin call-by-reference ve call-by-value metotlarıyla fonksiyonlara aktrarımı */

void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main()
{
	int arr[SIZE] = {0, 1, 2, 3, 4};  /* Dizinin baslangic degerleri ataniyor */
	size_t i;   /* Sayac */

	puts("Tum dizinin referans ile gecirilmesinin etkisi"
		 "\n**********************************************"
		 "\n\nOrijinal dizinin degerleri:");

	/* Orijinal dizinin ciktisi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%3d", arr[i]);
	}

	puts("");

	/* modifyArray fonksiyonuna dizinin referansinin gecirilmesi */
	modifyArray(arr, SIZE);

	puts("Degistirilen dizinin degerleri:");

	/* Degistirilen dizinin ciktisi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%3d", arr[i]);
	}

	/* arr[3] icindeki degerlerin ciktisi */
	printf("\n\n\nDeger ile dizi elemani gecirmenin etkisi"
		   "\n****************************************"
		   "\narr[3] elemaninin degeri = %d\n", arr[3]);

	modifyElement(arr[3]); /* Dizi elemani olan arr[3]'un degerle fonksiyona gecirilmesi*/

	/* arr[3] icindeki degerlerin ciktisi */
	printf("arr[3] elemaninin degeri = %d\n", arr[3]);

	return 0;
}

/* modifyArray fonksiyonunda "b"nin, orijinal dizideki "arr"in bellekteki yerini gostermesi */
void modifyArray(int b[], size_t size)
{
	size_t j;   /* Sayac */

	/* Her elemani iki ile carpma */
	for (j = 0; j < size; ++j)
	{
		b[j] *= 2;   /* Orijinal diziyi gercek olacak sekilde degistirmek */
	}
}

/* modifyElement fonksiyonunda "e"nin main fonksiyonundan gelen arr[3] dizi elemaninin yerel kopyasi olmasi */
void modifyElement(int e)
{
	/* Parametreyi 2 ile carpma */
	printf("modifyElement degeri = %d\n", e *= 2);
}