#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Bir tamsayi dizisinin elemanlarini terslne cevirme-Reverse */
/*
    Elimizde N boyutunu verdigimiz bir dizi olsun. Bu diziyi tersine dondurebilmek icin en bastaki elemanla en sondaki elemanin
    yerlerini degismemiz gerekiyor. Indisler uzerinden dusunecek olursak ilk olarak 0. ve (N-1). indislerde bulunan elemanları
    swap islemiyle degismemiz gerekir. Dikkat ederseniz tek islemde iki elemanin yeri degisti. Oyleyse N/2 adet islem yapilacagi
    sonucuna ulasabiliriz.
*/

void arrayGenerator(int arr[], int size); /*Dizi uretme fonksiyonumuzun prototipi */
void printArray(int arr[], int size);    /* Dizi yazdirma fonksiyonumuzun prototip */
void reverseArray(int arr[], int startOfArray, int endOfArray);  /* Diziyi ters cevirme fonksiyonumuzun prototipi */

int main()
{
	int size;

	printf("Dizinini boyutunu giriniz: ");
	scanf("%d", &size);

	int arr[size];  /* Dizi tanimlandi */

	printf("\nDiziniz yazdiriliyor...\n");
	printf("************************\n");

	arrayGenerator(arr, size);  /* Dizi olusturma fonksiyonumuza cagri yapiliyor */
	printArray(arr, size);  /* Dizi yazdirma fonksiyonumuza cagri yapiliyor*/
	reverseArray(arr, 0, size - 1);   /* Diziyi ters döndürme fonksiyonumuza cagri yapiliyor */

	printf("\nTers cevirilen dizi yazdirliyor...\n");
	printf("**********************************\n");

	printArray(arr, size);

	return 0;
}

void arrayGenerator(int arr[], int size)
{
	srand(time(NULL));  /* Dizi elemanlarini rastgele belirleyecegiz */

	int i;

	for (i = 0; i < size; ++i)
	{
		arr[i] = 1 + rand() % 100;  /* Dizi elemanlarimiz 1-100 arasinda olacak sekilde diziye ataniyor */
	}
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void reverseArray(int arr[], int startOfArray, int endOfArray)
{
	int temp;   /* Gecici degiskenimiz olusturuldu */

	while (startOfArray < endOfArray)   /* Dizimizin baslangic ve bitis indisleri */
	{
		temp = arr[startOfArray];
		arr[startOfArray] = arr[endOfArray];
		arr[endOfArray] = temp;

		/* Asagidaki uygulama yoluyla islemlerimizi yariya indiriyoruz. Bir bastan bir sonran yer degistirip ortanca elemana yaklasiyoruz */
		startOfArray++;
		endOfArray--;
	}
}