#include<stdio.h>
#define SIZE 15

/* sirali dizide ikili arama */
/* dizi sirali ise yuksek hiza sahip ikili arama kullanilabilir */
/*
    ikili arama algoritmasinda her karsilastirma sonunda sirali dizideki elemanlarin yarisini eler. algoritma dizinin ortasina
    konumlanir ve anahtar ile karsilastirir. eger esitse, dizideki o elemanin indisi dondurulur. esit degilse, problemin boyutu
    dizinin bir yarisini aramak uzere azaltilmis olur. anahtar dizideki orta elemandan kucukse dizinin ilk yarisi aranir, degilse
    dizinin ikinci yarisi aranir. eger anahtar belirlenmis alt dizide(orijinal dizinin bir kismi) bulunamazsa, algoritma geregi
    orijinal dizinin ceyreginde arama devam ettirilir. bu islem anahtarin alt dizinin orta elemanina esit olmasina veya alt dizinin
    bir elema esit olmayana kadar arama devam ettirilir
*/

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
void printHeader();
void printRow(const int b[], size_t low, size_t mid, size_t high);

int main()
{
	int arr[SIZE];
	size_t i;   /* arr dizisindeki elemanlara baslangic degeri atayan sayac */
	int key;    /* arr dizisindeki degerin konumunu belirten degisken */
	size_t result;  /* anahtarin konumunu veya "-1" tutan degisken */

	/* verilerin olusturulmasi */
	for (i = 0; i < SIZE; ++i)
	{
		arr[i] = 2 * i;
	}

	printf("%s", "0-28 arasi rakam giriniz: ");
	scanf("%d", &key);

	printHeader();

	/* arr dizisinde anahtarin aranmasi */
	result = binarySearch(arr, key, 0, SIZE - 1);

	/* sonuclarin goruntulenmesi */
	if (result != -1)
	{
		printf("\n%d degeri %d icinde bulunmustur\n", key, result);
	}
	else
	{
		printf("\n%d bulunamadi\n", key);
	}

	return 0;
}

/* dizi icerisinde ikili aramanin gerceklestirilmesi */
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
	int middle; /* variable dizinin orta elemanini tutan degisken */

	/* dusuk indisin yuksek indisten buyuk olmasina kadar devam eden dongu */
	while (low <= high)
	{
		/* aranacak altdizinin orta elemaninin tesip edilmesi */
		middle = (low + high) / 2;

		/* dongu sirasinda kullanilan altdizinin goruntulenmesi */
		printRow(b, low, middle, high);

		/* orta elemanla anahtar uyusursa, orta elemanin dondurulmesi */
		if (searchKey == b[middle])
		{
			return middle;
		}

			/* anahtar orta elemandan kucukse, yeni yuksek degerin atanmasi */
		else if (searchKey < b[middle])
		{
			high = middle - 1;  /* dizi sonunda dusugun aranmasi */
		}

			/* anahtar orta elemandan buyukse, yeni dusuk degerin atanmasi */
		else
		{
			low = middle + 1;   /* dizi sonunda yuksegin aranmasi */
		}
	}

	return -1;  /* anahtarin bulunmasi */
}

/* cikti icin baslik yazdirilmasi */
void printHeader()
{
	unsigned int i; /* sayac */

	puts("\nIndisler:");

	/* sutun basinin ciktisi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%3u ", i);
	}

	puts("");

	/* "-" karakterlerin yazdirilmasi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%s", "-");
	}
	puts("");
}

/* bir satir cikti ile bir islem goren dizi parcasinin yazdirilmasi */
void printRow(const int b[], size_t low, size_t mid, size_t high)
{
	size_t i;   /* b dizisinde dolasmak icin sayac */

	/* dizi icin olusturulan dongu*/
	for (i = 0; i < SIZE; ++i)
	{
		/* altdizi kapsami disinda kalan bosluklarin yazdirilmasi */
		if (i < low || i > high)
		{
			printf("%s", " ");
		}
		else if (i == mid) /* orta elemanin goruntulenmesi */
		{
			printf("%3d", b[i]);    /*orta elemanin isaretlenmesi */
		}
		else    /* altdizideki diger elemanlarin yazdirilmasi */
		{
			printf("%3d", b[i]);
		}
	}

	puts("");
}