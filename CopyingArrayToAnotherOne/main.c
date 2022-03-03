#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	/* Dizi elemanlarimizi rastgele olusturacagimiz icin srand() fonksiyonunu kullaniyoruz */
	srand(time(NULL));

	int i;
	int size;

	/* Kullanicidan dizi boyutu alinir */
	printf("Dizinizin boyutunu giriniz:");
	scanf("%d", &size);

	int arr[size];      /*Ana dizi*/
	int copyArr[size];  /*Ikinci ve kopya dizi olarak kullanilacak olan dizi*/

	/* Ana dizi elemanlari rastgele ataniyor */
	for (i = 0; i < size; ++i)
	{
		arr[i] = 1 + rand() % 100;
	}

	/* Ikinci dizi elemanlari rastgele ataniyor */
	for (i = 0; i < size; ++i)
	{
		copyArr[i] = 1 + rand() % 100;
	}

	printf("\nAna dizi elemanlari yazdirliyor...\n");
	printf("******************************\n");

	/* Ana dizimizi yazdiralim */
	for (i = 0; i < size; ++i)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("\nIkinci dizi elemanlari yazdirliyor...\n");
	printf("***************************************\n");

	/* Ikinci dizimizi yazdiralim */
	for (i = 0; i < size; ++i)
	{
		printf("CopyArr[%d] = %d\n", i, copyArr[i]);
	}

	/* Ana dizimizi ikinci dizimize kopyaliyoruz*/
	for (i = 0; i < size; ++i)
	{
		copyArr[i] = arr[i];
	}

	printf("\nAna dizinin ikinci diziye kopyalanmasi ile olusan yeni dizi yazdirliyor...\n");
	printf("****************************************************************************\n");

	/* KOpyalanan dizimizi yazdiralim */
	for (i = 0; i < size; ++i)
	{
		printf("YeniArr[%d] = %d\n", i, copyArr[i]);
	}

	return 0;
}