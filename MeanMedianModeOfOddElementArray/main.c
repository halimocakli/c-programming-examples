#include<stdio.h>
#define SIZE 99

/* Anket verilerinin diziler ile analizi: Verilerin orta deger, ortalama ve modunu hesaplanmasi */
/* Fonksiyon tanimlamalari */
void mean(const unsigned int answer[]);
void median(unsigned int answer[]);
void mode(unsigned int freq[], unsigned const int answer[]);
void bubbleSort(unsigned int arr[]);
void printArray(unsigned const int arr[]);

int main()
{
	unsigned int frequency[10] = {0};   /* dizi frekansına baslangic degeri atanmasi */

	/* response dizisine baslangic degerlerinin atanmasi */
	unsigned int response[SIZE] =
			{6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
			 7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
			 6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
			 7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
			 6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
			 7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
			 5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
			 7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
			 7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
			 4, 5, 6, 1, 6, 5, 7, 8, 7};

	/* response degerlerin islenmesi */
	mean(response);
	median(response);
	mode(frequency, response);

	return 0;
}

/* response degerlerinin ortalamasini hesaplama */
void mean(const unsigned int answer[])
{
	size_t j;               /* dizi elemanlarini toplama sayaci */
	unsigned int total = 0; /* dizi elemanlarinin toplamini tutan degisken */

	printf("%s\n%s\n%s\n", "********", "Ortalama", "********");

	/*response verilerinin tümü */
	for (size_t j = 0; j < SIZE; ++j)
	{
		total += answer[j];
	}

	printf("Tum verilerin ortalamasi,\n"
		   "tum indislerdeki degerlerin toplaminin\n"
		   "indis sayisina olan bolumudur\n"
		   "(%u). Bu kosturmanin\n"
		   "ortalamasi : %u / %u = %.4f\n\n",
			SIZE, total, SIZE, (double)total / SIZE);
}

/* dizinin siralanmasi ve orta elemaninin bulunmasi */
void median(unsigned int answer[])
{
	printf("\n%s\n%s\n%s\n%s",
			"********", "Mod", "********",
			"Siralanmamis dizi");

	printArray(answer); /* siralanmamis dizinin ciktisi */

	bubbleSort(answer); /* dizinin siralanmasi */

	printf("%s", "\n\nSiralanmis dizi");
	printArray(answer); /* siralanmis dizinin ciktisi */

	/* orta elemanin gosterilmesi */
	/* eleman sayisi tek olan dizilerde medyan bulma formulu = (eleman sayisi + 1) / 2 */
	printf("\n\nOrta eleman(mod) olan %u\n"
		   "Dizideki %u eleman icinden secilmistir\n"
		   "Bu kosturmanin orta elemani = %u\n\n",
			(SIZE / 2) + 1, SIZE, answer[(SIZE / 2) + 1]);
}

/* en sik karsilasilan response degerinin bulunmasi */
void mode(unsigned int freq[], const unsigned int answer[])
{
	size_t rating;              /* freq dizisinde en sik karsilasilan eleman icin sayac */
	size_t j;                   /* 0-98 cevap dizisi icin sayac */
	unsigned int h;             /* freq dizisi degerlerinin cizelgesi icin sayac */
	unsigned int largest = 0;   /* en yuksek frekans */
	unsigned int modeValue = 0; /* en sik karsilasilan cevap */

	printf("\n%s\n%s\n%s\n",
			"********", "Mod", "********");

	/* frekanslara 0 baslangic degeri atanmasi */
	for (rating = 1; rating <= 9; ++rating)
	{
		freq[rating] = 0;
	}

	/* frekanslarin toplanmasi */
	for (j = 0; j < SIZE; ++j)
	{
		++freq[answer[j]];
	}

	/* cevap sutunlari basliginin ciktisi */
	printf("%s%11s%15s\n\n",
			"Cevap", "Frekans", "Cizelge");

	/* cevaplarin yazdirilmasi */
	for (rating = 1; rating <= 9; ++rating)
	{
		printf("%5u%9u\t\t", rating, freq[rating]);

		/* mod degeri ve en yuksek frekans degerinin takibi */
		if (freq[rating] > largest)
		{
			largest = freq[rating];
			modeValue = rating;
		}

		/* frekans degerlerinden olusan cizelge sutununun yazdirilmasi */
		for (h = 1; h <= freq[rating]; ++h)
		{
			printf("%s", "*");
		}

		puts("");
	}

	/* mod degerlerinin yazdirilmasi */
	printf("\nMod en sik karsilasilan degerdir.\n"
		   "Bu kosturmada mod = %u ve "
		   "%u kez bulunmustur.\n", modeValue, largest);
}

/* kabarcik algoritmasi ile diziyi siralayan fonksiyon */
void bubbleSort(unsigned int arr[])
{
	unsigned int pass;  /* dolasma sayaci */
	size_t j;           /* karsilastirma sayaci */
	unsigned int hold;  /* yer degistirme icin gecici degisken */

	/* dolasma sayilarini kontrol eden dongu */
	for (pass = 0; pass < SIZE; ++pass)
	{
		/* her dolasmadaki karsilastirma sayilarini kontrol eden dongu */
		for (j = 0; j < SIZE; ++j)
		{
			/* siralama disi ise yer degistirme */
			if (arr[j] > arr[j + 1])
			{
				hold = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = hold;
			}
		}
	}
}

/* dizi iceriginin yazdirilmasi(her sirada 20 deger) */
void printArray(const unsigned int arr[])
{
	size_t j;   /* sayac */

	printf("\n-----------------\n");

	/* dizi iceriginin yazdirilmasi */
	for (j = 0; j < SIZE; ++j)
	{
		if (j % 20 == 0)    /* her 20 degerden sonra satir basi */
		{
			puts("");
		}

		printf("%u ", arr[j]);
	}
}