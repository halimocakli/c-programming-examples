#include<stdio.h>

/* Klavyeden 10-100 arasinda 20 sayi okuyunuz. Her rakam okunur okunmaz, sayi
 * onceki girilenlerden farkli ise ekrana yazdiriniz. En kotu ihtimalle 20
 * sayinin da farkli oldugunu varsayiniz. Kullanilabilecek en kucuk boyutlu
 * dizi kullanarak bu problemi cozunuz
 */

/* tekrar eden sayi bulma fonksiyonu */
int repeatedNumberFunc(int number[], int insertedNumber, int differentNumbCounter);

int main()
{
	int i;                          /* sayac */
	int numbers[20] = {0};          /* elemanlari kontrol edilecek dizi */
	int insertedNumber;             /* kullanici tarafindan girilecek sayi */
	int differentNumbCounter = 0;   /* farkli sayi girdisini kontrol eden sayac */

	for (i = 0; i < 20; ++i)
	{
		printf("Enter a number between 10 and 100: ");
		scanf("%d", &insertedNumber);

		/* girilen sayinin 10 ve 100 arasinda olup olmadiginin kontrolu */
		while (insertedNumber < 10 || insertedNumber > 100)
		{
			printf("The number must be beetween 10 and 100\n");
			printf("Enter a number beetween 10 and 100: ");
			scanf("%d", &insertedNumber);
		}

		/* eger tekar eden sayiyi kontrol eden fonskiyondan 0 donerse else yapisi calistirilacak */
		/* else yapisi icindeki islemler geregi ayni sayilar diziye islenmeyecek */
		if (repeatedNumberFunc(numbers, insertedNumber, differentNumbCounter))
		{
			printf("\nYou've inserted same number.\n");
		}
		else
		{
			printf("\nThats it, %d is a new number!\n", insertedNumber);
			numbers[differentNumbCounter] = insertedNumber;    /* farkli girilen sayi diziye ekleniyor */
			++differentNumbCounter;
		}
	}

	puts("");
	printf("*************************************************\n");
	puts("");

	/* girilen sayilarin yazdirilmasi */
	for (i = 0; i < 20; ++i)
	{
		printf("%d. Number that you inserted is : %d\n", i + 1, numbers[i]);
	}

	return 0;
}

int repeatedNumberFunc(int numbers[], int insertedNumber, int differentNumbCounter)
{
	int j;

	for (j = 0; j < differentNumbCounter; ++j)
	{
		/* girilen sayinin ayni olup olmadiginin kontrolu */
		if (insertedNumber == numbers[j])
		{
			return 1;
		}
	}
	return 0;
}