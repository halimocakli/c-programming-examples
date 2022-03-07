#include<stdio.h>

/* Ozellikle belirtilmedikce static int array elemanlarina ilk deger olarak 0 atanmasi */

void staticArrayInit(); /* static array fonksiyonu prototipi */
void automaticArrayInit();  /* automatic array fonksiyonu prototipi */

int main()
{
	puts("Her fonksiyona yapilan ilk cagri:");
	staticArrayInit();
	automaticArrayInit();

	puts("\n\nHer fonksiyona yapilan ikinci cagri:");
	staticArrayInit();
	automaticArrayInit();

	return 0;
}

/* Static yerel diziyi gosteren fonksiyon */
void staticArrayInit()
{
	/* Ilk fonksiyon cagrisinda elemanlara 0 degeri atanmasi */
	static int array1[3];
	size_t i;   /* Sayac */

	puts("\nDegerlerin staticArrayInit fonksiyonuna girisi:");

	/* array1 iceriginin ciktisi */
	for (i = 0; i < 3; ++i)
	{
		printf("array[%u] = %d ", i, array1[i]);
	}

	puts("\nDegerlerin staticArrayInit fonksiyonundan cikisi:");

	/* array1 iceriginin degistirilmesi ve ciktisi */
	for (i = 0; i < 3; ++i)
	{
		printf("array1[%u] = %d ", i, array1[i] += 5);
	}
}

/* Otomatik yerel diziyi gosteren fonksiyon */
void automaticArrayInit()
{
	/* Her fonksiyon cagrsisinda elemanlara ilk deger atanmasi */
	int array2[3] = {1, 2, 3};
	size_t i;   /* Sayac */

	puts("\n\nDegerlerin automaticArrayInit fonksiyonuna girisi:");

	/* array2 iceriginin ciktisi */
	for (i = 0; i < 3; ++i)
	{
		printf("array2[%u] = %d ", i, array2[i]);
	}

	puts("\nDegerlerin automaticArrayInit fonksiyonundan cikisi:");

	/* array2 iceriginin degistirilmesi ve ciktisi */
	for (i = 0; i < 3; ++i)
	{
		printf("array2[%u] = %d ", i, array2[i] += 5);
	}
}