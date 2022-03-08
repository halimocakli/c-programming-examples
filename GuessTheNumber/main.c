#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int sayi, tahmin;
	int deneme = 0;

	srand(time(NULL));

	sayi = 1 + rand() % 1000;

	printf("%s", "1 Ile 1000 Arasinda Bir Sayi Tuttum...\n");
	printf("%s", "Bulabilecek Misin?\n\n");

	do
	{
		printf("%s", "Dene bakalim: ");
		scanf("%d", &tahmin);

		deneme++;

		if (tahmin < sayi)
			printf("Biraz Daha Buyuk Bir Sayi Girmelisin...\n");
		else if (tahmin > sayi)
			printf("Biraz Daha Kucuk Bir  Sayi Girmelisin...\n");
		else
			printf("TEBRIKLER, \"%d\" SAYISINI BULDUN!!\a", sayi);

	} while (tahmin != sayi);

	if (deneme < 10)
		printf("\n\nSanirim Biri Sana Sayiyi Soyledi :)");

	else if (deneme == 10)
		printf("\n\nSen Bu Isi Biliyorsun...");

	else if (deneme > 10)
		printf("\n\nDaha Iyisini Yapabilirsin...");

	return 0;
}