#include<stdio.h>
#define SIZE 10

/* buble sort algoritmasi ile dizi elemanlari siralama */

int main()
{
	int arr[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	int pass;   /* dolasma sayaci */
	size_t i;   /* karsilastirma sayaci */
	int hold;    /* elemanlar yer degistirirken kullanilacak gecici degisken */

	puts("Orijinal siradaki veriler\n"
		 "*************************");

	/* Orijinal dizinin yazdirilmasi */
	for (i = 0; i < SIZE; i++)
	{
		printf("%d  ", arr[i]);
	}

	/* Kabarcik siralama */
	/* Dizi ici dolasimi kontrol eden dongu */
	for (pass = 0; pass < SIZE; ++pass)
	{
		/* Her dolasimdaki karsilastirma sayisini kontrol eden dongu */
		for (i = 0; i < SIZE; ++i)
		{
			/* Komsu elemanlari karsilastirma ve ilk eleman ikinciden buyukse yer degistirme */
			if (arr[i] > arr[i + 1])
			{
				hold = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = hold;
			}
		}
	}

	puts("\n\nElemanlarin artan sirada siralanmasi\n"
		 "***********************************");

	/* Sirali dizinin ciktisi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}