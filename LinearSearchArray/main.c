#include<stdio.h>
#define SIZE 100

/* dizi elemanlarinin dogrusal olarak aranmasi */
/* dogrusal arama metodu kücük veya siralanmamis dizilerde etkili calisir ancak buyuk ve siralanmis dizilerde etkili degildir */

size_t linearSearch(const int array[], int key, size_t size);   /* dogrusal arama fonksiyonunun prototipi */

int main()
{
	int arr[SIZE];  /* arr dizisinin tanimlanmasi */
	size_t x;   /* arr dizisindeki 0-99 eleman icin sayac */
	int searchKey;  /* arr dizisi icerisinde aranacak anahtar */
	size_t element; /* anahtarin konumunu ya da geri donus degeri olarak "-1" tutacak degisken */

	/* veri uretme */
	for (x = 0; x < SIZE; ++x)
	{
		arr[x] = 2 * x;
	}

	puts("Tamsayi arama anahtari giriniz:");
	scanf("%d", &searchKey);

	/* arr dizisinde anahtar aranmasi */
	element = linearSearch(arr, searchKey, SIZE);

	/* sonuclarin goruntulenmesi */
	if (element != -1)
	{
		printf("Bulunan deger = %d\n", element);
	}
	else
	{
		puts("Deger bulunamadi");
	}

	return 0;
}

/* anahtar ile her elemanin dogru konumu bulunana kadar veya dizi sonuna ulasana kadar devam etmesi; */
/* eleman bulundu ise konumu, bulunamadi ise "-1" dondurulmesi */
size_t linearSearch(const int array[], int key, size_t size)
{
	size_t n;   /* sayac */

	/* dizi icinde dongu yoluyla dolasilmasi */
	for (n = 0; n < SIZE; ++n)
	{
		if (array[n] == key)
		{
			return n;   /* konumun dondurulmesi */
		}
	}
	return -1;  /* anahtar bulunamamasi durumu */
}